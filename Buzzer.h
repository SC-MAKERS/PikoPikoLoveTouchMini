// Buzzer.h

#ifndef _BUZZER_h
#define _BUZZER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

typedef enum {
	M01_Do = 262,
	M02_DoSharp = 277,
	M03_Re = 294,
	M04_ReSharp = 311,
	M05_Mi = 330,
	M06_Fa = 349,
	M07_FaSharp = 370,
	M08_So = 392,
	M09_SoSharp = 415,
	M10_Ra = 440,
	M11_RaSharp = 466,
	M12_Shi = 494
} eTone;

/// <summary>
/// <para>���d�u�U�[����N���X</para>
/// </summary>
class PiezoelectricBuzzer
{
protected:
	/// <summary>
	/// <para>>�o�̓s��</para>
	/// </summary>
	uint8_t pin;
	/// <summary>
	/// <para>�o�̗͂L������</para>
	/// </summary>
	bool enabled;

public:
	/// <summary>
	/// <para>�R���X�g���N�^</para>
	/// </summary>
	/// <param name="outputPin">�o�̓s��</param>
	PiezoelectricBuzzer(uint8_t outputPin);
	
	/// <summary>
	/// <para>����炷</para>
	/// </summary>
	/// <param name="frequency">���g��(Hz) </param>
	/// <param name="duration">�o�͂��鎞�Ԃ��~���b�Ŏw��ł��܂�(�I�v�V����) </param>
	void sound(unsigned int frequency, unsigned long duration);

	/// <summary>
	/// <para>>����炷</para>
	/// </summary>
	/// <param name="soundingTone">�炷��</param>
	/// <para>���K�i-1�F�I�N�^�[�u������, 0�F���̂܂�, 1�F�I�N�^�[�u�グ��)</para>
	/// <param name="duration">�o�͂��鎞�Ԃ��~���b�Ŏw��ł��܂�(�I�v�V����)</param>
	void sound(eTone soundingTone, byte scale, unsigned long duration);

	/// <summary>
	/// <para>�T�E���h�o�͂��~�߂�</para>
	/// </summary>
	void quit();

	/// <summary>
	/// ���̗L��������ݒ肷��
	/// </summary>
	/// <param name="enabled">�L�����ǂ���</param>
	void setEnabled(bool enabled);
	/// <summary>
	/// <para>�L���������擾����</para>
	/// </summary>
	bool getEnabled();
};

/// <summary>
/// <para>�u�U�[</para>
/// </summary>
extern PiezoelectricBuzzer Buzzer;

#endif

