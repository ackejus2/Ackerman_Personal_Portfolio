#include "projectile.h"
#include "program.h"
#include <iostream>
#include <cmath>

int main() {
    double weight, initialVelocity, caliber;
    double dragCoefficient, crossSectionalArea;
    const double inch_to_meter = 0.0254;
    const double PI = 3.14159265358979323846;

    std::cout << "Enter the weight of the bullet (grains): " << std::endl;
    std::cin >> weight;

    std::cout << "Enter the muzzle velocity (ft/s):" << std::endl;
    std::cin >> initialVelocity;

    std::cout << "Enter the drag coefficient (dimensionless):" << std::endl;
    std::cin >> dragCoefficient;

    std::cout << "Hint: Use the caliber in inches for a bullet.\nEnter the cross-sectional area of the projectile (in):" << std::endl;
    std::cin >> caliber;

    double caliberInMeters = caliber * inch_to_meter;
    crossSectionalArea = (PI / 4) * pow(caliberInMeters, 2);

    Projectile projectile(weight, initialVelocity);
    Program program(projectile, dragCoefficient, crossSectionalArea);

    std::cout << "Projectile trajectory based on weight, initial velocity, drag coefficient, and cross-sectional area:" << std::endl;
    program.run();

    return 0;
}