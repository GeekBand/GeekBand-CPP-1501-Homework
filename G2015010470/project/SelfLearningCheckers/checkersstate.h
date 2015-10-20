#ifndef CHECKERSSTATE_H
#define CHECKERSSTATE_H
#include "colleague.h"

namespace checkers {

    enum ChessState {
        INPROGRESS,
        GAMEOVER
    };

    class CheckersState: public Colleague
    {
    public:
        CheckersState(ChessState state = GAMEOVER, Square curPlayer = RED);
        void setChessState(ChessState state);
        void setCurrentPlayer(Square curPlayer);
        ChessState getChessState() const;
        Square getCurrentPlayer() const;
        void doSetup();
        void doNewGame();
        void gameOver();
        void changePlayer();
        virtual void onEvent(const Event& event);
        ~CheckersState();
    private:
        ChessState state;
        Square curPlayer;
    };
}

#endif // CHECKERSSTATE_H
