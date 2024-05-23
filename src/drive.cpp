#include "lemlib/api.hpp"
#include "main.h"
#include "globals.hpp"
#include "drive.hpp"
#include "lemlib/chassis/chassis.hpp"


// Code for chassis
void drive(){

	while(true){
		int dir = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y); 
		int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		chassis.curvature(dir, turn);

		pros::delay(25);

	}

}

// Code for roller movement 
void roller(){


}


// Code for slama
void slama(){

    
}