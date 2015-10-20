#include "event.h"
#include "colleague.h"
#include "checkersdata.h"

using namespace checkers;

Event::Event(EventName name, const Colleague* src,
             const Colleague *des):
    name(name),source(src), dest(des){}

EventName Event::getName() const {
    return name;
}

void Event::setName(EventName name) {
    this->name = name;
}

const Colleague* Event::getSource() const {
    return source;
}

void Event::setSource(const Colleague* source) {
    this->source = source;
}

const Colleague* Event::getDest() const{
    return dest;
}

void Event::setDist(const Colleague* dist) {
    this->dest = dist;
}

std::string Event::getMessage() const {
    return message;
}

void Event::setMessage(std::string msg){
    message = msg;
}

MoveEvent::MoveEvent(EventName name, const Colleague *source,
                     const Colleague *dest):
    Event(name, source, dest){

}

const CheckersMove* MoveEvent::getMove() const {
    return move;
}

void MoveEvent::setMove(const CheckersMove* move) {
    this->move = move;
}
