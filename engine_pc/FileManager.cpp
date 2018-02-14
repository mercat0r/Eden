/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/


#include "FileManager.h"
#include "..\..\include\typedefs.h"
#include <cstdio>
#include <d3d9.h>


FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}

/*
int __thiscall FileManager::LoadLevel(IDirect3D9 *g_pD3D, char *LevelName, int a3)
{
	char *FullPath;
	int result;
	_DWORD *v6;
	char *v7;
	int v8;
	char v9;
	int *v10;
	char FileName;
	char Extension;

	if (a3)
		*(_DWORD *)a3 = 0;

	FullPath = LevelName;
	LOBYTE(v10) = 0;

	if (!LevelName)
	{
		FileStruct fs;

		memset(&fs, 0, sizeof(stru_616818));
		byte_6165E0 = 0;
		fs.lStructSize = 76;
		fs.hwndOwner = (HWND)dword_614F24;
		fs.lpstrFilter = off_5F1640;
		fs.lpstrFile = &byte_6165E0;
		fs.nMaxFile = 256;
		fs.lpstrTitle = aLoadLevel;
		fs.Flags = 6148;
		fs.lpstrDefExt = (LPCSTR)off_5F1644[0];

		if (!GetOpenFileNameA(&fs))
			return 1;

		FullPath = fs.lpstrFile;
		LOBYTE(v10) = 1;
	}

	result = LoadLevelIntoD3D(g_pD3D, &FullPath, v10);
	if (!result)
	{
		if (a3)
		{
			_splitpath(FullPath, 0, 0, &FileName, &Extension);
			v6 = operator new(strlen(&FileName) + 1 + strlen(&Extension));
			*(_DWORD *)a3 = v6;

			if (v6)
			{
				v7 = &FileName;
				v8 = v6 - &FileName;

				do
				{
					v9 = *v7;
					v7[v8] = *v7;
					++v7;
				} while (v9);

				strcat(*(char **)a3, &Extension);
			}
		}
		result = 0;
	}

	return result;
}
*/
/*
signed int __thiscall FileManager::LoadLevelIntoD3D(IDirect3D9 *g_pD3D, char lpFileName, int *a3)
{
	HANDLE v4; // eax
	int v5; // edi
	signed int result; // eax
	bool v7; // zf
	int v8; // eax
	double v9; // st7
	int v10; // ecx
	__int16 v11; // fps
	bool v12; // c0
	char v13; // c2
	bool v14; // c3
	double v15; // st7
	signed int v16; // eax
	bool v17; // sf
	unsigned __int8 v18; // of
	double v19; // st7
	__int16 v20; // fps
	bool v21; // c0
	char v22; // c2
	bool v23; // c3
	int v24; // ecx
	int v25; // eax
	int v26; // ecx
	double v27; // st7
	__int16 v28; // fps
	bool v29; // c0
	char v30; // c2
	bool v31; // c3
	int v32; // ecx
	int v33; // ecx
	double v34; // st7
	__int16 v35; // fps
	bool v36; // c0
	char v37; // c2
	bool v38; // c3
	int v39; // eax
	char v40; // cl
	char v41; // al
	char *v42; // edi
	HANDLE v43; // eax
	HANDLE v44; // edi
	int v45; // ecx
	int i; // edi
	int v47; // ecx
	int v48; // edi
	int v49; // eax
	int v50; // eax
	int v51; // edi
	int j; // edx
	double v53; // st7
	int v54; // eax
	int v55; // ecx
	char v56; // [esp+8h] [ebp-420h]
	char v57; // [esp+108h] [ebp-320h]
	char v58; // [esp+20Ch] [ebp-21Ch]
	char FileName[260]; // [esp+30Ch] [ebp-11Ch]
	int v60; // [esp+410h] [ebp-18h]
	LPVOID lpBuffera; // [esp+414h] [ebp-14h]
	int v62; // [esp+418h] [ebp-10h]
	int v63; // [esp+41Ch] [ebp-Ch]
	int v64; // [esp+420h] [ebp-8h]
	char v65; // [esp+427h] [ebp-1h]

	v64 = 0;
	sub_508F70(1, 0x40000);
	*((_BYTE *)g_pD3D + 1964) = 0;
	g_pD3D[490] = 0;
	sprintf(g_lpFileName, "%s", lpFileName);
	v4 = sub_509200(g_lpFileName, 1u);
	v5 = (int)v4;

	if (v4 == (HANDLE)-1)
		return 1;

	v7 = g_pD3D[1229] == 2;
	lpFileName = 100.0 / flt_6166E8;

	if (v7)
	{
		v8 = sub_5093F0(v4);
		v9 = lpFileName + *((float *)g_pD3D + 1232);
		v10 = g_pD3D[1232];
		v60 = v8;
		g_pD3D[1233] = v10;
		*((float *)g_pD3D + 1232) = v9;
		v12 = v9 < 1.0;
		v13 = 0;
		v14 = v9 == 1.0;
		if (!(v11 & 0x4100))
			g_pD3D[1232] = 1065353216;
		v15 = (*((float *)g_pD3D + 1232) - *((float *)g_pD3D + 1233)) / (double)v60;
		g_pD3D[1230] = g_pD3D[1233];
		*((float *)g_pD3D + 1231) = v15;
	}

	v65 = 0;
	sub_45B570(g_pD3D);
	sub_4A30E0(&unk_75C050);
	sub_4A7800(7, sub_443930);
	sub_4A7800(10, sub_443BE0);
	sub_4A7800(13, sub_446C60);
	sub_4B97D0(g_pD3D, v5);
	v16 = *g_pD3D;
	v63 = *g_pD3D;

	if (v63 > 72)
	{
		v64 = 2;
	}

	else if (v16 < 72)
	{
		v64 = 3;
	}

	else
	{
		OdszyfrujReadFile(v5, (char *)&lpFileName + 3, 1u);
		OdszyfrujReadFile(v5, &v60, 4u);

		if (v60 > 356)
		{
			v64 = 1;
		}

		else
		{
			v62 = 0;
			if (v60 > 0)
			{
				lpBuffera = &dword_617E70;

				do
				{
					OdszyfrujReadFile(v5, lpBuffera, 4u);
					v18 = __OFSUB__(v62 + 1, v60);
					v17 = v62++ + 1 - v60 < 0;
					lpBuffera = (char *)lpBuffera + 36;
				} while (v17 ^ v18);
			}

			if (dword_6165C4 == 2)
			{
				lpBuffera = (LPVOID)sub_509350(v5, 0);
				v19 = (double)(signed int)lpBuffera * *(float *)&dword_6165CC + *(float *)&dword_6165D4;

				if (v19 - flt_6165C8 >= 0.0049999999)
				{
					flt_6165C8 = v19;
					v21 = v19 < 1.0;
					v22 = 0;
					v23 = v19 == 1.0;
					if (!(v20 & 0x4100))
						flt_6165C8 = 1.0;
					sub_44DBA0((HWND *)&lParam, 1.0);
				}
			}

			sub_45C710(v5, v63);
			sub_4B8DF0(v5, v63, sub_45C8C0);
			dword_6BE2DC = g_pD3D[25];

			if ((unsigned __int8)sub_4D20C0(v5, sub_45C8C0))
			{
				sub_4D4E10(&dword_615258);
				sub_45C3E0(v5, a3);
				v24 = g_pD3D[18];
				v62 = 0;

				if (v24 <= 0)
				{
				LABEL_24:
					sub_45BB20(v5);
					if (dword_6165C4 == 2)
					{
						a3 = (int *)sub_509350(v5, 0);
						v27 = (double)(signed int)a3 * *(float *)&dword_6165CC + *(float *)&dword_6165D4;

						if (v27 - flt_6165C8 >= 0.0049999999)
						{
							flt_6165C8 = v27;
							v29 = v27 < 1.0;
							v30 = 0;
							v31 = v27 == 1.0;
							if (!(v28 & 0x4100))
								flt_6165C8 = 1.0;
							sub_44DBA0((HWND *)&lParam, 1.0);
						}
					}

					v32 = g_pD3D[16];
					v63 = 0;

					if (v32 > 0)
					{
						a3 = 0;

						do
						{
							sub_45B930((char *)a3 + dword_6152D4);
							v33 = g_pD3D[16];
							v18 = __OFSUB__(v63 + 1, v33);
							v17 = v63++ + 1 - v33 < 0;
							a3 += 25;
						} while (v17 ^ v18);
					}

					OdszyfrujReadFile(v5, g_pD3D + 24, 4u);
					sub_4D5AC0(v5);
					OdszyfrujReadFile(v5, &v65, 1u);

					if (v65)
						OdszyfrujReadFile(v5, &v57, 0x104u);

					if (dword_6165C4 == 2)
					{
						a3 = (int *)sub_509350(v5, 0);
						v34 = (double)(signed int)a3 * *(float *)&dword_6165CC + *(float *)&dword_6165D4;

						if (v34 - flt_6165C8 >= 0.0049999999)
						{
							flt_6165C8 = v34;
							v36 = v34 < 1.0;
							v37 = 0;
							v38 = v34 == 1.0;
							if (!(v35 & 0x4100))
								flt_6165C8 = 1.0;
							sub_44DBA0((HWND *)&lParam, 1.0);
						}
					}

					g_pD3D[490] = sub_5092E0(v5);
					*((_BYTE *)g_pD3D + 1964) = 1;
				}

				else
				{
					a3 = 0;
					while (!v64)
					{
						v25 = sub_45BCA0(*(int *)((char *)a3 + g_pD3D[19] + 80));
						v26 = g_pD3D[18];
						v64 = v25;
						v18 = __OFSUB__(v62 + 1, v26);
						v17 = v62++ + 1 - v26 < 0;
						a3 += 51;

						if (!(v17 ^ v18))
						{
							if (v64)
								break;

							goto LABEL_24;
						}
					}
				}
			}

			else
			{
				v64 = 4;
			}
		}
	}

	sub_5092F0(v5);
	result = v64;

	if (!v64)
	{
		if (v65)
		{
			_splitpath(&v57, (char *)&lpFileName, &v56, &v58, 0);
			sprintf(g_lpFileName, aS_1, &v58);
			v39 = 0;

			do
			{
				v40 = g_lpFileName[v39];
				FileName[v39++] = v40;
			} while (v40);

			v41 = byte_5F1668;
			v42 = &FileName[strlen(FileName)];
			*(_DWORD *)v42 = dword_5F1664;
			v42[4] = v41;
			v43 = sub_509200(FileName, 1u);
			v44 = v43;

			if (v43 != (HANDLE)-1)
			{
				if ((unsigned __int8)sub_4AC9F0(v43))
					sub_4ABC90((int)&unk_61B4E8);

				sub_5092F0(v44);
			}
		}

		sub_45BFB0(g_pD3D);
		qsort(&dword_6082FC, dword_6082F8, 0xCu, sub_45C3C0);
		v45 = g_pD3D[18];
		lpFileName = 0.0;

		if (v45 > 0)
		{
			a3 = 0;
			do
			{
				for (i = *(int *)((char *)a3 + g_pD3D[19] + 80); i; i = *(_DWORD *)(i + 96))
				{
					if (*(_BYTE *)(i + 88) & 0x10)
						sub_4BA1E0(g_pD3D);
					if (*(_DWORD *)(i + 80))
						sub_45C340(*(_DWORD *)(i + 80));
				}
				v47 = g_pD3D[18];
				v18 = __OFSUB__(LODWORD(lpFileName) + 1, v47);
				v17 = LODWORD(lpFileName)++ + 1 - v47 < 0;
				a3 += 51;
			} while (v17 ^ v18);
		}
		lpFileName = 0.0;
		if ((signed int)dword_6082F8 > 0)
		{
			a3 = &dword_608304;
			do
			{
				v48 = *a3;
				if (dword_617E60[9 * *(_DWORD *)(*a3 + 8)] == 1)
				{
					v49 = sub_4A8A60(8);
					if (v49)
					{
						if (!*(_DWORD *)(v49 + 4))
						{
							sub_4BA1E0(g_pD3D);
							*(_BYTE *)(v48 + 89) |= 2u;
						}
					}
				}

				v18 = __OFSUB__(LODWORD(lpFileName) + 1, dword_6082F8);
				v17 = (signed int)(LODWORD(lpFileName)++ + 1 - dword_6082F8) < 0;
				a3 += 3;
			} while (v17 ^ v18);
		}

		v50 = g_pD3D[18];
		lpFileName = 0.0;

		if (v50 > 0)
		{
			v51 = 0;
			do
			{
				for (j = *(_DWORD *)(v51 + g_pD3D[19] + 80); j; j = *(_DWORD *)(j + 96))
				{
					if (*(_BYTE *)(j + 89) & 2)
						v53 = 0.0;
					else
						v53 = 1000000000.0;
					v54 = *(_DWORD *)(j + 80);
					*(float *)(j + 28) = v53;
					if (v54)
						sub_45C380(v54);
				}

				v55 = g_pD3D[18];
				v51 += 204;
				++LODWORD(lpFileName);
			} while (SLODWORD(lpFileName) < v55);
		}

		dword_75C404 = -747505337;
		dword_75C3FC = -747505337;
		sub_4CEF70(g_pD3D + 36);
		dword_694474 = 0;
		sub_4AEDF0(&unk_61B550);
		sub_44C7D0(&dword_6085FC);
		sub_44C9C0(&lParam);
		sub_508F70(0, 0x100000);
		sub_4A2210(sub_4A8FF0, g_pD3D);
		*((_BYTE *)g_pD3D + 4912) = 0;
		result = 0;
	}
	return result;
}
*/