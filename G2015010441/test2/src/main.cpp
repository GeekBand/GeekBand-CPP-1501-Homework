#include "Shape.h"
#include <ctime>
#include <cstdlib>

int main()
{
    Shape* shapes[20] = {0};

    ShapeFactory *factory = 0;

    for(int i=0; i < 20; ++i)
    {
        if(i < 10)
            factory = RectangleFactory::getRectangleFactory() ;
        else
            factory = CircleFactory::getCircleFactory() ;

        shapes[i] = factory->createShape(i+1);
        shapes[i]->print();
    }

    cout << "-------------------" << endl;
    int count = 0;

    for(int i=0; i < 20; ++i)
    {
        if(shapes[i]->getArea() >= 50)
        {
            ++count;
        }
        else
        {
            delete shapes[i];
            shapes[i] = NULL;
        }
    }

    Shape** array = new Shape*[count];
    int j = 0;
    for(int i=0; i < 20; ++i)
    {
        if(shapes[i] != NULL)
       {
           array[j] = shapes[i];
           array[j]->print();
           j++;
       }
    }
    return 0;
}
