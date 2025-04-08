#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjetJeuxEchecs.h"
#include <QGridLayout>
#include <vector>
#include "Pieces.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ProjetJeuxEchecsClass; };
QT_END_NAMESPACE

class ChessSquare : public QWidget {
public:
    ChessSquare(std::pair<int, int> pos, QWidget* parent = nullptr);
    void addPiece(Piece* piece);
    std::pair<int, int> getPos() { return pos_; }

private:
    Piece* piece_ = nullptr;
    std::pair<int, int> pos_;
};

class ProjetJeuxEchecs : public QMainWindow
{
    Q_OBJECT

public:
    ProjetJeuxEchecs(QWidget *parent = nullptr);
    ~ProjetJeuxEchecs();

    std::vector<std::vector<ChessSquare*>> squaresVector;

private:
    Ui::ProjetJeuxEchecsClass *ui;
    void setup();
    void setGrid(QGridLayout* grid);
};
