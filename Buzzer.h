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
/// <para>圧電ブザー操作クラス</para>
/// </summary>
class PiezoelectricBuzzer
{
protected:
	/// <summary>
	/// <para>>出力ピン</para>
	/// </summary>
	uint8_t pin;
	/// <summary>
	/// <para>出力の有効無効</para>
	/// </summary>
	bool enabled;

public:
	/// <summary>
	/// <para>コンストラクタ</para>
	/// </summary>
	/// <param name="outputPin">出力ピン</param>
	PiezoelectricBuzzer(uint8_t outputPin);
	
	/// <summary>
	/// <para>音を鳴らす</para>
	/// </summary>
	/// <param name="frequency">周波数(Hz) </param>
	/// <param name="duration">出力する時間をミリ秒で指定できます(オプション) </param>
	void sound(unsigned int frequency, unsigned long duration);

	/// <summary>
	/// <para>>音を鳴らす</para>
	/// </summary>
	/// <param name="soundingTone">鳴らす音</param>
	/// <para>音階（-1：オクターブ下げる, 0：そのまま, 1：オクターブ上げる)</para>
	/// <param name="duration">出力する時間をミリ秒で指定できます(オプション)</param>
	void sound(eTone soundingTone, byte scale, unsigned long duration);

	/// <summary>
	/// <para>サウンド出力を止める</para>
	/// </summary>
	void quit();

	/// <summary>
	/// 音の有効無効を設定する
	/// </summary>
	/// <param name="enabled">有効かどうか</param>
	void setEnabled(bool enabled);
	/// <summary>
	/// <para>有効無効を取得する</para>
	/// </summary>
	bool getEnabled();
};

/// <summary>
/// <para>ブザー</para>
/// </summary>
extern PiezoelectricBuzzer Buzzer;

#endif

