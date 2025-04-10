#include "ProjetJeuxEchecs.h"
#include "Pieces.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QPalette>
#include <QColor>
#include <utility>
#include <string>

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
        delete piece_;
    }
    piece_ = piece;
    this->update();
}

template <typename T>
void ProjetJeuxEchecs::addPieceToGrid(std::pair<int, int> position, bool isWhite, ChessSquare* square) {
    T* piece = new T(position, isWhite);
    connect(piece, &Piece::pieceRemove, this, &ProjetJeuxEchecs::onPieceRemove);
    connect(piece, &Piece::pieceSet, this, &ProjetJeuxEchecs::onPieceSet);
    square->addPiece(piece);
}

void ProjetJeuxEchecs::onPieceRemove(Piece* piece) {
    squaresVector[piece->getPosition().first][piece->getPosition().second]->setPieceNull();
}

void ProjetJeuxEchecs::onPieceSet(Piece* piece, std::pair<int, int> newPosition) {
    squaresVector[newPosition.first][newPosition.second]->addPiece(piece);
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
            if (row == 6) {
                addPieceToGrid<Pawn>(std::make_pair(row, col), true, square);
            }
            else if (row == 1){
                addPieceToGrid<Pawn>(std::make_pair(row, col), false, square);
            }
            else if ((row == 7) && (col == 0 || col == 7)) {
                addPieceToGrid<Rook>(std::make_pair(row, col), true, square);
            }
            else if ((row == 0) && (col == 0 || col == 7)) {
                addPieceToGrid<Rook>(std::make_pair(row, col), false, square);
            }
            else if ((row == 7) && (col == 1 || col == 6)) {
                addPieceToGrid<Knight>(std::make_pair(row, col), true, square);
            }
            else if ((row == 0) && (col == 1 || col == 6)) {
                addPieceToGrid<Knight>(std::make_pair(row, col), false, square);
            }
            else if ((row == 7) && (col == 2 || col == 5)) {
                addPieceToGrid<Bishop>(std::make_pair(row, col), true, square);
            }
            else if ((row == 0) && (col == 2 || col == 5)) {
                addPieceToGrid<Bishop>(std::make_pair(row, col), false, square);
            }
            else if ((row == 7) && (col == 3)) {
                addPieceToGrid<Queen>(std::make_pair(row, col), true, square);
            }
            else if ((row == 0) && (col == 3)) {
                addPieceToGrid<Queen>(std::make_pair(row, col), false, square);
            }
            else if ((row == 7) && (col == 4)) {
                addPieceToGrid<King>(std::make_pair(row, col), true, square);
            }
            else if ((row == 0) && (col == 4)) {
                addPieceToGrid<King>(std::make_pair(row, col), false, square);
            }
        }
    } 
}

void ProjetJeuxEchecs::setup() {
    QWidget* chessBoard = new QWidget(this);
    chessBoard->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QGridLayout* grid = new QGridLayout(chessBoard);
    setGrid(grid);
    chessBoard->setLayout(grid);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(chessBoard);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

ProjetJeuxEchecs::ProjetJeuxEchecs(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ProjetJeuxEchecsClass()) {
    ui->setupUi(this);
    setup();
}

ProjetJeuxEchecs::~ProjetJeuxEchecs() {
    delete ui;
}