#include "ProjetJeuxEchecs.h"
#include "Pieces.h"
#include <QGridLayout>
#include <QWidget>
#include <QPalette>
#include <QColor>

class ChessSquare : public QWidget {
public:
    ChessSquare(bool isEven, QWidget* parent = nullptr) : QWidget(parent) {
        QPalette pal = this->palette();
        if (isEven) {
            pal.setColor(QPalette::Window, QColor(227, 193, 111));
        }
        else {
            pal.setColor(QPalette::Window, QColor(184, 139, 74));
        }
        this->setAutoFillBackground(true);
        this->setPalette(pal);
        this->setFixedSize(75, 75);
    }

    Piece* piece = nullptr;
};

void ProjetJeuxEchecs::setGrid(QGridLayout* grid)
{
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    int gridSize = 8;

    for (int row = 0; row < gridSize; row++) {
        for (int col =   0; col < gridSize; col++) {
            bool isEven = (row + col) % 2 == 0;
            ChessSquare* box = new ChessSquare(isEven, this);
            grid->addWidget(box, row, col);
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
