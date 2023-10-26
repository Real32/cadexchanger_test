#ifndef CURVE3D_H
#define CURVE3D_H

#include <point3d.h>

class Curve3D {
public:
    virtual Point3D getPoint(double t) const = 0;
    virtual Point3D getDerivative(double t) const = 0;
};

#endif // CURVE3D_H
