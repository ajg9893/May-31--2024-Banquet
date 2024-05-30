#include "lemlib/api.hpp"
#include "main.h"
#include "globals.hpp"
#include "drive.hpp"
#include "lemlib/chassis/chassis.hpp"



/* 
 * Initialize each motor
 * L designates Left side
 * R designates right side
 * 
*/

// Leftside Motors
pros::Motor front_L(18, pros::v5::MotorGears::rpm_600, pros::v5::MotorUnits::counts);
pros::Motor mid_L(19, pros::v5::MotorGears::rpm_200, pros::v5::MotorUnits::counts);
pros::Motor back_L(20, pros::v5::MotorGears::rpm_600, pros::v5::MotorUnits::counts);

// Rightside Motors
pros::Motor front_R(13, pros::v5::MotorGears::rpm_600, pros::v5::MotorUnits::counts);
pros::Motor mid_R(12, pros::v5::MotorGears::rpm_200, pros::v5::MotorUnits::counts);
pros::Motor back_R(11, pros::v5::MotorGears::rpm_600, pros::v5::MotorUnits::counts);

// Slama Motors
pros::Motor slama_L(16, pros::v5::MotorGears::rpm_100, pros::v5::MotorUnits::counts);
pros::Motor slama_R(15, pros::v5::MotorGears::rpm_100, pros::v5::MotorUnits::counts);

// Roller Motors
pros::Motor roller_L(2, pros::v5::MotorGears::rpm_200, pros::v5::MotorUnits::counts);
pros::Motor roller_R(1, pros::v5::MotorGears::rpm_200, pros::v5::MotorUnits::counts);

// Motor Groups
pros::MotorGroup leftMotors({18, -19, 20});
pros::MotorGroup rightMotors({-13, 12, -11});
pros::MotorGroup slamaMotors({-14, 15});
pros::MotorGroup rollerMotors({-2, 1});

// Wings
pros::ADIDigitalOut wing_s('A');

// Inertial sensor
pros::Imu imu(14);

// Drivetrain
lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              10, // 10 inch track width
                              lemlib::Omniwheel::OLD_325, // using old 3.25" omni
                              360, // drivetrain rpm is 360
                              2 // horizontal drift 
);





// Odom Sensors
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1, set to nullptr as we don't have a first one
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);



// Lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// Angular PID controller
lemlib::ControllerSettings angular_controller(17, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              9.5, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);



// Initialize chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);


// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);