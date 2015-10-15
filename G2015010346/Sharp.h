#pragma once

class Sharp
{
public:
	Sharp(const int num);

	int getNo() const;

	virtual ~Sharp() = 0;

private:
	int no;
};