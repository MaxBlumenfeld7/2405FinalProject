/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       maxblumenfeld                                             */
/*    Created:      Fri Apr 26 2024                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision               vision        11              
// ymotor               motor         1               
// xmotor               motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// PID constants
const double kPy = 01; // Proportional constant
const double kIy = 0.01; // Integral constant
const double kDy = 01; // Derivative constant

const double kPx = 0.85; // Proportional constant
const double kIx = 0.01; // Integral constant
const double kDx = 01.1; // Derivative constant


// Target positions for the object in the vision sensor's field of view
const int yTarget = 120; // Target y-position, adjust based on sensor's resolution
const int xTarget = 158; // Target x-position, adjust based on sensor's resolution

int main() {
    vexcodeInit(); // Initialize VEXcode devices

    double yError = 0, xError = 0;
    double yPreviousError = 0, xPreviousError = 0;
    double yIntegral = 0, xIntegral = 0;
    double yDerivative = 0, xDerivative = 0;
    double yOutput = 0, xOutput = 0;

    while(true) {
        Vision.takeSnapshot(Vision__PINK_PAPER);

        if (Vision.largestObject.exists) {
            // Calculate the error from the center (y-axis)
            yError = yTarget - Vision.largestObject.centerY;
            // Calculate the error from the center (x-axis)
            xError = xTarget - Vision.largestObject.centerX;

            // Update integral for y-axis - only if error is small to prevent integral windup
            yIntegral += yError;
            // Update integral for x-axis - only if error is small to prevent integral windup
            xIntegral += xError;

            // Calculate derivative of error (y-axis)
            yDerivative = yError - yPreviousError;
            // Calculate derivative of error (x-axis)
            xDerivative = xError - xPreviousError;

            // Compute the motor control signal (y-axis)
            yOutput = kPy * yError + kIy * yIntegral + kDy * yDerivative;
            // Compute the motor control signal (x-axis)
            xOutput = kPx * xError + kIx * xIntegral + kDx * xDerivative;

            // Set motor speed (y-axis)
            ymotor.spin(directionType::fwd, yOutput, velocityUnits::pct);
            // Set motor speed (x-axis)
            xmotor.spin(directionType::fwd, xOutput, velocityUnits::pct);

            // Update previous error (y-axis)
            yPreviousError = yError;
            // Update previous error (x-axis)
            xPreviousError = xError;
        } else {
            // If no object is detected, stop the motors
            ymotor.stop(brakeType::brake);
            xmotor.stop(brakeType::brake);
            // Reset integral values
            yIntegral = 0;
            xIntegral = 0;
        }

        // Sleep to prevent CPU hogging
        vex::task::sleep(20);
    }
}
    // Since the loop is infinite, we do not need a return statement
