/*
考虑一个文件分割器的设计。 MainForm 为界面类，收集用户输入的文件路径，
和分割数量。 FileSplitter 为实现文件分割的类型，其中 Split()实现文件分割
算法。 1. 要求为 Split()支持多种文件分割算法（至少 3 种），在 MainForm
中灵活切换多种算法。 2.在 Split()分割过程中，实现对进度条的实时通知，
即对 progressBar 的赋值。 3.使用松耦合面向对象设计方法和思想，无需编写
具体算法实现，可使用伪码表示设计。
*/

class MainForm : public Form
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	ProgressBar* progressBar;
private:
	FileSplitterFunc(FileSplitterStrategy* fileSplitterStrategy)
	{
		getFilePath(txtFilePath);
		getFileNumber(txtFileNumber);
		FileSplitter* splitter;
		splitter = setFileSplitterStrategy(fileSplitterStrategy);
		splitter->Split();
		progressBar->setValue();
	}
public:
	void Button1_Click()
	{
		FileSplitterFunc(fileSplitterStrategy);
	}

};

class FileSplitter
{
	string filePath;
	int fileNumber;
public:
	virtual void Split()
	{
	}
};

class FileSplitter1 : public FileSplitter
{
	void Split()
	{

	}
};

class FileSplitter2 : public FileSplitter
{
	void Split()
	{

	}
};

class FileSplitter3 : public FileSplitter
{
	void Split()
	{

	}
};