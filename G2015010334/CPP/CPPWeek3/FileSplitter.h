#ifndef _FILESPLITTER_H_
#define _FILESPLITTER_H_


class MainForm: public Form
{
	TextBox * txtFilePath;
	TextBox * txtFileNumber;
	ProgressBar * progressBar;
public:
	MainForm() {}
	void Button1_Click();
}

typedef void (*SplitProgressCallback)(int);

enum SplitAlgoEnum {
	Algo0,
	Algo1,
	Algo2
} ;

class FileSplitterAlgo
{
public:
	FileSplitterAlgo( SplitAlgoEnum type);
	virtual int SplitAlgo();
	virtual ~FileSplitterAlgo () {}
}

class FileSplitterAlgo0 : FileSplitterAlgo
{
public:
	virtual int SplitAlgo();
}


class FileSplitterAlgo1 : FileSplitterAlgo
{
public:
	virtual int SplitAlgo();
}


class FileSplitterAlgo2 : FileSplitterAlgo
{
public:
	virtual int SplitAlgo();
}

class FileSplitter
{
	string filePath;
	int fileNumber;
	
	FileSplitterAlgo * algo;
	SplitProgressCallback callback;
	
public:
	FileSplitter(string path, int number, FileSplitterAlgo * pAlgo , SplitProgressCallback pFunc)
	{
		filepath = path;
		number = number;
		algo = pAlgo;
		callback = pFunc;
	}
	~FileSplitter () 
	{
	}
	
	int doSplit();
}


#endif 