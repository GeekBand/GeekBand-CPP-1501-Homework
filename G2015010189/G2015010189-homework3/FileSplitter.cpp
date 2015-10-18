class FileSplitter
{
	string filePath;
	int fileNumber;
	List<IPprogress*> m_ipprogressList;
	SplitMethod* m_splitMethod;
public:
	FileSplitter(const string& Path, int n):
	  filePath(Path),
	  fileNumber(n)
	{}

	void setMethod(SplitMethod* m)       // 设置切割方法
	{
		*m_splitMethod = *m;
	}

	void Split()
	{
		for(int i = 0; i < fileNumber; i++)
		{
			float progressValue = m_splitMethod->splitProgress(filePath, fileNumber); // 在切割方法 splitMethod 的子类中分别实现，返回值为进度，赋给进度条
			progressValue /= fileNumber;
			Onprogress(progressValue);
		}
	}
	
	void addIPprogress(IPprogress* ipprogress)
	{
		m_ipprogressList.push_back(ipprogress);
	}
	void removeIPprogress(IPprogress* ipprogress)
	{
		m_ipprogressList.remove(ipprogress);
	}

protected:
	virtual void OnProgress(float value)
	{
		List<IPprogress*>::iterator itor = m_ipprogressList.begin();
		while(itor != m_ipprogressList.end())
		{
			(*itor)->DoProgess(value);          // 虚函数，在 IPprogress的子类中分别实现，不同的进度条通知
			itor++;
		}
	}
};

