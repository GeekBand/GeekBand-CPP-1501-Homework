#ifndef __SPLITER_H
#define __SPLITER_H

class IProgressObserver {
public:
    virtual onProgress(float progress) = 0;
    virtual ~IProgressObserver() {}
};

#endif
