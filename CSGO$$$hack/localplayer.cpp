#include "includes.h"

// in milliseconds
#define JUMP_DELAY 17
#define SHOOT_DELAY 30

C_LocalPlayer::C_LocalPlayer() {
	m_dwBase = 0;
	m_iHealth = 0;
	m_iArmor = 0;
	m_iFlags = 0;
	m_iTeamNum = 0;

	update();
}

void C_LocalPlayer::update() {
	m_dwBase = *(uintptr_t*)(CLIENT + offsets::dwLocalPlayer);

	if (m_dwBase) {
		m_iHealth = *(int*)(m_dwBase + offsets::m_iHealth);
		m_iArmor = *(int*)(m_dwBase + offsets::m_ArmorValue);
		m_iFlags = *(int*)(m_dwBase + offsets::m_fFlags);
		m_iTeamNum = *(int*)(m_dwBase + offsets::m_iTeamNum);
		m_vVelocity = *(Vec3*)(m_dwBase + offsets::m_vecVelocity);
		m_vOrigin = *(Vec3*)(m_dwBase + offsets::m_vecOrigin);
	}
}

void C_LocalPlayer::forceJump() {
	*(int*)(CLIENT + offsets::dwForceJump) = CSGO::ACTIVE;
	Sleep(JUMP_DELAY);
	*(int*)(CLIENT + offsets::dwForceJump) = CSGO::INACTIVE;
}

void C_LocalPlayer::forceShoot() {
	*(int*)(CLIENT + offsets::dwForceAttack) = CSGO::ACTIVE;
	Sleep(SHOOT_DELAY);
	*(int*)(CLIENT + offsets::dwForceAttack) = CSGO::INACTIVE;
}

bool C_LocalPlayer::isAlive() {
	return m_iHealth > 0;
}