#pragma once

class Projectile {
private:
    double weight;
    double initialVelocity;

public:
    Projectile(double weight, double initialVelocity);
    double getWeight() const;
    double getInitialVelocity() const;
};
