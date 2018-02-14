/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/

#include <windows.h>
#include <tchar.h>
#include <CommCtrl.h>

#include "Wnd.h"
#include "DXInit.h"
#include "Lang.h"
#include "C:\devgit\include\typedefs.h"

#pragma comment (lib, "Comctl32.lib")


BOOL __cdecl MessageFunc(HWND hWnd, HINSTANCE hInstance)
{
	BOOL MsgGot;
	struct tagMSG Msg;

	if (hWnd)
		DestroyWindow(hWnd);

	MsgGot = true;

	while (PeekMessageA(&Msg, 0, 0, 0, 0))
	{
		if (!MsgGot)
			break;

		MsgGot = GetMessageA(&Msg, 0, 0, 0);
		TranslateMessage(&Msg);
		DispatchMessageA(&Msg);
	}

	return UnregisterClassA("EDEN_WINDOW", hInstance);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	/* Initialize Wnd::hInstance to the WinMain hInstance */
	Wnd g_Wnd = Wnd::GetSingleton();
	g_Wnd.hInstance = hInstance;

	CoInitialize(0);

	/* OBSOLETE!!! */
	InitCommonControls();

	/* Return error code */
	/* NOTE: it doesn't have to be a HRESULT... */
	HRESULT ErrorCode = g_Wnd.MainInit(0, lpCmdLine);

	int result;

	/* If there is an error... */
	if (ErrorCode)
	{
		MessageFunc(g_Wnd.hEdenWnd, hInstance);

		Lang g_Lang = Lang::GetSingleton();

		TCHAR *ErrorMsg = g_Lang.ReturnErrorString(ErrorCode);
		if (ErrorMsg)
		{
			switch (g_Lang.CurrentLanguage)
			{
				case FR:
				MessageBox(0, ErrorMsg, _T("Project Eden: Error (F)"), MB_ICONERROR);
				result = -1;
				break;

				case DE:
				MessageBox(0, ErrorMsg, _T("Project Eden: Error (G)"), MB_ICONERROR);
				result = -1;
				break;

				case IT:
				MessageBox(0, ErrorMsg, _T("Project Eden: Error (I)"), MB_ICONERROR);
				result = -1;
				break;

				case SP:
				MessageBox(0, ErrorMsg, _T("Project Eden: Error (S)"), MB_ICONERROR);
				result = -1;
				break;

				case JP:
				MessageBox(0, ErrorMsg, _T("Project Eden: Error (J)"), MB_ICONERROR);
				result = -1;
				break;

				/* Default... */
				default:
				MessageBox(0, ErrorMsg, _T("Project Eden: Error"), MB_ICONERROR);
				goto error;
			}
		}

		else
		{
		error:
			result = -1;
		}
	}

	/* If there was no errors... */
	else
	{
		/* Go to the main game loop */
		g_Wnd.GlownaPetla(0);

		/* Shutdown the game */
		g_Wnd.hEdenWnd = 0;
		MessageFunc(0, hInstance);
	//	sub_44A720(&lParam);
		result = 0;
	}

	CoUninitialize();

	/* Make sure DX9 doesn't exist (code added by me, not decompiled!) */
	DXInit g_DXInit = DXInit::GetSingleton();
	g_DXInit.MyDestroyD3D();

	return result;
}