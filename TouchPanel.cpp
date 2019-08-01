// 
// 
// 

#include "TouchPanel.h"

TouchPanel::TouchPanel(TactButton & button, PiezoelectricBuzzer & buzzer, LedStrip & led, uint8_t ledIndex)
	: led(led), button(button), buzzer(buzzer), ledIndex(ledIndex)
{
}

void TouchPanel::init()
{


}


TouchPanel TouchPanel01(Button01, Buzzer, LoveLedStrip, 0);
TouchPanel TouchPanel02(Button02, Buzzer, LoveLedStrip, 1);
TouchPanel TouchPanel03(Button03, Buzzer, LoveLedStrip, 2);
TouchPanel TouchPanel04(Button04, Buzzer, LoveLedStrip, 3);
TouchPanel TouchPanel05(Button05, Buzzer, LoveLedStrip, 4);
TouchPanel TouchPanel06(Button06, Buzzer, LoveLedStrip, 5);
TouchPanel TouchPanel07(Button07, Buzzer, LoveLedStrip, 6);
TouchPanel TouchPanel08(Button08, Buzzer, LoveLedStrip, 7);
TouchPanel TouchPanel09(Button09, Buzzer, LoveLedStrip, 8);

const uint8_t TouchPanelCount = 9U;
TouchPanel *TouchPanels[] = { &TouchPanel01,&TouchPanel02,&TouchPanel03,&TouchPanel04,&TouchPanel05,&TouchPanel06,&TouchPanel07,&TouchPanel08,&TouchPanel09 };

