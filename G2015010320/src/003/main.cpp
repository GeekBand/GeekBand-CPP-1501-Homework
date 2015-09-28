// The main entry of overall test program

#include "Window.h"
#include "Split.h"
#include <memory>

class MainForm : public Form
{
private:
  TextBox fileInput_;
  ProgressBar indicator_;
  
public:
  explicit MainForm(std::string title) : Form(title) { }

public:
  void SplitBtnClicked() {
    std::auto_ptr<SplitHandler> holder(Handlers::of(&indicator_, Splits::create(One, fileInput_.text())));
  	holder->start();
  }
};

int main() {
  MainForm window("Split running");
  // emulate the click call
  window.SplitBtnClicked();
  return 0;
}