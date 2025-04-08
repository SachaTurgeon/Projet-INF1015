#include "Pieces.h"
#include <QWidget>
#include <utility>
#include <vector>
#include <QPalette>

Piece::Piece(std::pair<int, int> position, bool isWhite, QWidget* parent) : QWidget(parent), position_(position), isWhite_(isWhite) {
	this->setFixedSize(50, 50);
	QPalette pal = this->palette();
	pal.setColor(QPalette::Window, QColor(255, 0, 0));
	this->setAutoFillBackground(true);
	this->setPalette(pal);
};

Pawn::Pawn(std::pair<int, int> position, bool isWhite, QWidget* parent) : Piece(position, isWhite, parent) {}

std::vector<std::pair<int, int>> Pawn::calculateMoves() {
	std::vector<std::pair<int, int>> moves;
	return moves;
}