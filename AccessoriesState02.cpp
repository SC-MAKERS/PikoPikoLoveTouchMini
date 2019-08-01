// 
// 
// 

#include "AccessoriesState02.h"


AccessoriesState02Class::AccessoriesState02Class() : offset(0)
{
}

void AccessoriesState02Class::Entry()
{
	this->timer.start();
}

IState * AccessoriesState02Class::Do()
{
	if (this->timer.isElapse(75)) {
		byte index = random(LoveLedStrip.getCount());

		this->offset = (this->offset + (65535 / 50)) % 65535;
		LoveLedStrip.clear();
		LoveLedStrip.setColorHSV(index, this->offset, 255, 255);
		LoveLedStrip.show();

		this->timer.start();
	}

	return this;
}

void AccessoriesState02Class::Exit()
{
}


AccessoriesState02Class AccessoriesState02;

