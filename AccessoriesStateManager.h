// AccessoriesStateManager.h

#ifndef _ACCESSORIESSTATEMANAGER_h
#define _ACCESSORIESSTATEMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IState.h"
#include "TactButton.h"
#include "Buzzer.h"
#include "AccessoriesState01.h"
#include "AccessoriesState02.h"

class AccessoriesStateManagerClass : public IState
{
 protected:
	 IState *states[5];
	 byte stateCount;

	 IState *current;
	 byte index;

 public:
	 AccessoriesStateManagerClass();

	// IState ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void Entry() override;
	virtual IState * Do() override;
	virtual void Exit() override;
};

extern AccessoriesStateManagerClass AccessoriesStateManager;

#endif

