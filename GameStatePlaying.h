// GameStatePlaying.h

#ifndef _GAMESTATEPLAYING_h
#define _GAMESTATEPLAYING_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IState.h"
#include "TactButton.h"
#include "Buzzer.h"
#include "GameData.h"
#include "LedStrip.h"

#include "GameStateResult.h"

class GameStatePlayingClass : public IState
{
 protected:
	 const byte PanelCount;
	 byte touching[9];
	 byte touched[9];

	 bool waitingForTouching;
	 byte touchingCount;

	 Timer gameTimer;

	 void shuffle();

 public:
	 GameStatePlayingClass();

	 // IState ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	 virtual void Entry() override;

	 virtual IState * Do() override;

	 virtual void Exit() override;

};

extern GameStatePlayingClass GameStatePlaying;

#endif

