//Code for the shoooter. Trimmed down to only ahve the stuff for the shooter.

#include "WPIlib.h"
#define PORT_JS_OPERATOR 3 //port for the operator joystick
#define PORT_SHOOTER_VIC_1 3 //port for one shooter motor
#define PORT_SHOOTER_VIC_2 4 //port for the other shooter motor
#define SHOOT_SPEED 0.5 //speed for shooter motors
#define PORT_COMPRESSOR 1 //port for the compressor
#define SPIN_WAIT 5000 //how long to wait while spinning up to speed

//labels the states with more useable names
enum {
  IDLE,
  SPIN_UP,
  EXTENDING,
  RECEDING
} shooterState;

class MyRobot : public IterativeRobot {

Joystick operatorStick;
Victor 

//initialization list
public:
MyRobot() :
  operatorStick(PORT_JS_OPERATOR)
{

}
//sets up the different iterative robot methods
  void AutonomousInit();
  void AutonomousPeriodic();
  void AutonomousDisabled();
  void TeleopInit();
  void TeleopPeriodic();
  void TeleopDisabled();
};

void MyRobot::AutonomousInit()
{
  
}

void MyRobot::AutonomousPeriodic()
{
  
}

void MyRobot::AutonomousDisabled()
{
  
}

void MyRobot::TeleopInit() 
{

}

void MyRobot::TeleopPeriodic()
{
  if(shooterState == IDLE){
    //if trigger pressed, change to SPIN_UP
    if(operatorStick.GetTrigger()){
      shooterState = SPIN_UP
    }
  }
  
  else if(shooterState == SPIN_UP){
    //if max speed reached, change to EXTENDING
     
  }
  
  else if(shooterState == EXTENDING){
    //if frisbee shot, change to RECEDING
    
  }
  
  else if(shooterState == RECEDING){
    //if piston receeded, change to IDLE
    
  }
}

void MyRobot::TeleopDisabled() 
{
  
}
