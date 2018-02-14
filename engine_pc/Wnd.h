/**********************************************

	Project Eden

	By mercat0r

	Released under the MIT license.

**********************************************/

#pragma once
#include "C:\devgit\include\typedefs.h"

class Wnd
{
public:
	Wnd();
	~Wnd();

	/* Funkcja singletonowa */
	static Wnd &GetSingleton()
	{
		static Wnd singleton;
		return singleton;
	}

	/*HWND hWnd;*/
	HINSTANCE hInstance;

	/* MainInit() */
	WNDCLASSEXA wcex;
	HWND hEdenWnd;
	LPARAM lParam;

	bool bLockFramerate;

	static LRESULT CALLBACK MainWndProc(LONG WndLong, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK PreMainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

	/* Główna inicjalizacja: okna, DirectX'a 9, itd... */
	HRESULT MainInit(int ThisIsZero, char *lpCmdLine);

//	std::codecvt_base *NetworkPtr;

//	void __thiscall GlownaPetla(char a2);
//	double __thiscall ReturnFPS();

	//_DWORD *InitSomething();
};
