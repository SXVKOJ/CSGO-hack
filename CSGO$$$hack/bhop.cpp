#include "includes.h"

C_LocalPlayer* localPlayer = pBaseApp->getLocalPlayer();

void modules::bhop::update() {
	if (!localPlayer)
		return;
	if (!localPlayer->isAlive())
		return;
	
	localPlayer->update();
	
	if (GetAsyncKeyState(VK_SPACE)) {
		if (localPlayer->m_iFlags is CSGO::FLAG_ON_GROUND) {
			localPlayer->forceJump();
		}
	}
}