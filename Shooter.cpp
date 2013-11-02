//Code for the shoooter. Trimmed down to only have the stuff for the shooter.

#include "WPIlib.h"
#define PORT_JS_OPERATOR 3 //port for the operator joystick
#define PORT_SHOOTER_VIC_1 3 //port for one shooter motor
#define PORT_SHOOTER_VIC_2 4 //port for the other shooter motor
#define PORT_PISTON
#define PORT_COMPRESSOR_RELAY 1 //port for the compressor relay
#define PORT_COMPRESSOR_CUTOFF 1 //port for the compressor cutoff
#define PORT_SHOOTER_SOL 5 //solenoid port
#define SHOOTER_SPIN_WAIT 5.0 //how long to wait while spinning up to speed
#define SHOOTER_EXTEND_WAIT 5.0 //how long to wait while extending
#define SHOOTER_RETRACT_WAIT 6.0 //hgow long to wait while rectracting


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
    //turn everything off
    shooterVic1.Set(0.0);
    shooterVic2.Set(0.0);
    shooterSol.Set(false);
    
    //if trigger pressed, change to SPIN_UP
    if(operatorStick.GetTrigger())
    {
      shooterState = SPIN_UP;
      //restarts timer (just in case) for usage
      shooterTimer.Reset();
      shooterTimer.Start();
    }
  }
  
  else if(shooterState == SPIN_UP)
  {
    //start accelerating to max speed
    shooterVic1.Set(1.0);
    shooterVic2.Set(1.0);
    shooterSol.Set(false);
    
    //if max speed reached(hoperfully), change to EXTENDING
    if(shooterTimer.Get()>=SHOOTER_SPIN_WAIT)
    {
      shooterState = EXTENDING;
      //restarts the timer to be used for how long it takes to extend
      shooterTimer.Reset();
      shooterTimer.Start();
    }
  }
  else if(shooterState == EXTENDING)
  {
    shooterVic1.Set(1.0);
    shooterVic2.Set(1.0);
    shooterSol.Set(true);

    //if frisbee shot(guesseed based on timer, change to RECEDING
    if(shooterTimer>=SHOOTER_EXTEND_WAIT)
    {
      shooterState = RETRACTING;
      shooterTimer.Reset();
      shooterTimer.Start();
    }
  }
  
  else if(shooterState == RETRACTING)
  {
    //the shooter vics remain at maximum speed, because it saves energy if shooting rapidly
    shooterVic1.Set(1.0);
    shooterVic2.Set(1.0);
    shooterSol.Set(false);
    //if piston retracted(guess based on time), change to IDLE
    if(shooterTimer>=SHOOTER_RETRACT_WAIT)
    {
      shooterState=IDLE;
      shooterTimer.Stop();
    }
  }
}

void MyRobot::TeleopDisabled() 
{
  
}
