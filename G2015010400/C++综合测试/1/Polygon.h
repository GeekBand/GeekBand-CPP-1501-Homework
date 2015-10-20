#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include "Shape.h"

class Polygon : public Shape
{
public:
    Polygon(Point* points_, int length_);
	Polygon(const Polygon& other);
	Polygon& operator = (const Polygon&);
	~Polygon();
	
	Point* getPoints() const {return points;}
	int getLength() const {return length;}
private:
    Point* points;
    int length;
};

Polygon::Polygon(Point* points_, int length_) : length(length_)
{
    if(length_ >= 3){
        points = new Point[length_];
        for(int i = 0; i < length_; i++)
            points[i] = points_[i];
    } else {
        std::cerr << "Polygon need 3 points at least" << std::endl;
		points = nullptr;
	}	
}

Polygon::Polygon(const Polygon& other) : length(other.length), Shape(other)
{
	if(other.points != nullptr){
		points = new Point[other.length];
		for(int i = 0; i < other.length; i++)
			points[i] = other.points[i];
	}else
		points = nullptr;
		
	
}

Polygon& Polygon::operator = (const Polygon& other)
{
	if(this != &other){
		length = other.length;
		Shape::operator=(other);
		if(points != nullptr && other.points != nullptr){
			delete[] points;
			points = new Point[other.length];
			for(int i = 0; i < other.length; i++)
				points[i] = other.points[i];
		} else {
			if(points == nullptr){
				points = new Point[other.length];
				for(int i = 0; i < other.length; i++)
					points[i] = other.points[i];
			}else{
				delete[] points;
				points = nullptr;
			}
		}
		return *this;
	}else
		return *this;
}

Polygon::~Polygon()
{
	delete points;
}

std::ostream& operator << (std::ostream& os, const Polygon& p)
{
    if (p.getPoints()) {
        for (int i = 0; i < p.getLength(); i++) {
            os << p.getPoints()[i] << " ";
        }
    } else
        std::cerr << "no needed points for Polygon";
    
    return os;
}
#endif