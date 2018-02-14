/**********************************************

	Project Eden

	By mercat0r

	Released under the MIT license.

**********************************************/
#ifdef FIXME

#include <dinput.h>
#include "Wnd.h"
#include "DirectInput.h"


DirectInput::DirectInput()
{
}


DirectInput::~DirectInput()
{
}


bool __thiscall DirectInput::InitDirectInput(HINSTANCE hInstance, HWND hWnd, char a4)
{
	bool result;

	result = MyCreateDINPUT(hInstance);
	if (result)
	{
		if (a4 & 1 || (result = MyCreateDeviceEx(hWnd)) != 0)
		{
			//if (!(a4 & 2) && !(unsigned __int8)sub_50C330(hWnd))
			//	sub_50C3F0(v4);
			if (a4 & 4 || (result = MyCreateDeviceExSecond(hWnd)) != 0)
				result = 1;
		}
	}
	return result;
}


bool __thiscall DirectInput::MyCreateDINPUT(HINSTANCE hInstance)
{
	HRESULT hr;

//	if (CoCreateInstance(&stru_5E149C, 0, 1u, &stru_5E148C, pvRef)) //Mo¿e stwórz now¹ zmienn¹ ppv w klasie ?
//		return false;

	/* Zwróæ hInstance */
	Wnd g_pWnd = Wnd::GetSingleton();

	/* Stwórz DINPUT */
	hr = g_pDI->Initialize(hInstance, DIRECTINPUT_VERSION);

	if (SUCCEEDED(hr))
	{
		hr = g_pDI->EnumDevices(DI8DEVCLASS_GAMECTRL, lpCallback, pvRef, DIEDFL_ATTACHEDONLY);

		if (SUCCEEDED(hr))
		{
			return true;
		}
	}

	return false;
}


bool __thiscall DirectInput::MyCreateDeviceEx(HWND hWnd)
{
	if (FAILED(g_pDI->CreateDeviceEx(rguid, riid, &ppvObject, NULL)))
		return false;

	if (FAILED(g_pDIDevice->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))
		return false;

	if (FAILED(g_pDIDevice->SetDataFormat(lpdf)))
		return false;

	// Wczeœniej by³o return hr == -2147024891 || SUCCEEDED(hr);
	return SUCCEEDED(g_pDIDevice->Acquire());
}


bool __thiscall DirectInput::MyCreateDeviceExSecond(HWND hWnd)
{
	bool result;

	if (FAILED(g_pDI->CreateDeviceEx(rguid, riid, &ppvObject, NULL)))
		return 0;

	if (FAILED(g_pDIDevice->SetCooperativeLevel(hWnd, DISCL_EXCLUSIVE | DISCL_FOREGROUND)))
		return 0;

	if (FAILED(g_pDIDevice->SetDataFormat(lpdf)))
		return 0;

	if (FAILED(g_pDIDevice->Acquire()))
		return 0;

	if (g_pDIDevice->GetProperty(DIPROP_GRANULARITY, pdiph))
	{
		g_pDIDevice[69] = 0;
		result = true;
	}
	else
	{
		result = true;
		g_pDIDevice[69] = v10;
	}

	return result;
}
#endif