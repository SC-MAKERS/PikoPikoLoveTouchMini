// GameData.h

#ifndef _GAMEDATA_h
#define _GAMEDATA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class GameDataClass
{
 protected:


 public:
	 GameDataClass();

	 uint8_t	GameLevel;
	 uint8_t	TouchCount;
};

extern GameDataClass GameData;

#endif

