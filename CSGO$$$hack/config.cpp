// объ€вление всех переменных из config.h
#include "config.h"

float config::glowesp::enteam::color[3] = {3.f, 243.f, 251.f};
float config::glowesp::enteam::alpha = 255.f;

float config::glowesp::lpteam::color[3] = {139.f, 238.f, 10.f};
float config::glowesp::lpteam::alpha = 255.f;

float* config::glowesp::enteam::r = &color[0];
float* config::glowesp::enteam::g = &color[1];
float* config::glowesp::enteam::b = &color[2];

float* config::glowesp::lpteam::r = &color[0];
float* config::glowesp::lpteam::g = &color[1];
float* config::glowesp::lpteam::b = &color[2];