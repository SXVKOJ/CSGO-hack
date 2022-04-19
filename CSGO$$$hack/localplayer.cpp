#include "includes.h"

// in milliseconds
#define JUMP_DELAY 17
#define SHOOT_DELAY 30

C_LocalPlayer::C_LocalPlayer() {
	m_dwBase = *(uintptr_t*)(CLIENT + offsets::dwLocalPlayer);
	
	m_iHealth = 0;
	m_iArmor = 0;
	m_iFlags = 0;
	m_iTeamNum = 0;
	m_iShotsFired = 0;
	m_iCrosshairId = 0;
	
	m_vVelocity = Vec3(0, 0, 0);
	m_vOrigin = Vec3(0, 0, 0);
	m_flFlashDuration = 0.f;
	
	update();
}

void C_LocalPlayer::update() {
	m_iHealth = *(int*)(m_dwBase + offsets::m_iHealth);
	m_iArmor = *(int*)(m_dwBase + offsets::m_ArmorValue);
	m_iFlags = *(int*)(m_dwBase + offsets::m_fFlags);
	m_iTeamNum = *(int*)(m_dwBase + offsets::m_iTeamNum);
	m_iCrosshairId = *(int*)(m_dwBase + offsets::m_iCrosshairId);
	m_iShotsFired = *(int*)(m_dwBase + offsets::m_iShotsFired);
	m_vVelocity = *(Vec3*)(m_dwBase + offsets::m_vecVelocity);
	m_vOrigin = *(Vec3*)(m_dwBase + offsets::m_vecOrigin);
	m_flFlashDuration = *(float*)(m_dwBase + offsets::m_flFlashDuration);
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

void C_LocalPlayer::forceForward() {
	*(int*)(CLIENT + offsets::dwForceForward) = CSGO::ACTIVE;
	Sleep(SHOOT_DELAY);
	*(int*)(CLIENT + offsets::dwForceForward) = CSGO::INACTIVE;
}

void C_LocalPlayer::forceBackward() {
	*(int*)(CLIENT + offsets::dwForceBackward) = CSGO::ACTIVE;
	Sleep(SHOOT_DELAY);
	*(int*)(CLIENT + offsets::dwForceBackward) = CSGO::INACTIVE;
}

void C_LocalPlayer::forceLeft() {
	*(int*)(CLIENT + offsets::dwForceLeft) = CSGO::ACTIVE;
	Sleep(SHOOT_DELAY);
	*(int*)(CLIENT + offsets::dwForceLeft) = CSGO::INACTIVE;
}

void C_LocalPlayer::forceRight() {
	*(int*)(CLIENT + offsets::dwForceRight) = CSGO::ACTIVE;
	Sleep(SHOOT_DELAY);
	*(int*)(CLIENT + offsets::dwForceRight) = CSGO::INACTIVE;
}

bool C_LocalPlayer::isAlive() {
	return m_iHealth > 0;
}

void C_LocalPlayer::resetFlashDuration() {
	*(float*)(m_dwBase + offsets::m_flFlashDuration) = 0.f;
}