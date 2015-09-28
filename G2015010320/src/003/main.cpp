// The main entry of overall test program

#include "Window.h"
#include "Split.h"

class MainForm : public Form
{
private:
  TextBox fileInput_;
  ProgressBar indicator_;
  
public:
  explicit MainForm(std::string title) : Form(title) { }

public:
  void SplitBtnClicked() {
  	SycnSplitHanler spliter(
      &indicator_, Splits::create(One, fileInput_.text()));
  	spliter.start();
  }
};

int main() {
  MainForm window("Split running");
  // emulate the click call
  window.SplitBtnClicked();
  return 0;
}