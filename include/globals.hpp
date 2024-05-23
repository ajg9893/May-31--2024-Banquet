#include "main.h"
#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"


// Right and Left side drive motors
extern pros::Motor front_L;
extern pros::Motor mid_M;
extern pros::Motor back_B;

extern pros::Motor front_R;
extern pros::Motor mid_R;
extern pros::Motor back_R;

// Slama motors
extern pros::Motor slama_L;
extern pros::Motor slama_R;

// Roller motors

extern pros::Motor roller_L;
extern pros::Motor roller_R;

// Motor Groups
extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;
extern pros::MotorGroup slamaMotors;
extern pros::MotorGroup rollerMotors;

// Wings
extern pros::ADIDigitalOut wing_s;

//Drivetrain
extern lemlib::Drivetrain drivetrain;



//Inertial sensor
extern pros::Imu imu;

//Odomsensors
extern lemlib::OdomSensors sensors;



// Lateral PID controller
extern lemlib::ControllerSettings lateral_controller;

//Angular PID controller
extern lemlib::ControllerSettings angular_controller;

//Chassis
extern lemlib::Chassis chassis;


//Controller
extern pros::Controller controller;