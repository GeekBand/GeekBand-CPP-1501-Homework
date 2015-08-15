#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(int x, int y);

        int get_x();
        int get_y();
    private:
        int x;
        int y;
};

#endif // POINT_H
