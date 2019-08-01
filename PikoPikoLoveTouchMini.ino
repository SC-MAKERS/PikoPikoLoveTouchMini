// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       PikoPikoLoveTouchMini.ino
    Created:	2019/07/07 4:00:54
    Author:     sorikomi-PC\sorikomi
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts

#include "AccessoriesState02.h"
#include "AccessoriesStateManager.h"
#include "GameStateResult.h"
#include "GameData.h"
#include "GameStatePlaying.h"
#include "IState.h"

#include <Adafruit_NeoPixel.h>
#include "LedStrip.h"
#include "Buzzer.h"
#include "Timer.h"
#include "EventHandler.h"
#include "TactButton.h"
#include "TouchPanel.h"

#include "GameStateManager.h"
#include "GameStateWaitingLoveTouch.h"
#include "AccessoriesState01.h"

Timer SensorTimer, LedTimer;

IState *modeStates[] = { &GameStateManager, &AccessoriesStateManager };
int modeStatesCount;
int modeIndex = 0;

IState *currentState = 0;

void setup()
{
	Serial.begin(9600);
	randomSeed(analogRead(0));

	LoveLedStrip.setup();
	SensorTimer.start();
	LedTimer.start();

	modeStatesCount = sizeof(modeStates) / sizeof(modeStates[0]);
	currentState = modeStates[modeIndex];

	currentState->Entry();
}

// Add the main program code into the continuous loop() function
void loop()
{
	if (SensorTimer.isElapse(80)){
		for (int i = 0; i < ButtonCount; ++i) {
			Buttons[i]->update();
		}
		SensorTimer.start();
	}

	if (ModeButton.isTouch()) {
		Buzzer.sound(eTone::M01_Do, 0, 10);

		currentState->Exit();
		modeIndex = (modeIndex + 1) % modeStatesCount;
		currentState = modeStates[modeIndex];
		currentState->Entry();

		delay(500);
	}

	IState *next = currentState->Do();
	if (next != currentState) {
		currentState->Exit();
		next->Entry();
		currentState = next;
	}

}
