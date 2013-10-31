#include "WPIlib.h"
#define PORT_DRIVE_VIC_1 5 //macro substitutes first part with second whenever first is used
#define PORT_DRIVE_VIC_2 10
#define PORT_DRIVE_VIC_3 2
#define PORT_DRIVE_VIC_4 1
#define PORT_JS_SPEED 1
#define PORT_JS_TURN 2
#define PORT_JS_OPERATOR 3

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
  rightVic2(PORT_DRIVE_VIC_4),
  speedStick(PORT_JS_SPEED),
  turnStick(PORT_JS_TURN),
  operatorStick(PORT_JS_OPERATOR)
{

}
  void AutonomousInit();
  void AutonomousPeriodic();
  void AutonomousDisabled();
  void TeleopInit();
  void TeleopPeriodic();
  void TeleopDisabled();
};

