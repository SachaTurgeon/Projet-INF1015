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
    Piece* getPiece() { return piece_; }
    void removePiece();

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
    std::vector<Piece*> whitePieces;
    std::vector<Piece*> blackPieces;

signals:
    void sendPieceOnSquare(Piece* piece);

private slots:
    void onPieceRemove(Piece* piece);
    void onPieceSet(Piece* piece, std::pair<int, int> newPosition);
    void onPieceOnSquareRequest(int row, int col);
    void onReset();

private:
    Ui::ProjetJeuxEchecsClass *ui;
    void setup();
    void setGrid(QGridLayout* grid);
    template <typename T>
    void addPieceToGrid(std::pair<int, int> position, bool isWhite, ChessSquare* square);
    void setNormalGame(int row, int col, ChessSquare* square);
};
