// 
// 
// 

#include "GameStateResult.h"



GameStateResultClass GameStateResult;

GameStateResultClass::GameStateResultClass() : timeCount(0), index(0)
{
}

void GameStateResultClass::Entry()
{
	this->timer.start();
	this->timeCount = 0;
	//GameData.TouchCount = 21;
}

IState * GameStateResultClass::Do()
{
	int panels[] = { 8, 7,6,1,2,3,4,9,8,7,6 };

	if (this->timeCount > 150) {
		LoveLedStrip.clear();
		LoveLedStrip.show();
		delay(1000);
		return &GameStateWaitingLoveTouch;
	}

	if (this->timer.isElapse(150)) {

		LoveLedStrip.clear();
		
		byte offset = 256 / LoveLedStrip.getCount() * 0.8;
		if (GameData.TouchCount < 8) {
			for (int i = 0; i < 4; ++i) {
				int newIndex = panels[index - i] - 1;
				LoveLedStrip.setColor(newIndex, 0, 0, 255 / (i + 1));
			}
			LoveLedStrip.setColor(4, 0, 0, 255);
		}
		else if (GameData.TouchCount < 16) {
			for (int i = 0; i < 4; ++i) {
				int newIndex = panels[index - i] - 1;
				LoveLedStrip.setColor(newIndex, 255 / (i + 1), 255 / (i + 1), 0);
			}
			LoveLedStrip.setColor(4, 255, 255, 0);
		}
		else if (GameData.TouchCount < 24) {
			for (int i = 0; i < 4; ++i) {
				int newIndex = panels[index - i] - 1;
				LoveLedStrip.setColor(newIndex, 255 / (i + 1), 0, 255 / (i + 1));
			}
			LoveLedStrip.setColor(4, 255, 0, 255);
		}
		else {
			for (int i = 0; i < LoveLedStrip.getCount(); ++i) {
				int color = ((this->timeCount + i) * (65535 / LoveLedStrip.getCount())) % 65535;
				LoveLedStrip.setColorHSV(i, color, 255, 255*0.4);
			}
		}
		LoveLedStrip.show();
		this->timeCount++;
		index = (index + 1) % (sizeof(panels) / sizeof(panels[0]));
		if (index < 3) { index = 3; }
		this->timer.start();
	}


	return this;
}

void GameStateResultClass::Exit()
{
}
