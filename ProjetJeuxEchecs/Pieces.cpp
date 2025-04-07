#include "Pieces.h"
#include <QWidget>
#include <utility>
#include <vector>

Piece::Piece(std::pair<int, int> position, bool isWhite, QWidget* parent) : QWidget(parent), position_(position), isWhite_(isWhite) {
	this->setFixedSize(50, 50);
};

Pawn::Pawn(std::pair<int, int> position, bool isWhite, QWidget* parent) : Piece(position, isWhite, parent) {}

std::vector<std::pair<int, int>> Pawn::calculateMoves() {
	std::vector<std::pair<int, int>> moves;
	return moves;
}