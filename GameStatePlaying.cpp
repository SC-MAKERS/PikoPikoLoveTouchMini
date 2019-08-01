// 
// 
// 

#include "GameStatePlaying.h"

GameStatePlayingClass GameStatePlaying;

void GameStatePlayingClass::shuffle()
{
	byte temp = 0, indexA = 0, indexB = 0;
	for (int i = 0; i < 25; ++i) {
		indexA = random(this->PanelCount);
		indexB = random(this->PanelCount);

		temp = this->touching[indexA];
		this->touching[indexA] = this->touching[indexB];
		this->touching[indexB] = temp;
	}
	//for (int i = 0; i < this->PanelCount; ++i) {
	//	this->touched[i] = 0;
	//}
}

GameStatePlayingClass::GameStatePlayingClass() : PanelCount(9), waitingForTouching(false), touchingCount(4)
{
	for (int i = 0; i < this->PanelCount; ++i) {
		this->touching[i] = i;
		this->touched[i] = 0;
	}
}

void GameStatePlayingClass::Entry()
{
	GameData.TouchCount = 0;
	this->timer.start();
	this->gameTimer.start();
	this->touchingCount = (GameData.GameLevel > 0) ? random(1, this->PanelCount) : 4;
}

IState * GameStatePlayingClass::Do()
{
	if (this->gameTimer.isElapse(30 * 1000)) {
		LoveLedStrip.clear();
		LoveLedStrip.show();

		Buzzer.sound(eTone::M01_Do, 0, 200);
		delay(200);
		Buzzer.sound(eTone::M03_Re, 0, 200);
		delay(200);
		Buzzer.sound(eTone::M05_Mi, 0, 200);
		delay(200);
		Buzzer.sound(eTone::M06_Fa, 0, 200);
		delay(200);
		Buzzer.sound(eTone::M08_So, 0, 200);
		delay(200);
		Buzzer.sound(eTone::M10_Ra, 0, 200);
		delay(200);
		Buzzer.sound(eTone::M12_Shi, 0, 200);
		delay(200);
		Buzzer.sound(eTone::M01_Do, 1, 200);
		delay(1000);
		Buzzer.quit();
		return &GameStateResult;
	}

	if (this->waitingForTouching) {
		if (this->timer.isElapse(50)) {
			LoveLedStrip.clear();
			int counter = 0;

			for (int i = 0; i < this->touchingCount; ++i) {
				byte index = this->touching[i];

				if (Buttons[index]->isTouch()) {
					LoveLedStrip.setColor(index, 255, 0, 255);
					if (this->touched[index] == 0) {
						this->touched[index] = 1;
						Buzzer.sound(eTone::M10_Ra, 1, 50);
					}
					counter++;
				}
				else {
					LoveLedStrip.setColor(index, 0, 0, 255);
					this->touched[index] = 0;
				}
			}
			LoveLedStrip.show();

			byte miss = 0;
			for (int i = this->touchingCount; i < this->PanelCount; ++i) {
				byte index = this->touching[i];

				if (Buttons[index]->isTouch()) {
					if (this->touched[index] == 0) {
						this->touched[index] = 1;
						Buzzer.sound(eTone::M03_Re, 0, 300);
					}
					++miss;
				}
				else {
					this->touched[index] = 0;
				}
			}
			
			if (miss == 0) {
				if (this->touchingCount == counter) {
					Buzzer.sound(eTone::M05_Mi, 1, 30);
					delay(30);
					Buzzer.sound(eTone::M08_So, 1, 30);
					delay(30);
					Buzzer.sound(eTone::M10_Ra, 1, 30);
					
					GameData.TouchCount++;
					this->waitingForTouching = false;
				}
			}
			this->timer.start();
		}
	}
	else {
		this->touchingCount = (GameData.GameLevel > 0) ? random(1, this->PanelCount) : 4;

		//Buzzer.quit();
		this->shuffle();

		LoveLedStrip.clear();
		for (int i = 0; i < this->touchingCount; ++i) {
			LoveLedStrip.setColor(this->touching[i], 0, 0, 255);
		}
		LoveLedStrip.show();

		this->waitingForTouching = true;
	}

	return this;
}

void GameStatePlayingClass::Exit()
{
}
