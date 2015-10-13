// define kinds of value changed destination
// and a simple handler facotry
#ifndef __HANDLERS_H__
#define __HANDLERS_H__

#include "Observable.h"
#include <iostream>

template<typename T>
class OStreamValueChanged : public ValueChanged<T>
{
private:
  std::ostream &os_;
public:
  explicit OStreamValueChanged(std::ostream &os) : os_(os) { }

public:
  void changed(const T &newValue) {
    os_ << "[OStream] \tvalue-changed to\t" << newValue << std::endl;
  }

  std::string name() const {
    return "OStream";
  }
};

class TextBox { 
  void setText(const std::string &txt) { }
};

template<typename T>
class TextBoxValueChanged : public ValueChanged<T>
{
private:
  TextBox &box_;
public:
  explicit TextBoxValueChanged(TextBox &box) : box_(box) { }

public:
  void changed(const T &newValue) {
    std::cout << "[TextBox] \tvalue-changed to\t" << newValue << std::endl;
  }

  std::string name() const {
    return "TextBox";
  }
};

// create a handler of value-changed destination
class Handlers
{
public:
  template<typename T>
  static Handler<T> *of(std::ostream &os) {
    return new Handler<T>(new OStreamValueChanged<T>(os));
  }

  template<typename T>
  static Handler<T> *of(TextBox &box) {
    return new Handler<T>(new TextBoxValueChanged<T>(box));
  }

  // TODO: overload different kinds of facotry methods of destinations
private:
  Handlers() { }
  ~Handlers() { }
};

#endif // __HANDLERS_H__