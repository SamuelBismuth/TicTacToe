#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(int x, int y);
        int getX();
        int getY();

    protected:

    private:
        int x,
            y;
};

#endif // POINT_H
