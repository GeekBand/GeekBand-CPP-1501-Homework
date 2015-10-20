#include "checkersdata.h"
#include "checkersstate.h"
#include "chessboard.h"
#include "event.h"
#include "window.h"
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
using namespace checkers;

ChessBoard::ChessBoard(QWidget *parent)
    : QWidget(parent), state(0), data(0) {

    setMouseTracking(true);
    Mediator::getInstance().attach(NOTIFY_STATE, this);
    Mediator::getInstance().attach(NOTIFY_BOARD, this);
}

ChessBoard::~ChessBoard() {
    Mediator::getInstance().detach(NOTIFY_STATE, this);
    Mediator::getInstance().detach(NOTIFY_BOARD, this);
}

QSize ChessBoard::minimumSizeHint() const {
    return QSize(320+4, 320+4);
}

QSize ChessBoard::sizeHint() const {
    return QSize(320+4, 320+4);
}

QRect ChessBoard::getSquareArea(int row, int col) const {
    int uw = (width() - 2) / 8;
    int uh = (height() - 2) / 8;
    return QRect(2 + col * uw, 2 + row * uh, uw, uh);
}

QRect ChessBoard::getChessArea(int row, int col) const {
    int uw = (width() - 2) / 8;
    int uh = (height() - 2) / 8;
    return QRect(4 + col * uw, 4 + row * uh, uw - 4, uh - 4);
}

QPoint ChessBoard::getRowCol(int x, int y) const{
    int uw = (width() - 2) / 8;
    int uh = (height() - 2) / 8;
    return QPoint((x-2)/uw, (y-2)/uh);
}

void ChessBoard::sendMessage(std::string msg) {
    Event e(NOTIFY_MESSAGE);
    e.setMessage(msg);
    this->fireEvent(e);
}

void ChessBoard::mousePressEvent(QMouseEvent* event) {
    if(state != 0) {
        CheckersState* s = (CheckersState*)state;
        if (s->getChessState() != INPROGRESS) {
            sendMessage("Click \"New Game\" to start a new game.");
        } else {
            QPoint point = getRowCol(event->pos().x(), event->pos().y());
            doClickSquare(point.ry(), point.rx());
        }
    }
}

const CheckersData* ChessBoard::getCheckersData() {
    if (data == 0)
        return 0;

    return (CheckersData*)data;
}

const CheckersState* ChessBoard::getCheckersState() {
    if (state == 0)
        return 0;

    return (CheckersState*)state;
}

void ChessBoard::doClickSquare(int row, int col) {

    const CheckersData* board = getCheckersData();
    const CheckersState* gameState = getCheckersState();
    if (board == 0 || gameState == 0)
        return ;
    Square currPlayer = gameState->getCurrentPlayer();
    LegalMoves moves = board->getLegalMoves(currPlayer);
    for (unsigned int i = 0; i < moves.size(); ++i) {
        if (moves[i].fromRow == row && moves[i].fromCol == col) {
            selectedRow = row;
            selectedCol = col;
            if (currPlayer == RED) {
                sendMessage("Make your move.");
            } else {
                sendMessage("The Mechine is thinking.");
            }
            repaint();
            return;
        }
    }

    //If a piece is selected.
    if (selectedRow < 0 && gameState->getChessState() == INPROGRESS) {
        sendMessage("Click the piece you want to move.");
        return;
    }

    //selected a piece and move
    for (unsigned int i = 0; i < moves.size(); i++) {
        if (moves[i].fromRow == selectedRow && moves[i].fromCol == selectedCol
                && moves[i].toRow == row && moves[i].toCol == col) {
            doMakeMove(&moves[i]);
            return;
        }
    }

    sendMessage("Click the square you want to move to");
}

void ChessBoard::doMakeMove(const CheckersMove* move) {

    MoveEvent e(ACTION_MOVE, this);
    e.setMove(move);
    this->fireEvent(e);

    const CheckersData* board = getCheckersData();
    const CheckersState* gameState = getCheckersState();
    if (board == 0 || gameState == 0)
        return ;

    //if the move was a jump, check another jump
    if (move->isJump()) {
        Square currPlayer = gameState->getCurrentPlayer();
        LegalMoves moves = board->getLegalJumpsFrom(
                    currPlayer,move->toRow,move->toCol);
        if (moves.size() != 0) {
            sendMessage("You must continue jumping.");
            selectedRow = move->toRow;
            selectedCol = move->toCol;
            repaint();
            return;
        }
    }

    selectedRow = -1;

    Event reverseEvent(ACTION_REVERSE);
    this->fireEvent(reverseEvent);
}

void ChessBoard::paintEvent(QPaintEvent * /* event */)
{
    QPainter g(this);

    if (data == 0 || state == 0) return;

    const CheckersData* board = (CheckersData*)data;
    const CheckersState* gameState = (CheckersState*)state;

    //draw border
    g.setPen(Qt::black);
    g.drawRect(QRect(0, 0, width() - 1, height() - 1));
    g.drawRect(QRect(1, 1, width() - 3, height() - 3));

    //draw square
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (row % 2 == col % 2)
                g.fillRect(getSquareArea(row, col), Qt::lightGray);
            else
                g.fillRect(getSquareArea(row, col), Qt::gray);
            switch (board->pieceAt(row, col)) {
                case RED:
                    g.setPen(Qt::red);
                    g.setBrush(Qt::red);
                    g.drawEllipse(getChessArea(row, col));
                    break;
                case BLACK:
                    g.setPen(Qt::black);
                    g.setBrush(Qt::black);
                    g.drawEllipse(getChessArea(row, col));
                    break;
                case RED_KING:
                    g.setPen(Qt::red);
                    g.setBrush(Qt::red);
                    g.drawEllipse(getChessArea(row, col));
                    g.setPen(Qt::white);
                    g.drawText(getChessArea(row, col), Qt::AlignCenter, "K");
                    break;
                case BLACK_KING:
                    g.setPen(Qt::black);
                    g.setBrush(Qt::black);
                    g.drawEllipse(getChessArea(row, col));
                    g.setPen(Qt::white);
                    g.drawText(getChessArea(row, col), Qt::AlignCenter, "K");
                    break;
                case EMPTY:
                    break;
            }
        }
    }

    // high light
    Square currPlayer = gameState->getCurrentPlayer();
    if (gameState->getChessState() == INPROGRESS) {
        LegalMoves moves = board->getLegalMoves(currPlayer);
        for (unsigned int i = 0; i < moves.size(); ++i) {
            int row = moves[i].fromRow;
            int col = moves[i].fromCol;
            g.setPen(QPen(Qt::cyan, 2));
            g.setBrush(Qt::NoBrush);
            g.drawRect(getSquareArea(row, col));
        }

        // if a pice is selected to move
        if (selectedRow >= 0) {
            g.setPen(QPen(Qt::white, 2));
            g.drawRect(getSquareArea(selectedRow, selectedCol));
            g.setPen(QPen(Qt::green, 2));
            for (unsigned int i = 0; i < moves.size(); ++i) {
                if (moves[i].fromRow == selectedRow && moves[i].fromCol == selectedCol) {
                    g.drawRect(getSquareArea(moves[i].toRow, moves[i].toCol));
                }
            }
        }

    }
}

void ChessBoard::onEvent(const Event& event){
    if (event.getName() == NOTIFY_BOARD) {
        data = event.getSource();
    } else if (event.getName() == NOTIFY_STATE) {
        state = event.getSource();
    }
    repaint();
}
