#include "Pieces.h"
#include <QWidget>
#include <utility>
#include <vector>
#include <QPalette>
#include <QMouseEvent>
#include <QTimer>
#include <algorithm>
#include <QLabel>
#include <QPixmap>

Piece::Piece(std::pair<int, int> position, bool isWhite, QWidget* parent) :
    QWidget(parent), position_(position), isWhite_(isWhite) {
    setFixedSize(70, 70);
    imageLabel_ = new QLabel(this);
};

void Piece::showPieceImage(const QString& imageFile) {
    QPixmap pixmap(imageFile);
    imageLabel_->setPixmap(pixmap.scaled(70, 70, Qt::KeepAspectRatio));
    imageLabel_->setAlignment(Qt::AlignCenter);
}

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

        std::vector<std::pair<int, int>> moves = calculateMoves();
        //std::vector<std::pair<int, int>> moves = { {0, 0}, {1, 1}, {2, 2}, {3, 3} };
        auto it = std::find(moves.begin(), moves.end(), squareUnderCursor);
        if (it != moves.end()) {
            position_ = std::make_pair(row, col);
        }

        emit pieceSet(this, position_);
    }
}

Pawn::Pawn(std::pair<int, int> position, bool isWhite, QWidget* parent) :
    Piece(position, isWhite, parent) {
    QString imageFile = isWhite ? "pieces-basic-png/white-pawn.png" : "pieces-basic-png/black-pawn.png";
    showPieceImage(imageFile);
}

std::vector<std::pair<int, int>> Pawn::calculateMoves() {
	std::vector<std::pair<int, int>> moves;
    moves.push_back(std::make_pair(4, 4));
	return moves;
}

Knight::Knight(std::pair<int, int> position, bool isWhite, QWidget* parent) :
    Piece(position, isWhite, parent) {
    QString imageFile = isWhite ? "pieces-basic-png/white-knight.png" : "pieces-basic-png/black-knight.png";
    showPieceImage(imageFile);
}

std::vector<std::pair<int, int>> Knight::calculateMoves() {
    std::vector<std::pair<int, int>> moves;
    return moves;
}

Bishop::Bishop(std::pair<int, int> position, bool isWhite, QWidget* parent) :
    Piece(position, isWhite, parent) {
    QString imageFile = isWhite ? "pieces-basic-png/white-bishop.png" : "pieces-basic-png/black-bishop.png";
    showPieceImage(imageFile);
}

std::vector<std::pair<int, int>> Bishop::calculateMoves() {
    std::vector<std::pair<int, int>> moves;
    return moves;
}

Rook::Rook(std::pair<int, int> position, bool isWhite, QWidget* parent) :
    Piece(position, isWhite, parent) {
    QString imageFile = isWhite ? "pieces-basic-png/white-rook.png" : "pieces-basic-png/black-rook.png";
    showPieceImage(imageFile);
}

std::vector<std::pair<int, int>> Rook::calculateMoves() {
    std::vector<std::pair<int, int>> moves;
    return moves;
}

Queen::Queen(std::pair<int, int> position, bool isWhite, QWidget* parent) :
    Piece(position, isWhite, parent) {
    QString imageFile = isWhite ? "pieces-basic-png/white-queen.png" : "pieces-basic-png/black-queen.png";
    showPieceImage(imageFile);
}

std::vector<std::pair<int, int>> Queen::calculateMoves() {
    std::vector<std::pair<int, int>> moves;
    return moves;
}

King::King(std::pair<int, int> position, bool isWhite, QWidget* parent) :
    Piece(position, isWhite, parent) {
    QString imageFile = isWhite ? "pieces-basic-png/white-king.png" : "pieces-basic-png/black-king.png";
    showPieceImage(imageFile);
}

std::vector<std::pair<int, int>> King::calculateMoves() {
    std::vector<std::pair<int, int>> moves;
    return moves;
}