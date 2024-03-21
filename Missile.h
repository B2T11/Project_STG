#pragma once
#include<cstdint>
#include"Vector2.h"
typedef struct missile_s {
	vector2_t   pos;
	vector2_t   dir;
	vector2_t   target;
	float       t;
	float       angle;
	bool        isShot;
	bool        isHit;
	float       hitboxRadius;
	int         spriteWidth;
	int         spriteHeight;
}missile_t;