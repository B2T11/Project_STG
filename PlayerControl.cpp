#include "PlayerControl.h"
#include <math.h>
#include "Novice.h"


float inclineLength;


vector2_t MovePlayer(char keys[], player_t& player,const HUD_t& THRHEAT) {
	player.speed = { 0.0f,0.0f };
	vector2_t length = { 5.0f,5.0f };
	
	inclineLength = sqrtf(length.x * length.x + length.y * length.y);
    

	if (keys[DIK_W]) {
		player.speed.y = -5.0f;
		if (THRHEAT.isFlash) {
			player.speed.y = -3.0f;
		}
	}
	if (keys[DIK_S]) {
		player.speed.y = 5.0f;
	}
	if (keys[DIK_A]) {
		player.speed.x = -5.0f;
		
	}
	if (keys[DIK_D]) {
		player.speed.x = 5.0f;
		
	}
	if (keys[DIK_W] && keys[DIK_A]) {
		if (THRHEAT.isFlash) {
			length = { 5.0f,3.0f };
		}
		player.speed.x = -1 * (length.x / inclineLength) * length.x;
		player.speed.y = -1 * (length.y / inclineLength) * length.y;
	}
	if (keys[DIK_W] && keys[DIK_D]) {
		if (THRHEAT.isFlash) {
			length = { 5.0f,3.0f };
		}
		player.speed.x = (length.x / inclineLength) * length.x;
		player.speed.y = -1 * (length.y / inclineLength) * length.y;
	}
	if (keys[DIK_S] && keys[DIK_A]) {
		player.speed.x = -1 * (length.x / inclineLength) * length.x;
		player.speed.y = (length.y / inclineLength) * length.y;
	}
	if (keys[DIK_S] && keys[DIK_D]) {
		player.speed.x = (length.x / inclineLength) * length.x;
		player.speed.y = (length.y / inclineLength) * length.y;
	}
	player.pos.x += player.speed.x;
	player.pos.y += player.speed.y;
    if (player.pos.x <= 390) {
		player.pos.x = 390;
	}
	if (player.pos.x >= 1530) {
		player.pos.x = 1530;
	}
	if (player.pos.y <= 35) {
		player.pos.y = 35;
	}
	if (player.pos.y >= 1045) {
		player.pos.y = 1045;
	}
	return player.pos;
}