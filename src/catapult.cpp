#include "main.h"
#include "okapi/impl/device/controllerUtil.hpp"
#include "globals.cpp"

// Flywheel TBH loop variables
float current_catapult_rpm = 0.0;
double error = 0.0;
double prev_error = 0.0;
double tbh = 0.0;
float gain = 0.01; //0.01;

// Flywheel control functions
void setCatapultMotor(int speed) {
    // R1 forward, R2 disabled
    // Spins at 10v if blooper disabled, 10.5v if blooper enabled
    Catapult.move_velocity(speed);

}

void catapultLoop() {
    // Get the current RPM of the flywheel
    current_catapult_rpm = Catapult.get_actual_velocity();
    
    // Calculate the error between the current RPM and the target RPM
    error = target_catapult_rpm - current_catapult_rpm;

    catapult_output += gain * error;

    if ( (error > 0 && prev_error < 0) || (error < 0 && prev_error > 0) ) {
        catapult_output = 0.5 * (catapult_output + tbh);
        tbh = catapult_output;
        prev_error = error;
    }
    
    if ( controller1.getDigital(ControllerDigital::R1) ) {
        // Set the flywheel motor speeds based on the catapult_output voltage
        Catapult.move_velocity(catapult_output);
    }
    else {
        current_catapult_rpm = flywheel.get_actual_velocity();
        catapult_output = 0.0;
        tbh = 0.0;
        prev_error = 0.0;
        flywheel.brake();
    }
    pros::lcd::set_text(1, std::to_string(current_catapult_rpm));
}

void resetCatapultTBH() {
    if ( controller1.getDigital(ControllerDigital::Y) ) {
        Catapult.brake();
        double error = 0.0;
        double prev_error = 0.0;
        catapult_output = 0.0;
        double tbh = 0.0;
    }
}

void runCata(int output) {
    if(master.getdigital(ControllerDigital::L1)) {
        Catapult.move_voltage(output);
    }
    else {
        Catapult.brake();

    }
    
}