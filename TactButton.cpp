// 
// 
// 

#include "TactButton.h"

TactButton::TactButton(uint8_t readPin) : ChatteringLoop(50), ChatteringThreshould(10)
{
	this->pin = readPin;
}

void TactButton::update()
{
	int counter = 0;
	for (int i = 0; i < ChatteringLoop; ++i) {
		counter += digitalRead(this->pin);
	}
	this->isTouchState = (ChatteringLoop - counter < ChatteringThreshould);
}

bool TactButton::isTouch()
{
	return this->isTouchState;
}


TactButton Button01(3);
TactButton Button02(4);
TactButton Button03(5);
TactButton Button04(6);
TactButton Button05(7);
TactButton Button06(8);
TactButton Button07(9);
TactButton Button08(10);
TactButton Button09(11);

TactButton ModeButton(13);

const uint8_t ButtonCount = 10;
TactButton*  Buttons[] = { &Button01, &Button02, &Button03, &Button04, &Button05, &Button06, &Button07, &Button08, &Button09, &ModeButton };

