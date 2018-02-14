/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/

#pragma once
#include <windows.h>

/* Definicje języków */
#define EN 0
#define FR 1
#define DE 2
#define IT 3
#define SP 4
#define JP 5
/* Zaimplementuj język Polski! */

/* Definicje błędów */
#define ERR_FAILED_OPEN_LEVEL		1
#define ERR_MAP_VER_NEWER			2
#define ERR_MAP_VER_OLDER			3
#define ERR_FAILED_GET_ACTOR_DATA	4
#define ERR_FAILED_JOIN_GAME		5

#define ERR_FAILED_START_D3D		12
#define ERR_FAILED_SETUP_INPUTSYS	13
#define ERR_FAILED_SETUP_NETWORKSYS	14

#define ERR_FAILED_REGISTER_WINDOW	17
#define ERR_FAILED_CREATE_WINDOW	18
#define ERR_FAILED_START_DINPUT		19
#define ERR_FAILED_START_DSOUND		20

#define ERR_FAILED_SETUP_D3D		22
#define ERR_FAILED_INIT_TIMESYS		23

#ifdef CDCHECK
#define ERR_NOCD					27
#endif

class Lang
{
public:
	Lang();
	~Lang();

	/* Funkcja singletonowa */
	static Lang &GetSingleton()
	{
		static Lang singleton;
		return singleton;
	}

	BYTE CurrentLanguage;

	TCHAR *ReturnErrorString(int error_return_code);
};