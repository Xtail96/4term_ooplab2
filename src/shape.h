#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <typeinfo>

#include "point.h"

const double eps = 0.00001;

class Shape
{
private:
    static unsigned int counter;


protected:
    const unsigned int id;
    Point center_coordinates;
    double current_angle;
    double current_scale;
    std::string current_color;

    Shape(double x, double y, double angle = 0, double scale = 1, std::string color = "#000") : id(counter++)
    {
        center_coordinates.x = x;
        center_coordinates.y = y;
        setAngle(angle);
        current_scale = scale;
        current_color = color;
    }
    virtual void print(std::ostream &os) = 0;

    // метод для вычисления количества точек пересечения фигур
    virtual int intersect(Shape& s2) const = 0;

public:
    virtual ~Shape(){}
    void setColor(std::string color);
    std::string getColor() const;
    Point getPosition() const;
    void setPosition(Point p);
    double getAngle() const;
    void setAngle(double angle);
    unsigned int getId() const;

    virtual void scale(double scale) = 0;
    virtual double getPerimetr() const = 0;
    virtual double getArea() = 0;

    friend std::ostream &operator << (std::ostream &os, Shape &f);

    virtual bool isPointOnBorder(const Point &p) const = 0;
};

#endif // SHAPE_H
