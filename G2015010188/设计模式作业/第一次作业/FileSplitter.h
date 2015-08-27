#pragma once
#include <string>	
#include <vector>
#include "FileSplitter.h"
using namespace std;

class MainForm;
class FileSplitter {
	string filePath;
	int fileNumber;

	//½ø¶È
	int processValue;

	MainForm *form;
protected:
	void setProcessValue(int value) {
		processValue = value;
	}
	void NotificationUpdate() {
		if (form != nullptr) {
			form->UpdateProgressBar(processValue);
		}
	}

public:
	virtual void Split() = 0;
	virtual ~FileSplitter(){}
};