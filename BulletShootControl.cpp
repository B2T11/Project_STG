#include "BulletShootControl.h"

void ShootBullet(char keys[], Player& player, std::vector<bullet_t>& bullets,bullet_t& bulletLeft,bullet_t& bulletRight,int& bulletDelayTimer,int& gunsAmmoRem) {
	
	
	if (keys[DIK_SPACE] && bulletDelayTimer >= player.GetWeaponRate()) {
		bulletLeft.isShot = true;
		bulletRight.isShot = true;
        bulletLeft.pos.x = player.GetPos().x - bulletLeft.spacing.x, bulletLeft.pos.y = player.GetPos().y - 10 + bulletLeft.spacing.y;
		bulletRight.pos.x = player.GetPos().x + bulletRight.spacing.x, bulletRight.pos.y = player.GetPos().y - 10 + bulletLeft.spacing.y;
		bullets.push_back(bulletLeft);
		bullets.push_back(bulletRight);
		gunsAmmoRem -= 2;
		bulletDelayTimer = 0;
	}
	
}
