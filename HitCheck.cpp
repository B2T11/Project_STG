#include "HitCheck.h"
#include "Novice.h"
#include <math.h>

bool HitCheck(Player& player, const enemy_t& enemy) {
	if (player.GetIsAlive() && enemy.isAlive) {
		if (pow((player.GetPos().x - enemy.pos.x), 2) + pow((player.GetPos().y - enemy.pos.y), 2) <= pow((player.GetHitboxRadius() + enemy.hitboxRadius), 2)) {
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
		
bool HitCheck(const bullet_t& bullet, Player& player) {
	if (bullet.isShot && player.GetIsAlive()) {
		if (pow((bullet.pos.x - player.GetPos().x), 2) + pow((bullet.pos.y - player.GetPos().y), 2) <= pow((bullet.hitboxRadius + player.GetHitboxRadius()), 2)) {
			return true;
		}
	}
	return false;
}
			
		
		
