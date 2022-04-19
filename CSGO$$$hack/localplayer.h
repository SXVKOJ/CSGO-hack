#include <Windows.h>
#include "vec.h"

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
	int m_iShotsFired;
	int m_iCrosshairId;
	Vec3 m_vVelocity;
	Vec3 m_vOrigin;
	float m_flFlashDuration;
public:
	void forceJump();
	void forceShoot();
	void forceForward();
	void forceBackward();
	void forceLeft();
	void forceRight();
	
	void resetFlashDuration();
	
	bool isAlive();
public:
	// обновляет все внутреигровые переменные
	void update();
public:
	C_LocalPlayer();
};

#endif // !CSGO$$$HACK_LOCALPLAYER_H_