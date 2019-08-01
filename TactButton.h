// TactButton_H.h

#ifndef _TACTBUTTON_H
#define _TACTBUTTON_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class TactButton
{
 protected:
	 const int ChatteringLoop;
	 const int ChatteringThreshould;

	 uint8_t pin;
	 bool isTouchState;
public:
	/// <summary>
	/// <para>コンストラクタ</para>
	/// </summary>
	/// <param name="readPin">読み取りピン</param>
	TactButton(uint8_t readPin);
	/// <summary>
	/// <para>状態を更新する</para>
	/// </summary>
	void update();
	/// <summary>
	/// <para>タッチされているかどうか</para>
	/// </summary>
	/// <returns>タッチ有無</returns>
	bool isTouch();
};

extern TactButton Button01;
extern TactButton Button02;
extern TactButton Button03;
extern TactButton Button04;
extern TactButton Button05;
extern TactButton Button06;
extern TactButton Button07;
extern TactButton Button08;
extern TactButton Button09;

extern TactButton ModeButton;

extern const uint8_t ButtonCount;
extern TactButton *Buttons[];

#endif

