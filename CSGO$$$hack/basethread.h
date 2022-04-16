#pragma once

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
		ThreadState state;
	public:
		virtual void run();
		virtual void stop();
	private:
		// вызывает keyboardHandler
		virtual void initKeyboardHandler();
		// Вызывает функции модулей чита
		// определен в callmodulemethods.cpp
		virtual void callModuleMethods();
		// отвечает за обработку нажатий на горячие клавиши
		// определен в keyboardhandler.cpp
		virtual void keyboardHandler();
	public:
		C_Thread();
	};

	extern C_Thread *pThread;
}

#endif // !CSGO$$$HACK_BASETHREAD_H_