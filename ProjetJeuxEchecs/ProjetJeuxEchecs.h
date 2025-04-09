#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjetJeuxEchecs.h"
#include "Pieces.h"
#include <QGridLayout>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class ProjetJeuxEchecsClass; };
QT_END_NAMESPACE

class ChessSquare : public QWidget
{
    Q_OBJECT

public:
    ChessSquare(std::pair<int, int> position, QWidget* parent = nullptr);
    void setPieceNull() { piece_ = nullptr; }
    void addPiece(Piece* piece);
    std::pair<int, int> getPosition() { return position_; }

private:
    Piece* piece_ = nullptr;
    std::pair<int, int> position_;
};

class ProjetJeuxEchecs : public QMainWindow
{
    Q_OBJECT

public:
    ProjetJeuxEchecs(QWidget *parent = nullptr);
    ~ProjetJeuxEchecs();

    std::vector<std::vector<ChessSquare*>> squaresVector;

private slots:
    void onPieceRemove(Piece* piece);
    void onPieceSet(Piece* piece, std::pair<int, int> newPosition);

private:
    Ui::ProjetJeuxEchecsClass *ui;
    void setup();
    void setGrid(QGridLayout* grid);
};
