#include "basethread.h"

basethread::C_Thread::C_Thread() {
	state = ThreadState::running;
}

void
basethread::C_Thread::initKeyboardHandler() {
	if (state == ThreadState::running) {
		keyboardHandler();
	}
}

void
basethread::C_Thread::run() {
	initKeyboardHandler();

	while (state == ThreadState::running) {
		callModuleMethods();
	}
}

void
basethread::C_Thread::stop() {
	state = ThreadState::stopped;
}