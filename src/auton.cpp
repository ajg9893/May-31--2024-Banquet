#include "lemlib/api.hpp"
#include "main.h"
#include "globals.hpp"
#include "drive.hpp"
ASSET(close_txt);

    
//ASSET(example2_txt)
void close_auton(){
    // path file name is "example.txt".
// "." is replaced with "_" to overcome c++ limitations


    // set chassis pose
    chassis.setPose(0, 0, 0);
    // lookahead distance: 15 inches
    // timeout: 2000 ms
    chassis.follow(close_txt, 15, 2000);
    // follow the next path, but with the robot going backwards
    //chassis.follow(example2_txt, 15, 2000, false);
}


void far_auton(){

    //Close auton code
}

