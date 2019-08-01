// AccessoriesState02.h

#ifndef _ACCESSORIESSTATE02_h
#define _ACCESSORIESSTATE02_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IState.h"
#include "LedStrip.h"

class AccessoriesState02Class : public IState
{
 protected:
	 int offset;

 public:

	 AccessoriesState02Class();

	// IState ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void Entry() override;
	virtual IState * Do() override;
	virtual void Exit() override;
};

extern AccessoriesState02Class AccessoriesState02;

#endif

