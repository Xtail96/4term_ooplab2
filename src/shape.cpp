#include "shape.h"

unsigned int Shape::counter = 0;

void Shape::setColor(std::string color)
{
    current_color = color;
}
std::string Shape::getColor() const
{
    return current_color;
}
double Shape::getAngle() const
{
    return current_angle;
}
void Shape::setAngle(double angle)
{
    current_angle = fmod(angle, 2 * M_PI);
    Point old_coordinates = center_coordinates;
    center_coordinates.x = old_coordinates.x * cos(current_angle) - old_coordinates.y * sin(current_angle);
    center_coordinates.y = old_coordinates.x * sin(current_angle) + old_coordinates.y * cos(current_angle);
}

Point Shape::getPosition() const
{
    return center_coordinates;
}
void Shape::setPosition(Point p)
{
    center_coordinates = p;
}
unsigned int Shape::getId() const
{
    return id;
}
std::ostream &operator<< (std::ostream &os, Shape &f)
{
    f.print(os);
    return os;
}
