// LedStrip.h

#ifndef _LEDSTRIP_h
#define _LEDSTRIP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_NeoPixel.h>

class LedStrip
{
 protected:
	 Adafruit_NeoPixel pixel;
	 uint16_t ledCount;
	 uint8_t  pin;

 public:
	 /// <summary>
	 /// <para>>�R���X�g���N�^</para>
	 /// </summary>
	 /// <param name="ledCount">LED��</param>
	 /// <param name="doutPin">�o�̓s��</param>
	 /// <param name="type">���g��</param>
	 LedStrip(uint16_t ledCount, uint8_t doutPin, neoPixelType type);
	 /// <summary>
	 /// <para>setup�֐��̒��ŌĂяo��������</para>
	 /// </summary>
	 void setup();
	 /// <summary>
	 /// <para>�ݒ肵���F���o�͂���</para>
	 /// </summary>
	 void show();

	 /// <summary>
	 /// <para>�F��ݒ肷��</para>
	 /// </summary>
	 /// <param name="index">LED�C���f�b�N�X</param>
	 /// <param name="r">R</param>
	 /// <param name="g">G</param>
	 /// <param name="b">B</param>
	 void setColor(uint16_t index, uint8_t r, uint8_t g, uint8_t b);
	 /// <summary>
 /// <para>�F��ݒ肷��</para>
 /// </summary>
 /// <param name="index">LED�C���f�b�N�X</param>
 /// <param name="r">R</param>
 /// <param name="g">G</param>
 /// <param name="b">B</param>
	 void setColor(uint16_t index, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
	 /// <summary>
	 /// <para>�F��ݒ肷��</para>
	 /// </summary>
	 /// <param name="index">LED�C���f�b�N�X</param>
	 /// <param name="hue">H</param>
	 /// <param name="sat">S</param>
	 /// <param name="val">V</param>
	 void setColorHSV(uint16_t index, uint16_t hue, uint8_t sat, uint8_t val);

	 /// <summary>
	 /// <para>LED����Pixel�̃|�C���^���擾����</para>
	 /// </summary>
	 /// <returns>LED����Pixel�̃|�C���^</returns>
	 Adafruit_NeoPixel *Pixel();

	 /// <summary>
	 /// <para>LED��</para>
	 /// </summary>
	 /// <returns></returns>
	 uint16_t getCount();
	 /// <summary>
	 /// <para>�N���A����</para>
	 /// </summary>
	 void clear();
};

extern LedStrip LoveLedStrip;

#endif

