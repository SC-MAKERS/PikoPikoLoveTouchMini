// TouchPanel.h

#ifndef _TOUCHPANEL_h
#define _TOUCHPANEL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "LedStrip.h"
#include "Buzzer.h"
#include "Timer.h"
#include "TactButton.h"

class TouchPanel
{
protected:
	TactButton&				button;
	LedStrip&				led;
	PiezoelectricBuzzer&	buzzer;
	uint8_t					ledIndex;

public:
	TouchPanel(TactButton& button, PiezoelectricBuzzer& buzzer, LedStrip& led, uint8_t ledIndex);

	void init();
};

extern TouchPanel TouchPanel01;
extern TouchPanel TouchPanel02;
extern TouchPanel TouchPanel03;
extern TouchPanel TouchPanel04;
extern TouchPanel TouchPanel05;
extern TouchPanel TouchPanel06;
extern TouchPanel TouchPanel07;
extern TouchPanel TouchPanel08;
extern TouchPanel TouchPanel09;

extern const uint8_t TouchPanelCount;
extern TouchPanel *TouchPanels[];

#endif

