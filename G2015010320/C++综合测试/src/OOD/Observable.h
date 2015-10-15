// It defines and provides the observer capacity
#ifndef __OBSERVABLE_H__
#define __OBSERVABLE_H__

#include <list>
#include <algorithm>
#include <string>
#include <cassert>
#include <iostream>

// define a value changed destination.
// you can implement the specified value changed destination,
// and bind to an obserable model through a handler.
// e.g. TextBoxValueChanged, ConsoleValueChanged
template<class T>
class ValueChanged
{
public:
  virtual void changed(const T &newValue) = 0;
  virtual std::string name() const = 0;

public:
  virtual ~ValueChanged() { }
};

// dispatch value-changed event to a destination
// type T : the value type
// note: it will hand over the life of destination object
template<typename T>
class Handler
{
private:
  ValueChanged<T> *dest_; // value changed destination
public:
  explicit Handler(ValueChanged<T> *dest) : dest_(dest) { }
  virtual ~Handler() { 
    std::cout << "[Handler] \t" << dest_->name() << "\tdtor" << std::endl;
    delete dest_;
  }
public:
  // report the value changed event to destination
  void report(const T &newValue) {
    dest_->changed(newValue);
  }

  std::string name() const {
    return dest_->name();
  }
};

// observable utility class, it provides the bind and unbind 
// functions, this implementation is not thread-safed.
template<typename T>
class Observable
{
private:
  // wrapper/cache the value to enhance the notify capacity
  T value_;

  // It's not good practice for keeping raw pointer.
  // list<weak_ptr<Handler<T>>> would be perferred.
  std::list<Handler<T> *> obsevers;

  void notifyChanged(const T &newValue) {
    // for thread safe, should synchronized copy the overall vector, 
    // then iterates the copied one.
    for (typename std::list<Handler<T> *>::iterator it = std::begin(obsevers); 
      it != std::end(obsevers); ++it) {
        (*it)->report(newValue);
    }
  }

public:
  explicit Observable(T & value) : value_(value) { }
  virtual ~Observable() { std::cout << "[Observable] \tdtor" << std::endl; }

public:
  // delegate set value function, 
  // for the obserable capacity
  // The value type should overload operator != and assign ctor
  void setValue(const T &newValue) {
    if (value_ != newValue) {
      value_ = newValue;
      notifyChanged(newValue);
    }
  }
  
  T getValue() const {
    return value_;
  }

public:
  void bind(Handler<T> *h) {
    // for thread safe, should synchronize this.
    std::cout << "[Observable] " << "\tbind \t"  << h->name() << std::endl;
    obsevers.push_back(h);
  }

  void unbind(Handler<T> *h) {
    // for thread safe, should synchronize this.
    const typename std::list<Handler<T> *>::iterator position = 
      std::find(obsevers.begin(), obsevers.end(), h);
    if (position != obsevers.end()) {
      std::cout << "[Observable] " << "\tunbind \t" << h->name() << std::endl;
      obsevers.erase(position);
    }
  }
};

// provides a bind and unbind static method for
// binding an observer handler to an observable model
class Binder
{
public:
  template<typename T>
  static void bind(Handler<T> &hd, Observable<T> &ob) {
    ob.bind(&hd);
  }

  template<typename T>
  static void unbind(Handler<T> &hd, Observable<T> &ob) {
    ob.unbind(&hd);
  }

private:
  Binder() { }
  ~Binder() { }
};

#endif // __OBSERVABLE_H__