#pragma once
#include <string>	
#include <vector>
#include "FileSplitter.h"
using namespace std;

class MainForm;
class FileSplitter {
	string filePath;
	int fileNumber;

	void (*Update)(int);
protected:
	void NotificationUpdate(int processValue) {
		if (Update != nullptr) {
			Update(processValue);
		}
	}
public:
	FileSplitter(string& _filepath, int _filenumber, void(*updateFun)(int)) :
		filePath(_filepath), fileNumber(_filenumber), Update(updateFun) {}

public:
	virtual void Split() = 0;
	virtual ~FileSplitter(){}
};