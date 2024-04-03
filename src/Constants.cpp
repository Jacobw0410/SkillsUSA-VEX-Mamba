
// //Auton constants
// const CatapultSpeed = 127
// const PistonSpeed = 127
// const PistonDelay = 1000
// const DriveSpeed = 127
// const TurnSpeed = 127
// const SwingSpeed = 127
// const SwingAngle = 45
// const Attempts = 3
// const DriveDistance = 24
// const TurnAngle = 45
// const SwingAngle2 = -45


// //Drivetrain ports
// const lFront = 1
// const lMiddle = 3
// const lBack = 3
// const rFront = 4
// const rMiddle = 5
// const rBack = 6
// const imuPort = 8
// const imuPort2 = 9

// //Vision ports
// const VisionPort1 = 13
// const VisionPort2 = 14


// //Pneumatics ports 
// const LeftWing = "A"
// const RightWing = "B"

// //Catapult ports
// const Catapult1 = 17
// const Catapult2 = -18

// //Sensors ports
// const LimitSwitch = 'C'
// const LimitSwitch2 = 'D'

// const Bummper = 'E'
// const Bummper2 = 'F'

// const DistanceSensor = 21
// const DistanceSensor2 = 22

// //autons
// const Autons = [
//   {
//     name: "Combine all 3 movements",
//     code: function() {
//       chassis.pid_drive_set(DriveDistance, DriveSpeed, true)
//       chassis.pid_wait()

//       chassis.pid_turn_set(TurnAngle, TurnSpeed)
//       chassis.pid_wait()

//       chassis.pid_swing_set(ez.RIGHT_SWING, SwingAngle2, SwingSpeed, SwingAngle)
//       chassis.pid_wait()

//       chassis.pid_turn_set(0, TurnSpeed)
//       chassis.pid_wait()

//       chassis.pid_drive_set(-DriveDistance, DriveSpeed, true)
//       chassis.pid_wait()
//     }
//   },
//   {
//     name: "Interference\n\nAfter driving forward, robot performs differently if interfered or not.",
//     code: function() {
//       chassis.pid_drive_set(DriveDistance, DriveSpeed, true)
//       chassis.pid_wait()

//       if (chassis.interfered) {
//         tug(Attempts)
//         return
//       }

//       chassis.pid_turn_set(90, TurnSpeed)
//       chassis.pid_wait()
//     }
//   }
// ]



// const Constants = {
//   CatapultSpeed,
//   PistonSpeed,
//   PistonDelay,
//   DriveSpeed,
//   TurnSpeed,
//   SwingSpeed,
//   SwingAngle,
//   Attempts,
//   DriveDistance,
//   TurnAngle,
//   SwingAngle2,
//   Autons
// }

