#ifndef ROUND_H
#define ROUND_H
#include "arc.h"

class Round : public Arc
{
public:
    Round(double x, double y, double radius, double angle = 0, double scale = 1, std::string color = "#000")
        : Arc(x, y, 0, 2*M_PI, radius, angle, scale, color){}
    virtual ~Round(){}

    double getPerimetr() const override;
    double getArea() override;

    void print(std::ostream &os) override;

    bool isPointOnBorder(const Point &p) const override;
};

#endif // ROUND_H
