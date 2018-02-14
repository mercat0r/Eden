/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include "DXInit.h"
#include "Wnd.h"
#include "C:\devgit\include\typedefs.h"
#include <d3d9.h>
//#include <d3d9caps.h>

#pragma comment (lib, "d3d9.lib")

DXInit::DXInit()
{
	g_pDX9 = nullptr;
}


DXInit::~DXInit()
{
	/* Make sure DX doesn't exist */
	if (D3D9Exists)
		MyDestroyD3D();
}


bool DXInit::Init()
{
	/* Try to create DirectX 9 */
	if (!AMCreateD3D())
		return false;

	HRESULT hr = g_pDX9->GetAdapterDisplayMode(0, &mode);

	UINT uAdapterCount = g_pDX9->GetAdapterCount();

	g_pDX9->GetAdapterIdentifier(0, 0, &pIdentifier);

	/* More than one GPU has been detected */
	if (uAdapterCount > 1)
	{
		TCHAR buffer[140];
		swprintf(buffer, _T("More than one GPU has been detected.\nDirectX will now choose the main adapter '%s'"), pIdentifier.Description);
		MessageBox(0, buffer, _T("Project Eden: Warning"), MB_ICONWARNING);
	}

	if (mode.Format != D3DFMT_X8R8G8B8)
	{
		MessageBox(0, _T("Your GPU doesn't meet the minimal requirements to run the game"), _T("Project Eden: Error"), MB_ICONERROR);
		hr = -1;
	}

	return (SUCCEEDED(hr)) ? true : false;
}


bool DXInit::CheckD3DExistance()
{
	if (g_pDX9)
		D3D9Exists = true;
	else
		D3D9Exists = false;

	return D3D9Exists;
}


bool DXInit::MyCreateD3D()
{
	g_pDX9 = Direct3DCreate9(D3D_SDK_VERSION);

	return CheckD3DExistance();
}


bool DXInit::MyDestroyD3D()
{-
	if (g_pDX9)
	{
		g_pDX9->Release();
		D3D9Exists = false;
		return true;
	}
	
	return false;
}

/* Unused function!!! */
HRESULT __cdecl DXInit::MyCheckDeviceType(UINT uAdapter, D3DFORMAT a3, D3DDEVTYPE devtype, const char *HalNum)
{
	HRESULT hr;

	// IDirect3D8::CheckDeviceType(), for example ( 0, D3DDEVTYPE_HAL, D3DFMT_X8R8G8B8, D3DFMT_X8R8G8B8, FALSE )
	hr = g_pDX9->CheckDeviceType(uAdapter, devtype, a3, a3, 0);

	if (SUCCEEDED(hr))
	{
		g_pDX9->GetDeviceCaps(uAdapter, devtype, &caps);
	}

	return hr;
}

/* Is a2 a pointer to IDirect3D9 ? */
char __thiscall DXInit::SetupD3D(_DWORD *a2, bool IsOne)
{
	_DWORD *v5; // [esp+10h] [ebp-9Ch]
	char v6; // [esp+14h] [ebp-98h]
	int v7; // [esp+40h] [ebp-6Ch]
	int v8; // [esp+44h] [ebp-68h]

	if (*((_BYTE *)a2 + 5) && !(unsigned __int8)sub_502070(a2) || g_pDX9[452701] && *((_DWORD *)v3 + 113174) != *a2)
		return 0;
	if (!v3[457145] && !(unsigned __int8)sub_4FFCD0(a2))
	{
		if ((unsigned __int8)sub_4FFBC0(a2))
			v3[457144] = 1;
		v5 = v3 + 452696;
		qmemcpy(v3 + 452696, a2, 0x98u);
		goto LABEL_11;
	}
	v5 = v3 + 452696;
	qmemcpy(&v6, v3 + 452696, 0x98u);
	sub_4FFA00(*((_DWORD *)v3 + 113185) != a2[11]);
	if (MySetupDX(a2) || IsOne == 1 && (sub_4FFA00(*((_DWORD *)v3 + 113185) != v7), v8) && MySetupDX(v3, &v6))
	{
	LABEL_11:
		sub_4FFEC0(a2);
		*v5 = *a2;
		return 1;
	}
	return 0;
}


char __thiscall DXInit::MySetupDX(_DWORD *a2) // decompiled code was 'dword this' as the first parameter
{
	Wnd g_Wnd = Wnd::GetSingleton();

	/* Create the device interface */
	if (FAILED(g_pDX9->CreateDevice(0, D3DDEVTYPE_HAL, g_Wnd.hEdenWnd, 134, &pPresentationParameters, &g_pDX9Device)))
	{
		return 0;
	}

	//(*(void(__stdcall **)(_DWORD))(*(_DWORD *)v3[113434] + 12))(v3[113434]); // What's this ? A DX function probably...
	return 1;
}