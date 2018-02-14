/**********************************************

	Project Eden

	By mercat0r
	
	Released under the MIT license.

**********************************************/

#include <tchar.h>
#include "Lang.h"


Lang::Lang()
{
	/* Set default language to English */
	CurrentLanguage = EN;
}


Lang::~Lang()
{
}


TCHAR *Lang::ReturnErrorString(int error_return_code)
{
	TCHAR *result;

	switch (error_return_code)
	{
	case 0:
		result = __T("Success - No error");
		break;

	case ERR_FAILED_OPEN_LEVEL:
		result = __T("Failed to open level file (Title.edf, GenText.EDT or TitleBackDrop.edn ?)");
		break;

	case ERR_MAP_VER_NEWER:
		result = __T("Failed, map version is newer than Eden (title.edf / TitleBackDrop.edn ?)");
		break;

	case ERR_MAP_VER_OLDER:
		result = __T("Failed, map version is older than Eden (title.edf / TitleBackDrop.edn ?)");
		break;

	case ERR_FAILED_GET_ACTOR_DATA:
		result = __T("Failed to get actor data from file");
		break;

	case ERR_FAILED_JOIN_GAME:
		result = __T("Failed to start / join the game");
		break;

	case 6:
		result = __T("Failed to correctly prepare a network game client");
		break;

	case ERR_FAILED_START_D3D:
		result = __T("Failed to start Direct3D9 (DirectX9) or Find a DX9 compatible graphics card.");
		break;

	case ERR_FAILED_SETUP_INPUTSYS:
		result = __T("Failed to set up the input system");
		break;

	case ERR_FAILED_SETUP_NETWORKSYS:
		result = __T("Failed to set up the network system");
		break;

	case 15:
		result = __T("Failed to initialise the network game type");
		break;

	case 16:
		result = __T("Failed to prepare the network for startup");
		break;

	case ERR_FAILED_REGISTER_WINDOW:
		result = __T("Failed to register the game window");
		break;

	case ERR_FAILED_CREATE_WINDOW:
		result = __T("Failed to create the game window");
		break;

	case ERR_FAILED_START_DINPUT:
		result = __T("Failed to start DirectInput");
		break;

	case ERR_FAILED_START_DSOUND:
		result = __T("Failed to start DirectSound");
		break;

	case 21:
		result = __T("Failed to start the input collection system");
		break;

	case ERR_FAILED_SETUP_D3D:
		result = __T("Failed to setup the DirectDraw or Direct3D");
		break;

	case ERR_FAILED_INIT_TIMESYS:
		result = __T("Failed to initialise the time system");
		break;

	case 24:
		result = __T("Command line parameters are invalid");
		break;

	case 26:
		result = __T("Timed out");
		break;

		/* Tylko w wersji finalnej/końcowej!!! */
#ifdef CDCHECK
	case ERR_NOCD:
		result = __T("No CD-ROM");
		break;
#endif

	default:
		result = 0;
		break;
	}
	return result;
}