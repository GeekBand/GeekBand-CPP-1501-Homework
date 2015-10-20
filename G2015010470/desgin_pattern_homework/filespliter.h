#ifndef FILESPLITER_H
#define FILESPLITER_H

class FileSpliter {

public:
   FileSpliter(std::stirng, int, const ISplitAlgorithm*);
   void removeObserver(const IProgressObserver*);
   void addObserver(const IProgressObserver*);
   void split();
   void notify(float progress);
private:
   std::string filePath;
   int fileNumber;
   ISplitAlgorithm* algorithm;
   std::vector<IProgressObserver*> observerList;
}



#endif // FILESPLITER_H

