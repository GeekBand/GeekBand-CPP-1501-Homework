#ifndef __RECTANGLE__
#define __RECTANGLE__

class Shape
{
    int no;
};
class Point
{
    int x;
    int y;
public:
    Point(int x = 0, int y = 0)
        : x (x), y (y)
    {}
    int GetX() const
    {
        return x;
    }
    int GetY() const
    {
        return y;
    }
};

class Rectangle: public Shape
{
    int width;
    int height;
    Point * leftUp;
public:
    Rectangle(int width, int height, int x, int y);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle();

    int GetWidth() const
    {
        return width;
    }

    int GetHeight() const
    {
        return height;
    }

    Point* GetLeftUp() const
    {
        return leftUp;
    }
};

inline Rectangle::Rectangle(int width, int height, int x, int y)
{
    if (width < 0 || height < 0) {
        return;
    }
    this->width = width;
    this->height = height;
    this->leftUp = new Point(x, y);
}

inline Rectangle::Rectangle(const Rectangle& other)
{
    if(this == &other) {
        return;
    }

    this->width = other.width;
    this->height = other.height;
    this->leftUp = new  Point(*other.leftUp);
}

inline Rectangle& Rectangle::operator = (const Rectangle& other)
{
    if (this == &other) {
        return *this;
    }
    this->width = other.width;
    this->height = other.height;

    delete this->leftUp;
    this->leftUp = new Point(*other.leftUp);
    return *this;
}

inline Rectangle::~Rectangle()
{
    this->width = 0;
    this->height = 0;
    delete this->leftUp;
}

std::ostream&
operator << (std::ostream& os, const Point* p)
{
    return os << '(' << p->GetX() << ',' << p->GetY() << ')';
}

std::ostream& operator << (std::ostream& os, const Rectangle& r)
{
    return os << "leftUp = " << r.GetLeftUp() << ", width = " << r.GetWidth() << ", height = " << r.GetHeight() << '.';
}

#endif // __RECTANGLE__
