CFLG= -g

all: test

rectangle.o: rectangle.cpp
	g++ $(CFLAG) -c rectangle.cpp

test: test.cpp rectangle.o
	g++ $(CFLG) test.cpp rectangle.o -o test

clean:
	rm test rectangle.o
