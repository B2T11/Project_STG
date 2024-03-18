#pragma once
#include"Struct.h"
#include <Novice.h>
#include<cmath>
#include <vector>
void ShootBullet(char keys[], const player_t& player_t, std::vector<bullet_t>& bullets, bullet_t& bulletLeft, bullet_t& bulletRight, int& bulletDelayTimer, int& gunsAmmoRem);


