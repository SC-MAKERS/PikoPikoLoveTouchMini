// Timer.h

#ifndef _TIMER_h
#define _TIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

/// <summary>
/// <para>�^�C�}�[</para>
/// </summary>
class Timer
{
 protected:
	 unsigned long beginTime;
	 unsigned long endTime;
	 bool running;

 public:
	 /// <summary>
	 /// <para>�v�����J�n����</para>
	 /// </summary>
	 void start();
	 /// <summary>
	 /// <para>�v�����I������</para>
	 /// </summary>
	 void stop();
	 /// <summary>
	 /// <para>�v�����J�n���Ďw�莞�Ԃ��߂��Ă��邩�ǂ���</para>
	 /// </summary>
	 /// <param name="pastTime">�w��o�ߎ���</param>
	 /// <returns>�o�߂��Ă��邩�ǂ���</returns>
	 bool isElapse(unsigned long pastTime);
	 /// <summary>
	 /// <para>�o�ߎ��Ԃ��擾����</para>
	 /// </summary>
	 /// <returns>�o�ߎ���</returns>
	 unsigned long getElapse();
	
};



#endif

