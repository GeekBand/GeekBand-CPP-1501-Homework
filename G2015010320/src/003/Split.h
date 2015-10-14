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
  const int totalSize_;
  Split(const std::string &filePath, int totalSize) : 
    filePath_(filePath), totalSize_(totalSize) { 
      assert (totalSize_ > 0);
    }

public:
  virtual ~Split() { std::cout << "[Split] \tdtor" << std::endl; }

public:
  std::string getFile() const {
    return filePath_;
  }
  
  int size() const {
    return totalSize_;
  }

  virtual void split() = 0;
};

// abstract the obserable split interface
class ObservableSplit : public Split, public Observable
{
protected:
  ObservableSplit(const std::string &filePath, int totalSize) : 
    Split(filePath, totalSize) { }
};

// a split implementation with observale utility
class OneSplit : public ObservableSplit
{
public:
  OneSplit(const std::string &filePath, int totalSize) : 
    ObservableSplit(filePath, totalSize) { 
    std::cout << "[Split] " << "\tcreated \tOne" << std::endl;
  }

  void split() {
    const int totalSize = this->size();
    std::cout << "[Split] " << "\tjob start with totalSize " << totalSize << std::endl;
    for (int step = 0; step < totalSize; ++step) {
      // one dummy split operation
      std::cout << "[Split] " << "\tjob done \t" << step+1 << std::endl;
      notifyAll(step+1, totalSize);
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
  static ObservableSplit * create(TheSpliter s, const std::string& filePath, int totalSize) {
    switch (s) {
      case One:
        return new OneSplit(filePath, totalSize);
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
    assert (bar_ != NULL && split_ != NULL);
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
    
    // after complete, remove this.
    split_->remove(this);
  }

  void report(int size, int totalSize) {
    // in real env, you should invoke this update action 
    // to GUI thread.
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