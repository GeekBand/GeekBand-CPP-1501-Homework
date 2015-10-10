// The entry point of Question 2

#include "Handlers.h"
#include "Point.h"
#include <memory>

int main()
{
  TextBox box; // a TextBox somewhere
  Point origin(1, 2);

  // define a observable point with origin value
  Observable<Point> op(origin);
  // define and bind the changed-event to std::out destination
  // best practice: should use std::make_shared<>
  std::auto_ptr< Handler<Point> > os_handler(Handlers::accept<Point>(std::cout));
  std::auto_ptr< Handler<Point> > box_handler(Handlers::accept<Point>(box));
  op.bind(os_handler.get());
  op.bind(box_handler.get());

  std::cout << op.getValue() << std::endl;

  Point newValue(1, 3);
  // set a new value to emit changed-event
  op.setValue(newValue);

  std::cout << op.getValue() << std::endl;

  return 0;
}