#ifndef __WINDWOW_H__
#define __WINDWOW_H__

#include <string>
#include <iostream>

// A dummy base form class
class Form
{
public:
   explicit Form(std::string title) {
    std::cout << "[GUI Window] A form window created and showing - " << title << std::endl;
  }

public:
  virtual ~Form() { 
    std::cout << "[GUI Window] \tdtor" << std::endl;
  }
};

// A dummy text box class
class TextBox
{
public:
  std::string text() const { return "/tmp/bigfile.data"; }
  int number() const { return 10; }

public:
  virtual ~TextBox() { }
};

// A dummy progress bar class
class ProgressBar
{
public:
  void set(int size, int totalSize) { 
    std::cout << "[GUI Bar] \t" << (float)size/totalSize*100 << " %" << std::endl;
  }

public:
  virtual ~ProgressBar() { }
};

#endif // __WINDWOW_H__