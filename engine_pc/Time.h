/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/

#pragma once

class Time
{
public:
	Time();
	~Time();

	/* Funkcja singletonowa */
	static Time &GetSingleton()
	{
		static Time singleton;
		return singleton;
	}

	float freq_01;
	__int64 quadfreq_01;
	__int64 quadfreq_quadpart_01;
	__int64 quadfreq_quadpart_02;
	float freq_02;

	float zerodword;
	float one_div_quad;

	/* Important! */
	DWORD current_time;

	bool __cdecl InitTimeSys(float framerate);
	void SetTime();
	double Something();
};