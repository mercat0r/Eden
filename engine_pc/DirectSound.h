/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/

#pragma once


class DirectSound
{
public:
	DirectSound();
	~DirectSound();

	/* Funkcja singletonowa */
	static DirectSound &GetSingleton()
	{
		static DirectSound singleton;
		return singleton;
	}

	bool DirectSound::Init(HWND hWnd);
};

