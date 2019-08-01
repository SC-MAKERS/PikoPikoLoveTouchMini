// GameStateResult.h

#ifndef _GAMESTATERESULT_h
#define _GAMESTATERESULT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IState.h"
#include "GameData.h"
#include "LedStrip.h"
#include "GameStateWaitingLoveTouch.h"

class GameStateResultClass : public IState
{
 protected:
	 int timeCount;
	 int index;

 public:
	 GameStateResultClass();

	 // IState ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	 virtual void Entry() override;

	 virtual IState * Do() override;

	 virtual void Exit() override;

};

extern GameStateResultClass GameStateResult;

#endif

