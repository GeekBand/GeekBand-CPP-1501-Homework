#ifndef __MYRECTANGLE__

#define __MYRECTANGLE__


class Shape
{
public:
    Shape(int i = 0): no(i) { std::cout << "Shape Constructor" << std::endl;};
protected:
    int no;
};

class Point
{
public:
    Point(int px = 0, double py = 0): x(px),y(py) {std::cout << "Point Constructor" << std::endl;};
    int px() const {return x;}
    int py() const {return y;}
private:
    int x;
    int y;
};

class Rectangle:public Shape
{
public:
    Rectangle(int p_width, int p_height, int p_x, int p_y);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle();
    int disp_no() const {return no;}
    int disp_width() const {return width;}
    int disp_height() const {return height;}
    int disp_leftUp_x() const {return leftUp->px();}
    int disp_leftUp_y() const {return leftUp->py();}
private:
    int width;
    int height;
    Point *leftUp;
};

inline
Rectangle::Rectangle(int p_width = 0, int p_height = 0, int p_x = 0, int p_y = 0)
{
    std::cout << "Rectangle Constructor" << std::endl;
    leftUp = new Point(p_x, p_y);
    no = 2;  // for Rectangle.
    width = p_width;
    height = p_height;
}

inline
Rectangle::Rectangle(const Rectangle& other)
{
    std::cout << "Rectangle Copy Constructor" << std::endl;
    leftUp = new Point(other.leftUp->px(),other.leftUp->py());
    no = other.no;
    width = other.width;
    height = other.height;
}
inline
Rectangle& Rectangle::operator=(const Rectangle& other)
{
    std::cout << "Rectangle Operator Constructor" << std::endl;
    if (this == &other)
        return *this;
    
    delete leftUp;
    leftUp = new Point(other.leftUp->px(),other.leftUp->py());
    no = other.no;
    width = other.width;
    height = other.height;
    return *this;
}

inline
Rectangle::~Rectangle()
{
    std::cout << "Rectangle Destructor" << std::endl;
    delete leftUp;
}

#endif

