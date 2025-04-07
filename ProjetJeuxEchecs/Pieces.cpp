#include "Pieces.h"
#include <QWidget>
#include <utility>
#include <vector>

Piece::Piece(std::pair<int, int> position, bool isWhite, QWidget* parent) : QWidget(parent), position_(position), isWhite_(isWhite) {
	this->setFixedSize(50, 50);
};