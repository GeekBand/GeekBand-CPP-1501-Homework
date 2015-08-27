#pragma once
class MainForm : public Form {
	TextBox *txtFilePath;
	TextBox *txtFileNumber;
	ProgressBar *progressBar;
	friend class FileSplitter;

	void UpdateProgressBar(int Number) { progressBar->value = Number; }
public:
	void Button_Click1() {

	}


};