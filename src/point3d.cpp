#include "point3d.h"

// Calculate the distance between two 3D points (optional)
double Point3D::distanceTo(const Point3D& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    double dz = z - other.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}
