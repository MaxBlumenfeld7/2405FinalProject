#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision__SOLO_CUP = signature (1, 9683, 12451, 11067, -763, -97, -430, 4, 0);
signature Vision__PAPER = signature (2, 2085, 2467, 2276, -1351, -1053, -1202, 1.7, 0);
signature Vision__PINK_PAPER = signature (3, 3873, 4525, 4199, 1647, 2185, 1916, 9.3, 0);
vision Vision = vision (PORT11, 50, Vision__SOLO_CUP, Vision__PAPER, Vision__PINK_PAPER);
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