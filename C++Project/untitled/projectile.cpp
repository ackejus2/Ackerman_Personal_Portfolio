#include "projectile.h"

Projectile::Projectile(double weight, double initialVelocity) : weight(weight), initialVelocity(initialVelocity) {}

double Projectile::getWeight() const {
    return weight;
}

double Projectile::getInitialVelocity() const {
    return initialVelocity;
}