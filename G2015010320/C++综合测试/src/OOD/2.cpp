// The entry point of Question 2

#include "Handlers.h"
#include "Point.h"
#include <memory>

int main()
{
  TextBox box; // a TextBox somewhere
  Point origin(1, 2);

  // define a observable model(point) with origin value(1, 2)
  Observable<Point> op(origin);
  // define and bind an observer handler to above observable model(point)
  std::auto_ptr< Handler<Point> > console_h(Handlers::of<Point>(std::cout));
  std::auto_ptr< Handler<Point> > box_h(Handlers::of<Point>(box));
  Binder::bind(*console_h.get(), op);
  Binder::bind(*box_h.get(), op);

  // print the origin value(1, 2)
  std::cout << op.getValue() << std::endl;

  Point newValue(1, 3);
  // set a new value(1, 3) to emit changed-event
  op.setValue(newValue);

  // print the new value(1, 3)
  std::cout << op.getValue() << std::endl;

  return 0;
}