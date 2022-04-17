#include "includes.h"
// файл отвечает за обработку нажатий всех горячих клавиш

#define ESCAPE_KEY VK_INSERT
// количество миллисекунд в одной секунде
#define MIL_SECOND 1000
// количество миллисекунд в одной минуте
#define MIL_MINUTE (60 * MIL_SECOND)
// задержка ядра для оптимизации (больше - быстрее, меньше - стабильнее)
#define THREAD_DELAY MIL_SECOND // in milliseconds

uintptr_t __stdcall
basethread::C_Thread::keyboardHandler() {
	while (state == ThreadState::running) {
		if (GetAsyncKeyState(ESCAPE_KEY)) {
			state = ThreadState::stopped;
		}

		Sleep(THREAD_DELAY);
	}

	FreeLibraryAndExitThread(hModule, 0);
}