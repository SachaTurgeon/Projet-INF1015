#pragma once

#include <utility>
#include <vector>
#include <QWidget>
#include <QLabel>

class Piece: public QWidget
{
	Q_OBJECT

public:
	Piece(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	void setPosition(std::pair<int, int> position) { position_ = position; }
	std::pair<int, int> getPosition() { return position_; }
    virtual std::vector<std::pair<int, int>> calculateMoves() { return {}; }
    virtual std::string getClassName() { return "Piece"; }
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void showPieceImage(const QString& imageFile);
    bool getIsWhite() { return isWhite_; }
    void changeIsWhiteTurn() { isWhiteTurn_ = !isWhiteTurn_; }
    void setHasMovedTrue() { hasMoved_ = true; }
    void setHasMovedFalse() { hasMoved_ = false; }


signals:
	void pieceRemove(Piece* piece);
    void pieceSet(Piece* piece, std::pair<int, int> newPosition, std::pair<int, int> oldPosition, bool hasMoved);
	void requestPieceOnSquare(int row, int col);
    void changeTurn();

public slots:
	void getPieceOnSquare(Piece* piece);

protected:
	QLabel* imageLabel_;
	Piece* otherPiece_ = nullptr;    
	std::pair<int, int> position_;
	bool hasMoved_ = false;
	bool isWhite_;

private:
	bool isDragging_ = false;
	QPoint offset_;
    bool isWhiteTurn_ = true;
};

class Pawn : public Piece
{
public:
	Pawn(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	std::vector<std::pair<int, int>> calculateMoves() override;
    std::string getClassName() override { return "Pawn"; }

private:

};

class Knight : public Piece
{
public:
	Knight(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	std::vector<std::pair<int, int>> calculateMoves() override;
    std::string getClassName() override { return "Knight"; }

private:

};

class Bishop : public Piece
{
public:
	Bishop(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	std::vector<std::pair<int, int>> calculateMoves() override;
    std::string getClassName() override { return "Bishop"; }

private:

};

class Rook : public Piece
{
public:
	Rook(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
    std::vector<std::pair<int, int>> calculateMoves() override;
    std::string getClassName() override { return "Rook"; }

private:

};

class Queen : public Piece
{
public:
	Queen(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
    std::vector<std::pair<int, int>> calculateMoves() override;
    std::string getClassName() override { return "Queen"; }

private:

};

class King : public Piece
{
    Q_OBJECT

public:
	King(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
    std::vector<std::pair<int, int>> calculateMoves() override;
    std::string getClassName() override { return "King"; }
    ~King();

signals:
    void kingAdded();
    void kingDeleted();

private:

};
