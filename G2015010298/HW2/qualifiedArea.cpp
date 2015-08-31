//  GeekBand G2015010298
//
//  Created by Xun Gong on 8/21/15.
//  Copyright (c) 2015 Xun Gong. All rights reserved.
//

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

int main(int argc, const char * argv[]) {
    const int n = 20; // total size of this array
    srand ((unsigned)time(NULL));
    int qualified = 0; // number of shapes with area larger than 50
                       // Declare an Array
    Shape** arr = new Shape*[n] ;
    // Initialize each slot, 10 Rectangle + 10 Circle
    cout << "Creation of Rectangles and Circles: \n" << endl;
    for (int i = 0; i < n / 2; ++i) {
        arr[i] = new Rectangle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, i);
        cout << i << ". "; arr[i]->info(); cout << endl;
        arr[i+10] = new Circle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, i + 10);
        cout << i + 10 << ". "; arr[i + 10]->info(); cout << endl;
    }
    // delete area < 50
    for (int i = 0; i < n; ++i) {
        if (arr[i]->getArea() < 50) {
            delete arr[i];
            arr[i] = nullptr;
        }
        else
            ++qualified;
    }
    // return a new array
    Shape** arr2 = new Shape*[qualified];
    for (int i = 0, j = 0; i < n; ++i) {
        if (arr[i]) {
            arr2[j++] = arr[i];
            arr[i] = nullptr;
        }
    }
    // print out qualified shapes
    cout << "\n\nQualified Shapes with area larger than 50: \n" << endl;
    for (int i = 0; i < qualified; ++i) {
        cout << "Shape " << i + 1 << ". Area: " << arr2[i]->getArea() << endl;
    }
    // delete memory allocated before
    for (int i = 0; i < n; ++i) {
        delete arr[i];
        arr[i] = nullptr;
    }
    // since arr and arr2 are HEAP variable, need delete
    delete[] arr;
    delete[] arr2;

    return 0;
}