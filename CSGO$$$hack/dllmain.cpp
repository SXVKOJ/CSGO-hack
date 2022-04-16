// Точка входа в приложение
#include "includes.h"

basethread::C_Thread* basethread::pThread = new basethread::C_Thread();

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        basethread::pThread->run();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        basethread::pThread->stop();
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

