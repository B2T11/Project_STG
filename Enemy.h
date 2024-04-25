#pragma once
#include<cstdint>
#include"Vector2.h"
typedef struct enemy_s {
	vector2_t   pos;
	vector2_t   speed;
	int8_t      indexR;
	int8_t      hp;
	float       hitboxRadius;
	bool        isAlive;
	float       angle;
	int8_t      shotTimer;
	int8_t      rate;
	vector2_t   target;
	int8_t      moveCase;
	uint32_t    color;
	int8_t      colorChangeTimer;
	int         spriteWidth;
	int         spriteHeight;
	//float       kLeftTopX,
	//            kLeftTopY;
	//float       kRightTopX,
	//	        kRightTopY;
	//float       kLeftBottomX,
	//            kLeftBottomY;
	//float       kRightBottomX,
	//	        kRightBottomY;
	//vector2_t   leftTopRotated;
	//vector2_t   leftTopPos;
	//float       theta;
}enemy_t;
