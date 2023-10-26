#ifndef HELIX3D_H
#define HELIX3D_H

#include <curve3d.h>

class Helix3D : public Curve3D {
public:
    double radius;
    double step;

    Helix3D(double radius, double step) : radius(radius), step(step) {}

    Point3D getPoint(double t) const override {
        double x = radius * std::cos(t);
        double y = radius * std::sin(t);
        double z = step * t;
        return Point3D(x, y, z);
    }

    Point3D getDerivative(double t) const override {
        double dx = -radius * std::sin(t);
        double dy = radius * std::cos(t);
        double dz = step;
        return Point3D(dx, dy, dz);
    }
};

#endif // HELIX3D_H
