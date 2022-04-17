#pragma once
#include <Windows.h>

#ifndef CSGO$$$HACK_BASETHREAD_H_
#define CSGO$$$HACK_BASETHREAD_H_

// Состояние потока, при активном stopped поток не будет выполняться
enum class ThreadState
{
	running,
	stopped
};

namespace moduleconfig
{
	extern bool glowesp;
}

namespace basethread
{
	class C_Thread
	{
	private:
		HMODULE hModule;
		ThreadState state;
	public:
		void run(HMODULE hModule);
		void stop();
	private:
		uintptr_t __stdcall mainthread();
		// вызывает keyboardHandler
		void initKeyboardHandler();
		// Вызывает функции модулей чита
		// определен в callmodulemethods.cpp
		void callModuleMethods();
		// отвечает за обработку нажатий на горячие клавиши
		// определен в keyboardhandler.cpp
		uintptr_t __stdcall keyboardHandler();
	public:
		C_Thread();
	};

	extern C_Thread *pThread;
}

#endif // !CSGO$$$HACK_BASETHREAD_H_