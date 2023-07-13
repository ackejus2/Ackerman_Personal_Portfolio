#include "program.h"
#include <iostream>

double yardsToFeet(double yards) {
    return yards * 3;
}

double feetToInches(double feet) {
    return feet * 12;
}

Program::Program(const Projectile& projectile, double dragCoefficient, double crossSectionalArea)
        : projectile(projectile), trajectory(Trajectory(projectile.getInitialVelocity(), projectile.getWeight(), dragCoefficient, crossSectionalArea)) {}

void Program::run() const {
    for (int yards = 50; yards <= 2000; yards += 25) {
        double distanceFeet = yardsToFeet(yards);
        double dropFeet = trajectory.calculateDrop(distanceFeet);
        double dropInches = feetToInches(dropFeet);
        double finalVelocity = trajectory.calculateFinalVelocity(distanceFeet);

        std::cout << "\nAt " << yards << " yards, projectile drop: " << dropInches << " inches, final velocity: " << finalVelocity << " ft/s.";
    }
}