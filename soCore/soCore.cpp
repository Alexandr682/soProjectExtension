/*
*	S.T.A.L.K.E.R. Online - Core module
*	Developers:
*		009 (Михайлов Алексей)
*		
*	Extension:
*		DiR.X (Александр Шевченко)
*/

#include <windows.h>
#include <stdlib.h>

#include <stdio.h>

#include "multipatch.h"
#include "md5.h"
#include "resource.h"

#pragma comment(lib,"../X-Ray libs/xrCore.lib")
#pragma comment(lib,"../X-Ray libs/xrEngine.lib")
#pragma comment(lib,"../X-Ray libs/xrGame.lib")
#pragma comment(lib,"../X-Ray libs/xrCDB.lib")

/*
*	Vars
*/
CHook*	HookHandle;
BYTE	PatchVersion;
bool	g_dedicated_server;
bool	error = false;

// FOV  command
//float* g_fov = &(DWORD)(HookHandle->GameOffset + 0x635C44));
float  g_fov_min = 55;
float  g_fov_max = 90;
CCC_Float* g_fov_cmd;

/*
*	Headers functions
*/
bool CheckParamExist(wchar_t* paramline,wchar_t* param);
void HookSetup();
void LoadNetworkGame();
void LoadCoopGame();
void GetNetworkVersion();
void testFov(const char* agrs);

/*
*	Functions body
*/
bool CheckParamExist(wchar_t* paramline,wchar_t* param)
{
	int len1 = wcslen(paramline);
	int len2 = wcslen(param);

	for(int i = 0;i < len1 - len2;i++)
	{
		int j = 0;
		for(;j < len2;j++)
		{
			if(paramline[i + j] != param[j]) break;
		}

		if(j == len2) return true;
	}
	return false;
}

void HookSetup()
{
	while(GetModuleHandle(L"xrCore.dll") == NULL) Sleep(100);

	DWORD check_addr = (DWORD)GetModuleHandle(L"xrCore.dll") + 0x12120;
	
	if(*(BYTE*)(check_addr) == 0xC8) HookHandle = new CHook_Patch_00();
	else if(*(BYTE*)(check_addr) == 0x00) HookHandle = new CHook_Patch_01();
	else if(*(BYTE*)(check_addr) == 0x8B) HookHandle = new CHook_Patch_02();
	else MessageBox(NULL,L"Неизвестная версия.",L"S.T.A.L.K.E.R. Online",MB_OK);
	
	HookHandle->InstallHooks();
	HookHandle->LinkAddresses();
}

void testFov(const char* agrs)
{
	/*void(_cdecl * Msg)(char const*, ...);
	Msg = reinterpret_cast<void(_cdecl*)(char const*, ...)>(GetProcAddress(GetModuleHandle(L"xrCore.dll"), "?Msg@@YAXPBDZZ"));

	float fov = (float)strtod(agrs, NULL);
	if (fov > g_fov_min && fov < g_fov_max) 
	{
		Msg("FOV set to: %0.f, %0.f, %f, %f", fov, g_fov_cmd->GetValue(), &g_fov_cmd->valuef, &g_fov_cmd->valuet);
		g_fov = &fov;
		g_fov_cmd->valuef = &fov;
		HookHandle->FloatToHex((DWORD)(HookHandle->GameOffset)+0x635C44, fov);
		Msg("FOV set to: %0.f, %0.f", *g_fov, g_fov_cmd->GetValue());
	}
	else
	{
		g_fov_cmd->InvalidSyntax();
	}*/

}

void test_so() {


	
	void (_cdecl * Msg)(char const *, ...);


	Msg = reinterpret_cast<void (_cdecl *)(char const *, ...)>(GetProcAddress(GetModuleHandle(L"xrCore.dll"),"?Msg@@YAXPBDZZ"));
	DWORD CLevel = (DWORD)g_pGameLevel;
	DWORD game_cl_GameState = *(DWORD*)(CLevel+0x486F8);



	Msg("pointer %x",*(DWORD*)(game_cl_GameState+0xBC));
}

void MainThread(void*)
{
	// check dedicated
	wchar_t* cmdline = GetCommandLine();
	g_dedicated_server = CheckParamExist(cmdline,L"-dedicated");
	// vars
	IConsole_Command* cmd;
	// hook
	HookSetup();
	// add commands
	// network game
	cmd = HookHandle->CreateConsoleCommand("so",test_so);
	HookHandle->Console->AddCommand(cmd);
	// network version
	cmd = HookHandle->CreateConsoleCommand("so_version_network_game",GetNetworkVersion);
	HookHandle->Console->AddCommand(cmd);
	// load module for dedicated (EDITED: FOR ALL)
	//float* test = new float(55);
	//void(_cdecl * Execute)(char const*);
	//Execute = reinterpret_cast<void(_cdecl*)(char const*)>(GetProcAddress(GetModuleHandle(L"xrEngine.exe"), "?Execute@CCC_Float@@UAEXPBD@Z"));

	//float* g_fov = (float*)*(DWORD*)((DWORD)HookHandle->GameOffset + 0x635C44);
	//void(_cdecl * Msg)(char const *, ...);
	//Msg = reinterpret_cast<void(_cdecl *)(char const *, ...)>(GetProcAddress(GetModuleHandle(L"xrCore.dll"), "?Msg@@YAXPBDZZ"));
	//Msg("test_fov!!! %f", g_fov);
	//DWORD game_cl_GameState = (DWORD)(*(DWORD*)CLevel + 0x486F8);

	//g_fov_cmd = HookHandle->CreateConsoleCommandFloat("fov", g_fov, g_fov_min, g_fov_max);
	//HookHandle->Console->AddCommand(g_fov_cmd);
	/*if(g_dedicated_server)*/ LoadNetworkGame();
}

void LoadNetworkGame()
{
	if(GetModuleHandle(L"soNetwork.dll") == NULL) 
	{
		if(g_dedicated_server) LoadLibrary(L"../soProject/soNetwork.dll");
		else LoadLibrary(L"./soProject/soNetwork.dll");
	}
}

void GetNetworkVersion()
{
	HMODULE handle = GetModuleHandle(L"soNetwork.dll");
	if(handle != NULL)
	{
		void (__cdecl* GetModuleVersion)(char* dest,int size);
		void (_cdecl * Msg)(char const *, ...);
		char versionstr[64];

		GetModuleVersion = reinterpret_cast<void (_cdecl *)(char* dest,int size)>(GetProcAddress(handle,"?GetModuleVersion@@YAXPADH@Z"));
		Msg = reinterpret_cast<void (_cdecl *)(char const *, ...)>(GetProcAddress(GetModuleHandle(L"xrCore.dll"),"?Msg@@YAXPBDZZ"));
		
		GetModuleVersion(versionstr,64);

		Msg("soNetwork module version: %s",versionstr);
	}
}

/*
*	Dll entry point
*/

BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			// loadscreen
			HRSRC hRes = FindResource(hModule, MAKEINTRESOURCE(IDB_LOADSCREEN), RT_BITMAP);
			HGLOBAL hResLoad = LoadResource(hModule, hRes);
			LPVOID lpResLock = LockResource(hResLoad);

			HMODULE hExe = GetModuleHandle(TEXT("xrEngine.exe"));

			HRSRC hRes2 = FindResource(hExe, MAKEINTRESOURCE(123), RT_BITMAP);
			HGLOBAL hRes2Load = LoadResource(hExe, hRes2);
			LPVOID lpRes2Lock = LockResource(hRes2Load);
			
			DWORD oldp;
			VirtualProtect(lpRes2Lock,SizeofResource(hModule, hRes),PAGE_EXECUTE_READWRITE, &oldp);
			memcpy(lpRes2Lock,lpResLock,SizeofResource(hModule, hRes));
			
			// thread
			DWORD threadId = 0; 
			if(!error) 
			{
				CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&MainThread, 0, 0, (LPDWORD)&threadId);
			}
			break;
		}
	case DLL_PROCESS_DETACH:
		{
			break;
		}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}