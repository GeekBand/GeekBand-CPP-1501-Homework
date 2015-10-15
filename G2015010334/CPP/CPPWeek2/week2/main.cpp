#include <iostream>
#include <time.h>
#include "Shape.h"

using namespace std;

typedef void(*FP_GetArray)(Shape **, const int);

void outputShape(Shape * shape, int index)
{
	if (shape == nullptr)
	{
		cout << "This shape is null" << endl;
		return;
	}
	cout << index << " area=" << shape->getArea();
	shape->outputInfo();
	cout << endl;
}

int getRandom()
{
	return (1 + rand() % 10);
}

void getRandomArray(Shape ** array, const int arraycount)
{
	int half = arraycount >> 1;
	for (int i = 0; i < arraycount; i++)
	{
		if (i < half)
		{
			array[i] = new Rectangle(getRandom(), getRandom(), getRandom(), getRandom(), i);
		}
		else
		{
			array[i] = new Circle(getRandom(), getRandom(), getRandom(), i);
		}
	}
}

int getAreaLarge50(Shape ** &resultarray, int& resultcount, FP_GetArray getArray)
{
	const int arraycount = 20;
	Shape * array[arraycount];

	getArray(array, arraycount);
	
	resultcount = 0;
	bool * resultisOk = new bool[arraycount];
	for (int i = 0; i < arraycount; i++)
	{
		outputShape(array[i], i);

		if (array[i]->getArea() >= 50)
		{
			resultisOk[i] = true;
			++resultcount;
		}
		else
		{
			resultisOk[i] = false;
		}
	}

	if ( resultcount > 0 )
	{
		resultarray = new Shape*[resultcount];
		for (int i = 0, j = 0; i < arraycount; i++)
		{
			if (resultisOk[i])
			{
				resultarray[j++] = array[i];

				if (j == resultcount)
				{
					break;
				}
			}
			else
			{
				delete array[i];
			}
		}
	}
	else
	{
		resultarray = nullptr;
		resultcount = 0;
	}

	return 0;
}

int x_test[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int y_test[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int w_test1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int h_test1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int r_test1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

void getTestArrayBase(Shape ** array, const int arraycount, int w[], int h[], int r[])
{
	int half = arraycount >> 1;
	for (int i = 0; i < arraycount; i++)
	{
		if (i < half)
		{
			array[i] = new Rectangle(w[i], h[i], x_test[i], y_test[i], i);
		}
		else
		{
			array[i] = new Circle(x_test[i - half], y_test[i - half], r[i - half], i);
		}
	}
}

void getTest1Array(Shape ** array, const int arraycount)
{
	getTestArrayBase(array, arraycount, w_test1, h_test1, r_test1);
}

int w_test2[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int h_test2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int r_test2[] = { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2 };

void getTest2Array(Shape ** array, const int arraycount)
{
	getTestArrayBase(array, arraycount, w_test2, h_test2, r_test2);
}

int w_test3[] = { 10, 7, 6, 10, 10, 10, 10, 10, 10, 10 };
int h_test3[] = { 5, 7, 9, 5, 5, 5, 5, 5, 5, 5 };
int r_test3[] = { 3, 4, 3, 4, 3, 4, 3, 4, 3, 4 };

void getTest3Array(Shape ** array, const int arraycount)
{
	getTestArrayBase(array, arraycount, w_test3, h_test3, r_test3);
}

int w_test4[] = { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };
int h_test4[] = { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };
int r_test4[] = { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };

void getTest4Array(Shape ** array, const int arraycount)
{
	getTestArrayBase(array, arraycount, w_test4, h_test4, r_test4);
}

void doProess(FP_GetArray getArray)
{
	Shape ** shapeArray = nullptr;
	int shapeArraycount = 0;
	getAreaLarge50(shapeArray, shapeArraycount, getArray);

	cout << endl << "result Array count=" << shapeArraycount << endl;
	if (shapeArraycount > 0)
	{
		for (int i = 0; i < shapeArraycount; i++)
		{
			outputShape(shapeArray[i], i);
			delete shapeArray[i];
		}
		delete[] shapeArray;
	}
	shapeArray = nullptr;
	shapeArraycount = 0;
}

int main(int argc, char** argv)
{
	srand((unsigned)time(NULL));

	doProess(getRandomArray);

	cout << endl << "Test1" << endl;
	doProess(getTest1Array);

	cout << endl << "Test2 for all area < 50" << endl;
	doProess(getTest2Array);
	
	cout << endl << "Test3 for area aroud 50" << endl;
	doProess(getTest3Array);

	cout << endl << "Test3 for all area > 50" << endl;
	doProess(getTest4Array);

	return 0;
}

