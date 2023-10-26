#ifndef POINT3D_H
#define POINT3D_H

#include <cmath>

class Point3D {
public:
    double x, y, z;

    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
    double distanceTo(const Point3D& other) const;
};

#endif // POINT3D_H
