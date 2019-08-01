// EventHandler.h

#ifndef _EVENTHANDLER_h
#define _EVENTHANDLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EventInvoker {

};

class EventHandler
{
 public:
	virtual void action(const EventInvoker& sender) = 0;
};



#endif

