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

signals:
    void deletePieceFromVector(Piece* piece);

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
    Piece* whiteKing;
    Piece* blackKing;

signals:
    void sendPieceOnSquare(Piece* piece);

private slots:
    void onPieceRemove(Piece* piece);
    void onPieceSet(Piece* piece, std::pair<int, int> newPosition, std::pair<int, int> oldPosition, bool hasMoved);
    void onPieceOnSquareRequest(int row, int col);
    void onReset();
    void onChangeTurn();
    void onDeletePieceFromVector(Piece* piece);
    void onKingAdded();
    void onKingDeleted();

private:
    Ui::ProjetJeuxEchecsClass *ui;
    void setup();
    void setGrid(QGridLayout* grid);
    template <typename T>
    void addPieceToGrid(std::pair<int, int> position, bool isWhite, ChessSquare* square);
    void setNormalGame(int row, int col, ChessSquare* square);
    bool isWhiteTurn_ = true;
    QLabel* turnLabel = new QLabel("White turn", this);
    void addPieceByName(std::string& typeName, std::pair<int, int> pos, bool isWhite, ChessSquare* square);
    int kingCount_ = 0;
};

class TooManyKingsException: public std::exception{
public:
    const char* what() const noexcept override {
        return "Erreur: trop de roi, il ne peut avoir plus d'un roi par côté";
    }
};
