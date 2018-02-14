/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/
#ifdef SOUND

#include <windows.h>
#include "DirectSound.h"


DirectSound::DirectSound()
{
}


DirectSound::~DirectSound()
{
}

/* First parameter was _DWORD *this, maybe DSoundptr */
bool DirectSound::Init(/* _DWORD *this */HWND hWnd)
{
	_DWORD *v2; // esi
	int v3; // edx
	int v4; // eax
	int v5; // ecx
	bool v6; // zf
	BYTE v8[4]; // [esp+4h] [ebp-20h]
	int v9; // [esp+8h] [ebp-1Ch]
	int v10; // [esp+Ch] [ebp-18h]
	DWORD cbData; // [esp+10h] [ebp-14h]
	int v12; // [esp+14h] [ebp-10h]

	v2 = this;
	sub_4C30A0();
	sub_520DD0(&cbData);
	sub_521F90((DWORD)&cbData);
	sub_5221E0((unsigned int)v8);
	v3 = *(_DWORD *)v8;
	v4 = v10;
	v2[18] = v9;
	v5 = v12;
	v6 = v12 == 0;
	v2[19] = v3;
	v2[17] = v4;
	v2[6] = v5;
	if (v6 || !(*(unsigned __int8(__stdcall **)(HWND, DWORD *))(*(_DWORD *)v5 + 124))(hWnd, &cbData))
		return 0;
	sub_4C2F00((int)v2);
	return 1;
}
#endif