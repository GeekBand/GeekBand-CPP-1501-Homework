#include "shapes.h"
#include <cstdlib>
#include <ctime>

int getRandomValue()
{
	return (1 + rand() % 10);
}

const int max_amount = 20;
const int min_area = 50;

void randomArray(Shape** shape_array) 
{
	for(int index = 0; index <= max_amount - 1; ++index) {
		if (index <= max_amount/2 - 1) {
			shape_array[index] = new Rectangle(getRandomValue(), getRandomValue(), 
										getRandomValue(), getRandomValue(), index);
		}
		else {
			shape_array[index] = new Circle(getRandomValue(), getRandomValue(), getRandomValue(), index);
			shape_array[index]->outputInfo();
		}
	}
}

int getShapeArrayLarger50(Shape** shape_array, Shape***presult_array, int* presult_amount) 
{
	int result_amount = 0; 
	bool flag_array[max_amount];
	for(int index = 0; index <= max_amount - 1; ++index) {
		if(shape_array[index]->getArea() >= min_area) {
			flag_array[index] = true;
			++result_amount;
		}
		else {
			flag_array[index] = false;
		}
	}
	*presult_amount = result_amount; // return result_amount
	Shape** result_shape_array = new Shape*[result_amount];
	for (int index= 0, result_index = 0; index <= max_amount - 1; ++index) {
		if (flag_array[index]) {
			result_shape_array[result_index++] = shape_array[index];
		}
	}
	*presult_array = result_shape_array; //return result_array
	result_shape_array = nullptr;
}

int main()
{
	// get a array of random shapes: shape_array 
	srand((unsigned)time(NULL));
	Shape** shape_array = new Shape*[max_amount];
	randomArray(shape_array);
	// from shape_array get a array of shapes whose area >= 50: result_array
	Shape** result_array = nullptr;
	int result_amount = 0;
	getShapeArrayLarger50(shape_array, &result_array, &result_amount);
	// output result_array
	std::cout << std::endl << "Area Large than 50: " << std::endl;
	for (int result_index = 0; result_index <= result_amount -1; ++result_index) {
		result_array[result_index]->outputInfo();
	}
	// delete shape_array
	for(int index = 0; index <= max_amount - 1; ++index) {
		delete shape_array[index];
		shape_array[index] = nullptr;
	}
	delete[] shape_array;
	shape_array = nullptr;
	// delete result_array
	for(int result_index = 0; result_index <= result_amount - 1; ++result_index) {
		result_array[result_index] = nullptr; // memory has been freed by delete shape_array[index]  
	}
	delete[] result_array;
	result_array = nullptr;

	system("pause");
	return 0;
}