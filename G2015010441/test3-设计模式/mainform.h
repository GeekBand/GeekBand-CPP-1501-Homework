#ifndef _MAINFORM_H
#define _MAINFORM_H

class MainForm
{
public:
	MainForm(FileSplitter* spliter){
		fileSplitter = spliter;
	}
	~MainForm();
	
	void Button1_Click(){
		fileSplitter->SetFilePath(txtFilePath->GetFilePath());
		fileSplitter->SetFileNumber(txtFileNumber->GetFileNumber());
		fileSplitter->SetProgressBar(progressBar);
		fileSplitter->Split();
	}

private:
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	ProgressBar* progressBar;
	FileSplitter* fileSplitter;
};

class FileSplitter
{
public:
	FileSplitter();
	virtual ~FileSplitter();
	
	virtual void Split() = 0;
	
	void SetFilePath(string& filepath){
		filePath = filepath;
	}
	void SetFileNumber(int num){
		fileNumber = num;
	}
	void SetProgressBar(ProgressBar* progressBar){
		progressBar = progressBar;
	}
	void DisplayProgress(int value){
		progressBar->setValue(value);
	}
private:
	string filePath;
	int fileNumber;
	ProgressBar* progressBar;
};

class FileSplitterA : public FileSplitter
{
public:
	void Split(){
		//第一步，打开文件filePath
		*******
		//第二步，把文件分割成fileNumber个文件
		************
		DisplayProgress(value);
	}
};

class FileSplitterB : public FileSplitter
{
public:
	void Split(){
		//第一步，打开文件filePath
		*******
		//第二步，把文件分割成fileNumber个文件
		************
		DisplayProgress(value);
	}
};

class FileSplitterC : public FileSplitter
{
public:
	void Split(){
		//第一步，打开文件filePath
		*******
		//第二步，把文件分割成fileNumber个文件
		************
		DisplayProgress(value);
	}
};

#endif
