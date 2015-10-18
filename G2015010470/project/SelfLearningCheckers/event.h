#ifndef EVENT
#define EVENT
#include "enum.h"
#include <string>

namespace checkers {

    class CheckersMove;
    class Colleague;

    class Event {
    public:
        Event(EventName name,const Colleague* source = 0,
              const Colleague* dest = 0);
        EventName getName() const;
        void setName(EventName name);
        const Colleague* getSource() const;
        void setSource(const Colleague* source);
        const Colleague* getDest() const;
        void setDist(const Colleague* dest);
        std::string getMessage() const;
        void setMessage(std::string msg);

    protected:
        EventName name;
        const Colleague * source;
        const Colleague * dest;
        std::string message;
    };

    class MoveEvent: public Event {
    public:
        MoveEvent(EventName name, const Colleague *source = 0,
              const Colleague *dest = 0);
        void setMove(const CheckersMove* move);
        const CheckersMove* getMove() const;
    private:
        const CheckersMove* move;
    };
}

#endif // EVENT

