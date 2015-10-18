#ifndef MAINFORM_H
#define MAINFORM_H

#include "observer.h"
#include <string>

class MainForm: public ProgressListener
{
public:
    MainForm();
    void onProgress(float progress);
    void buttonClick();
    ~MainForm();
private:
    ProgressBar* progressBar;
    SplitAlgorithm* splitAlgorithm;
    FileSpliter* fileSpliter;
    std::string filePath;
    int fileNumber;
};

#endif // MAINFORM_H
