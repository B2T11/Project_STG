#pragma once
#include<cstdint>
#include"Vector2.h"

typedef struct player_s {
	vector2_t   pos;
	vector2_t   speed;
	vector2_t   length;
	int8_t      hp;
	int8_t      weaponRate;
	int8_t      weaponLV;
	float       drawPosX;
	float       hitboxRadius;
	bool        isAlive;
	bool        isOC;
}player_t;
