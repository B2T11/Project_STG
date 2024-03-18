#include "BulletShootControl.h"

void ShootBullet(char keys[], const player_t& player_t, std::vector<bullet_t>& Bullets,bullet_t& BulletLeft,bullet_t& BulletRight,int& BulletDelayTimer,int& GAmmoRem) {
	
	
	if (keys[DIK_SPACE] && BulletDelayTimer >= player_t.weaponRate) {
		BulletLeft.isShot = true;
		BulletRight.isShot = true;
        BulletLeft.pos.x = player_t.pos.x - BulletLeft.spacing.x, BulletLeft.pos.y = player_t.pos.y-10+ BulletLeft.spacing.y;
		BulletRight.pos.x = player_t.pos.x + BulletRight.spacing.x, BulletRight.pos.y = player_t.pos.y-10 + BulletLeft.spacing.y;
		Bullets.push_back(BulletLeft);
		Bullets.push_back(BulletRight);
		GAmmoRem -= 2;
		BulletDelayTimer = 0;
	}
	
}
