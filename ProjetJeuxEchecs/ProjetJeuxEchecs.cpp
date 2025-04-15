#include "ProjetJeuxEchecs.h"
#include "Pieces.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QPalette>
#include <QColor>
#include <utility>
#include <QPushButton>

 ChessSquare::ChessSquare(std::pair<int, int> position, QWidget* parent) : QWidget(parent), position_(position) {
    QPalette pal = this->palette();
    if ((position_.first + position_.second) % 2 == 0) {
        pal.setColor(QPalette::Window, QColor(227, 193, 111));
    }
    else {
        pal.setColor(QPalette::Window, QColor(184, 139, 74));
    }
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setFixedSize(75, 75);
 }

void ChessSquare::addPiece(Piece* piece) {
    int offsetX = (width() - piece->width()) / 2;
    int offsetY = (height() - piece->height()) / 2;
    piece->move(offsetX, offsetY);
    piece->setParent(this);
    piece->setPosition(getPosition());
    piece->show();
    if (piece_) {
        removePiece();
    }
    piece_ = piece;
    this->update();
}

void ChessSquare::removePiece() {
    delete piece_;
    setPieceNull();
}

template <typename T>
void ProjetJeuxEchecs::addPieceToGrid(std::pair<int, int> position, bool isWhite, ChessSquare* square) {
    T* piece = new T(position, isWhite);
    connect(piece, &Piece::pieceRemove, this, &ProjetJeuxEchecs::onPieceRemove);
    connect(piece, &Piece::pieceSet, this, &ProjetJeuxEchecs::onPieceSet);
    connect(piece, &Piece::requestPieceOnSquare, this, &ProjetJeuxEchecs::onPieceOnSquareRequest);
    connect(this, &ProjetJeuxEchecs::sendPieceOnSquare, piece, &Piece::getPieceOnSquare);
    square->addPiece(piece);
    if (isWhite) { whitePieces.push_back(piece); }
    else { blackPieces.push_back(piece); }
}

void ProjetJeuxEchecs::setNormalGame(int row, int col, ChessSquare* square) {
    std::pair<int, int> pos = { row, col };

    if (row == 6) {
        addPieceToGrid<Pawn>(pos, true, square);
        return;
    }
    if (row == 1) {
        addPieceToGrid<Pawn>(pos, false, square);
        return;
    }

    if (row != 0 && row != 7)
        return;

    bool isWhite = (row == 7);

    switch (col) {
        case 0: case 7:
            addPieceToGrid<Rook>(pos, isWhite, square);
            break;
        case 1: case 6:
            addPieceToGrid<Knight>(pos, isWhite, square);
            break;
        case 2: case 5:
            addPieceToGrid<Bishop>(pos, isWhite, square);
            break;
        case 3:
            addPieceToGrid<Queen>(pos, isWhite, square);
            break;
        case 4:
            addPieceToGrid<King>(pos, isWhite, square);
            break;
    }
}

void ProjetJeuxEchecs::onPieceRemove(Piece* piece) {
    squaresVector[piece->getPosition().first][piece->getPosition().second]->setPieceNull();
}

void ProjetJeuxEchecs::onPieceSet(Piece* piece, std::pair<int, int> newPosition) {
    squaresVector[newPosition.first][newPosition.second]->addPiece(piece);
}

void ProjetJeuxEchecs::onPieceOnSquareRequest(int row, int col) {
    emit sendPieceOnSquare(squaresVector[row][col]->getPiece());
}

void ProjetJeuxEchecs::onReset() {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            ChessSquare* square = squaresVector[row][col];
            if (square->getPiece()) {
                square->removePiece();
            }
            setNormalGame(row, col, squaresVector[row][col]);
        }
    }
}

void ProjetJeuxEchecs::setGrid(QGridLayout* grid) {
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    int gridSize = 8;
    squaresVector.resize(gridSize, std::vector<ChessSquare*>(gridSize, nullptr));

    for (int row = 0; row < gridSize; row++) {
        for (int col =   0; col < gridSize; col++) {
            ChessSquare* square = new ChessSquare(std::make_pair(row, col), grid->parentWidget());
            grid->addWidget(square, row, col);
            squaresVector[row][col] = square;
            setNormalGame(row, col, square);
        }
    } 
}

void ProjetJeuxEchecs::setup() {
    QWidget* chessBoard = new QWidget(this);
    chessBoard->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QGridLayout* grid = new QGridLayout(chessBoard);
    setGrid(grid);
    chessBoard->setLayout(grid);

    QPushButton* resetButton = new QPushButton("Reset Board", this);
    connect(resetButton, &QPushButton::clicked, this, &ProjetJeuxEchecs::onReset);
    

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(resetButton);
    mainLayout->addWidget(chessBoard);
    mainLayout->setAlignment(resetButton, Qt::AlignHCenter);
    mainLayout->setAlignment(chessBoard, Qt::AlignHCenter);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

ProjetJeuxEchecs::ProjetJeuxEchecs(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ProjetJeuxEchecsClass()) {
    ui->setupUi(this);
    setWindowTitle("Projet jeu d'echec INF1015");
    setup();
}

ProjetJeuxEchecs::~ProjetJeuxEchecs() {
    delete ui;
}