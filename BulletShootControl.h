#pragma once
#include"Struct.h"
#include <Novice.h>
#include<cmath>
#include <vector>
void ShootBullet(char keys[], const player_t& player_t, std::vector<bullet_t>& Bullets, bullet_t& BulletLeft, bullet_t& BulletRight, int& BulletDelayTimer, int& GAmmoRem);


