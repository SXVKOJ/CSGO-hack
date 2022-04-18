/*+===================================================================
* @file:		localplayer.h
* 
* @summary:		Local player class
* 
* @classes:		C_LocalPlayer
* 
* @functions:	none
* 
* ===================================================================+*/

#pragma once

#ifndef CSGO$$$HACK_LOCALPLAYER_H_
#define CSGO$$$HACK_LOCALPLAYER_H_

class C_LocalPlayer {
public:
	DWORD m_dwBase;
	int m_iHealth;
	int m_iArmor;
	int m_iTeamNum;
	int m_iFlags;
public:
	void forceJump();
	void forceShoot();
	bool isAlive();
public:
	// обновляет все внутреигровые переменные
	void update();
public:
	C_LocalPlayer();
};

#endif // !CSGO$$$HACK_LOCALPLAYER_H_