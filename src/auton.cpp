#include "lemlib/api.hpp"
#include "main.h"
#include "globals.hpp"
#include "drive.hpp"
ASSET(frontpathtest_txt);
ASSET(testpath_txt);
    
ASSET(example_txt)
void close_auton(){
    // path file name is "example.txt".
// "." is replaced with "_" to overcome c++ limitations


    // set chassis pose
    chassis.setPose(0, 0, 0);
    // lookahead distance: 15 inches
    // timeout: 2000 ms
    //chassis.follow(close_txt, 15, 2000);
    //chassis.follow(frontpathtest_txt, 15, 1000);
    //chassis.follow(testpath_txt, 15, 1000);
    // follow the next path, but with the robot going backwards
    //chassis.follow(example2_txt, 15, 2000, false);
   // chassis.setPose(0, 0 , 0);
   // chassis.moveToPose(0, 200, 0, 10000);
   
    leftMotors.move(80);
    rightMotors.move(-80);
    pros::delay(500);


    leftMotors.move(-90);
    rightMotors.move(-90);
    pros::delay(500);
    
    leftMotors.move(10);
    rightMotors.move(-20);
    pros::delay(500);

    leftMotors.move(-20);
    rightMotors.move(-20);
    pros::delay(500);

    leftMotors.move(30);
    rightMotors.move(-30);
    pros::delay(500);

    leftMotors.move(-80);
    rightMotors.move(-80);
    pros::delay(1500);

    leftMotors.move(0);
    rightMotors.move(0);
/*
    pros::delay(1000);
    leftMotors.move(0);
    rightMotors.move(0);
    leftMotors.move(50);
    rightMotors.move(-50);
    pros::delay(500);
    leftMotors.move(0);
    rightMotors.move(0);    

    leftMotors.move(100);
    rightMotors.move(100);
    pros::delay(500);
    leftMotors.move(0);
    rightMotors.move(0);

    leftMotors.move(-100);
    rightMotors.move(100);
    pros::delay(100);
    leftMotors.move(0);
    rightMotors.move(0);

    leftMotors.move(100);
    rightMotors.move(100);
    pros::delay(300);
    leftMotors.move(0);
    rightMotors.move(0);
*/
    
    

    
}


void far_auton(){

    //Close auton code
}

