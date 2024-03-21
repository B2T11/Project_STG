#pragma once
#include<cstdint>
#include"Vector2.h"
typedef struct item_s {
	vector2_t   pos;
	vector2_t   speed;
	float       hitboxRadius;
	int         randSpawn;
	bool        isSpawn;
}item_t;