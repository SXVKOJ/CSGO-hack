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

uintptr_t __stdcall basethread(HMODULE hModule);

namespace moduleConfig {
	extern bool bhop;
}

enum class AppState {
	RUNNING,
	PAUSED,
	STOPPED
};

class C_BaseApp {
private:
	HMODULE m_hModule;
	AppState m_state;
	C_LocalPlayer m_localPlayer;
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
	// getters
	AppState getState();
	C_LocalPlayer* getLocalPlayer();
	// setters
	void setState(const AppState state);
public:
	C_BaseApp();
	C_BaseApp(HMODULE hModule);
};

// определен в dllmain.cpp
extern C_BaseApp* pBaseApp;

#endif // !CSGO$$$HACK_MAIN_H_