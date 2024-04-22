#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include<vector>
bool HitCheck(Player& player, const enemy_t& enemy);
bool HitCheck(const bullet_t& bullet, const enemy_t& enemy);
bool HitCheck(const bullet_t& bullet, Player& player);

