// GameStateWaitingLoveTouch.h

#ifndef _GAMESTATEWAITINGLOVETOUCH_h
#define _GAMESTATEWAITINGLOVETOUCH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IState.h"
#include "TactButton.h"
#include "LedStrip.h"
#include "Buzzer.h"
#include "GameStatePlaying.h"


class GameStateWaitingLoveTouchClass : public IState
{
 protected:
	 bool cornerPushed[4] = { false };
	 bool crossPushed[4] = { false };
	 int crossPushCounter;
	 int mutePushCounter;

	 byte offset;

 public:
	 GameStateWaitingLoveTouchClass();

	// IState ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void Entry() override;
	virtual IState * Do() override;
	virtual void Exit() override;

	bool checkHardMode();
};

extern GameStateWaitingLoveTouchClass GameStateWaitingLoveTouch;

#endif

