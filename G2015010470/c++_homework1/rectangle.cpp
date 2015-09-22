class Shape {
	int no;
public:
	virtual ~Shape() {};
};

class Point {
	int x;
	int y;

public:
	Point(int x = 0, int y = 0):x(x), y(y) {
	}
};

class Rectangle: public Shape {
	int width;
	int height;

	Point* leftUp;

public:
	Rectangle(int width, int height, int x, int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();
};

Rectangle::Rectangle(int width = 0, int height = 0, int x = 0, int y = 0) :
		width(width), height(height), leftUp(new Point(x, y)) {
}

Rectangle::Rectangle(const Rectangle& other) :
		width(other.width), height(other.height), Shape(other){
	if (other.leftUp != 0) {
		leftUp = new Point(*other.leftUp);
	} else {
		leftUp = 0;
	}
}

Rectangle& Rectangle::operator=(const Rectangle& other) {

	if (this == &other) {
		return *this;
	}

	Shape::operator=(other);

	width = other.width;
	height = other.height;

	if (other.leftUp != 0 && leftUp != 0) {
		*leftUp = *other.leftUp;
	} else if (other.leftUp != 0 && leftUp == 0) {
		leftUp = new Point(*other.leftUp);
	} else {
		delete leftUp;
		leftUp = 0;
	}

	return *this;
}

Rectangle::~Rectangle() {
	delete leftUp;
}
