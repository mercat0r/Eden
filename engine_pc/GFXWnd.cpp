


#include <windows.h>
#include "GFXWnd.h"


GFXWnd::GFXWnd()
{
}


GFXWnd::~GFXWnd()
{
}


int __cdecl GFXWnd::InitGFXWnd(int a1, HINSTANCE hInstance, HWND hWndParent, int a4)
{
	const DLGTEMPLATE hDialogTemplate = { 281542656u, 0u, 0u, 10, 10, 400, 400 };

	//	Tymczasowy_Konstruktor(&hO, a1, a4);
	DialogBoxIndirectParamA(hInstance, &hDialogTemplate, hWndParent, PreGFXMainWndProc, (LPARAM)&g_dwIntParam);

	if (DeleteObject(g_dwIntParam))
		return true;

	else
		return false;
}


BOOL __stdcall GFXWnd::PreGFXMainWndProc(HWND hWnd, UINT a2, WPARAM a3, LPARAM dwNewLong)
{
	LPARAM WndLong;

	WndLong = GetWindowLongA(hWnd, -21);

	if (a2 != 272)
		return DrawWnd(WndLong, hWnd, a2, a3, (HWND)dwNewLong);

	SetWindowLongA(hWnd, -21, dwNewLong);
	return DrawWnd(dwNewLong, hWnd, 272, a3, (HWND)dwNewLong);
}


int __thiscall GFXWnd::DrawWnd(LPARAM lParam, HWND hWnd, int Y, int a4, LPARAM a5) // Y to Msg
{
	HKEY v5; // esi
	HWND v6; // edi
	HINSTANCE v7; // ebx
	int v8; // ebp
	int v9; // ebp
	int v10; // ebp
	int v11; // ebp
	int v12; // ebp
	int v13; // ebp
	int v14; // ebp
	int v15; // ebp
	int v16; // ebp
	int v17; // ebp
	int v18; // ebp
	int v19; // ebp
	int v20; // ebp
	int v21; // ebp
	int v22; // ebp
	int v23; // ebp
	int v24; // ebp
	int v25; // ebp
	int v26; // ebp
	int v27; // ebp
	int v28; // ebp
	int v29; // ebp
	int v30; // ebp
	int v31; // ebp
	int v32; // ebp
	int v33; // ebp
	int v34; // ebp
	int v35; // ebp
	int v36; // ebp
	int v37; // ecx
	int v38; // ebp
	int v39; // ebp
	int v40; // ebp
	int v41; // ebp
	int v42; // ebp
	int v43; // ebp
	int v44; // ebp
	int v45; // ebp
	int v46; // ebp
	int v47; // ebp
	int v48; // ebp
	int v49; // ebp
	int v50; // ebp
	int v51; // ebp
	int v52; // ebp
	int v53; // ebp
	int v54; // ebp
	int v55; // ebp
	int v56; // ebp
	HWND v57; // eax
	WPARAM v58; // ST28_4
	HWND v59; // eax
	WPARAM v60; // ST28_4
	HWND v61; // eax
	WPARAM v62; // ST28_4
	HWND v63; // ST20_4
	int result; // eax
	LRESULT v65; // edi
	LRESULT v66; // eax
	LRESULT v67; // edi
	LRESULT v68; // eax
	struct HKEY__ *v69; // edi
	LRESULT v70; // eax
	LRESULT v71; // edi
	LRESULT v72; // eax
	HWND hWnda; // [esp+14h] [ebp+4h]
	HWND hWndb; // [esp+14h] [ebp+4h]
	HWND hWndc; // [esp+14h] [ebp+4h]
	int Ya; // [esp+18h] [ebp+8h]
	HWND v77; // [esp+20h] [ebp+10h]
	HWND v78; // [esp+20h] [ebp+10h]
	HWND v79; // [esp+20h] [ebp+10h]

	v5 = this;
	if ((unsigned int)Y > 0x111)
	{
	/*	if (Y == 276)
		{
			if (a5 == *((HWND *)this + 17))
			{
				*((_DWORD *)lParam + 105) = SendMessageA(a5, 0x400u, 0, 0);
				return 0;
			}
			if (a5 == *((HWND *)this + 18))
				*((float *)lParam + 104) = (double)SendMessageA(a5, 0x400u, 0, 0) * 0.00024420026;
		}*/
		return 0;
	}
	if (Y != 273)
	{
		if (Y == 16)
		{
			EndDialog(hWnd, 2);
			return 0;
		}
		if (Y == 272)
		{
			/* Najpierw tu! */
			v6 = hWnd;
			v7 = (HINSTANCE)GetWindowLongA(hWnd, -6);
			sub_502570(v5, hWnd);
			SetWindowTextA(hWnd, String);
			Ya = 0;
			sub_507110(
				v5,
				hWnd,
				(int)(v5 + 5),
				(HMENU)0x67,
				aCard,
				*((_DWORD *)v5 + 126),
				10,
				*((_DWORD *)v5 + 114),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 53),
				aCard,
				*((_DWORD *)v5 + 125),
				10,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v8 = *((_DWORD *)v5 + 113) + 10;
			sub_507110(
				v5,
				hWnd,
				(int)(v5 + 6),
				(HMENU)0x68,
				aD3ddevice,
				*((_DWORD *)v5 + 126),
				v8,
				*((_DWORD *)v5 + 114),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 54),
				aDevice,
				*((_DWORD *)v5 + 125),
				v8,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v9 = *((_DWORD *)v5 + 113) + v8;
			sub_507170(
				hWnd,
				(int)(v5 + 7),
				(HMENU)0x69,
				aMode,
				*((_DWORD *)v5 + 126),
				v9,
				*((_DWORD *)v5 + 114),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 55),
				aMode,
				*((_DWORD *)v5 + 125),
				v9,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v10 = *((_DWORD *)v5 + 113) + v9;
			sub_507110(
				v5,
				hWnd,
				(int)(v5 + 8),
				(HMENU)0x6A,
				aZbuffer,
				*((_DWORD *)v5 + 126),
				v10,
				*((_DWORD *)v5 + 114),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 56),
				aZbuffer,
				*((_DWORD *)v5 + 125),
				v10,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v11 = *((_DWORD *)v5 + 113) + v10;
			sub_507110(
				v5,
				hWnd,
				(int)(v5 + 9),
				(HMENU)0x6B,
				aTextureRgb,
				*((_DWORD *)v5 + 126),
				v11,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 57),
				aTextureRgb,
				*((_DWORD *)v5 + 125),
				v11,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v12 = *((_DWORD *)v5 + 113) + v11;
			sub_507110(
				v5,
				hWnd,
				(int)(v5 + 10),
				(HMENU)0x6C,
				aTextureArgb,
				*((_DWORD *)v5 + 126),
				v12,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 58),
				aTextureArgb,
				*((_DWORD *)v5 + 125),
				v12,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v13 = *((_DWORD *)v5 + 113) + v12;
			sub_507110(
				v5,
				hWnd,
				(int)(v5 + 11),
				(HMENU)0x6D,
				aTextureMrgb,
				*((_DWORD *)v5 + 126),
				v13,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 59),
				aTextureMrgb,
				*((_DWORD *)v5 + 125),
				v13,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v14 = *((_DWORD *)v5 + 113) + v13;
			sub_507110(
				v5,
				hWnd,
				(int)(v5 + 12),
				(HMENU)0x85,
				aBumpRgb,
				*((_DWORD *)v5 + 126),
				v14,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 60),
				aBumpRgb,
				*((_DWORD *)v5 + 125),
				v14,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v15 = *((_DWORD *)v5 + 113) + v14;
			sub_507110(
				v5,
				hWnd,
				(int)(v5 + 13),
				(HMENU)0x86,
				aBumpArgb,
				*((_DWORD *)v5 + 126),
				v15,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 61),
				aBumpArgb,
				*((_DWORD *)v5 + 125),
				v15,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v16 = *((_DWORD *)v5 + 113) + v15;
			sub_507110(
				v5,
				hWnd,
				(int)(v5 + 14),
				(HMENU)0x87,
				aBumpEmbm,
				*((_DWORD *)v5 + 126),
				v16,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 62),
				aBumpEmbm,
				*((_DWORD *)v5 + 125),
				v16,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v17 = *((_DWORD *)v5 + 113) + v16;
			sub_507110(
				v5,
				hWnd,
				(int)(v5 + 15),
				(HMENU)0x88,
				aBumpDot3,
				*((_DWORD *)v5 + 126),
				v17,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 63),
				aBumpDot3,
				*((_DWORD *)v5 + 125),
				v17,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v18 = *((_DWORD *)v5 + 113) + v17;
			sub_507110(
				v5,
				hWnd,
				(int)(v5 + 16),
				(HMENU)0x75,
				aTextureLm,
				*((_DWORD *)v5 + 126),
				v18,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 112),
				v7);
			sub_5039E0(
				v5,
				hWnd,
				(int)(v5 + 64),
				aTextureLm,
				*((_DWORD *)v5 + 125),
				v18,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 116),
				v7);
			v19 = *((_DWORD *)v5 + 113) + v18;
			if (v19 >= 0)
				Ya = v19;
			hWnda = (HWND)(*((_DWORD *)v5 + 127) + *((_DWORD *)v5 + 123));
			v77 = (HWND)*((_DWORD *)v5 + 127);
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 19),
				(HMENU)0x94,
				aDrawRooms,
				*((_DWORD *)v5 + 127),
				10,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v20 = *((_DWORD *)v5 + 111) + 10;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 20),
				(HMENU)0x95,
				aDrawObjects,
				(int)v77,
				v20,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v21 = *((_DWORD *)v5 + 111) + v20;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 21),
				(HMENU)0x96,
				aDrawCharacters,
				(int)hWnda,
				v21,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v22 = *((_DWORD *)v5 + 111) + v21;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 23),
				(HMENU)0x98,
				aDrawEmitters,
				(int)hWnda,
				v22,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v23 = *((_DWORD *)v5 + 111) + v22;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 22),
				(HMENU)0x97,
				aDrawFog,
				(int)v77,
				v23,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v24 = *((_DWORD *)v5 + 111) + v23;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 34),
				(HMENU)0x8D,
				aFallbackMethod,
				(int)v77,
				v24,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v25 = *((_DWORD *)v5 + 111) + v24;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 52),
				(HMENU)0x89,
				aOptionalDynami_0,
				(int)v77,
				v25,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v26 = *((_DWORD *)v5 + 111) + v25;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 32),
				(HMENU)0x8A,
				aBlitBackbuffer,
				(int)v77,
				v26,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v27 = *((_DWORD *)v5 + 111) + v26;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 33),
				(HMENU)0x8B,
				aLastframeEffec,
				(int)v77,
				v27,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v28 = *((_DWORD *)v5 + 111) + v27;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 26),
				(HMENU)0x6F,
				aWBuffer,
				(int)v77,
				v28,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v29 = *((_DWORD *)v5 + 111) + v28;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 27),
				(HMENU)0x70,
				aHardwareTransf,
				(int)v77,
				v29,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v30 = *((_DWORD *)v5 + 111) + v29;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 31),
				(HMENU)0x77,
				aBatch_0,
				(int)v77,
				v30,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v31 = *((_DWORD *)v5 + 111) + v30;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 35),
				(HMENU)0x93,
				aDisableallstag,
				(int)v77,
				v31,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v32 = *((_DWORD *)v5 + 111) + v31;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 28),
				(HMENU)0x71,
				aMipmaps_0,
				(int)v77,
				v32,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v33 = *((_DWORD *)v5 + 111) + v32;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 29),
				(HMENU)0x72,
				aTrilinear_0,
				(int)hWnda,
				v33,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v34 = *((_DWORD *)v5 + 111) + v33;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 30),
				(HMENU)0x76,
				aAnisotropic,
				(int)hWnda,
				v34,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v35 = *((_DWORD *)v5 + 111) + v34;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 24),
				(HMENU)0x99,
				aAspect169_0,
				(int)v77,
				v35,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v36 = *((_DWORD *)v5 + 111) + v35;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 25),
				(HMENU)0x9A,
				aAspectLetterbo_0,
				(int)v77,
				v36,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v37 = (int)v77;
			v38 = *((_DWORD *)v5 + 111) + v36;
			v78 = (HWND)((char *)v77 + *((_DWORD *)v5 + 117));
			sub_5039E0(v5, v6, (int)(v5 + 65), aTextureDetail, v37, v38, *((_DWORD *)v5 + 117), *((_DWORD *)v5 + 108), v7);
			sub_503A40(
				v6,
				(int)(v5 + 17),
				(HMENU)0x73,
				aTextureDetail,
				(int)v78,
				v38,
				*((_DWORD *)v5 + 118),
				*((_DWORD *)v5 + 108),
				v7);
			v39 = *((_DWORD *)v5 + 109) + v38;
			if (Ya <= v39)
				Ya = v39;
			v79 = (HWND)*((_DWORD *)v5 + 128);
			hWndb = (HWND)((char *)v79 + *((_DWORD *)v5 + 123));
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 42),
				(HMENU)0x7F,
				aAllTextures,
				*((_DWORD *)v5 + 128),
				10,
				80,
				*((_DWORD *)v5 + 106),
				v7);
			v40 = *((_DWORD *)v5 + 111) + 10;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 43),
				(HMENU)0x80,
				aDiffuse,
				(int)v79,
				v40,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v41 = *((_DWORD *)v5 + 111) + v40;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 45),
				(HMENU)0x82,
				aSelfIll,
				(int)v79,
				v41,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v42 = *((_DWORD *)v5 + 111) + v41;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 47),
				(HMENU)0x84,
				aEnviroment,
				(int)v79,
				v42,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v43 = *((_DWORD *)v5 + 111) + v42;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 44),
				(HMENU)0x81,
				aLightmap,
				(int)v79,
				v43,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v44 = *((_DWORD *)v5 + 111) + v43;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 40),
				(HMENU)0x7D,
				aX1,
				(int)hWndb,
				v44,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v45 = *((_DWORD *)v5 + 111) + v44;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 41),
				(HMENU)0x7E,
				aAlphablend,
				(int)hWndb,
				v45,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v46 = *((_DWORD *)v5 + 111) + v45;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 46),
				(HMENU)0x83,
				aBump,
				(int)v79,
				v46,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v47 = *((_DWORD *)v5 + 111) + v46;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 37),
				(HMENU)0x78,
				aDot3,
				(int)hWndb,
				v47,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v48 = *((_DWORD *)v5 + 111) + v47;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 36),
				(HMENU)0x79,
				aEmbm,
				(int)hWndb,
				v48,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v49 = *((_DWORD *)v5 + 111) + v48;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 38),
				(HMENU)0x7A,
				aAlpha,
				(int)hWndb,
				v49,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v50 = *((_DWORD *)v5 + 111) + v49;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 39),
				(HMENU)0x7B,
				aTwopass,
				(int)hWndb,
				v50,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v51 = v50 + 2 * *((_DWORD *)v5 + 111);
			hWndc = (HWND)((char *)v79 + *((_DWORD *)v5 + 117));
			sub_5039E0(
				v5,
				v6,
				(int)(v5 + 66),
				aCharacterDetai,
				(int)v79,
				v51,
				*((_DWORD *)v5 + 117),
				*((_DWORD *)v5 + 108),
				v7);
			sub_503A40(
				v6,
				(int)(v5 + 18),
				(HMENU)0x8C,
				aCharacterDetai,
				(int)hWndc,
				v51,
				*((_DWORD *)v5 + 118),
				*((_DWORD *)v5 + 108),
				v7);
			v52 = *((_DWORD *)v5 + 109) + v51;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 50),
				(HMENU)0x90,
				aCharacterBump,
				(int)v79,
				v52,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v53 = *((_DWORD *)v5 + 111) + v52;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 48),
				(HMENU)0x8E,
				aCharacterDiffu,
				(int)v79,
				v53,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v54 = *((_DWORD *)v5 + 111) + v53;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 49),
				(HMENU)0x8F,
				aCharacterSelfI,
				(int)v79,
				v54,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v55 = *((_DWORD *)v5 + 111) + v54;
			sub_5071D0(
				v5,
				v6,
				(int)(v5 + 51),
				(HMENU)0x91,
				aCharacterEnvir,
				(int)v79,
				v55,
				*((_DWORD *)v5 + 115),
				*((_DWORD *)v5 + 106),
				v7);
			v56 = *((_DWORD *)v5 + 111) + v55;
			if (Ya <= v56)
				Ya = v56;
			v57 = CreateWindowExA(0, aButton, aOk, 0x50000000u, 10, Ya, 60, *((_DWORD *)v5 + 106), v6, (HMENU)0x65, v7, 0);
			v58 = *((_DWORD *)v5 + 1);
			*((_DWORD *)v5 + 2) = v57;
			SendMessageA(v57, 0x30u, v58, 1);
			v59 = CreateWindowExA(
				0,
				aButton,
				aCancel,
				0x50000000u,
				100,
				Ya,
				60,
				*((_DWORD *)v5 + 106),
				v6,
				(HMENU)0x66,
				v7,
				0);
			v60 = *((_DWORD *)v5 + 1);
			*((_DWORD *)v5 + 3) = v59;
			SendMessageA(v59, 0x30u, v60, 1);
			v61 = CreateWindowExA(
				0,
				aButton,
				aDefault,
				0x50000000u,
				190,
				Ya,
				60,
				*((_DWORD *)v5 + 106),
				v6,
				(HMENU)0x92,
				v7,
				0);
			v62 = *((_DWORD *)v5 + 1);
			v63 = (HWND)*((_DWORD *)v5 + 2);
			*((_DWORD *)v5 + 4) = v61;
			SendMessageA(v63, 0x30u, v62, 1);
			SendMessageA(*((HWND *)v5 + 3), 0x30u, *((_DWORD *)v5 + 1), 1);
			SendMessageA(*((HWND *)v5 + 4), 0x30u, *((_DWORD *)v5 + 1), 1);
			SendMessageA(v6, 0x30u, *((_DWORD *)v5 + 1), 1);
			sub_5038F0(v5);
			sub_502630(v5);
			sub_5026A0(v5);
			sub_502730(v5);
			sub_502820(v5);
			sub_502A10(v5);
			sub_502C80(v5);
			sub_502CA0(v5);
			sub_502DC0(v5);
			sub_502DE0(v5);
			sub_502E00(v5);
			sub_502ED0(v5);
			sub_502A30(v5);
			sub_503470(v5);
			sub_5025C0(v5);
			SetWindowPos(v6, 0, 0, 0, *((_DWORD *)v5 + 129), Ya + *((_DWORD *)v5 + 106) + *((_DWORD *)v5 + 107), 0x206u);
			return 0;
		}
		return 0;
	}
	switch (0)
	{
	case 1:
	case 101:
		sub_505A90(*(_DWORD *)this, this + 68);
		EndDialog(hWnd, 1);
		return 0;
	case 2:
	case 102:
		EndDialog(hWnd, 2);
		return 0;
	case 103:
		if ((unsigned int)a4 >> 16 != 1)
			return 0;
		v65 = 0;
		v66 = SendMessageA(a5, 0x147u, 0, 0);
		if (v66 != -1)
		{
			v65 = SendMessageA(a5, 0x150u, v66, 0);
			if (v65 == -1)
				v65 = 0;
		}
		*((_DWORD *)v5 + 79) = v65;
		sub_503770(v5);
		sub_5026A0(v5);
		sub_502730(v5);
		sub_502820(v5);
		sub_502A10(v5);
		sub_502C80(v5);
		sub_502CA0(v5);
		sub_502DC0(v5);
		sub_502DE0(v5);
		sub_502ED0(v5);
		sub_502E00(v5);
		sub_502A30(v5);
		sub_502EF0(v5);
		sub_502F40(v5);
		sub_5025C0(v5);
		return 0;
	case 104:
		if ((unsigned int)a4 >> 16 != 1)
			return 0;
		v67 = 0;
		v68 = SendMessageA(a5, 0x147u, 0, 0);
		if (v68 != -1)
		{
			v67 = SendMessageA(a5, 0x150u, v68, 0);
			if (v67 == -1)
				v67 = 0;
		}
		*((_DWORD *)v5 + 80) = v67;
		sub_503690(v5);
		sub_502730(v5);
		sub_502820(v5);
		sub_502A10(v5);
		sub_502C80(v5);
		sub_502CA0(v5);
		sub_502DC0(v5);
		sub_502DE0(v5);
		sub_502ED0(v5);
		sub_502E00(v5);
		goto LABEL_24;
	case 105:
		if ((unsigned int)a4 >> 16 != 1)
			return 0;
		v69 = 0;
		v70 = SendMessageA(a5, 0x147u, 0, 0);
		if (v70 != -1)
		{
			v69 = (struct HKEY__ *)SendMessageA(a5, 0x150u, v70, 0);
			if (v69 == (struct HKEY__ *) - 1)
				v69 = 0;
		}
		*((_DWORD *)v5 + 81) = v69;
		v5[70] = (struct HKEY__)*(_DWORD *)v69;
		v5[71] = v69[1];
		v5[72] = v69[4];
		sub_503470(v5);
		sub_5025C0(v5);
		return 0;
	case 106:
		if ((unsigned int)a4 >> 16 != 1)
			return 0;
		v71 = 0;
		v72 = SendMessageA(a5, 0x147u, 0, 0);
		if (v72 != -1)
		{
			v71 = SendMessageA(a5, 0x150u, v72, 0);
			if (v71 == -1)
				v71 = 0;
		}
		*((_DWORD *)v5 + 82) = v71;
		*(_DWORD *)(v5 + 73) = *(_DWORD *)(HKEY)(v71 + 16);
		*(_DWORD *)(v5 + 74) = *(_DWORD *)(HKEY)(v71 + 20);
		sub_503470(v5);
		sub_5025C0(v5);
		return 0;
	case 107:
		sub_503AA0(a5, a4, (int)(this + 83));
		return 0;
	case 108:
		sub_503AA0(a5, a4, (int)(this + 84));
		return 0;
	case 109:
		sub_503AA0(a5, a4, (int)(this + 85));
		return 0;
	case 111:
		if (HIWORD(a4))
			return 0;
		*((_BYTE *)v5 + 384) = SendMessageA(*((HWND *)this + 26), 0xF0u, 0, 0) == 1;
		sub_502EF0(v5);
		return 0;
	case 112:
		if (HIWORD(a4))
			return 0;
		*((_BYTE *)v5 + 385) = SendMessageA(*((HWND *)this + 27), 0xF0u, 0, 0) == 1;
		sub_502F40(v5);
		return 0;
	case 113:
		if (HIWORD(a4))
			return 0;
		*((_BYTE *)v5 + 386) = SendMessageA(*((HWND *)this + 28), 0xF0u, 0, 0) == 1;
		goto LABEL_57;
	case 114:
		if (HIWORD(a4))
			return 0;
		*((_BYTE *)v5 + 388) = SendMessageA(*((HWND *)this + 29), 0xF0u, 0, 0) == 1;
		goto LABEL_57;
	case 117:
		sub_503AA0(a5, a4, (int)(this + 86));
		result = 0;
		break;
	case 118:
		if (HIWORD(a4))
			return 0;
		*((_BYTE *)v5 + 389) = SendMessageA(*((HWND *)this + 30), 0xF0u, 0, 0) == 1;
	LABEL_57:
		sub_502F90(v5);
		sub_502FF0(v5);
		sub_503050(v5);
		result = 0;
		break;
	case 119:
		if (HIWORD(a4))
			return 0;
		*((_BYTE *)v5 + 390) = SendMessageA(*((HWND *)this + 31), 0xF0u, 0, 0) == 1;
		sub_5030B0(v5);
		result = 0;
		break;
	case 120:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 37), (int)(this + 98));
		result = 0;
		break;
	case 121:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 36), (int)this + 391);
		result = 0;
		break;
	case 122:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 38), (int)this + 394);
		result = 0;
		break;
	case 123:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 39), (int)this + 393);
		result = 0;
		break;
	case 125:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 40), (int)this + 395);
		result = 0;
		break;
	case 126:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 41), (int)(this + 99));
		result = 0;
		break;
	case 127:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 42), (int)(this + 93));
		result = 0;
		break;
	case 128:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 43), (int)this + 373);
		result = 0;
		break;
	case 129:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 44), (int)this + 374);
		result = 0;
		break;
	case 130:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 45), (int)this + 375);
		result = 0;
		break;
	case 131:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 46), (int)(this + 94));
		result = 0;
		break;
	case 132:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 47), (int)this + 377);
		result = 0;
		break;
	case 133:
		sub_503AA0(a5, a4, (int)(this + 87));
		result = 0;
		break;
	case 134:
		sub_503AA0(a5, a4, (int)(this + 88));
		result = 0;
		break;
	case 135:
		sub_503AA0(a5, a4, (int)(this + 89));
		result = 0;
		break;
	case 136:
		sub_503AA0(a5, a4, (int)(this + 90));
		result = 0;
		break;
	case 137:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 52), (int)this + 397);
		result = 0;
		break;
	case 138:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 32), (int)this + 398);
		result = 0;
		break;
	case 139:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 33), (int)this + 399);
		result = 0;
		break;
	case 141:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 34), (int)(this + 100));
		result = 0;
		break;
	case 142:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 48), (int)this + 378);
		result = 0;
		break;
	case 143:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 49), (int)(this + 95));
		result = 0;
		break;
	case 144:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 50), (int)this + 381);
		result = 0;
		break;
	case 145:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 51), (int)this + 382);
		result = 0;
		break;
	case 146:
		sub_503850(this);
		sub_502630(v5);
		sub_5026A0(v5);
		sub_502730(v5);
		sub_502820(v5);
		sub_502A10(v5);
		sub_502C80(v5);
		sub_502CA0(v5);
		sub_502DC0(v5);
		sub_502DE0(v5);
		sub_502E00(v5);
		sub_502ED0(v5);
	LABEL_24:
		sub_502A30(v5);
		sub_503470(v5);
		sub_5025C0(v5);
		result = 0;
		break;
	case 147:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 35), (int)this + 402);
		result = 0;
		break;
	case 148:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 19), (int)this + 406);
		result = 0;
		break;
	case 149:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 20), (int)this + 405);
		result = 0;
		break;
	case 150:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 21), (int)this + 407);
		result = 0;
		break;
	case 151:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 22), (int)(this + 102));
		result = 0;
		break;
	case 152:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 23), (int)this + 409);
		result = 0;
		break;
	case 153:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 24), (int)this + 411);
		result = 0;
		break;
	case 154:
		sub_5039A0(SHIWORD(a4), *((HWND *)this + 25), (int)(this + 103));
		result = 0;
		break;
	default:
		return 0;
	}
	return result;
}