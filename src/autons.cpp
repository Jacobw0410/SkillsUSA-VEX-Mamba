#include "main.h"

/////
// For installation, upgrading, documentations and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int chassiss_SPEED = 110;  
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  chassiss.pid_heading_constants_set(3, 0, 20);
  chassiss.pid_chassiss_constants_set(10, 0, 100);
  chassiss.pid_turn_constants_set(3, 0, 20);
  chassiss.pid_swing_constants_set(5, 0, 30);

  chassiss.pid_turn_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassiss.pid_swing_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassiss.pid_chassiss_exit_condition_set(300_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

  chassiss.slew_chassiss_constants_set(7_in, 80);
}


///
// chassiss Example
///
void chassiss_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will chassiss at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of chassiss motions
  // for slew, only enable it when the chassiss distance is greater then the slew distance + a few inches

  
}

///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will chassiss at

  chassiss.pid_turn_set(90_deg, TURN_SPEED);
  chassiss.pid_wait();

  chassiss.pid_turn_set(45_deg, TURN_SPEED);
  chassiss.pid_wait();

  chassiss.pid_turn_set(0_deg, TURN_SPEED);
  chassiss.pid_wait();
}

///
// Combining Turn + chassiss
///
void chassiss_and_turn() {
  chassiss.pid_chassiss_set(24_in, chassiss_SPEED, true);
  chassiss.pid_wait();

  chassiss.pid_turn_set(45_deg, TURN_SPEED);
  chassiss.pid_wait();

  chassiss.pid_turn_set(-45_deg, TURN_SPEED);
  chassiss.pid_wait();

  chassiss.pid_turn_set(0_deg, TURN_SPEED);
  chassiss.pid_wait();

  chassiss.pid_chassiss_set(-24_in, chassiss_SPEED, true);
  chassiss.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 30
  chassiss.pid_chassis_set(24_in, chassiss_SPEED, true);
  chassiss.pid_wait_until(6_in);
  chassiss.pid_speed_max_set(30);  // After driving 6 inches at chassiss_SPEED, the robot will go the remaining distance at 30 speed
  chassiss.pid_wait();

  chassiss.pid_turn_set(45_deg, TURN_SPEED);
  chassiss.pid_wait();

  chassiss.pid_turn_set(-45_deg, TURN_SPEED);
  chassiss.pid_wait();

  chassiss.pid_turn_set(0_deg, TURN_SPEED);
  chassiss.pid_wait();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 30
  chassiss.pid_chassiss_set(-24_in, chassiss_SPEED, true);
  chassiss.pid_wait_until(-6_in);
  chassiss.pid_speed_max_set(30);  // After driving 6 inches at chassiss_SPEED, the robot will go the remaining distance at 30 speed
  chassiss.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the chassiss
  // The fourth parameter is the speed of the still side of the chassiss, this allows for wider arcs

  chassiss.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassiss.pid_wait();

  chassiss.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassiss.pid_wait();

  chassiss.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassiss.pid_wait();

  chassiss.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassiss.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassiss.pid_chassiss_set(24_in, chassiss_SPEED, true);
  chassiss.pid_wait();

  chassiss.pid_turn_set(45_deg, TURN_SPEED);
  chassiss.pid_wait();

  chassiss.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassiss.pid_wait();

  chassiss.pid_turn_set(0_deg, TURN_SPEED);
  chassiss.pid_wait();

  chassiss.pid_chassiss_set(-24_in, chassiss_SPEED, true);
  chassiss.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to chassiss backwards
    printf("i - %i", i);
    chassiss.pid_chassiss_set(-12_in, 127);
    chassiss.pid_wait();

    // If failsafed...
    if (chassiss.interfered) {
      chassiss.chassiss_sensor_reset();
      chassiss.pid_chassiss_set(-2_in, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will chassiss forward and turn 90 degrees.
// If interfered, robot will chassiss forward and then attempt to chassiss backwards.
void interfered_example() {
  chassiss.pid_chassiss_set(24_in, chassiss_SPEED, true);
  chassiss.pid_wait();

  if (chassiss.interfered) {
    tug(3);
    return;
  }

  chassiss.pid_turn_set(90_deg, TURN_SPEED);
  chassiss.pid_wait();
}

// . . .
// Make your own autonomous functions here!
// . . .