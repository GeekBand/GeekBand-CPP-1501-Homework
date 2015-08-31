class MainForm : public Form, public IPprogress
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	ProgressBar* progressBar;

public:
	void Button0_Click()     // 初始化按钮
	{
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());
		FileSplitter m_fileSplitter(filePath, number);

		IPprogress1 ipprogress1;
		IPprogress2 ipprogress2;
		m_fileSplitter.addIPprogress(this);
		m_fileSplitter.addIPprogress(&ipprogress1);        // 不同的进度条通知
		m_fileSplitter.addIPprogress(&ipprogress2);		
	}

	void Button1_Click()
	{
		Method1 m_method1;
		m_fileSplitter.setMethod(m_method1);             // 用切割方法1
		m_fileSplitter.Split();
	}
	void Button2_Click()
	{
		Method2 m_method2;
		m_fileSplitter.setMethod(m_method2);             // 换用切割方法2
		m_fileSplitter.Split();
	}
	void Button3_Click()
	{
		Method3 m_method3;
		m_fileSplitter.setMethod(m_method3);             // 换用切割方法3
		m_fileSplitter.Split();
	}
};