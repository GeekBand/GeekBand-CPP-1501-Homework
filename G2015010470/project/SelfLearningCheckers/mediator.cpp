#include "mediator.h"
#include <utility>
#include "colleague.h"
#include "event.h"
#include <QDebug>

using namespace checkers;

Mediator* Mediator::instance = 0;

Mediator::Mediator() {

}

Mediator& Mediator::getInstance() {
    if (!instance) {
        instance = new Mediator();
    }
    return *instance;
}

void Mediator::attach(const EventName& key, Colleague *colleague) {
    qDebug() << key;
    connection.insert(std::make_pair(key, colleague));
}

void Mediator::detach(const EventName& key, Colleague *colleague) {
    std::pair<Connection::iterator, Connection::iterator> ret;
    ret = connection.equal_range(key);
    Connection::iterator it = ret.first;
    while (it != ret.second) {
        if (it->second == colleague) {
            connection.erase(it);
        }
        it++;
    }
 }

void Mediator::fireEvent(const Event& event){
    std::pair<Connection::iterator, Connection::iterator> ret;
    ret = connection.equal_range(event.getName());
    Connection::iterator it = ret.first;
    while (it != ret.second) {
        it->second->onEvent(event);
        it++;
    }
}
