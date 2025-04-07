#pragma once

#include <utility>
#include <vector>

class Piece
{
public:
	Piece() = default;
	Piece(std::pair<int, int> position, bool isWhite) : position_(position), isWhite_(isWhite) {};
	virtual std::vector<std::pair<int, int>> calculateMoves() {}
private:
	std::pair<int, int> position_;
	bool isWhite_;
};
