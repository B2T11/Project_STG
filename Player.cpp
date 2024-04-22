#include "Player.h"
#include"cmath"


Player::Player(vector2_t pos, vector2_t speed, int8_t hp, int8_t weaponRate, int8_t weaponLV, float drawPosX, float hitboxRadius, bool isAlive, bool isOC, int textureHandle) {
	pos_ = pos;
	speed_ = speed;
	hp_ = hp;
	weaponRate_ = weaponRate;
	weaponLV_ = weaponLV;
	drawPosX_ = drawPosX;
	hitboxRadius_ = hitboxRadius;
	isAlive_ = isAlive;
	isOC_ = isOC;
	textureHandle_ = textureHandle;
}
void Player::SetPos(float x, float y) {
	pos_.x = x;
	pos_.y = y;
}
void Player::SetSpeed(float x, float y) {
	speed_.x = x;
	speed_.y = y;
}
void Player::SetHP(int8_t hp) {
	hp_ = hp;
}
void Player::SetWeaponRate(int8_t weaponRate) {
	weaponRate_ = weaponRate;
}
void Player::SetWeaponLV(int8_t weaponLV) {
	weaponLV_ = weaponLV;
}
void Player::SetDrawPosX(float drawPosX) {
	drawPosX_ = drawPosX;
}
void Player::SetIsAlive(bool isAlive) {
	isAlive_ = isAlive;
}
void Player::SetIsOC(bool isOC) {
	isOC_ = isOC;
}
void Player::Initalize(vector2_t pos, vector2_t speed, int8_t hp, int8_t weaponRate, int8_t weaponLV, bool isAlive, bool isOC) {
	SetPos(pos.x, pos.y);
	SetSpeed(speed.x, speed.y);
	SetHP(hp);
	SetWeaponRate(weaponRate);
	SetWeaponLV(weaponLV);
	SetIsAlive(isAlive);
	SetIsOC(isOC);
}

void Player::Move(char keys[],const HUD_t& tHRHEAT) {
	speed_ = { 0.0f,0.0f };
	vector2_t length = { 5.0f,5.0f };
	float inclineLength = sqrtf(length.x * length.x + length.y * length.y);
	if (keys[DIK_W]) {
		speed_.y = -5.0f;
		if (tHRHEAT.isFlash) {
			speed_.y = -3.0f;
		}
	}
	if (keys[DIK_S]) {
		speed_.y = 5.0f;
	}
	if (keys[DIK_A]) {
		speed_.x = -5.0f;
	}
	if (keys[DIK_D]) {
		speed_.x = 5.0f;
	}
	if (keys[DIK_W] && keys[DIK_A]) {
		if (tHRHEAT.isFlash) {
			length = { 5.0f,3.0f };
		}
		speed_.x = -1 * (length.x / inclineLength) * length.x;
		speed_.y = -1 * (length.y / inclineLength) * length.y;
	}
	if (keys[DIK_W] && keys[DIK_D]) {
		if (tHRHEAT.isFlash) {
			length = { 5.0f,3.0f };
		}
		speed_.x = (length.x / inclineLength) * length.x;
		speed_.y = -1 * (length.y / inclineLength) * length.y;
		
	}
    if (keys[DIK_S] && keys[DIK_A]) {
		speed_.x = -1 * (length.x / inclineLength) * length.x;
		speed_.y = (length.y / inclineLength) * length.y;
	}
	if (keys[DIK_S] && keys[DIK_D]) {
		speed_.x = (length.x / inclineLength) * length.x;
		speed_.y = (length.y / inclineLength) * length.y;
	}
	pos_.x += speed_.x;
	pos_.y += speed_.y;
	if (pos_.x <= 390) {
		pos_.x = 390;
	}
	if (pos_.x >= 1530) {
		pos_.x = 1530;
	}
	if (pos_.y <= 35) {
		pos_.y = 35;
	}
	if (pos_.y >= 1045) {
		pos_.y = 1045;
	}
}

void Player::OnCollision(const int8_t& damage) {
	hp_ += damage;
}

void Player::Draw() {
	Novice::DrawSpriteRect((int)pos_.x - 78 / 2, (int)pos_.y - 66 / 2, (int)drawPosX_, 0, 78, 66, textureHandle_, 1.0f / 3.0f, 1, 0, WHITE);
}