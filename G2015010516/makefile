clean:
	rm *.o
	rm rectangle

rectangle: Test4Rectangle.o Rectangle.o
	g++ -o rectangle Test4Rectangle.o Rectangle.o

Test4Rectangle.o: Test4Rectangle.cpp Rectangle.cpp Rectangle.h
	g++ -c Test4Rectangle.cpp 

Rectangle.o:Rectangle.cpp Rectangle.h
	g++ -c Rectangle.cpp
