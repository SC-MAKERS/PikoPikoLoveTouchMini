// Timer.h

#ifndef _TIMER_h
#define _TIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

/// <summary>
/// <para>タイマー</para>
/// </summary>
class Timer
{
 protected:
	 unsigned long beginTime;
	 unsigned long endTime;
	 bool running;

 public:
	 /// <summary>
	 /// <para>計測を開始する</para>
	 /// </summary>
	 void start();
	 /// <summary>
	 /// <para>計測を終了する</para>
	 /// </summary>
	 void stop();
	 /// <summary>
	 /// <para>計測を開始して指定時間が過ぎているかどうか</para>
	 /// </summary>
	 /// <param name="pastTime">指定経過時間</param>
	 /// <returns>経過しているかどうか</returns>
	 bool isElapse(unsigned long pastTime);
	 /// <summary>
	 /// <para>経過時間を取得する</para>
	 /// </summary>
	 /// <returns>経過時間</returns>
	 unsigned long getElapse();
	
};



#endif

