#include "basethread.h"
#include <Windows.h>

basethread::C_Thread::C_Thread() {
	state = ThreadState::running;
}

void
basethread::C_Thread::initKeyboardHandler() {
	auto pKeyboard = &C_Thread::keyboardHandler;

	if (state == ThreadState::running) {
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&pKeyboard, NULL, NULL, NULL);
	}
}

void
basethread::C_Thread::run() {
	//initKeyboardHandler()
	// TODO: поместить этот блок в хук функции обновления кадра
	while (state == ThreadState::running) {
		callModuleMethods();
	}
}

void
basethread::C_Thread::stop() {
	state = ThreadState::stopped;
}