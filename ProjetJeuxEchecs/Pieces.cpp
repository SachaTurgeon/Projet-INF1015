#include "Pieces.h"
#include "ProjetJeuxEchecs.h"
#include <QWidget>
#include <utility>
#include <vector>
#include <QPalette>
#include <QMouseEvent>

Piece::Piece(std::pair<int, int> position, bool isWhite, QWidget* parent) : QWidget(parent), position_(position), isWhite_(isWhite) {
	this->setFixedSize(50, 50);
	QPalette pal = this->palette();
	pal.setColor(QPalette::Window, QColor(255, 0, 0));
	this->setAutoFillBackground(true);
	this->setPalette(pal);
};

void Piece::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        offset_ = event->pos();
        isDragging_ = true;
        setCursor(Qt::ClosedHandCursor);
    }
}

void Piece::mouseMoveEvent(QMouseEvent* event)
{
    if (isDragging_) {
        QPoint parentPos = parentWidget()->mapFromGlobal(event->globalPosition().toPoint());
        move(parentPos - offset_);
    }
}

void Piece::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging_ = false;
        setCursor(Qt::ArrowCursor);
    }
}

Pawn::Pawn(std::pair<int, int> position, bool isWhite, QWidget* parent) : Piece(position, isWhite, parent) {}

std::vector<std::pair<int, int>> Pawn::calculateMoves() {
	std::vector<std::pair<int, int>> moves;
	return moves;
}