// 
// 
// 

#include "AccessoriesStateManager.h"


AccessoriesStateManagerClass::AccessoriesStateManagerClass() : index(0), current(nullptr), stateCount(0)
{
	IState *accessories[] = { &AccessoriesState01, &AccessoriesState02 };

	this->stateCount = sizeof(accessories) / sizeof(accessories[0]);
	for (int i = 0; i < this->stateCount; ++i) {
		this->states[i] = accessories[i];
	}

	this->current = this->states[this->index];
}

void AccessoriesStateManagerClass::Entry()
{
	this->index = 0;
	this->current = this->states[this->index];
	this->current->Entry();
	this->timer.start();
}

IState * AccessoriesStateManagerClass::Do()
{
	int scale = 1;

	if (Button01.isTouch()) { Buzzer.sound(eTone::M01_Do, scale, 10); }
	if (Button02.isTouch()) { Buzzer.sound(eTone::M03_Re, scale, 10); }
	if (Button03.isTouch()) { Buzzer.sound(eTone::M05_Mi, scale, 10); }
	if (Button06.isTouch()) { Buzzer.sound(eTone::M06_Fa, scale, 10); }
	if (Button05.isTouch()) { Buzzer.sound(eTone::M08_So, scale, 10); }
	if (Button04.isTouch()) { Buzzer.sound(eTone::M10_Ra, scale, 10); }
	if (Button07.isTouch()) { Buzzer.sound(eTone::M12_Shi, scale, 10); }
	if (Button08.isTouch()) { Buzzer.sound(eTone::M01_Do, scale * 2, 10); }

	if (Button09.isTouch()) {
		Buzzer.sound(eTone::M05_Mi, 0, 180);
		delay(180);
		Buzzer.sound(eTone::M08_So, 0, 180);
		delay(180);
		Buzzer.sound(eTone::M05_Mi, 1, 180);
		delay(180);
		Buzzer.sound(eTone::M01_Do, 1, 180);
		delay(180);
		Buzzer.sound(eTone::M03_Re, 0, 180);
		delay(180);
		Buzzer.sound(eTone::M08_So, 1, 180);
		delay(180);
		Buzzer.quit();
	}

	if (this->timer.isElapse(10 * 1000)) {
		this->index = (this->index + 1) % this->stateCount;

		this->current->Exit();
		this->current = this->states[this->index];
		this->current->Entry();

		this->timer.start();
	}
	else {
		this->current->Do();
	}

	return this;
}

void AccessoriesStateManagerClass::Exit()
{
}


AccessoriesStateManagerClass AccessoriesStateManager;

