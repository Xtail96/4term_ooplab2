#include "arc.h"
void Arc::scale(double scale)
{
    radius *= scale;
}
double Arc::getArea()
{
    return 0;
}
double Arc::getPerimetr() const
{
    double n = fabs(startAngle - finishAngle);
    double l = (M_PI * radius / 180) * n;
    return l;
}
void Arc::print(std::ostream &os)
{
    os<<"Arc:"<<std::endl;
    os<<"Id: "<<id<<std::endl;
    os<<"Center( x , y ): ( "<<center_coordinates.x<<" , "<<center_coordinates.y<<" )"<<std::endl;
    os<<"Start Angle: "<<startAngle<<std::endl;
    os<<"Finish Angle: "<<finishAngle<<std::endl;
    os<<"Radius: "<<radius<<std::endl;
}

bool Arc::isPointOnBorder(const Point &p) const
{
    // x = cos(t) y = sin(t)
    Point r = p;
    r.rotate(-current_angle);
    double dx = r.x - center_coordinates.x;
    double dy = r.y - center_coordinates.y;
    bool borderFlag = fabs(pow(dx, 2) + pow(dy, 2) - pow(radius, 2)) < eps;
    double pointAngle = (acos(r.x) + asin(r.y))/2;
    bool startAngleFlag = pointAngle >= startAngle;
    bool finishAngleFlag = pointAngle <= finishAngle;
    return (borderFlag && startAngleFlag && finishAngleFlag);
}

int Arc::intersect(Shape &s2) const
{
    int intersectCount = 0;
    double x, y;
    for(double t = startAngle; t <= finishAngle; t+=eps)
    {
        x = radius * cos(t) + center_coordinates.x;
        y = radius * sin(t) + center_coordinates.y;

        Point p(x, y);

        if(s2.isPointOnBorder(p))
        {
            intersectCount++;
        }
    }
    return intersectCount;
}
