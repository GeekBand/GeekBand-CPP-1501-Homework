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
  virtual ~Split() { }
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
  OneSplit(const std::string &filePath) : ObservableSplit(filePath) { }
  void split() {
    for (int step = 0; step < 10; ++step) {
      // one dummy split operation
      std::cout << "[Split] " << "make job " << step+1 << std::endl;
      notifyAll(step+1, 10);
    }
  }
};

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
class SplitHandler
{
  virtual void start() = 0;
};

// one synchronize impl of split handler
// note: this class will hand over the life of split
class SycnSplitHanler : public ProgressIndicator
{
private:
  ProgressBar * const bar_;
  ObservableSplit * const split_;

public:
  explicit SycnSplitHanler(ProgressBar *bar, ObservableSplit *split) :
    bar_(bar), split_(split)
  {
    assert (bar != NULL && split != NULL);
    split_->regist(this);
    std::cout << "[Handler] " << "created" << std::endl;
  }
  
  virtual ~SycnSplitHanler() {
    delete split_;
  }

  void start() {
    std::cout << "[Handler] " << "start split \t" << split_->getFile() << std::endl;
  	split_->split();
  }

  void report(int size, int totalSize) {
    bar_->set(size, totalSize);
  }
};


#endif // __SPLIT_H__