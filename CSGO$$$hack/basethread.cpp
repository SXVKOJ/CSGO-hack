#include "basethread.h"
#include <Windows.h>

basethread::C_Thread::C_Thread() {
	state = ThreadState::running;
}

void
basethread::C_Thread::initKeyboardHandler() {
	auto pKeyboard = &C_Thread::keyboardHandler;

	if (state == ThreadState::running) {
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&pKeyboard, hModule, NULL, NULL);
	}
}

void
basethread::C_Thread::run(HMODULE hModule) {
	this->hModule = hModule;
	
	initKeyboardHandler();

	auto pMain = &C_Thread::mainthread;
	
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&pMain, hModule, NULL, NULL);
}

void
basethread::C_Thread::stop() {
	state = ThreadState::stopped;
}

uintptr_t __stdcall
basethread::C_Thread::mainthread() {
	// TODO: поместить этот блок в хук функции обновления кадра
	while (state == ThreadState::running) {
		callModuleMethods();
	}

	FreeLibraryAndExitThread(hModule, 0);
}