/*
Autonomous mode is to check Dead Reckoning, before going into joystick mode

Autonomous: Rotates 90 degrees left, then right, like calibration

*/
#include "WPIlib.h"
#define PORT_DRIVE_VIC_1 5 //macro substitutes first part with second whenever first is used
#define PORT_DRIVE_VIC_2 10
#define PORT_DRIVE_VIC_3 2
#define PORT_DRIVE_VIC_4 1
#define PORT_JS_1 1
#define PORT_JS_2 2
#define PORT_JS_3 3

//sets up 
class MyRobot : public IterativeRobot {

Victor leftVic1;
Victor leftVic2;
Victor rightVic1;
Victor rightVic2;
Timer t;
Joystick speedStick;
Joystick turnStick;
Joystick operatorStick;

public:
MyRobot() :
  leftVic1(PORT_DRIVE_VIC_1),
  leftVic2(PORT_DRIVE_VIC_2), //initialization list (saves memory by using this format)
  rightVic1(PORT_DRIVE_VIC_3),
  rightVic2(PORT_DRIVE_VIC_4)
{

}


void AutonomousInit() {
t.Start(); //start the timer
}

void AutonomousPeriodic(){
  
  if(t.Get() < 2.0) { //during the first 2 seconds, turn right
  leftVic1.Set(0.5);
  leftVic2.Set(0.5);
  rightVic1.Set(0);
  rightVic2.Set(0);
  }
  
  else if(t.Get() < 4.0) { //during next 2 seconds (2-->4), turn left
  leftVic1.Set(0);
  leftVic2.Set(0);
  rightVic1.Set(0.5);
  rightVic2.Set(0.5);
  }
}

void AutonomousDisabled(){
  //set all speeds to zero after Autonomous ends
  leftVic1.Set(0);
  leftVic2.Set(0);
  rightVic1.Set(0);
  rightVic2.Set(0);

}

void TeleopInit() {

}

void TeleopPeriodic() {
  //Joystick.GetY() returns value b/w -1 and 1
    
    //takes the input from the joysticks and multiplies it by a constant
    float speed = 1.0 * speedStick.GetY(); 
    float turn = 1.0 * turnStick.GetX(); 
    float input = speed - turn;

    leftVic1.Set(-input);
    leftVic2.Set(-input);
    rightVic1.Set(input);
    rightVic2.Set(input);

}

void TeleopDisabled() {
  leftVic1.Set(0);
  leftVic2.Set(0);
  rightVic1.Set(0);
  rightVic2.Set(0);
}
