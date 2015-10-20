#ifndef COLLEAGUE_H
#define COLLEAGUE_H
#include "mediator.h"

namespace checkers {

    class Colleague
    {
    public:
        Colleague();
        void fireEvent(const Event& event);
        virtual void onEvent(const Event& event) = 0;
        virtual ~Colleague();
    };
}
#endif // COLLEAGUE_H
