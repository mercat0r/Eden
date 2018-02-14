/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/

#pragma once
#include <d3d9.h>

class FileManager
{
public:
	FileManager();
	~FileManager();

#pragma pack(push, 1)
	struct FileStruct
	{
		DWORD lStructSize;
		HWND hwndOwner;
		HINSTANCE hInstance;
		LPCSTR lpstrFilter;
		LPSTR lpstrCustomFilter;
		DWORD nMaxCustFilter;
		DWORD nFilterIndex;
		LPSTR lpstrFile;
		DWORD nMaxFile;
		LPSTR lpstrFileTitle;
		DWORD nMaxFileTitle;
		LPCSTR lpstrInitialDir;
		LPCSTR lpstrTitle;
		DWORD Flags;
		WORD nFileOffset;
		WORD nFileExtension;
		LPCSTR lpstrDefExt;
		LPARAM lCustData;
		LPOFNHOOKPROC lpfnHook;
		LPCSTR lpTemplateName;
	};
#pragma pack(pop)

	/* Funkcja singletonowa */
	static FileManager &GetSingleton()
	{
		static FileManager singleton;
		return singleton;
	}

//	int __thiscall LoadLevel(IDirect3D9 *g_pD3D, char *LevelName, int a3);
//	signed int __thiscall LoadLevelIntoD3D(IDirect3D9 *g_pD3D, char lpFileName, int *a3);

	char g_lpFileName[264];
};