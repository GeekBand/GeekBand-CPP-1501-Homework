#include "mainform.h"

MainForm::MainForm(){
    bar = new ProgressBar();
}

void MainForm::onProgress(float progress) {
    bar.setProgress(progress);
}

void MainForm::buttonClick(int algNum) {

    switch (algNum) {
    case 1:
        splitAlgorithm = new SplitAlorithm1();
        break;
    case 2:
        splitAlgorithm = new SplitAlorithm2();
        break;
    case 3:
        splitAlgorithm = new SplitAlorithm3();
        break;
    }

    fileSpliter = new fileSpliter(
                filePath, fileNumber, splitAlgorithm);
    fileSpliter->addObserver(this);
    fileSpliter->split();
}

MainForm::~MainForm() {
    fileSpliter->removeObserver(this);
    delete fileSpliter;
    delete splitAlgorithm;
    delete progressBar;
}

