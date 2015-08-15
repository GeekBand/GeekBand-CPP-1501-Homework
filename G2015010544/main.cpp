#include <stdlib.h>
#include "Shape.h"
#include "Rectangle.h"

 
Shape* main(void)
{
	//
	Shape shapes[20];
	Shape* shapes_temp[20];

	for(int i = 0; i < 20; i++)
	{
		if(i < 10)
		{
			int x_t = rand() % 11; // 1-10
			int y_t = rand() % 11;
			int no_t = rand() % 11;

			Rectangle r = new Rectangle(x_t, y_t);
			r.no = no_t;
			shapes[i] = r;
		}
		else
		{
			int radius_t = rand() % 11;
			int no_t = rand() % 11;
			Circle c = new Circle(radius_t);
			c.no = no_t;
			shapes[i] = c;
		}		
	}

	for(int j = 0; j < 20; j ++)
	{
		int i = 0;
		if(shapes[j].getArea() > 50)
		{	
			shapes_temp[i] = &shapes[j];
			i ++;
		}
	}

	int shapes_length = sizeof(shapes_temp) / 4;

	Shape shapes_result[shapes_length];

	for(int k = 0; k < shapes_length; k ++)
	{
		shapes_result[k] = *(shapes_temp[i]);
	}

	return shapes_result;

}