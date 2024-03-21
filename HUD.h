#pragma once
#include<cstdint>
#include"Vector2.h"
typedef struct HUD_s {
	vector2_t   pos;
	float       drawPosX;
	int8_t      flashSpeed;
	int8_t      flashTimer;
	bool        isFlash;
	uint32_t    color;
	int         spriteWidth;
	int         spriteHeight;
}HUD_t;