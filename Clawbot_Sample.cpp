/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       robol                                                     */
/*    Created:      8/25/2024, 2:31:56 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

controller Controller1 = controller(primary);

brain Brain;

motor LeftDrive = motor(PORT18, ratio18_1,true);
motor RightDrive = motor(PORT19, ratio18_1, false);
motor Arm = motor(PORT2, ratio18_1, true);
motor Claw = motor(PORT1, ratio18_1, false);

drivetrain Drivetrain = drivetrain(LeftDrive, RightDrive,320, 320, 320,mm,1);



// Functions

void when_controller_button_L1_pressed() {

    Arm.spin(reverse);
    while(Controller1.ButtonL1.pressing()) {

        wait(5, msec);
    }

    Arm.stop(hold);
}
void when_controller_button_L2_pressed() {

    Arm.spin(forward);
    while(Controller1.ButtonL2.pressing()) {

        wait(5, msec);
    }

    Arm.stop(hold);
}
void when_controller_button_R1_pressed() {

    Claw.spin(reverse);
    while(Controller1.ButtonR1.pressing()) {

        wait(5, msec);
    }

    Claw.stop(hold);
}
void when_controller_button_R2_pressed() {

    Claw.spin(forward);
    while(Controller1.ButtonR2.pressing()) {

        wait(5, msec);
    }

    Claw.stop(hold);
}

// void Autonomous() {

//     Drivetrain.driveFor(15, inches);



// }
// A global instance of vex::brain used for printing to the V5 brain screen


// define your global instances of motors and other devices here


int main() {

    // competition competition;
    // competition.autonomous(Autonomous)
    
    Claw.spinFor(fwd,170,degrees);
    Drivetrain.driveFor(79,inches);
    wait(2,sec);
    Claw.spinFor(reverse,150,degrees);
    

//Autonomous();

    Controller1.ButtonL1.pressed(when_controller_button_L1_pressed);
    Controller1.ButtonL2.pressed(when_controller_button_L2_pressed);

    Controller1.ButtonR1.pressed(when_controller_button_R1_pressed);
    Controller1.ButtonR2.pressed(when_controller_button_R2_pressed);
  
    while(true) {

        
        LeftDrive.spin(forward,Controller1.Axis3.position()*.5, percent);
        RightDrive.spin(forward,Controller1.Axis2.position()*.5, percent);
        
        wait(5, msec);
        
 
    }

    
}


