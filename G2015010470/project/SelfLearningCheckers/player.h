#ifndef PLAYER_H
#define PLAYER_H

#include "colleague.h"
#include "movestrategy.h"

namespace checkers {

    class Player: public Colleague
    {
    public:
        Player(const MoveStrategy* strategy);
        ~Player();
        void onEvent(const Event &event);
    private:
        const Colleague* state;
        const Colleague* data;
        const MoveStrategy* strategy;
    };
}

#endif // PLAYER_H
