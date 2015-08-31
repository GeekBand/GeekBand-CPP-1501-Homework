#pragma once
#include "Splitters.h"
class MainForm : public Form {
	TextBox *txtFilePath;
	TextBox *txtFileNumber;
	ProgressBar *progressBar;

	void UpdateProgressBar(int Number) { progressBar->value = Number; }
public:
	void Button_Click1() {
		

		//switch case video:
		FileSplitter* spliiter = new VideoFileSplitter(txtFilePath->text, txtFileNumber->text, &UpdateProgressBar);
		spliiter->Split();
		

	}


};