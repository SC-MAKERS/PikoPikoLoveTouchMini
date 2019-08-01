// IState.h

#ifndef _ISTATE_h
#define _ISTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Timer.h"

class IState
{
 protected:
	 Timer timer;

 public:
	IState();
	 virtual ~IState();

	virtual void Entry() = 0;
	virtual IState* Do() = 0;
	virtual void Exit() = 0;
};



#endif

