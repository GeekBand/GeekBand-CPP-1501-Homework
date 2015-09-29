#ifndef __SPLIT_H__
#define __SPLIT_H__

#include <iostream>
#include <string>
#include <cassert>
#include "Observable.h"

// to enum all kinds of spliter
enum TheSpliter
{
  One, Two, Three
};

// the definition of split interface
class Split
{
protected:
  std::string filePath_;
  Split(const std::string &filePath) : filePath_(filePath) { }

public:
  virtual ~Split() { std::cout << "[Split] \tdtor" << std::endl; }
public:
  std::string getFile() const {
    return filePath_;
  }

  virtual void split() = 0;
};

// abstract the obserable split interface
class ObservableSplit : public Split, public Observable
{
protected:
  ObservableSplit(const std::string &filePath) : Split(filePath) { }
};

// a split implementation with observale utility
class OneSplit : public ObservableSplit
{
public:
  OneSplit(const std::string &filePath) : ObservableSplit(filePath) { 
    std::cout << "[Split] " << "\tcreated \tOne" << std::endl;
  }
  void split() {
    // `10` is a magic number, just for simpfy the demostration.
    std::cout << "[Split] " << "\tjob start with totalSize " << 10 << std::endl;
    for (int step = 0; step < 10; ++step) {
      // one dummy split operation
      std::cout << "[Split] " << "\tjob done \t" << step+1 << std::endl;
      notifyAll(step+1, 10);
    }
  }
};

// TODO: you can implement the others,
// such as TowSplit, ThreeSplit ...

// a simple factory class to create 
// the specific spliter
class Splits
{
private:
  explicit Splits() { }

public:
  static ObservableSplit * create(TheSpliter s, const std::string& filePath) {
    switch (s) {
      case One:
        return new OneSplit(filePath);
      default:
        return NULL;
    }
  }
};

// bridge/delegate the progess issue to a handler
class SplitHandler : public ProgressIndicator
{
public:
  virtual void start() = 0;
  std::string name() const {
    return "split-handler";
  }

public:
  virtual ~SplitHandler() {}
};

// one synchronize impl of split handler
// note: this class will hand over the life of split
class SyncSplitHanler : public SplitHandler
{
private:
  ProgressBar * const bar_;
  ObservableSplit * const split_;

public:
  explicit SyncSplitHanler(ProgressBar *bar, ObservableSplit *split) :
    bar_(bar), split_(split)
  {
    assert (bar != NULL && split != NULL);
    // it's not good practice, since `this` escaped from ctor.
    // we have moved this regist action to start function
    // split_->regist(this); 
    std::cout << "[Handler] " << "\tcreated \t"  << this->name() << std::endl;
  }

  virtual ~SyncSplitHanler() {
    delete split_;
    std::cout << "[Handler] " << "\tdtor"  << std::endl;
  }

  void start() {
    // before starting to split, regist this.
    split_->regist(this);

    std::cout << "[Handler] " << "\tstart split \t" << split_->getFile() << std::endl;
  	split_->split();
    
    // after completed, remove this.
    split_->remove(this);
  }

  void report(int size, int totalSize) {
    bar_->set(size, totalSize);
  }
};

// a simple factory class to create 
// the default split progress handler
class Handlers
{
private:
  explicit Handlers() { }

public:
  static SplitHandler * of(ProgressBar *bar, ObservableSplit *split) {
    return new SyncSplitHanler(bar, split);
  }
};

#endif // __SPLIT_H__