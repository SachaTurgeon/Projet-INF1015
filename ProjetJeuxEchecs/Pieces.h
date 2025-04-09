#pragma once

#include <utility>
#include <vector>
#include <QWidget>

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

signals:
	void pieceRemove(Piece* piece);
	void pieceSet(Piece* piece, std::pair<int, int> newPosition);

private:
	bool isDragging_ = false;
	QPoint offset_;
	std::pair<int, int> position_;
	bool isWhite_;
};

class Pawn : public Piece
{
public:
	Pawn(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	std::vector<std::pair<int, int>> calculateMoves() override;
private:
	bool hasMoved_ = false;
};