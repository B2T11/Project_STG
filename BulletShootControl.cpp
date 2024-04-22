#include "BulletShootControl.h"

void ShootBullet(char keys[], const player_t& player_t, std::vector<bullet_t>& bullets,bullet_t& bulletLeft,bullet_t& bulletRight,int& bulletDelayTimer,int& gunsAmmoRem) {
	
	
	if (keys[DIK_SPACE] && bulletDelayTimer >= player_t.weaponRate) {
		bulletLeft.isShot = true;
		bulletRight.isShot = true;
        bulletLeft.pos.x = player_t.pos.x - bulletLeft.spacing.x, bulletLeft.pos.y = player_t.pos.y-10+ bulletLeft.spacing.y;
		bulletRight.pos.x = player_t.pos.x + bulletRight.spacing.x, bulletRight.pos.y = player_t.pos.y-10 + bulletLeft.spacing.y;
		bullets.push_back(bulletLeft);
		bullets.push_back(bulletRight);
		gunsAmmoRem -= 2;
		bulletDelayTimer = 0;
	}
	
}
