#ifndef ELLIPSE3D_H
#define ELLIPSE3D_H

#include <curve3d.h>

class Ellipse3D : public Curve3D {
public:
    Point3D center;
    double majorAxis;
    double minorAxis;

    Ellipse3D(const Point3D& center, double majorAxis, double minorAxis)
        : center(center), majorAxis(majorAxis), minorAxis(minorAxis) {}

    Point3D getPoint(double t) const override {
        double x = center.x + majorAxis * std::cos(t);
        double y = center.y + minorAxis * std::sin(t);
        return Point3D(x, y, center.z);
    }

    Point3D getDerivative(double t) const override {
        double dx = -majorAxis * std::sin(t);
        double dy = minorAxis * std::cos(t);
        return Point3D(dx, dy, 0.0);
    }
};

#endif // ELLIPSE3D_H
