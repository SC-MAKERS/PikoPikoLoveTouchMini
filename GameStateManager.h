// GameStateManager.h

#ifndef _GAMESTATEMANAGER_h
#define _GAMESTATEMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IState.h"
#include "GameStateWaitingLoveTouch.h"


class GameStateManagerClass : public IState
{
 protected:
	 IState *current;

 public:
	 GameStateManagerClass();

	// IState ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void Entry() override;
	virtual IState * Do() override;
	virtual void Exit() override;
};

extern GameStateManagerClass GameStateManager;


#endif

