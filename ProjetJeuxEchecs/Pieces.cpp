#include "Pieces.h"
#include <QWidget>
#include <utility>
#include <vector>
#include <QPalette>
#include <QMouseEvent>
#include <QTimer>
#include <algorithm>

Piece::Piece(std::pair<int, int> position, bool isWhite, QWidget* parent) :
    QWidget(parent), position_(position), isWhite_(isWhite) {
	this->setFixedSize(50, 50);
	QPalette pal = this->palette();
	pal.setColor(QPalette::Window, QColor(255, 0, 0));
	this->setAutoFillBackground(true);
	this->setPalette(pal);
};

void Piece::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        offset_ = event->pos();
        isDragging_ = true;
        setCursor(Qt::ClosedHandCursor);

        QPoint globalPos = mapToGlobal(pos());
        QWidget* newParent = parentWidget()->parentWidget();
        setParent(newParent);
        move(mapFromGlobal(globalPos));
        show();

        grabMouse();

        emit pieceRemove(this);
    }
}

void Piece::mouseMoveEvent(QMouseEvent* event) {
    if (isDragging_) {
        QPoint parentPos = parentWidget()->mapFromGlobal(event->globalPosition().toPoint());
        move(parentPos - offset_);
    }
}

void Piece::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDragging_ = false;
        setCursor(Qt::ArrowCursor);

        releaseMouse();

        QPoint globalPos = event->globalPosition().toPoint();
        QPoint relativePos = parentWidget()->mapFromGlobal(globalPos);
        int row = std::clamp(relativePos.y() / 75, 0, 7);
        int col = std::clamp(relativePos.x() / 75, 0, 7);
        std::pair<int, int> squareUnderCursor = std::make_pair(row, col);

        //moves = calculateMoves();
        std::vector<std::pair<int, int>> moves = { {0, 0}, {1, 1}, {2, 2}, {3, 3} };
        auto it = std::find(moves.begin(), moves.end(), squareUnderCursor);
        if (it != moves.end()) {
            position_ = std::make_pair(row, col);
        }

        emit pieceSet(this, position_);
    }
}

Pawn::Pawn(std::pair<int, int> position, bool isWhite, QWidget* parent) :
    Piece(position, isWhite, parent) {}

std::vector<std::pair<int, int>> Pawn::calculateMoves() {
	std::vector<std::pair<int, int>> moves;
	return moves;
}