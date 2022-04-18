#include "includes.h"

C_LocalPlayer localPlayer;

void modules::bhop::update() {
	localPlayer.update();

	if (not localPlayer.isAlive())
		return;
	
	if (GetAsyncKeyState(VK_SPACE)) {
		if (localPlayer.m_iFlags is CSGO::FLAG_ON_GROUND) {
			localPlayer.forceJump();
		}
	}
}