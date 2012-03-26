#pragma once
class CADController
{
public:
	CADController(void);
	virtual ~CADController(void);

	virtual void Execute(HWND hWnd, LPCSTR szCommand, double deltaX, double deltaY);

	virtual void TumbleExecute(int deltaX, int deltaY);
	virtual void TrackExecute(int deltaX, int deltaY);
	virtual void DollyExecute(int deltaX, int deltaY);

	// Tumble/Track/Dolly�ȊO�̃R�}���h�̎��s
	virtual void OriginalCommandExecute(LPCSTR command);
};

