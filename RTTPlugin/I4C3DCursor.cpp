#include "StdAfx.h"
#include "I4C3DCursor.h"
#include "Miscellaneous.h"

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

	hCursor = LoadCursorFromFile(_T("transparent.cur"));
	if (hCursor == NULL) {
		LogDebugMessage(Log_Error, _T("�����J�[�\�������[�h�ł��Ȃ����߁A�J�[�\���̕ύX���s���܂���B"));
		return FALSE;
	}

	if (SetSystemCursor(hCursor, 32512)) {
		return TRUE;
	} else {
		RestoreCursor();
	}
	DestroyCursor(hCursor);	// ���ݎg�p���̃J�[�\����Destroy���邱�Ƃ͂ł��Ȃ��B

	return FALSE;
}

void I4C3DCursor::RestoreCursor(void)
{
	SystemParametersInfo(SPI_SETCURSORS, 0, NULL, 0);
}
