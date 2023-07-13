#pragma once
#include "projectile.h"
#include "trajectory.h"

class Program {
public:
    Program(const Projectile& Projectile, double dragCoefficient, double crossSectionalArea);
    void run() const;

private:
    Projectile projectile;
    Trajectory trajectory;
};