#include "includes.h"

#define localPlayer pBaseApp->m_game.m_localPlayer

void modules::noflash::update() {
	if (not localPlayer.isAlive()) {
		return;
	}

	if (localPlayer.m_flFlashDuration > 0.0f) {
		localPlayer.resetFlashDuration();
	}
}