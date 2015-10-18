
#include "colleague.h"
#include "mediator.h"
#include "event.h"

using namespace checkers;

Colleague::Colleague(){
}

void Colleague::fireEvent(const Event& event) {
    Mediator::getInstance().fireEvent(event);
}

Colleague::~Colleague() {
}

