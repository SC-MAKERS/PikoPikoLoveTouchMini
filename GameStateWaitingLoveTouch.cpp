// 
// 
// 

#include "GameStateWaitingLoveTouch.h"

GameStateWaitingLoveTouchClass::GameStateWaitingLoveTouchClass() : offset(0), crossPushCounter(0), mutePushCounter(0)
{
}

void GameStateWaitingLoveTouchClass::Entry()
{
	this->timer.start();
	for (int i = 0; i < sizeof(this->cornerPushed) / sizeof(this->cornerPushed[0]); ++i) {
		this->cornerPushed[i] = false;
	}
	Buzzer.setEnabled(true);
	GameData.GameLevel = 0;
	GameData.TouchCount = 0;
}

IState * GameStateWaitingLoveTouchClass::Do()
{
	if (this->timer.isElapse(50)) {
		LoveLedStrip.clear();

		int corners[] = { 0, 2, 6, 8};
		TactButton *buttons[] = { &Button01, &Button03, &Button07, &Button09 };

		int count = sizeof(corners) / sizeof(corners[0]);
		bool allPushed = true;

		// らぶタッチ判定前処理
		for (int i = 0; i < count; ++i) {
			if (buttons[i]->isTouch()) {
				LoveLedStrip.setColor(corners[i], 255, 0, 255);
				if (!this->cornerPushed[i]) {
					this->cornerPushed[i] = true;
					Buzzer.sound(eTone::M06_Fa, 1, 10);
				}
			}
			else {
				this->offset = (this->offset + 5) % 256;
				if (GameData.GameLevel == 0) {
					LoveLedStrip.setColor(corners[i], 0, 0, this->offset);
				}
				else {
					LoveLedStrip.setColor(corners[i], this->offset, 0, 0);
				}
				this->cornerPushed[i] = false;
			}
			allPushed &= buttons[i]->isTouch();
		}
		LoveLedStrip.show();

		// らぶタッチ判定
		if (allPushed) {
			LoveLedStrip.clear();
			LoveLedStrip.show();

			for (int i = 0; i < 3; ++i) {
				Buzzer.sound(eTone::M01_Do, 1, 250);
				delay(1000);
			}
			Buzzer.sound(eTone::M01_Do, 2, 250);
			delay(1000);

			return &GameStatePlaying;
		}
		
		// ミュートチェック
		if (Button05.isTouch()) {
			if (this->mutePushCounter++ > 50) {
				Buzzer.sound(eTone::M10_Ra, 0, 50);
				Buzzer.setEnabled(!Buzzer.getEnabled());
				Buzzer.sound(eTone::M10_Ra, 0, 50);
				this->mutePushCounter = 0;
			}
		}

		if (this->checkHardMode()) {
			if (this->crossPushCounter++ > 50) {
				for (int i = 0; i < 2; ++i) {
					Buzzer.sound(eTone::M04_ReSharp, i, 50);
					delay(100);
				}
				GameData.GameLevel = GameData.GameLevel ? 0 : 1;
				this->crossPushCounter = 0;
			}
		}

		this->timer.start();
	}

	return this;
}

void GameStateWaitingLoveTouchClass::Exit()
{
}

bool GameStateWaitingLoveTouchClass::checkHardMode()
{
	TactButton *buttons[] = { &Button02, &Button04, &Button06, &Button08 };

	bool allPush = true;
	for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); ++i) {
		allPush &= buttons[i]->isTouch();
	}

	return allPush;
}


GameStateWaitingLoveTouchClass GameStateWaitingLoveTouch;

