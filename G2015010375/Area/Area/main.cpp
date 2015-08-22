#include <iostream>
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

#define RANDNUM rand() % 10 + 1

Shape** createAndCheckShapes()
{
	const int rCount = 10;
	const int cCount = 10;
	const int totalCount = rCount + cCount;

	Shape* shapes[totalCount];
	int index = 0;

	for (int i = 0; i < rCount && index < totalCount; i++, index++)
	{
		shapes[index] = new Rectangle(RANDNUM, RANDNUM, RANDNUM, RANDNUM);
	}

	for (int i = 0; i < cCount && index < totalCount; i++, index++)
	{
		shapes[index] = new Circle(RANDNUM, RANDNUM, RANDNUM);
	}

	int resultCount = totalCount;
	for (int i = 0; i < totalCount; i++)
	{
		if (shapes[i]->getArea() < 50)
		{
			delete shapes[i];
			shapes[i] = 0;
			resultCount--;
		}
	}

	index = 0;
	Shape** resultShapes = new Shape*[resultCount + 1];
	for (int i = 0; i < totalCount && index < resultCount; i++)
	{
		if (shapes[i] != 0)
		{
			resultShapes[index] = shapes[i];
			index++;
		}
	}

	resultShapes[resultCount] = 0;

	return resultShapes;
}

void main()
{
	Shape** shapes = createAndCheckShapes();

	for (int i = 0;shapes[i] != 0; i++)
	{
		cout << shapes[i]->getArea() << "\n";
	}
}