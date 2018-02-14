/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/

#pragma once
#include <windows.h>
#include <d3d9.h>
#include "..\..\include\typedefs.h"


class DXInit
{
public:
	DXInit();
	~DXInit();

	/* Funkcja singletonowa */
	static DXInit &GetSingleton()
	{
		static DXInit singleton;
		return singleton;
	}

	HMODULE *D3DModule;

	bool Init();
	bool D3D9Exists;

	bool CheckD3DExistance();
	bool MyCreateD3D();
	bool MyDestroyD3D();

	HRESULT __cdecl MyCheckDeviceType(UINT, D3DFORMAT, D3DDEVTYPE, const char *);
//	char __thiscall SetupD3D(_DWORD *a2, bool IsOne);
	char __thiscall MySetupDX(_DWORD *a2);

	IDirect3D9 *g_pDX9;
	IDirect3DDevice9 *g_pDX9Device;
	D3DCAPS9 caps;
	D3DDISPLAYMODE mode;
	D3DADAPTER_IDENTIFIER9 pIdentifier;
	D3DPRESENT_PARAMETERS pPresentationParameters;
};

