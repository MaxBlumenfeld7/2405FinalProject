#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision__SOLO_CUP = signature (1, 9683, 12451, 11067, -763, -97, -430, 4, 0);
vision Vision = vision (PORT11, 50, Vision__SOLO_CUP);
/*vex-vision-config:end*/
motor ymotor = motor(PORT1, ratio18_1, false);
motor xmotor = motor(PORT2, ratio18_1, true);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}