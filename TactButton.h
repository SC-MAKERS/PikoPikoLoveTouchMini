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
	/// <para>�R���X�g���N�^</para>
	/// </summary>
	/// <param name="readPin">�ǂݎ��s��</param>
	TactButton(uint8_t readPin);
	/// <summary>
	/// <para>��Ԃ��X�V����</para>
	/// </summary>
	void update();
	/// <summary>
	/// <para>�^�b�`����Ă��邩�ǂ���</para>
	/// </summary>
	/// <returns>�^�b�`�L��</returns>
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

