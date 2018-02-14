/*

	CDCheck

	By mercat0r
	
	Released under the MIT license.

*/

#include <windows.h>
#include <stdio.h>
#include "C:\devgit\include\typedefs.h"

char LiteraDysku;

int dword_625BFC = 3157553;
__int16 word_625C00 = 92;

DWORD CheckCD()
{
	CHAR *v0; //ebp
	unsigned int v1; // kr04_4
	CHAR v2; // al
	int v3; // ecx
	char v4; // al
	DWORD FileSystemFlags; // [esp+18h] [ebp-320h]
	CHAR Buffer; // [esp+28h] [ebp-310h]
	CHAR VolumeNameBuffer; // [esp+130h] [ebp-208h]
	CHAR FileSystemNameBuffer; // [esp+234h] [ebp-104h]

	if (GetLogicalDriveStringsA(0x104u, &Buffer) && (v0 = &Buffer, Buffer))
	{
		while (GetDriveTypeA(v0) != 5
			|| !GetVolumeInformationA(v0, &VolumeNameBuffer, 0x104u, 0, 0, &FileSystemFlags, &FileSystemNameBuffer, 0x104u)
			|| memcmp(&VolumeNameBuffer, "PROJECTEDEN", 0xCu))
		{
			v1 = strlen(v0) + 1;
			v2 = v0[v1];
			v0 += v1;
			if (!v2)
			{
				FileSystemFlags = 27;
				goto END;
			}
		}

		v3 = &LiteraDysku - v0;
		do
		{
			v4 = *v0;
			v0[v3] = *v0;
			++v0;
		} while (v4);

		FileSystemFlags = 28;
	}
	else
	{
		FileSystemFlags = 27;
	}
END:
	return FileSystemFlags;
}