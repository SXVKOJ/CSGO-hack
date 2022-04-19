#include "includes.h"

#define localPlayer pBaseApp->m_game.m_localPlayer

void modules::bhop::update() {
	if (not localPlayer.isAlive())
		return;
	
	// Если игрок стоит на месте
	if (localPlayer.m_vVelocity is Vec3(0, 0, 0)) {
		return;
	}
	
	if (GetAsyncKeyState(VK_SPACE)) {
		if (localPlayer.m_iFlags is CSGO::FLAG_ON_GROUND) {
			localPlayer.forceJump();
		}
	}
}