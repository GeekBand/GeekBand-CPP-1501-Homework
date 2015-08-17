#ifndef SHAPE_H
#define SHAPE_H

class Shape;

class Shape
{
public:
	Shape(int no = 0) : no_(no) {}
	Shape(const Shape&);
	Shape& operator= (const Shape&);
	virtual ~Shape() {}

	int no() const { return no_;}
	void set_no(const int no) { no_ = no; }
private:
	int no_;
};

inline
	Shape::Shape(const Shape& other_shape) 
{
	this->no_ = other_shape.no_;
}

inline Shape&
	Shape::operator= (const Shape& other_shape)
{
	if (this != &other_shape) {
		this->no_ = other_shape.no_;
	}
	return *this;
}

#endif