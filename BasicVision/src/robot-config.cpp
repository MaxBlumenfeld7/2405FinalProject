#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision__SOLO_CUP = signature (1, 11701, 12289, 11996, -1171, -589, -880, 3, 0);
signature Vision__PAPER = signature (2, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision__PINK_PAPER = signature (3, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision__PURPLE1 = signature (4, 615, 911, 763, 8655, 9363, 9009, 11, 0);
vision Vision = vision (PORT11, 50, Vision__SOLO_CUP, Vision__PAPER, Vision__PINK_PAPER, Vision__PURPLE1);
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