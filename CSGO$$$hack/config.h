#pragma once

#ifndef CSGO$$$HACK_CONFIG_H_
#define CSGO$$$HACK_CONFIG_H_

namespace config
{
	namespace glowesp {
		// моя команда
		namespace lpteam {
			extern float color[3];
			extern float alpha;
			
			extern float* r;
			extern float* g;
			extern float* b;
		}
		// команда противника
		namespace enteam {
			extern float color[3];
			extern float alpha;

			extern float* r;
			extern float* g;
			extern float* b;
		}
	}
}

#endif // !CSGO$$$HACK_CONFIG_H_