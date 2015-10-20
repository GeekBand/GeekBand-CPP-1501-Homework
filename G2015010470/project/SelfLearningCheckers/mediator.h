#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include "event.h"

namespace checkers {

    class Mediator
    {
        typedef std::multimap<const EventName, Colleague* > Connection;

    public:
        static Mediator& getInstance();
        void attach(const EventName& name, Colleague *colleague);
        void detach(const EventName& name, Colleague *colleague);
        void fireEvent(const Event& event);
    private:
        Mediator();
        Mediator(Mediator&);
        Connection connection;
        static Mediator* instance;
    };

}

#endif // MEDIATOR_H
