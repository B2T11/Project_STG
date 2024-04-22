#pragma once
#include<cstdint>
#include"Vector2.h"
#include"HUD.h"
#include"Novice.h"
class Player
{
private:
	vector2_t   pos_;
	vector2_t   speed_;
	int8_t      hp_;
	int8_t      weaponRate_;
	int8_t      weaponLV_;
	float       drawPosX_;
	float       hitboxRadius_;
	bool        isAlive_;
	bool        isOC_;
	int         textureHandle_;
public:
	Player(vector2_t pos, vector2_t speed, int8_t hp, int8_t weaponRate, int8_t weaponLV, float drawPosX, float hitboxRadius, bool isAlive, bool isOC, int textureHandle);
	void Initalize(vector2_t pos, vector2_t speed, int8_t hp, int8_t weaponRate, int8_t weaponLV, bool isAlive, bool isOC);
	vector2_t GetPos() { return pos_; };
	vector2_t GetSpeed() { return speed_; };
	int8_t GetHP() { return hp_; };
	int8_t GetWeaponRate() { return weaponRate_; };
	int8_t GetWeaponLV() { return weaponLV_; };
	float GetDrawPosX() { return drawPosX_; };
	float GetHitboxRadius() { return hitboxRadius_; };
	bool GetIsAlive() { return isAlive_; };
	bool GetIsOC() { return isOC_; };
	void SetPos(float x, float y);
	void SetSpeed(float x, float y);
	void SetHP(int8_t hp);
	void SetWeaponRate(int8_t weaponRate);
	void SetWeaponLV(int8_t weaponLV);
	void SetDrawPosX(float drawPosX);
	void SetIsAlive(bool isAlive);
	void SetIsOC(bool isOC);
	void Move(char keys[],const HUD_t& tHRHEAT);
	void OnCollision(const int8_t& damage);
    void Draw();
};
typedef struct player_s {
	vector2_t   pos;
	vector2_t   speed;
    int8_t      hp;
	int8_t      weaponRate;
	int8_t      weaponLV;
	float       drawPosX;
	float       hitboxRadius;
	bool        isAlive;
	bool        isOC;
}player_t;
