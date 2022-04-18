#pragma once

#include <Windows.h>

#ifndef CSGO$$$HACK_DEFINES_H_
#define CSGO$$$HACK_DEFINES_H_

#define CSGO$$$HACK_VERSION_MAJOR 1

// операторы pystyle
#define is  ==
#define and &&
#define or  ||
#define not !

#define CLIENT (DWORD)GetModuleHandle("client.dll")
#define ENGINE (DWORD)GetModuleHandle("engine.dll")

// game const vars

namespace CSGO {
	constexpr int MAX_PLAYERS = 64;
	constexpr int FLAG_ON_GROUND = 257;
	constexpr int FLAG_IN_AIR = 256;
	constexpr int ACTIVE = 5;
	constexpr int INACTIVE = 4;
	constexpr int DEFAULT_FOV = 90;
}

#endif // !CSGO$$$HACK_DEFINES_H_