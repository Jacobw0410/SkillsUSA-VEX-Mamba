#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"

// Variables
double catapult_output = 127.0;
float target_catapult_rpm =130.0;

// Controllers
okapi::Controller master(ControllerId::master);

//Motors
pros::Motor Catapult_1(15, false, MOTOR_GEAR_RED);
pros::Motor Catapult_2(18, true, MOTOR_GEAR_RED);

// Motor Groups
pros::Motor_Group Catapult({Catapult_1, Catapult_2});

// ADI Digital Outs
pros::ADIDigitalOut wing1('A', false);
pros::ADIDigitalOut wing2('B', false);

// Inertial Sensor
pros::Imu imu(8);
pros::Imu imu2(21);


