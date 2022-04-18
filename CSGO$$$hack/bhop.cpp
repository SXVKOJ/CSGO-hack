#include "includes.h"

C_LocalPlayer* localPlayer = pBaseApp->getLocalPlayer();

void modules::bhop::update() {
	std::cout << 1 << endl;
	if (not localPlayer->isAlive())
		return;
	
	localPlayer->update();
	
	if (GetAsyncKeyState(VK_SPACE)) {
		if (localPlayer->m_iFlags is CSGO::FLAG_ON_GROUND) {
			localPlayer->forceJump();
		}
	}
}