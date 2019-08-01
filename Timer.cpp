// 
// 
// 

#include "Timer.h"

void Timer::start()
{
	this->beginTime = millis();
	this->running = true;
}

void Timer::stop()
{
	this->endTime = millis();
	this->running = false;
}

bool Timer::isElapse(unsigned long pastTime)
{
	return this->getElapse() >= pastTime;
}

unsigned long Timer::getElapse()
{
	if (this->running) {
		return (millis() - this->beginTime);
	}
	else {
		return (this->endTime - this->beginTime);
	}
}


