/*+===================================================================
* @file:			baseapp.h
* 
* @purpose:			This file contains the base class for all applications
* 
* @classes: 		CBaseApp
* 
* @enums:			AppState
* 
* @functions:		basethread
* 
* ===================================================================+*/

#pragma once

#include <string>
#include <map>

#include <Windows.h>

#ifndef CSGO$$$HACK_MAIN_H_
#define CSGO$$$HACK_MAIN_H_

// определен в basethread.cpp
uintptr_t __stdcall basethread(HMODULE hModule);

// Опрелен в baseapp.cpp
namespace moduleConfig {
	extern bool bhop;
}

enum class AppState {
	RUNNING,
	PAUSED,
	STOPPED
};

class C_Game {
public:
	C_LocalPlayer m_localPlayer{};
public:
	// Обновляет значение всех переменных подчиненных классов
	void update();
};

class C_BaseApp {
private:
	HMODULE  m_hModule;
	AppState m_state;
public:
	C_Game	 m_game{};
#if CSGO$$$HACK_DEBUG
	FILE* m_fConsole;
#endif // !CSGO$$$HACK_DEBUG
private:
	// Словарь для получения адресов по имени модуля
	std::map<std::string, void*> m_mapFunctions;
private:
	void runModule(const std::string &moduleName);
	void regModule(const std::string &moduleName, void* pFunction);
public:
	void run();
	void stop();
	void callExternalMethods();
public:
	// getters
	AppState getState();
public:
	// setters
	void setState(const AppState state);
public:
	C_BaseApp();
	C_BaseApp(HMODULE hModule);
	~C_BaseApp();
};

// определен в dllmain.cpp
extern C_BaseApp* pBaseApp;

#endif // !CSGO$$$HACK_MAIN_H_