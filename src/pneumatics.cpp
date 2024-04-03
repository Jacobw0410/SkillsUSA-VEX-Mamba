#include "main.h"
#include "pros/misc.h"
#include "globals.cpp"

bool deployLeftWing = false;
bool deployRightWing = false;

// String launcher control functions
void setWings() {
  if ( controller2.getDigital(ControllerDigital::left) ) {
    if ( deployLeftWing == false || deployRightWing == false ) {
      wing1.set_value(1);
      deployLeftWing = true;
      wing2.set_value(1);
      deployRightWing = true;
      pros::delay(500);
    }
    else {
      wing1.set_value(0);
      deployRightWing = false;
      wing2.set_value(0);
      deployLeftWing = false;
      pros::delay(500);
    }
  }
}