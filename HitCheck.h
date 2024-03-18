#pragma once
#include "Struct.h"
#include<vector>
bool HitCheck(const player_t& player, const enemy_t& enemy);
bool HitCheck(const bullet_t& bullet, const enemy_t& enemy);
bool HitCheck(const bullet_t& bullet, const player_t& player);

