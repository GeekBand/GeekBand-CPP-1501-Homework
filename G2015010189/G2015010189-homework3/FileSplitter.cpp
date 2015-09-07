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

	void setMethod(SplitMethod* m)       // �����и��
	{
		*m_splitMethod = *m;
	}

	void Split()
	{
		for(int i = 0; i < fileNumber; i++)
		{
			float progressValue = m_splitMethod->splitProgress(filePath, fileNumber); // ���и�� splitMethod �������зֱ�ʵ�֣�����ֵΪ���ȣ�����������
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
		List<IPprogress*>::iterator itor = m_ipprogress.begin();
		while(itor != m_ipprogress.end())
		{
			DoProgess(value);          // �麯������ IPprogress�������зֱ�ʵ�֣���ͬ�Ľ�����֪ͨ
			itor++;
		}
	}
};

