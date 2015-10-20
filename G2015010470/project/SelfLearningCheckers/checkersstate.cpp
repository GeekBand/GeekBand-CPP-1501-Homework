#include "checkersstate.h"
using namespace checkers;

CheckersState::CheckersState(ChessState state,
                             Square curPlayer):
    state(state), curPlayer(curPlayer){
     Mediator::getInstance().attach(ACTION_NEWGAME, this);
     Mediator::getInstance().attach(ACTION_SETUP, this);
     Mediator::getInstance().attach(ACTION_REVERSE, this);
     Mediator::getInstance().attach(NOTIFY_GAMEOVER, this);
}

CheckersState::~CheckersState() {
    Mediator::getInstance().detach(ACTION_NEWGAME, this);
    Mediator::getInstance().detach(ACTION_SETUP, this);
    Mediator::getInstance().detach(ACTION_REVERSE, this);
    Mediator::getInstance().detach(NOTIFY_GAMEOVER, this);
}

ChessState CheckersState::getChessState() const {
    return state;
}

void CheckersState::setChessState(ChessState state) {
    this->state = state;
}

Square CheckersState::getCurrentPlayer() const {
    return curPlayer;
}

void CheckersState::setCurrentPlayer(Square curPlayer) {
    this->curPlayer = curPlayer;
}

void CheckersState::doSetup() {
    this->state = GAMEOVER;
}

void CheckersState::doNewGame() {
    this->state = INPROGRESS;
    this->curPlayer = RED;
}

void CheckersState::gameOver() {
    this->state = GAMEOVER;
}

void CheckersState::changePlayer() {
    if (curPlayer == RED) {
        curPlayer = BLACK;
    } else {
        curPlayer = RED;
    }
}

void CheckersState::onEvent(const Event& event) {
    if (event.getName() == ACTION_SETUP) {
        doSetup();
        Event e(NOTIFY_STATE);
        e.setSource(this);
        this->fireEvent(e);
    } else if (event.getName() == ACTION_NEWGAME) {
        doNewGame();
        Event e(NOTIFY_STATE);
        e.setSource(this);
        this->fireEvent(e);
    } else if (event.getName() == ACTION_REVERSE) {
        changePlayer();
        Event e(NOTIFY_STATE);
        e.setSource(this);
        this->fireEvent(e);
    } else if (event.getName() == NOTIFY_GAMEOVER) {
        gameOver();
        Event e(NOTIFY_STATE);
        e.setSource(this);
        this->fireEvent(e);
    }
}

