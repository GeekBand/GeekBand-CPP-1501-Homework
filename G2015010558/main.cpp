#include <iostream>
#include <vector>
#include "Shape.h"

#include <ctime>
#include <cstdlib>

using namespace std;

void week1test()
{
    Rectangle r1(5, 10, 1, 2);

    Rectangle r2(r1);

    Rectangle r3 = r1;
    r2 = r3;
}

int gen_rand()
{
    srand(time(0));
    return rand() % 10 + 1;
}

void week2test(Shape* ret_array[], int& len)
{
    //vector<Shape *> s_array;
    Shape* s_array[20];
    // generate 20 Shape object
    for (int i = 0; i < 20; i++)
    {
        Shape* s;
        if (i < 10)
        {
            int w = rand() % 10 + 1;
            int h = rand() % 10 + 1;
            int x = rand() % 10 + 1;
            int y = rand() % 10 + 1;
            s = new Rectangle(w, h, x, y);
            //Rectangle* s = new Rectangle(w, h, x, y);
            //Rectangle* s = new Rectangle(gen_rand(), gen_rand(), gen_rand(), gen_rand());

        }
        else
        {   int r = rand() % 10 + 1;
            int x = rand() % 10 + 1;
            int y = rand() % 10 + 1;
            s = new Circle(x, y, r);
            //Circle* s = new Circle(gen_rand(), gen_rand(), gen_rand());
        }
        s->set_no(i);
        s_array[i] = s;
        cout << "gen new shape, area " << s->getArea() << endl;

    }

    // check whether area is larger than 50, delete object if not
    int deleted = 0;
    for (int i = 0; i < 20; ++i)
    {
        if (s_array[i]->getArea() < 50)
        {
            cout << "deleting shape area " << s_array[i]->getArea() << endl;
            delete s_array[i];
            s_array[i] = nullptr;
            ++ deleted;
        }
    }

    // copy shape pointer to return array
    len = 20 - deleted;
    for (int i = 0,  j = 0; i < len; i++)
    {
        while (!s_array[j])
            ++j;
        if (s_array[j])
        {
            ret_array[i] = s_array[j];
            ++ j;
            //++ ret_array;
        }
        else
        {
            ++ j;
        }
    }
}

int main()
{
    Shape* array[20];
    int len;

    for (auto& s : array) {
        s = nullptr;
    }
    week2test(array, len);

    for (int i = 0; i < len; ++i)
    {
        cout << "remained shape " << array[i]->getArea() << endl;
        delete array[i];
    }

    cout << "Hello, World!" << endl;
    return 0;
}