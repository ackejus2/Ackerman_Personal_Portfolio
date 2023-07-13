#include "trajectory.h"
#include <cmath>

const double GRAVITY = 32.174;
const double air_density = 1.225;
const double DT = 0.001;

Trajectory::Trajectory(double initialVelocity, double projectileMass, double dragCoefficient, double crossSectionalArea)
        : initialVelocity(initialVelocity), projectileMass(projectileMass), dragCoefficient(dragCoefficient), crossSectionalArea(crossSectionalArea) {}

double Trajectory::calculateDrop(double distance) const {
    double time = calculateTime(distance);
    return 0.5 * GRAVITY * pow(time, 2);
}

double Trajectory::calculateTime(double distance) const {
    double currentDistance = 0;
    double currentVelocity = initialVelocity;
    double time = 0;

    while (currentDistance < distance) {
        double acceleration = -calculateDragForce(currentVelocity) / projectileMass;
        currentVelocity += acceleration * DT;
        currentDistance += currentVelocity * DT;
        time += DT;
    }
    return time;
}

double Trajectory::calculateFinalVelocity(double distance) const {
    double currentDistance = 0;
    double currentVelocity = initialVelocity;

    while (currentDistance < distance) {
        double acceleration = -calculateDragForce(currentVelocity) / projectileMass;
        currentVelocity += acceleration * DT;
        currentDistance += currentVelocity * DT;
    }

    return currentVelocity;
}

double Trajectory::calculateDragForce(double velocity) const {
    return 0.5 * air_density * pow(velocity, 2) * dragCoefficient * crossSectionalArea;
}