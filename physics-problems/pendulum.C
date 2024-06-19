#include <iostream>
#include <fstream>
#include <cmath>

// Constants
const double g = 9.81; // gravitational acceleration (m/s^2)

// Function to convert initial height to initial angle
double heightToAngle(double height, double length)
{
    return std::asin(height / length);
}

int main()
{
    // Pendulum parameters
    double length = 1.0;                                        // length of the pendulum (meters)
    double mass = 1.0;                                          // mass of the pendulum (kg)
    double damping = 0.05;                                      // damping coefficient (kg/s)
    double initialHeight = 0.5;                                 // initial height (meters)
    double initialAngle = heightToAngle(initialHeight, length); // initial angle (radians)
    double initialAngularVelocity = 0.0;                        // initial angular velocity (rad/s)

    // Simulation parameters
    double dt = 0.01;        // time step (seconds)
    double totalTime = 20.0; // total simulation time (seconds)

    // Initial conditions
    double theta = initialAngle;
    double omega = initialAngularVelocity;

    // Open file to write the output
    std::ofstream outFile("pendulum_data.csv");
    outFile << "time,angle,angular_velocity,x,y\n";

    // Simulation loop
    for (double t = 0.0; t <= totalTime; t += dt)
    {
        // Calculate angular acceleration
        double alpha = -(g / length) * std::sin(theta) - (damping / mass) * omega;

        // Update angular velocity and position using Euler's method
        omega += alpha * dt;
        theta += omega * dt;

        // Calculate x and y positions
        double x = length * std::sin(theta);
        double y = -length * std::cos(theta);

        // Write data to file
        outFile << t << "," << theta << "," << omega << "," << x << "," << y << "\n";
    }

    outFile.close();
    std::cout << "Simulation complete. Data written to pendulum_data.csv" << std::endl;

    return 0;
}