#include "localplayer.h"

#ifndef CSGO$$$HACK_ENTITY_H_
#define CSGO$$$HACK_ENTITY_H_

class C_Entity : public C_LocalPlayer {
private:
	int index;
public:
	C_Entity operator[] (const int &index);
public:
	C_Entity();
};

#endif // !CSGO$$$HACK_ENTITY_H_