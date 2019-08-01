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
	 /// <para>>コンストラクタ</para>
	 /// </summary>
	 /// <param name="ledCount">LED数</param>
	 /// <param name="doutPin">出力ピン</param>
	 /// <param name="type">周波数</param>
	 LedStrip(uint16_t ledCount, uint8_t doutPin, neoPixelType type);
	 /// <summary>
	 /// <para>setup関数の中で呼び出す初期化</para>
	 /// </summary>
	 void setup();
	 /// <summary>
	 /// <para>設定した色を出力する</para>
	 /// </summary>
	 void show();

	 /// <summary>
	 /// <para>色を設定する</para>
	 /// </summary>
	 /// <param name="index">LEDインデックス</param>
	 /// <param name="r">R</param>
	 /// <param name="g">G</param>
	 /// <param name="b">B</param>
	 void setColor(uint16_t index, uint8_t r, uint8_t g, uint8_t b);
	 /// <summary>
 /// <para>色を設定する</para>
 /// </summary>
 /// <param name="index">LEDインデックス</param>
 /// <param name="r">R</param>
 /// <param name="g">G</param>
 /// <param name="b">B</param>
	 void setColor(uint16_t index, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
	 /// <summary>
	 /// <para>色を設定する</para>
	 /// </summary>
	 /// <param name="index">LEDインデックス</param>
	 /// <param name="hue">H</param>
	 /// <param name="sat">S</param>
	 /// <param name="val">V</param>
	 void setColorHSV(uint16_t index, uint16_t hue, uint8_t sat, uint8_t val);

	 /// <summary>
	 /// <para>LED操作Pixelのポインタを取得する</para>
	 /// </summary>
	 /// <returns>LED操作Pixelのポインタ</returns>
	 Adafruit_NeoPixel *Pixel();

	 /// <summary>
	 /// <para>LED数</para>
	 /// </summary>
	 /// <returns></returns>
	 uint16_t getCount();
	 /// <summary>
	 /// <para>クリアする</para>
	 /// </summary>
	 void clear();
};

extern LedStrip LoveLedStrip;

#endif

