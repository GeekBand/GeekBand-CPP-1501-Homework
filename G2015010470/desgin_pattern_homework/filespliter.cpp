#include "observer.h"
#include "filespliter.h"
#include "algorithm"

FileSpliter::FileSpliter(std::stirng path, int number, const ISplitAlgorithm* alg):
    filePath(path), fileNumber(number), algorithm(alg) {

}

void FileSpliter::addObserver(const IProgressObserver *observer) {
    observerList.push_back(observer);
}

void FileSpliter::removeObserver(const IProgressObserver *observer) {
    observerList::iterator it;
    it = std::find(observerList.begin(), observerList.end(), observer);
    if (it != observerList.end()) {
        observerList.erase(it);
    }
}

void FileSpliter::notify(float progress) {
    for (unsigned int i = 0; i < observerList.size(); i++) {
        observerList[i].onProgress(progress);
    }
}

void FileSpliter::split() {
    algorithm->split(this);
}
