#pragma once

#include <utility>
#include <vector>
#include <QWidget>

class Piece: public QWidget
{
public:
	Piece(std::pair<int, int> position, bool isWhite, QWidget* parent = nullptr);
	virtual std::vector<std::pair<int, int>> calculateMoves() {return {};}
private:
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