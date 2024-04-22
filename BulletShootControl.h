#pragma once
#include <Novice.h>
#include <cmath>
#include <vector>
#include "Player.h"
#include "Bullet.h"
void ShootBullet(char keys[], Player& player, std::vector<bullet_t>& bullets, bullet_t& bulletLeft, bullet_t& bulletRight, int& bulletDelayTimer, int& gunsAmmoRem);


