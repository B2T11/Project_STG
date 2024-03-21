#pragma once
#include<cstdint>
#include"Vector2.h"
typedef struct bullet_s {
	vector2_t   pos;
	vector2_t   spacing;
	vector2_t   speed;
	int8_t      damage;
	float       hitboxRadius;
	float       angle;
	bool        isShot;
	bool        isHit;
	int         spriteWidth;
	int         spriteHeight;
}bullet_t;