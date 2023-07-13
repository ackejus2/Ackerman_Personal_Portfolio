#pragma once

class Trajectory {
public:
    Trajectory(double initialVelocity, double projectileMass, double dragCoefficient, double crossSectionalArea);
    double calculateDrop(double distance) const;
    double calculateTime(double distance) const;
    double calculateFinalVelocity(double distance) const;

private:
    double projectileMass;
    double dragCoefficient;
    double crossSectionalArea;
    double initialVelocity;
    double calculateDragForce(double velocity) const;
};