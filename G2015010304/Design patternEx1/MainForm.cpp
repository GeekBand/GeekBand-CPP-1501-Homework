/*
����һ���ļ��ָ�������ơ� MainForm Ϊ�����࣬�ռ��û�������ļ�·����
�ͷָ������� FileSplitter Ϊʵ���ļ��ָ�����ͣ����� Split()ʵ���ļ��ָ�
�㷨�� 1. Ҫ��Ϊ Split()֧�ֶ����ļ��ָ��㷨������ 3 �֣����� MainForm
������л������㷨�� 2.�� Split()�ָ�����У�ʵ�ֶԽ�������ʵʱ֪ͨ��
���� progressBar �ĸ�ֵ�� 3.ʹ����������������Ʒ�����˼�룬�����д
�����㷨ʵ�֣���ʹ��α���ʾ��ơ�
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