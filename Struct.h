#pragma once
#include<cstdint>
typedef struct vector2_s {
	float       x;
	float       y;
}vector2_t;

typedef struct player_s{
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

typedef struct enemy_s{
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

typedef struct lockon_s{
	vector2_t   pos;
}lockon_t;

typedef struct missile_s{
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

typedef struct bullet_s{
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

typedef struct WPNOC_s{
	int         timer;
	int         coolDownTimer;
	bool        isCoolDown;
}WPNOC_t;

typedef struct HUD_s{
	vector2_t   pos;
	float       drawPosX;
	int8_t      flashSpeed;
	int8_t      flashTimer;
	bool        isFlash;
	uint32_t    color;
	int         spriteWidth;
	int         spriteHeight;
}HUD_t;

typedef struct item_s{
	vector2_t   pos;
	vector2_t   speed;
	float       hitboxRadius;
	int         randSpawn;
	bool        isSpawn;
}item_t;

typedef struct animetion_s{
	int         timer;
	int8_t      currentFrame;
}animetion_t;

typedef struct object_s {
	vector2_t   pos;
	vector2_t   speed;
	int8_t      radius;
	int         timer;
	bool        isShot;
}object_t;

//typedef struct particle_s {
//	vector2_t   pos;
//	int         timer;
//	bool        isShot;
//}particle_t;