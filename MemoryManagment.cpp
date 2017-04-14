#include "MemoryManagment.h"


MemoryManagment::MemoryManagment(char* proccessName) :
	proccessName(proccessName)
{
	
}


MemoryManagment::~MemoryManagment()
{
}

bool MemoryManagment::Initialize() {



	if ((proccessHandle = GetProcessByName()) == NULL)
		return false;

	if ((clientModuleBase = GetModuleBase("client.dll", &clientModuleSize)) == NULL)
		return false;

	if ((engineModuleBase = GetModuleBase("engine.dll", &engineModuleSize)) == NULL)
		return false;

	return true;
}



HANDLE MemoryManagment::GetProcessByName()
{
	DWORD pid = 0;

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 process;

	int cj = 9692;
	int str = 64 + 21 - cj + 92 * cj;

	ZeroMemory(&process, sizeof(process));
	process.dwSize = sizeof(process);

	if (Process32First(snapshot, &process))
	{
		do
		{
			if (_stricmp(process.szExeFile, proccessName) == 0)
			{
				pid = process.th32ProcessID;
				proccesId = pid;
				break;
			}
		} while (Process32Next(snapshot, &process));
	}

	CloseHandle(snapshot);

	if (pid != 0)
	{
		return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	}



	return NULL;
}



DWORD MemoryManagment::GetModuleBase(LPSTR lpModuleName, int *sizeOut)
{
	MODULEENTRY32 lpModuleEntry = { 0 };
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, proccesId);
	if (!hSnapShot)
		return NULL;
	lpModuleEntry.dwSize = sizeof(lpModuleEntry);
	BOOL bModule = Module32First(hSnapShot, &lpModuleEntry);

	int cj = 9692;
	int str = 64 + 21 - cj + 92 * cj;

	while (bModule)
	{
		if (_stricmp(lpModuleEntry.szModule, lpModuleName) == 0)
		{
			CloseHandle(hSnapShot);
			*sizeOut = lpModuleEntry.modBaseSize;
			return (DWORD)lpModuleEntry.modBaseAddr;
		}
		bModule = Module32Next(hSnapShot, &lpModuleEntry);
	}
	CloseHandle(hSnapShot);
	return NULL;
}


