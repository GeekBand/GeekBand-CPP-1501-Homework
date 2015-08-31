class splitMethod
{
public:
	virtual float splitProgress(const string& filePath, int fileNumber) = 0;
	virtual ~splitMethod(){}
};

class Method1 : public splitMethod
{
	virtual float splitProgress(const string& filePath, int fileNumber)
	{
		cout<<"Method1 is working..."<<endl;
	}
};

class Method2 : public splitMethod
{
	virtual float splitProgress(const string& filePath, int fileNumber)
	{
		cout<<"Method2 is working..."<<endl;
	}
};

class Method3 : public splitMethod
{
	virtual float splitProgress(const string& filePath, int fileNumber)
	{
		cout<<"Method3 is working..."<<endl;
	}
};