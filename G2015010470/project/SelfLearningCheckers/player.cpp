#include "movestrategy.h"
#include "player.h"
#include "checkersdata.h"
#include "checkersstate.h"

using namespace checkers;

Player::Player(const MoveStrategy* strategy):strategy(strategy) {
    Mediator::getInstance().attach(NOTIFY_STATE, this);
    Mediator::getInstance().attach(NOTIFY_BOARD, this);
}

Player::~Player() {
    Mediator::getInstance().detach(NOTIFY_STATE, this);
    Mediator::getInstance().detach(NOTIFY_BOARD, this);
}

void Player::onEvent(const Event &event) {
    if (event.getName() == NOTIFY_BOARD) {
        data = event.getSource();
    } else if (event.getName() == NOTIFY_STATE) {
        state = event.getSource();
        if (data != 0) {
            const CheckersData* board = (const CheckersData*)data;
            const CheckersState* gameState = (const CheckersState*)state;
            if (gameState->getChessState() == INPROGRESS &&
                    gameState->getCurrentPlayer() == BLACK) {
                strategy->move(board);
            }
        }
    }
}
