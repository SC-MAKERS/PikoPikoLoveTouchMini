// AccessoriesState01.h

#ifndef _ACCESSORIESSTATE01_h
#define _ACCESSORIESSTATE01_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IState.h"

#include "LedStrip.h"
#include "Buzzer.h"
#include "TactButton.h"

class AccessoriesState01Class : public IState
{
 protected:
	 int index;

 public:
	 AccessoriesState01Class();
	 ~AccessoriesState01Class();


	 // IState ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	  void Entry() override;

	  IState* Do() override;

	  void Exit() override;

};

extern AccessoriesState01Class AccessoriesState01;

#endif

