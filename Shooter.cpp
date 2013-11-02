//Code for the shoooter. Trimmed down to only have the stuff for the shooter.

#include "WPIlib.h"
#define PORT_JS_OPERATOR 3 //port for the operator joystick
#define PORT_SHOOTER_VIC_1 3 //port for one shooter motor
#define PORT_SHOOTER_VIC_2 4 //port for the other shooter motor
#define PORT_PISTON
#define PORT_COMPRESSOR_RELAY 1 //port for the compressor relay
#define PORT_COMPRESSOR_CUTOFF 1 //port for the compressor cutoff
#define PORT_SHOOTER_SOL 5 //solenoid port
#define SPIN_WAIT 5 //how long to wait while spinning up to speed


//labels the states with more useable names
enum {
  IDLE,
  SPIN_UP,
  EXTENDING,
  RECEDING
} shooterState;

class MyRobot : public IterativeRobot {

Joystick operatorStick;
Victor shooterVic1;
Victor shooterVic2;
Solenoid shooterSol;
Timer shooterTimer;

//initialization list (constructor)
public:
MyRobot() :
  operatorStick(PORT_JS_OPERATOR),
  shooterVic1(PORT_SHOOTER_VIC_1),
  shooterVic2(PORT_SHOOTER_VIC_2),
  shooterSol(PORT_SHOOTER_SOL)
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
    shooterVic1.Set(0.0);
    shooterVic2.Set(0.0);
    shooterSol.Set(false);
    //if trigger pressed, change to SPIN_UP
    if(operatorStick.GetTrigger())
    {
      shooterState = SPIN_UP;
      shooterTimer.Reset();
      shooterTimer.Start();
    }
  }
  
  else if(shooterState == SPIN_UP)
  {
    shooterVic1.Set(1.0);
    shooterVic2.Set(1.0);
    shooterSol.Set(false);
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
