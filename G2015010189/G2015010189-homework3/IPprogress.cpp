class IPprogress
{
public:
	virtual void Doprogress(float value) = 0;
	virtual ~IPprogress(){}
};

class IPprogress1 : public: IPprogress
{
	virtual void Doprogress(float value)
	{
		cout<<"Do progress1, value = "<<value<<endl;
	}
};

class IPprogress2 : public: IPprogress
{
	virtual void Doprogress(float value)
	{
		cout<<"Do progress2, value = "<<value<<endl;
	}
};

class IPprogress3 : public: IPprogress
{
	virtual void Doprogress(float value)
	{
		cout<<"Do progress3, value = "<<value<<endl;
	}
};