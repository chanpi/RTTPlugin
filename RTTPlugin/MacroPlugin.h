#pragma once

class MacroPlugin
{
public:
	MacroPlugin(void);
	virtual ~MacroPlugin(void);

	virtual BOOL RegisterMacro(LPCSTR szBuffer, char* termination);
	virtual void PlayMacro(LPCSTR macroName, HWND hKeyInputWnd, BOOL bUsePostMessageToSendKey);
	virtual void CleanupMacro(void);

protected:
	virtual BOOL AnalyzeMacro(LPCSTR macroName, LPCSTR macroValue);
};

