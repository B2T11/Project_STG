#pragma once
#include<cstdint>
#include"Vector2.h"
typedef struct object_s {
	vector2_t   pos;
	vector2_t   speed;
	int8_t      radius;
	int         timer;
	bool        isShot;
}object_t;
