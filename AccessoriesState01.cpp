// 
// 
// 

#include "AccessoriesState01.h"

AccessoriesState01Class::AccessoriesState01Class() : index(2)
{
}

AccessoriesState01Class::~AccessoriesState01Class()
{
}

void AccessoriesState01Class::Entry()
{
	this->timer.start();
}

IState* AccessoriesState01Class::Do()
{

	if (this->timer.isElapse(150)) {	
		int panels[] = {7,6,1,2,3,4,9,8,7,6 };
		
		LoveLedStrip.Pixel()->clear();
		
		for (int i = 0; i < 3; ++i) {
			int newIndex = panels[index - i] - 1;
			LoveLedStrip.setColor(newIndex, 0, 0, 255 / (i + 1));
		}

		LoveLedStrip.show();
		this->timer.start();
		
		index = (index + 1) % (sizeof(panels) / sizeof(panels[0]));
		if (index < 2) { index = 2; }
	}

	return this;
}

void AccessoriesState01Class::Exit()
{
}

AccessoriesState01Class AccessoriesState01;