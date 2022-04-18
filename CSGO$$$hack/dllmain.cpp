#define _CRT_SECURE_NO_WARNINGS
/**
 * @file:       dllmain.cpp
 * 
 * @summary:    application entry point
 */

#include "includes.h"

C_BaseApp* pBaseApp = new C_BaseApp();

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    pBaseApp = new C_BaseApp(hModule);

    if (CSGO$$$HACK_DEBUG) {
        AllocConsole();
        pBaseApp->m_fConsole = freopen("CONOUT$", "w", stdout);
    }
	
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        pBaseApp->run();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        pBaseApp->stop();
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

