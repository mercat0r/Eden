/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/

#include <windows.h>
#include "Time.h"
#include "..\..\include\typedefs.h"

#pragma comment (lib, "winmm.lib")

Time::Time()
{
}


Time::~Time()
{
}


bool __cdecl Time::InitTimeSys(float framerate)
{
	char result;
	LARGE_INTEGER Frequency;
	DWORD v3; // [esp+8h] [ebp-8h]
	int v4; // [esp+Ch] [ebp-4h]

	SetTime();

	if (!QueryPerformanceFrequency(&Frequency))
		return false;

	v3 = Frequency.LowPart;
	v4 = 0;
	freq_01 = ((double)Frequency.HighPart * 4294967300.0 + (double)(signed int)Frequency.LowPart) / framerate;
	quadfreq_01 = Frequency.QuadPart / (signed __int64)framerate;

	if (!QueryPerformanceCounter(&Frequency))
		return false;

	quadfreq_quadpart_01 = Frequency.QuadPart;
	quadfreq_quadpart_02 = Frequency.QuadPart;
	result = true;
	freq_02 = ((double)Frequency.HighPart * 4294967300.0 + (double)(signed int)Frequency.LowPart) / freq_01;
	
	return result;
}


void Time::SetTime()
{
	LARGE_INTEGER Frequency;

	if (QueryPerformanceFrequency(&Frequency))
	{
		zerodword = 0;
		one_div_quad = 1.0 / (double)Frequency.QuadPart;
		*(float *)&zerodword = Something();
	}
	else
	{
		one_div_quad = 0.0;
		current_time = timeGetTime();
	}
}


double Time::Something()
{
	double result; // st7
	LARGE_INTEGER PerformanceCount;

	if (QueryPerformanceCounter(&PerformanceCount))
		result = ((double)PerformanceCount.QuadPart - *(float *)&zerodword) * one_div_quad;
	else
		result = (double)(timeGetTime() - current_time) * 0.001; //Is this the fps count ?

	return result;
}