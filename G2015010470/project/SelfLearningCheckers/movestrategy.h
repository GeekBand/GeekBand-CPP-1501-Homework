#ifndef MOVESTRATEGY_H
#define MOVESTRATEGY_H

#include "checkersdata.h"
#include "checkersstate.h"

namespace checkers {
    class MoveStrategy
    {
    public:
        MoveStrategy() {}
        virtual void move(const CheckersData* board) const = 0;
        virtual ~MoveStrategy() {}
    private:
        const CheckersData *board;
        const CheckersState *state;
    };

    class MovesRandom: public MoveStrategy
    {
    public:
        MovesRandom();
        void move(const CheckersData *board) const;
        ~MovesRandom();
    private:
        void sendMoveAction(CheckersMove* move) const;
        void jump(const CheckersData* board, int fromRow, int fromCol) const;
    };
}

#endif // MOVESTRATEGY_H
