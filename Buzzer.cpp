// 
// 
// 

#include "Buzzer.h"

PiezoelectricBuzzer::PiezoelectricBuzzer(uint8_t outputPin) : enabled(true)
{
	this->pin = outputPin;
}


void PiezoelectricBuzzer::sound(unsigned int frequency, unsigned long duration = 0UL)
{
	if (this->enabled) {
		tone(this->pin, frequency, duration);
	}
}

void PiezoelectricBuzzer::sound(eTone soundingTone, byte scale, unsigned long duration = 0UL)
{
	unsigned int etone = (unsigned int)soundingTone;

	if (scale < 0) {
		for (int i = scale; i < 0; ++i) {
			etone /= 2;
		}
	}
	else {
		for (int i = 0; i < scale; ++i) {
			etone *= 2;
		}
	}

	this->sound(etone, duration);
}

void PiezoelectricBuzzer::quit()
{
	noTone(this->pin);
}

void PiezoelectricBuzzer::setEnabled(bool enabled)
{
	this->enabled = enabled;
}

bool PiezoelectricBuzzer::getEnabled()
{
	return this->enabled;
}


PiezoelectricBuzzer Buzzer(12);

