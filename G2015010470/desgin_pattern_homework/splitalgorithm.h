#ifndef SPLITALGORITHM
#define SPLITALGORITHM

class ISplitAlgorithm {
public:
   virtual split(FileSpliter* spliter) = 0;
   virtual ~SplitAlgorithm(){}
};


class SplitAlgorithm1: public ISplitAlgorithm {
public:
   virtual split(FileSpliter* spliter) {
      //algorithm1 details
      //calculate progress
      spliter->notify(progress);
   }
};

class SplitAlgorithm2: public ISplitAlgorithm {
public:
   virtual split(FileSpliter* spliter) {
      //algorithm2 details
      //calculate progress
      spliter->notify(progress);
   }
};

class SplitAlgorithm3: public ISplitAlgorithm {
public:
    virtual split(FileSpliter* spliter) {
       //algorithm3 details
       //calculate progress
       spliter->notify(progress);
    }
};


#endif // SPLITALGORITHM

