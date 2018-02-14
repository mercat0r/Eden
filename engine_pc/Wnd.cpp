/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/

#include <windows.h>
#include <tchar.h>
#include "Wnd.h"
#include "DXInit.h"
#include "DirectInput.h"
#include "Lang.h"
#include "Time.h"
#include "DirectSound.h"
#include <codecvt>
#include "resource.h"
#include "C:\devgit\include\typedefs.h"

// Uncomment the following #define if you want the game
// to check if there's a CD named "PROJECTEDEN":
//#define CDCHECK

#ifdef CDCHECK
#include "cdcheck.h"
#endif


Wnd::Wnd()
{
	/* inicjalizuj hWnd na 0 */
	//hWnd = 0;

	hEdenWnd = 0;
//	lParam = 0;

	// Move to Network class!!!
	//NetworkPtr = 0; //std::codecvt_base::ok

	// Move to Util or DX class!!!
	bLockFramerate = false;
}


Wnd::~Wnd()
{

}

/* This link helped a lot :)                        */
/* https://wiki.winehq.org/List_Of_Windows_Messages */
/*                                                  */
LRESULT CALLBACK Wnd::MainWndProc(LONG WndLong, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	UINT v5; // esi
	LRESULT result; // eax
	int v7; // esi
	double v8; // st7
	WPARAM v9; // eax
	int v10; // eax
	float v11; // [esp+10h] [ebp+4h] //Move to contructor!!!

	v5 = Msg;
	if (Msg > 0x10)
	{
		switch (Msg)
		{
		case WM_SETCURSOR:
		//	if (!*(_BYTE *)(WndLong + 100001))
		//		goto LABEL_12;
			SetCursor(0); //Set an empty cursor
			return 1;

		case WM_KEYDOWN:
		//	if (dword_75BEAC) //NEWINPUT::Key
		//		sub_4672C0(wParam);
			goto LABEL_18;

		case WM_KEYUP:
		LABEL_18:
			/* 44 = key on keyboard which makes a screenshot */
			/* https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx */
			if (wParam != /*44*/ VK_SNAPSHOT) //Print screen key
				goto LABEL_12;

			/* Add to Input class */
			/* Check what is NEWINPUT:: ? */
			IsScreenshotKeyPressed = 1;
			return 0;

		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
			v9 = wParam;
			if (wParam != 18 && wParam != 121) //ALT + F4 keys pressed at once, TODO: add VK_ prefix
				goto LABEL_24;
			return 0;

		case WM_SYSCOMMAND:
			v9 = wParam;
		LABEL_24:
			v10 = v9 - 61760;
			if (v10 && v10 != 48)
				goto LABEL_12;
			result = 0;
			break;

		default:
			goto LABEL_12;
		}
	}
	else if (Msg == 16)
	{
//		sub_508DA0(dword_75BEAC);
//		sub_50C590(&dword_6D3318);
//		sub_4FFA00(1);
//		sub_4ABE30(&unk_61B4E8);
		DestroyWindow(hWnd);
		result = 0;
	}
	else
	{
		switch (Msg)
		{
		case WM_CREATE:
			/* Coś tam z DX'em */
		//	sub_44D720(WndLong, (int)hWnd);
			return DefWindowProcA(hWnd, Msg, wParam, lParam);

		case WM_DESTROY:
			WndLong = 4;
			PostQuitMessage(0);
			return DefWindowProcA(hWnd, Msg, wParam, lParam);

		case WM_SIZE:
		//	v7 = WndLong;
		//	if (!*(_BYTE *)(WndLong + 100001))
		//	{
		//		*(_DWORD *)(WndLong + 100024) = 0;
		//		*(_DWORD *)(WndLong + 100004) = (unsigned __int16)lParam;
		//		v8 = (double)(unsigned __int16)lParam;
		//		*(_DWORD *)(WndLong + 100032) = 0;
		//		*(float *)(WndLong + 100028) = v8;
		//		*(_DWORD *)(WndLong + 100008) = (unsigned int)lParam >> 16;
		//		*(_DWORD *)(WndLong + 100148) = 0;
		//		v11 = (double)((unsigned int)lParam >> 16);
		//		*(float *)(v7 + 100036) = v11;
		//		*(_DWORD *)(v7 + 100156) = (signed __int64)v8;
		//		*(_DWORD *)(v7 + 100152) = 0;
		//		*(_DWORD *)(v7 + 100160) = (signed __int64)v11;
		//		RedrawWindow(hWnd, 0, 0, 0x403u);
		//	}
		//	v5 = Msg;
			break;

		case WM_ACTIVATE:
		//	if ((_WORD)wParam || *(_BYTE *)(WndLong + 100001) != 1)
				break;

			ShowWindow(hWnd, 6);
			return DefWindowProcA(hWnd, Msg, wParam, lParam);

		case WM_PAINT:
		//	sub_44D3B0((DWORD *)WndLong, hWnd);
			return DefWindowProcA(hWnd, Msg, wParam, lParam);

		default:
			break;
		}

	LABEL_12:
		result = DefWindowProcA(hWnd, v5, wParam, lParam);
	}

	return result;
}


LRESULT CALLBACK Wnd::PreMainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LONG WndLong;
	LRESULT result;

	if (Msg == 1)
		SetWindowLongA(hWnd, GWLP_USERDATA, *(_DWORD *)lParam);

	WndLong = GetWindowLongA(hWnd, GWLP_USERDATA);

	if (WndLong)
		result = MainWndProc(WndLong, hWnd, Msg, wParam, lParam);
	else
		result = DefWindowProcA(hWnd, Msg, wParam, lParam);

	return result;
}


HRESULT Wnd::MainInit(int ThisIsZero, char *lpCmdLine)
{
	/* UWAGA!!! Umieścić te zmienne na odpowiednie miejsce zainicjalizowania w tej funkcji MainInit!!! */
	//_BYTE *v5; // eax

	/* Jeśli nie ma regkey "Language" lub jeśli lpCmdLine zawiera argument "-language" */
/*	if (!sub_404D40() || strstr(lpCmdLine, "-language"))
	{
		DialogBoxParam(hInstance, (LPCWSTR)IDC_LANG, 0, DialogFunc, 0);

		HKEY hKey; // ecx
		WriteLanguageToRegistry(hKey);
	}*/

#ifdef CDCHECK
	/* Sprawdź czy płyta jest włożona do czytnika */
	if (CheckCD() == 27)
		return ERR_NOCD;
#endif

	if (strstr(lpCmdLine, "-lockframerate"))
		bLockFramerate = true;

//#ifdef CZAS
	/* Inicjalizacja systemu czasu */
	Time g_Time = Time::GetSingleton();
	if (!g_Time.InitTimeSys(60.0))
		return ERR_FAILED_INIT_TIMESYS;
//#endif

	/* Głupi "Exception Check" chyba */
	//InitSomething();

	DXInit g_DXInit = DXInit::GetSingleton();

	if (!ThisIsZero)
	{
		/* Init DirectX 9 and check if GPU is compatible */
		// MsgBox: Failed to start Direct3D9 (DirectX9) or Find a DX9 compatible graphics card.
		if (!g_DXInit.Init())
			return ERR_FAILED_START_D3D;

//		if (strstr(lpCmdLine, "-gfxsettings"))
//			InitGFXWnd(g_DXInit.g_pDX9, hInstance, 0, 0);

//		if (strstr(lpCmdLine, "-sfxsettings"))
//			sub_507D00(dx, hInstance, 0);

//		sub_4AD9E0((int)&v8, (int)&v11, 0.0);
//		dword_6BE2E8 = (int)&unk_615320;
	}

//	v5 = sub_4676D0(ThisIsZero);

//	dword_75BEAC = (int)v5;

//	if (!v5)
//		return 13;

//	NetworkPtr = (std::codecvt_base *)sub_46EA60((int)v5, ThisIsZero);

//	if (!NetworkPtr)
//		return ERR_FAILED_SETUP_NETWORKSYS;

	/* Zero the wcex out... */
	memset(&wcex, 0, sizeof(wcex));

	wcex.cbSize = sizeof(wcex);
	wcex.lpfnWndProc = &Wnd::PreMainWndProc; //HACKHACK!!! https://stackoverflow.com/questions/17221815/why-cant-my-wndproc-be-in-a-class
	wcex.hInstance = hInstance;

	/* Is this needed ? */
	HICON hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDEN));
	wcex.hIcon = hIcon;
	wcex.hIconSm = hIcon; //Small icon

	wcex.hbrBackground = CreateSolidBrush(COLOR_GRAYTEXT); /* In the demo version: (HBRUSH)GetStockObject(5);*/
	wcex.hCursor = LoadCursor(0, IDC_ARROW);
	wcex.lpszClassName = "EDEN_WINDOW";

	if (!RegisterClassExA(&wcex))
		return ERR_FAILED_REGISTER_WINDOW;

	hEdenWnd = CreateWindowExA(
		0x40000u,
		"EDEN_WINDOW",
		"Eden",
		WS_OVERLAPPED, // decompiled code was (DWORD)&unk_CF0000,
		2147483648,
		2147483648,
		640,
		480,
		0,
		0,
		hInstance,
		&lParam); // FIXME: is lParam really needed here ?

/*	hWnd = hEdenWnd;	*/ //We don't need this anymore...

	if (!hEdenWnd)
		return ERR_FAILED_CREATE_WINDOW;

	if (!ThisIsZero) //Is this a server mode ? EDIT: No...
	{
		ShowWindow(hEdenWnd, SW_SHOW);

//		DirectInput g_dI = DirectInput::GetSingleton();

//		if (!g_dI.InitDirectInput(hInstance, hEdenWnd, 0))
//			return ERR_FAILED_START_DINPUT;
	}
#ifdef SOUND
	DirectSound g_DS = DirectSound::GetSingleton();

	// &unk_61B4E8
	if (!g_DS.Init(hEdenWnd))
		return ERR_FAILED_START_DSOUND;
#endif
//	sub_4ABC90((int)&unk_61B4E8);

//	if (!(unsigned __int8)InitInputCollection(&dword_6D3318, hEdenWnd))
//		return 21;

//	if ((_BYTE)ThisIsZero || g_DXInit.SetupD3D(&dword_614F24, 1))
//		return 0;

	//Failed to setup the DirectDraw or Direct3D
	return ERR_FAILED_SETUP_D3D;
}


/*
_DWORD *InitSomething()
{
	_DWORD *result; // eax
	float *v1; // esi

	dword_945D24 = sub_5C0E60();
	dword_945D20 = (int)sub_5A9940();
	result = sub_5CFDD0();
	dword_945D28 = (int)result;
	v1 = (float *)&dword_945D20;
	do
	{
		if (*(_DWORD *)v1)
		{
			result = (_DWORD *)(*(int(**)(void))(**(_DWORD **)v1 + 12))();
			if (!(_BYTE)result)
			{
				if (*(_DWORD *)v1)
					result = (_DWORD *)(*(int(__stdcall **)(signed int))(**(_DWORD **)v1 + 128))(1);
				*v1 = 0.0;
			}
		}
		++v1;
	} while (v1 != &flt_945D2C);
	return result;
}
*/


void __thiscall Wnd::GlownaPetla(char a2)
{
	int v3; // eax
	float fps; // ST10_4 // Is this really the fps count ?
	HWND v5; // esi
	float v6; // [esp+14h] [ebp-20h]
	struct tagMSG Msg; // [esp+18h] [ebp-1Ch] // Nie ten sam Msg co inne DLGPROC!

	while (lParam != 4)
	{
		v6 = ReturnFPS();

		if (a2)
		{
			while (PeekMessageA(&Msg, 0, 0, 0, 0))
			{
				if (!GetMessageA(&Msg, 0, 0, 0))
					lParam = 4;

				TranslateMessage(&Msg);
				DispatchMessageA(&Msg);
			}

			lParam[8] = lParam[3];
			v3 = lParam;
			if (lParam != 4 && v3 != 6 && v3 != 8 && (unsigned __int8)sub_470F20(lParam + 7))
				lParam = 4;
		}

		else
		{
			sub_44DBA0((HWND *)lParam, v6);
		}

		if (v6 != 0.0 && !a2)
		{
			sub_4ABDA0(&unk_61B4E8);
			sub_4A0CA0(&unk_615290);
			fps = v6 * 0.016666668; // v4 = Framerate * Ratio
			sub_4AB930(&unk_61B4E8, fps);
		}
	}

	v5 = (HWND)lParam[7];

	if (v5)
		DestroyWindow(v5);
}


double __thiscall Wnd::ReturnFPS()
{
	int v1; // edi
	int v4; // eax
	char *v5; // eax
	int v6; // eax
	char *v7; // eax
	int v8; // eax
	int v9; // ebx
	int v10; // ebp
	int v11; // eax
	int v12; // ebp
	int v13; // ebx
	_DWORD *v14; // ebx
	double v15; // st7
	int v16; // ecx
	int v17; // ebx
	int v18; // ebp
	int v19; // eax
	int v21; // eax
	double v22; // st7
	__int16 v23; // fps
	unsigned __int8 v24; // c0
	unsigned __int8 v25; // c2
	bool v26; // c0
	char v27; // c2
	bool v28; // c3
	char v29; // [esp+13h] [ebp-11h]
	float v30; // [esp+14h] [ebp-10h]
	int v31; // [esp+18h] [ebp-Ch]
	unsigned int v32; // [esp+1Ch] [ebp-8h]
	unsigned int v33; // [esp+20h] [ebp-4h]

	v1 = 0;
	v33 = _control87(0, 0);
	v32 = v33 & 0x30300;
	if ((v33 & 0x30300) != 0x20000)
		_control87(0x20000u, 0x30300u);

	LPARAM lOrigParam = lParam;
	v30 = 0.0; // This is the fps count...

	switch (lOrigParam)
	{
	case 0:
		lParam = 1;
		v4 = LoadFiles(
			&unk_615290, //DX Texture pointer, or just DX pointer ?
			"Title.edf",
			"gentext.edt",
			"vidtext.edt",
			"loadtext.edt",
			"menutext.edt",
			"hints.edt",
			0);

		if (!v4)
			goto LABEL_51;

		v5 = sub_4A02D0(v4);
		if (!v5)
			goto LABEL_11;

		strncpy(lParam + 142, v5, 0x400u);
		goto LABEL_10;

	case 1:
	case 11:
		sub_4687D0(dword_75BEB0);
		*((_DWORD *)lParam + 11931) = 1;

		v6 = sub_45D480(&unk_615290, "titlebackdrop.edn", 0);
		if (v6)
		{
			v7 = sub_4A02D0(v6);
			if (v7)
			{
				strncpy(lParam + 142, v7, 0x400u);

			LABEL_10:
				lParam[1165] = 0;
			}

		LABEL_11:
			lParam = 4;
		}

		else
		{
			if (*(_DWORD *)lParam == 11)
				sub_425920(73, *((_DWORD *)lParam + 11898), 0, 0);
			else
				sub_425920(16, 0, 0, 0);

			*(_DWORD *)lParam = 2;

		LABEL_16:
			v31 = sub_44DC50(lParam + 1168, &v29);

			if (v31)
			{
				if (*((_DWORD *)lParam + 294) == 3)
				{
					*(_DWORD *)lParam = 7;
				}

				else
				{
					v8 = *((_DWORD *)lParam + 11931);
					v9 = 0;
					v30 = (double)v31;
					if (v8 > 0)
					{
						v10 = (int)(lParam + 27808);
						do
						{
							sub_425B00(&lParam[48 * (v1 + *((_DWORD *)lParam + 292)) + 1180]);
							++v9;
							v1 += 60;
							v10 += 20048;
						} while (v9 < *((_DWORD *)lParam + 11931));
					}

					if (*((_DWORD *)lParam + 292) != *((_DWORD *)lParam + 293))
					{
						if (!(unsigned __int8)sub_46EA40(dword_75BEB0) || (v11 = *((_DWORD *)lParam + 294), v11 == 1) || v11 == 2)
							sub_44B490(lParam + 1168);
					}
				}
			}
		}
		goto LABEL_57;
	case 2:
		goto LABEL_16;
	case 4:
		goto LABEL_57;
	case 5:
		sub_46DB20(dword_75BEB0);
		if (lParam[24])
		{
			if (*((_DWORD *)lParam + 7))
			{
				DestroyWindow(*((HWND *)lParam + 7));
				*((_DWORD *)lParam + 7) = 0;
			}
			*(_DWORD *)lParam = 8;
		}
		else
		{
			*(_DWORD *)lParam = 2;
		}
		v17 = 0;
		if (*((_DWORD *)lParam + 11931) > 0)
		{
			v18 = (int)(lParam + 27808);
			do
			{
				if (sub_46DD60(dword_75BEB0) == 1)
				{
					sub_425920(38, 0, 0, 0);
				}
				else if (sub_46DD60(dword_75BEB0) == 2)
				{
					sub_425920(39, 0, 0, 0);
				}
				else
				{
					sub_425920(40, 0, 0, 0);
				}
				++v17;
				v18 += 20048;
			} while (v17 < *((_DWORD *)lParam + 11931));
		}
		goto LABEL_57;
	case 6:
		*(_DWORD *)lParam = (unsigned __int8)sub_46FE70(&dword_75BEB0) != 0 ? 8 : 4;
	LABEL_51:
		sub_477B70();
		goto LABEL_57;
	case 7:
		if (!lParam[24])
		{
			v12 = 0;
			if (*((_DWORD *)lParam + 11931) > 0)
			{
				v13 = (int)(lParam + 27808);
				do
				{
					sub_425920(0, 0, 0, 0);
					++v12;
					v13 += 20048;
				} while (v12 < *((_DWORD *)v2 + 11931));
			}
		}
		*(_DWORD *)lParam = 3;
		sub_447970(lParam + 99960);
		if (!lParam[24])
			v30 = sub_44B490(lParam + 1168);
		goto LABEL_57;
	case 8:
		*(_DWORD *)lParam = (unsigned __int8)sub_46FED0((int)&dword_75BEB0, (LPARAM)(lParam + 28)) != 0 ? 7 : 4;
		goto LABEL_57;
	case 9:
		v14 = lParam + 1168;
		v31 = sub_44DC50(lParam + 1168, &v29);
		if (v31)
		{
			v15 = (double)v31;
			v16 = 3 * *v14;
			*v14 = *((_DWORD *)lParam + 293);
			v30 = v15;
			sub_425B00(&lParam[16 * v16 + 1180]);
			if ((unsigned __int8)sub_46D650(0) == 1)
				*(_DWORD *)v2 = 1;
		}
		goto LABEL_57;
	default:
		v19 = sub_44DC50(lParam + 1168, &v29);
		*((_DWORD *)lParam + 3) = v19;
		if (!v19)
			return 0.0;
		v30 = sub_44B490(lParam + 1168);
		if (v29)
		{
			sub_4ABD60(&unk_61B4E8);
			*(_DWORD *)lParam = 5;
		}
	LABEL_57:
		v21 = *((_DWORD *)lParam + 24983);
		if (v21 && v21 != 3)
		{
			v22 = v30 * *((float *)lParam + 24985) + *((float *)lParam + 24984);
			*((float *)lParam + 24984) = v22;
			if (v24 | v25)
			{
				*((_DWORD *)lParam + 24984) = 0;
				*((_DWORD *)lParam + 24983) = 0;
			}
			else
			{
				v26 = v22 < 255.0;
				v27 = 0;
				v28 = v22 == 255.0;
				if (!(v23 & 0x4100))
				{
					*((_DWORD *)lParam + 24984) = 1132396544;
					*((_DWORD *)lParam + 24983) = 3;
				}
			}
		}
		if (v32 != 0x20000)
			_control87(v33, 0x30300u);
		return v30;
	}
}