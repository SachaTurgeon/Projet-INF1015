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
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void showPieceImage(const QString& imageFile);

signals:
	void pieceRemove(Piece* piece);
	void pieceSet(Piece* piece, std::pair<int, int> newPosition);
	void requestPieceOnSquare(int row, int col);

public slots:
	void getPieceOnSquare(Piece* piece);

	bool isWhite_;

protected:
	QLabel* imageLabel_;
	Piece* otherPiece_ = nullptr;
	std::pair<int, int> position_;

private:
	bool isDragging_ = false;
	QPoint offset_;
};

class Pawn : public Piece
{
public:
	Pawn(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	std::vector<std::pair<int, int>> calculateMoves() override;
private:
	bool hasMoved_ = false;
};

class Knight : public Piece
{
public:
	Knight(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	std::vector<std::pair<int, int>> calculateMoves() override;
private:

};

class Bishop : public Piece
{
public:
	Bishop(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	std::vector<std::pair<int, int>> calculateMoves() override;
private:

};

class Rook : public Piece
{
public:
	Rook(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	std::vector<std::pair<int, int>> calculateMoves() override;
private:

};

class Queen : public Piece
{
public:
	Queen(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	std::vector<std::pair<int, int>> calculateMoves() override;
private:

};

class King : public Piece
{
public:
	King(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	std::vector<std::pair<int, int>> calculateMoves() override;
private:

};