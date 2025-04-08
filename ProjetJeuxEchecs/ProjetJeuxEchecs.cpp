#include "ProjetJeuxEchecs.h"
#include "Pieces.h"
#include <QGridLayout>
#include <QWidget>
#include <QPalette>
#include <QColor>
#include <utility>

 ChessSquare::ChessSquare(std::pair<int, int> pos, QWidget* parent) : QWidget(parent), pos_(pos) {
    QPalette pal = this->palette();
    if ((pos_.first + pos_.second) % 2 == 0) {
        pal.setColor(QPalette::Window, QColor(227, 193, 111));
    }
    else {
        pal.setColor(QPalette::Window, QColor(184, 139, 74));
    }
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setFixedSize(75, 75);
 }

void ProjetJeuxEchecs::setGrid(QGridLayout* grid)
{
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    int gridSize = 8;
    squaresVector.resize(8, std::vector<ChessSquare*>(8, nullptr));

    for (int row = 0; row < gridSize; row++) {
        for (int col =   0; col < gridSize; col++) {
            ChessSquare* square = new ChessSquare(std::make_pair(row, col), this);
            grid->addWidget(square, row, col);
            squaresVector[row][col] = square;
        }
    } 
}

void ProjetJeuxEchecs::setup() {
    QGridLayout* grid = new QGridLayout();
    setGrid(grid);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(grid);
    setCentralWidget(centralWidget);
}

ProjetJeuxEchecs::ProjetJeuxEchecs(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProjetJeuxEchecsClass())
{
    ui->setupUi(this);
    setup();
}

ProjetJeuxEchecs::~ProjetJeuxEchecs()
{
    delete ui;
}
