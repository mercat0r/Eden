#pragma once
class GFXWnd
{
public:
	GFXWnd();
	~GFXWnd();

	/* Funkcja singletonowa */
	static GFXWnd &GetSingleton()
	{
		static GFXWnd singleton;
		return singleton;
	}

	LPARAM g_dwIntParam;

	int __cdecl InitGFXWnd(int a1, HINSTANCE hInstance, HWND hWndParent, int a4);
	BOOL __stdcall PreGFXMainWndProc(HWND hWnd, UINT a2, WPARAM a3, LPARAM dwNewLong);
	int __thiscall DrawWnd(LPARAM this, HWND hWnd, int Y, int a4, LPARAM a5);
};