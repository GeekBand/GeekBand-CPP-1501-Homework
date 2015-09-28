#ifndef __WINDWOW_H__
#define __WINDWOW_H__

#include <string>
#include <iostream>

// A dummy base form class,
// just let compiler happy.
class Form
{
public:
   explicit Form(std::string title) {
    std::cout << "[GUI Window] A form window created and showing - " << title << std::endl;
  }
protected:
  virtual ~Form() { }
};

// A dummy text box class,
// just let compiler happy.
class TextBox
{
public:
  std::string text() const { return "/tmp/bigfile.data"; }
};

// A dummy progress bar class,
// just let compiler happy.
class ProgressBar
{
public:
  void set(int size, int totalSize) { 
    std::cout << "[GUI Bar] " << (float)size/totalSize*100 << " %" << std::endl;
  }
};

#endif // __WINDWOW_H__