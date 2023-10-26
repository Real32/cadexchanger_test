#ifndef CIRCLE3D_H
#define CIRCLE3D_H

#include <curve3d.h>

class Circle3D : public Curve3D {
public:
    Point3D center;
    double radius;

    Circle3D(const Point3D& center, double radius) : center(center), radius(radius) {}

    Point3D getPoint(double t) const override {
        double x = center.x + radius * std::cos(t);
        double y = center.y + radius * std::sin(t);
        return Point3D(x, y, center.z);
    }

    Point3D getDerivative(double t) const override {
        double dx = -radius * std::sin(t);
        double dy = radius * std::cos(t);
        return Point3D(dx, dy, 0.0);
    }
};

#endif // CIRCLE3D_H
