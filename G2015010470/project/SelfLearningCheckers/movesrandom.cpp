#include "movestrategy.h"
using namespace checkers;

MovesRandom::MovesRandom() {

}

void MovesRandom::move(const CheckersData* board) const{
    LegalMoves moves = board->getLegalMoves(BLACK);
    if (moves.size() > 0) {
        int r = rand() % moves.size();
        sendMoveAction(&moves[r]);
        if (moves[r].isJump()) {
            jump(board, moves[r].toRow, moves[r].toCol);
        }
        if (board->getLegalMoves(RED).size() != 0) {
            Event e(ACTION_REVERSE);
            Mediator::getInstance().fireEvent(e);
        } else {
            Event g(NOTIFY_GAMEOVER);
            g.setMessage("You lost!");
            Mediator::getInstance().fireEvent(g);
        }

    } else {
        Event g(NOTIFY_GAMEOVER);
        g.setMessage("You won!");
        Mediator::getInstance().fireEvent(g);
    }
}

void MovesRandom::jump(const CheckersData* board, int fromRow, int fromCol) const {
    LegalMoves moves = board->getLegalJumpsFrom(BLACK, fromRow, fromCol);
    if (moves.size() != 0) {
        int r = rand() % moves.size();
        sendMoveAction(&moves[r]);
        jump(board, moves[r].toRow, moves[r].toCol);
    }
}

void MovesRandom::sendMoveAction(CheckersMove* move) const {
    MoveEvent e(ACTION_MOVE);
    e.setMove(move);
    Mediator::getInstance().fireEvent(e);
}

MovesRandom::~MovesRandom(){

}

