#include "includes.h"
#include "glowesp.h"

#define CLIENT (uintptr_t)GetModuleHandle("client.dll")
#define ENGINE (uintptr_t)GetModuleHandle("engine.dll")

#define PLAYER_START 1
#define PLAYERS_MAX 64
#define PLAYER_SIZE 0x38

#define m_bRenderWhenOccluded(entityGlowIndex)   ((entityGlowIndex + PLAYER_SIZE) + 0x28)
#define m_bRenderWhenUnoccluded(entityGlowIndex) ((entityGlowIndex + PLAYER_SIZE) + 0x29)

void
glowesp::update() {
	int lpteam = *(int*)(CLIENT + offsets::dwLocalPlayer);
	uintptr_t glowManager = *(uintptr_t*)(ENGINE + offsets::dwGlowObjectManager);
	uintptr_t entitylist = *(uintptr_t*)(CLIENT + offsets::dwEntityList);

	for (int i = PLAYER_START; i < PLAYERS_MAX; i++) {
		uintptr_t entity = *(uintptr_t*)(entitylist + i * PLAYER_SIZE);

		if (!entity) {
			continue;
		}

		int entityhealth = *(int*)(entity + offsets::m_iHealth);

		if (entityhealth <= 0) {
			continue;
		}

		int entityteam = *(int*)(entity + offsets::m_iTeamNum);
		int entityGlowIndex = *(int*)(entity + offsets::m_iGlowIndex);

		if (entityteam == lpteam) {
			*(float*)(glowManager + (entityGlowIndex * PLAYER_SIZE) + 0x8) = *config::glowesp::lpteam::r;
			*(float*)(glowManager + (entityGlowIndex * PLAYER_SIZE) + 0xC) = *config::glowesp::lpteam::g;
			*(float*)(glowManager + (entityGlowIndex * PLAYER_SIZE) + 0x10) = *config::glowesp::lpteam::b;
			*(float*)(glowManager + (entityGlowIndex * PLAYER_SIZE) + 0x14) = config::glowesp::lpteam::alpha;
		}
		else {
			*(float*)(glowManager + (entityGlowIndex * PLAYER_SIZE) + 0x8) = *config::glowesp::enteam::r;
			*(float*)(glowManager + (entityGlowIndex * PLAYER_SIZE) + 0xC) = *config::glowesp::enteam::g;
			*(float*)(glowManager + (entityGlowIndex * PLAYER_SIZE) + 0x10) = *config::glowesp::enteam::b;
			*(float*)(glowManager + (entityGlowIndex * PLAYER_SIZE) + 0x14) = config::glowesp::enteam::alpha;
		}

		*(bool*)(entity + m_bRenderWhenOccluded(entityGlowIndex)) = TRUE;
		*(bool*)(entity + m_bRenderWhenUnoccluded(entityGlowIndex)) = FALSE;
	}
}