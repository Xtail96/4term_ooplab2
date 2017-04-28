#ifndef POINT_H
#define POINT_H
struct Point
{
    double x;
    double y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    void rotate(double angle)
    {
        double old_x = x;
        double old_y = y;

        x = old_x * cos(angle) - old_y * sin(angle);
        y = old_x * sin(angle) + old_y * cos(angle);
    }
};

#endif // POINT_H
