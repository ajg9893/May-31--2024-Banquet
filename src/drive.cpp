#include "lemlib/api.hpp"
#include "main.h"
#include "globals.hpp"
#include "drive.hpp"
#include "lemlib/chassis/chassis.hpp"

bool slamaOn = false;
bool wingsOut = false;

// Code for chassis
void drive(){


	
    int dir = -1*controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y); 
    int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    chassis.curvature(dir, turn);

    pros::delay(25);

	

}


// Code for roller movement 
void roller(){
    
    // Sets the roller on based on controller input    
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
    {
        rollerMotors.move(127);
    } 
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
    {
        rollerMotors.move(-127);
    } 
    else{
        rollerMotors.move(0);
    }

}


// Code for wings
void wings(){

    // Toggle Wings Based on Controller Input
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) 
    {
        wingsOut = !wingsOut;
        pros::delay(50);
    }
    // Set Wings Value Based on Toggled State
    if(wingsOut) 
    {
        wing_s.set_value(1);
    } 
    else 
    {
        wing_s.set_value(0);
    }
}


// Code for slama
void slama(){

    // Sets the slama on based on controller input
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
    {
        slamaOn = !slamaOn;
        pros::delay(50);
    }
    // Set Catapult Voltage Based on Toggled State
    if (slamaOn)
    {
        slamaMotors.move(127);
    } 
    else
    {
        slamaMotors.move(0);
    }    

}