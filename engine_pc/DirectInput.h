/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/
#ifdef FIXME

#pragma once
#include <dinput.h>


class DirectInput
{
public:
	DirectInput();
	~DirectInput();

	/* Funkcja singletonowa */
	static DirectInput &GetSingleton()
	{
		static DirectInput singleton;
		return singleton;
	}

	bool __thiscall InitDirectInput(HINSTANCE hInstance, HWND hWnd, char a4);
	bool __thiscall MyCreateDINPUT(HINSTANCE hInstance);
	bool __thiscall MyCreateDeviceEx(HWND hWnd);
	bool __thiscall MyCreateDeviceExSecond(HWND hWnd);

	IDirectInput7 *g_pDI;
	IDirectInputDevice *g_pDIDevice;
	LPDIENUMDEVICESCALLBACK lpCallback;
	LPVOID pvRef;
	REFGUID rguid;
	REFIID riid;
	LPVOID ppvObject;
	LPCDIDATAFORMAT lpdf;
	LPDIPROPHEADER pdiph;
};
#endif