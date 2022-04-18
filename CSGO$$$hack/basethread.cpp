#include "includes.h"

#define THREAD_DELAY 100 // in milliseconds

uintptr_t __stdcall basethread(HMODULE hModule) {
	while (pBaseApp -> getState() != AppState::STOPPED) {
		pBaseApp -> callExternalMethods();
		
		Sleep(THREAD_DELAY);

		if (GetAsyncKeyState(VK_INSERT)) {
			pBaseApp -> setState(AppState::STOPPED);
		}
	}

	FreeLibraryAndExitThread(hModule, 0);
}