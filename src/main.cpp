#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>

#include <circle3d.h>
#include <ellipse3d.h>
#include <helix3d.h>

int main() {
    std::vector<Curve3D*> curves;
    std::list<Circle3D*> circleContainer;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> uniformDist(0.5, 10.0); // radii must be positive

    // Populate the container with random curves
    for (int i = 0; i < 10; i++) {
        double radius = uniformDist(gen);
        double majorAxis = uniformDist(gen);
        double minorAxis = uniformDist(gen);
        double pitch = uniformDist(gen);
        curves.push_back(new Circle3D(Point3D(0.0, 0.0, 0.0), radius));
        curves.push_back(new Ellipse3D(Point3D(0.0, 0.0, 0.0), majorAxis, minorAxis));
        curves.push_back(new Helix3D(radius, pitch));
    }

    // Print coordinates of points and derivatives at t=PI/4
    for (const auto& curve : curves) {
        Point3D point = curve->getPoint(M_PI / 4);
        Point3D derivative = curve->getDerivative(M_PI / 4);
        std::cout << "Point: (" << point.x << ", " << point.y << ", " << point.z << "), "
                  << "Derivative: (" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")\n";
    }

    // Populate the second container with circles
    for (auto curve : curves) {
        if (dynamic_cast<Circle3D*>(curve)) {
            circleContainer.push_back(static_cast<Circle3D*>(curve));
        }
    }

    // Sort the second container by radii in ascending order
    circleContainer.sort([](Circle3D* a, Circle3D* b) {
        return a->radius < b->radius;
    });

    // Compute the total sum of radii in the second container
    double totalRadiusSum = 0.0;

//#pragma omp parallel for reduction(+:totalRadiusSum)
    for (auto circle : circleContainer) {
        totalRadiusSum += circle->radius;
    }

    std::cout << "Total sum of radii in the second container: " << totalRadiusSum << std::endl;

    // Clean up allocated memory
    for (auto curve : curves) {
        delete curve;
    }

    return 0;
}
