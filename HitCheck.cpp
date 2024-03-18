#include "HitCheck.h"
#include "Novice.h"
#include <math.h>

bool HitCheck(const player_t& player, const enemy_t& enemy) {
	if (player.isAlive && enemy.isAlive) {
		if (pow((player.pos.x - enemy.pos.x), 2) + pow((player.pos.y - enemy.pos.y), 2) <= pow((player.hitboxRadius + enemy.hitboxRadius), 2)) {
            return true;
		}
		
	}
	return false;
}

bool HitCheck(const bullet_t& bullet, const enemy_t& enemy) {
    if (bullet.isShot && enemy.isAlive) {
        if (pow((bullet.pos.x - enemy.pos.x), 2) + pow((bullet.pos.y - enemy.pos.y), 2) <= pow((bullet.hitboxRadius + enemy.hitboxRadius), 2)) {
			return true;
		}
	}
	return false;
}
		
bool HitCheck(const bullet_t& bullet, const player_t& player) {
	if (bullet.isShot && player.isAlive) {
		if (pow((bullet.pos.x - player.pos.x), 2) + pow((bullet.pos.y - player.pos.y), 2) <= pow((bullet.hitboxRadius + player.hitboxRadius), 2)) {
			return true;
		}
	}
	return false;
}
			
		
		
