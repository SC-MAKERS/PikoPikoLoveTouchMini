// 
// 
// 

#include "LedStrip.h"

LedStrip::LedStrip(uint16_t ledCount, uint8_t doutPin, neoPixelType type = NEO_GRB + NEO_KHZ800) : pixel(ledCount, doutPin, type)
{
	this->ledCount = ledCount;
	this->pin = doutPin;
}

void LedStrip::setup()
{
	this->pixel.begin();
	this->pixel.setBrightness(40);
	this->pixel.clear();
	this->pixel.show();
}

void LedStrip::show()
{
	this->pixel.show();
}

void LedStrip::setColor(uint16_t index, uint8_t r, uint8_t g, uint8_t b)
{
	this->pixel.setPixelColor(index, this->pixel.Color(r, g, b));
}

void LedStrip::setColor(uint16_t index, uint8_t r, uint8_t g, uint8_t b, uint8_t w)
{
	this->pixel.setPixelColor(index, this->pixel.Color(r, g, b, w));
}

void LedStrip::setColorHSV(uint16_t index, uint16_t hue, uint8_t sat = 255U, uint8_t val = 255U)
{
	this->pixel.setPixelColor(index, this->pixel.ColorHSV(hue, sat, val));
}

Adafruit_NeoPixel * LedStrip::Pixel()
{
	return &(this->pixel);
}

uint16_t LedStrip::getCount()
{
	return this->ledCount;
}

void LedStrip::clear()
{
	this->pixel.clear();
}

LedStrip LoveLedStrip(9, 2);
