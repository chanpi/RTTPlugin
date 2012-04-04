#include "StdAfx.h"
#include "I4C3DCursor.h"
#include "Misc.h"
#include "SharedConstants.h"


#if UNICODE || _UNICODE
static LPCTSTR g_FILE = __FILEW__;
#else
static LPCTSTR g_FILE = __FILE__;
#endif

I4C3DCursor::I4C3DCursor(void)
{
}

I4C3DCursor::~I4C3DCursor(void)
{
	RestoreCursor();
}

BOOL I4C3DCursor::SetTransparentCursor()
{
	HCURSOR hCursor;

	hCursor = LoadCursorFromFile(_T(CURSOR_FILE_NAME));
	if (hCursor == NULL) {
		LoggingMessage(Log_Error, _T(MESSAGE_ERROR_CURSOR_MISSING), GetLastError(), g_FILE, __LINE__);

		return FALSE;
	}

	if (SetSystemCursor(hCursor, 32512)) {
		return TRUE;
	} else {
		RestoreCursor();
	}
	DestroyCursor(hCursor);	// 現在使用中のカーソルはDestroyすることはできない。

	return FALSE;
}

void I4C3DCursor::RestoreCursor(void)
{
	SystemParametersInfo(SPI_SETCURSORS, 0, NULL, 0);
}
