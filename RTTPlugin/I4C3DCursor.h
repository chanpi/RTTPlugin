#pragma once

#define CURSOR_FILE_NAME	 "transparent.cur"

class I4C3DCursor
{
public:
	I4C3DCursor(void);
	~I4C3DCursor(void);

	BOOL SetTransparentCursor();
	void RestoreCursor(void);
};

