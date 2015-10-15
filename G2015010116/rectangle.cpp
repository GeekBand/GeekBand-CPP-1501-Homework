class Shape {
private:
    int no;
public:
    Shape(int no = 0)
    :no(no)
    {}
    virtual ~Shape() {}
};

class Point {
    int x;
    int y;
public:
    Point(int x = 0, int y = 0)
    :x(x), y(y)
    {}
};

class Rectangle: public Shape
{
    int width;
    int height;
    Point * leftUp;
public:
    Rectangle(int width = 0, int height = 0, int x = 0, int y = 0)
    : width(width), height(height), leftUp(new Point(x,y))
    {}
    Rectangle(const Rectangle& other)
    : Shape(other), width(other.width), height(other.height)
    {
        if (other.leftUp != nullptr) {
            this->leftUp = new Point(*other.leftUp);
        }
        else {
            this->leftUp = nullptr;
        }
    }
    Rectangle& operator = (const Rectangle& other)
    {
        if (this != &other)
        {
            Shape::operator = (other);
            this->width = other.width;
            this->height = other.height;
            if (other.leftUp != 0) {
                if (this->leftUp != 0) {
                    *this->leftUp = *other.leftUp;
                }
                else
                {
                    this->leftUp = new Point(*other.leftUp);
                }
            }
            else
            {
                delete this->leftUp;
                this->leftUp = 0;
            }
        }
        return *this;
    }
    ~Rectangle()
    {
        delete leftUp;
    }
};