//Code for the shoooter. Trimmed down to only have the stuff for the shooter.

#include "WPIlib.h"
#define PORT_JS_OPERATOR 3 //port for the operator joystick
#define PORT_SHOOTER_VIC_1 3 //port for one shooter motor
#define PORT_SHOOTER_VIC_2 4 //port for the other shooter motor
#define PORT_PISTON
#define PORT_COMPRESSOR_RELAY 1 //port for the compressor relay
#define PORT_COMPRESSOR_CUTOFF 1 //port for the compressor cutoff
#define SPIN_WAIT 5000 //how long to wait while spinning up to speed
#define SHOOT_SPEED 0.5 //speed for shooter motors


//labels the states with more useable names
enum {
  IDLE,
  SPIN_UP,
  EXTENDING,
  RECEDING
} shooterState;

class MyRobot : public IterativeRobot {

Joystick operatorStick;
Victor shootVic1;
Victor shootVic2;
Solenoid shooterSol;

//initialization list (constructor)
public:
MyRobot() :
  operatorStick(PORT_JS_OPERATOR),
  shootVic1(PORT_SHOOTER_VIC_1),
  shootVic2(PORT_SHOOTER_VIC_2)
  
{

}
//sets up the different iterative robot methods
  void AutonomousInit();
  void AutonomousPeriodic();
  void AutonomousDisabled();
  void TeleopInit();
  void TeleopPeriodic();
  void TeleopDisabled();
//sets up robot init method
  void RobotInit();
};

void MyRobot::RobotInit() 
{
  Compressor *c = new Compressor(PORT_COMPRESSOR_CUTOFF, PORT_COMPRESSOR_RELAY);
  c->Start();
}

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
  if(shooterState == IDLE)
  {
    //if trigger pressed, change to SPIN_UP
    if(operatorStick.GetTrigger())
    {
      shooterState = SPIN_UP
    }
  }
  
  else if(shooterState == SPIN_UP)
  {
    //if max speed reached, change to EXTENDING
     
  }
  
  else if(shooterState == EXTENDING)
  {
    //if frisbee shot, change to RECEDING
    
  }
  
  else if(shooterState == RECEDING)
  {
    //if piston receeded, change to IDLE
    
  }
}

void MyRobot::TeleopDisabled() 
{
  
}
