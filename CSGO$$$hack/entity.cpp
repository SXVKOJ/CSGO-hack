#include "includes.h"

#define FIRST_PLAYER_INDEX 1

C_Entity::C_Entity() {
	index = FIRST_PLAYER_INDEX;
	
	uintptr_t entitylist = *(uintptr_t*)(CLIENT + offsets::dwEntityList);
	
	m_dwBase = *(uintptr_t*)(entitylist + (index * CSGO::PLAYER_SIZE));
}

C_Entity C_Entity::operator[] (const int &index) {
	this->index = index;
	
	uintptr_t entitylist = *(uintptr_t*)(CLIENT + offsets::dwEntityList);
	
	m_dwBase = *(uintptr_t*)(entitylist + (index * CSGO::PLAYER_SIZE));

	update();
	
	return *this;
}