#include <Novice.h>
#include <ctime>
#include <cmath>
#include <vector>
#include "Vector2.h"
#include "BezierCurves.h"
#include "HitCheck.h"
#include "Animetion.h"
#include "Player.h"
#include "Enemy.h"
#include "HUD.h"
#include "Item.h"
#include "Bullet.h"
#include "Missile.h"
#include "Object.h"
#include "BulletShootControl.h"
#include "WPNOC.h"

using namespace std;

const char kWindowTitle[] = "Orion";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	int windowLength = 1920;
	int windowHeight = 1080;
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, windowLength, windowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	int mousePosX = 0;
	int mousePosY = 0;
#pragma region LoadTexture
    int defaultBackgroundTH = Novice::LoadTexture("./DefaultBackground.png");
	int backgroundTH = Novice::LoadTexture("./RS/BackGround/BackGround.png");
	int titleBackgroundTH = Novice::LoadTexture("./RS/BackGround/Title.png");
	int missileTH = Novice::LoadTexture("./RS/missile1-Sheet.png");//(84x42)
	int lockonTH = Novice::LoadTexture("./RS/HUD/LockOn.png");
	//=============Number=======================================
    int y24NumTH[10] = {
		Novice::LoadTexture("./RS/HUD/Number/Y24Num_0.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y24Num_1.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y24Num_2.png"),
	    Novice::LoadTexture("./RS/HUD/Number/Y24Num_3.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y24Num_4.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y24Num_5.png"),
	    Novice::LoadTexture("./RS/HUD/Number/Y24Num_6.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y24Num_7.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y24Num_8.png"),
	    Novice::LoadTexture("./RS/HUD/Number/Y24Num_9.png")
	};
	int y36NumTH[10] = {
		Novice::LoadTexture("./RS/HUD/Number/Y36Num_0.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y36Num_1.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y36Num_2.png"),
	    Novice::LoadTexture("./RS/HUD/Number/Y36Num_3.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y36Num_4.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y36Num_5.png"),
	    Novice::LoadTexture("./RS/HUD/Number/Y36Num_6.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y36Num_7.png"),
		Novice::LoadTexture("./RS/HUD/Number/Y36Num_8.png"),
	    Novice::LoadTexture("./RS/HUD/Number/Y36Num_9.png")
	};
	//=====LeftHUD=============
	int leftHUD_TH = Novice::LoadTexture("./RS/HUD/HUD_Left.png");
	int radarEnemyHUD_TH = Novice::LoadTexture("./RS/HUD/HUD_Radar_Enemy.png");//21x21
	int pROXWARN_TH = Novice::LoadTexture("./RS/HUD/PJSTG_HUD_PROXWARN-Sheet-export.png");
	int qTMFAIL_TH = Novice::LoadTexture("./RS/HUD/PJSTG_HUD_QTMFAIL-Sheet-export.png");
	int qDRLOCK_TH = Novice::LoadTexture("./RS/HUD/PJSTG_HUD_RDRLOCK-Sheet-export.png");
	//int MISLWARN_HUD_TH = Novice::LoadTexture("./RS/HUD_t/PJSTG_HUD_MISLWARN-Sheet-export.png");
	int coolFailTH = Novice::LoadTexture("./RS/HUD/PJSTG_HUD_COOLFAIL-Sheet-export.png");
	int mSLINCM_TH = Novice::LoadTexture("./RS/HUD/HUD_MISLINCM-Sheet.png");
	int eMPINCM_TH = Novice::LoadTexture("./RS/HUD/HUD_EMPINCM-Sheet.png");
	int menuTH = Novice::LoadTexture("./RS/HUD/HUD_MENU.png");
	int cOMMS_TH = Novice::LoadTexture("./RS/HUD/HUD_COMMS.png");
	//=====RightHUD=============
	int rightHUD_TH = Novice::LoadTexture("./RS/HUD/HUD_Right.png");
	int oN_OFF_TH = Novice::LoadTexture("./RS/HUD/ON_OFF-Sheet.png");
	int tHR_BarTH = Novice::LoadTexture("./RS/HUD/HUD_THR_Bar.png");
	
	int vEL_Indicator_1TH = Novice::LoadTexture("./RS/HUD/HUD_VELIndicator1.png");
	int vEL_indicator_2TH = Novice::LoadTexture("./RS/HUD/HUD_VELIndicator2.png");
	int vTOL_TH = Novice::LoadTexture("./RS/HUD/HUD_VTOL-Sheet.png");
	int cPLD_TH = Novice::LoadTexture("./RS/HUD/HUD_CPLD-Sheet.png");
	int eSP_TH = Novice::LoadTexture("./RS/HUD/HUD_ESP-Sheet.png");
	int gEAR_TH = Novice::LoadTexture("./RS/HUD/HUD_GEAR-Sheet.png");



	int wPNHEAT_TH = Novice::LoadTexture("./RS/HUD/HUD_WPNHEAT-Sheet.png");
	int sHIELDDOWN_TH = Novice::LoadTexture("./RS/HUD/HUD_SHIELDDOWN-Sheet.png");
	int tHRHEAT_TH = Novice::LoadTexture("./RS/HUD/HUD_THRHEAT-Sheet.png");
	int pWRHEAT_TH = Novice::LoadTexture("./RS/HUD/HUD_PWRHEAT-Sheet.png");
	int pWRLOW_TH = Novice::LoadTexture("./RS/HUD/HUD_PWRLOW-Sheet.png");
	int hYDLOW_TH = Novice::LoadTexture("./RS/HUD/HUD_HYDLOW-Sheet.png");
	int qUALOW_TH = Novice::LoadTexture("./RS/HUD/HUD_QUALOW-Sheet.png");
	int pWR_HYD_QUA_BarTH = Novice::LoadTexture("./RS/HUD/HUD_QUA_HYD_PWR_Bar.png");
	//=================enemy============================================
	int enemy1TH = Novice::LoadTexture("./RS/Enemy/Enemy1.png");//72x78
	int eliteTH = Novice::LoadTexture("./RS/Enemy/Elite.png");
	int enemyBulletTH = Novice::LoadTexture("./RS/Enemy/EnemyBullet1.png");
	//=====================================================================
	int playerBullet1TH = Novice::LoadTexture("./RS/Player/Bullet1.png");
	int itemTH = Novice::LoadTexture("./RS/Item.png");
	int playerFlameAni[9] = {
		Novice::LoadTexture("./RS/PlayerFlameAnimetion/stop.png"),
		Novice::LoadTexture("./RS/PlayerFlameAnimetion/up.png"),
		Novice::LoadTexture("./RS/PlayerFlameAnimetion/down.png"),
		Novice::LoadTexture("./RS/PlayerFlameAnimetion/left.png"),
		Novice::LoadTexture("./RS/PlayerFlameAnimetion/right.png"),
		Novice::LoadTexture("./RS/PlayerFlameAnimetion/leftup.png"),
		Novice::LoadTexture("./RS/PlayerFlameAnimetion/leftdown.png"),
		Novice::LoadTexture("./RS/PlayerFlameAnimetion/rightup.png"),
		Novice::LoadTexture("./RS/PlayerFlameAnimetion/rightdown.png"),
	};
	int playerFlameAniNum = 0;
	animetion_t playerFlame = {};
	playerFlame.timer = 0;
	playerFlame.currentFrame = 0;
#pragma endregion
	int vEL_Indicator_DrawPosY = 339;
	

	vector2_t backGround_1 = { 0 };
	vector2_t backGround_2 = { 0,-1080 };

	Player* player = new Player({ 960.0f,800.0f }, { 0.0f,0.0f }, 30, 10, 1, 78.0f, 35.0f, true, false, Novice::LoadTexture("./RS/Player/Player1-Sheet.png"));

	//player_t player = {};
	//player.pos = { 960.0f,800.0f };
	//player.weaponLV = 1;
	//player.drawPosX = 78;
	//player.weaponRate = 10;
	//player.hitboxRadius = 35.0f;
	//player.hp = 30;
	//player.isOC = false;
	//player.isAlive = true;
	bool isMislShot = false;
	vector2_t mislLockOn = {};
	
#pragma region enemy
	vector<enemy_t> enemies;
	enemy_t enemy = {};
	enemy.pos = { 650,-740};
	enemy.speed = {0.0f,2.0f};
	enemy.indexR = 35;
	enemy.hp = 9;
	enemy.hitboxRadius = 15.0f;
	enemy.isAlive = true;
	enemy.rate = 100;
	enemy.shotTimer = enemy.rate;
	enemy.color = WHITE;
	int enemySpawnTimer = 60;
	//========================================
	vector<bullet_t>enemyBullets;
	bullet_t enemyBullet = {};
	enemyBullet.speed = { 0.0f,8.0f };
	enemyBullet.damage = 5;
	enemyBullet.hitboxRadius = 8.0f;
	enemyBullet.isShot = true;
	//===================================================
	vector<enemy_t> elites;
	enemy_t elite = {};
	elite.pos = {};
	elite.speed = { 0.0f,3.0f };
	elite.indexR = 60;
	elite.hp = 100;
	elite.hitboxRadius = 50.0f;
	elite.isAlive = true;
	elite.rate = 60;
	elite.shotTimer = elite.rate;
	elite.spriteWidth = 114;
	elite.spriteHeight = 117;
	//elite.kLeftTopX = -elite.spriteWidth / 2.0f;
	//elite.kLeftTopY = -elite.spriteHeight / 2.0f;
	//elite.kRightTopX = elite.spriteWidth / 2.0f;
	//elite.kRightTopY = -elite.spriteHeight / 2.0f;
	//elite.kLeftBottomX = -elite.spriteWidth / 2.0f;
	//elite.kLeftBottomY = elite.spriteHeight / 2.0f;
	//elite.kRightBottomX = elite.spriteWidth / 2.0f;
	//elite.kRightBottomY = elite.spriteHeight / 2.0f;
	//=============================================
	vector<bullet_t>eliteBullets;
	bullet_t eliteBullet = {};
	eliteBullet.speed = { 0.0f,10.0f };
	eliteBullet.damage = 6;
	eliteBullet.hitboxRadius = 8.0f;
	eliteBullet.isShot = true;


    int targetEnemyIndex = -1;
#pragma endregion
	vector2_t p0 = { player->GetPos().x,player->GetPos().y};
	vector2_t p1 = { p0.x-200.0f,p0.y-300.0f };
	/*vector2_t P2 = { enemy.Pos.x,enemy.Pos.y };*/
#pragma region bullet
	vector<bullet_t> bullets;
	bullet_t bulletLeft1 = {};
	bulletLeft1.pos = {};
	bulletLeft1.spacing = { 10.0f,0.0f };
	bulletLeft1.speed = { 0.0f,20.0f };
	bulletLeft1.damage = 3;
	bulletLeft1.angle = 0.0f;
	bulletLeft1.hitboxRadius = 10.0f;
	bulletLeft1.isShot = false;
	bulletLeft1.isHit = false;
	bulletLeft1.spriteWidth = 15;
	bulletLeft1.spriteHeight = 30;
	bullet_t bulletRight1 = {};
	bulletRight1.pos = {};
	bulletRight1.spacing = { 9.0f,0.0f };
	bulletRight1.speed = { 0.0f,20.0f };
	bulletRight1.damage = 3;
	bulletRight1.angle = 0.0f;
	bulletRight1.hitboxRadius = 10.0f;
	bulletRight1.isShot = false;
	bulletRight1.isHit = false;
	bulletRight1.spriteWidth = 15;
	bulletRight1.spriteHeight = 30;
	int bullet1DelayTimer = 10;
	bullet_t bulletLeft2 = {};
	bulletLeft2.pos = {};
	bulletLeft2.spacing = { 12.0f,5.0f };
	bulletLeft2.speed = { -1.0f,20.0f };
	bulletLeft2.damage = 3;
	bulletLeft2.angle = 0.0f;
	bulletLeft2.hitboxRadius = 10.0f;
	bulletLeft2.isShot = false;
	bulletLeft2.isHit = false;
	bulletLeft2.spriteWidth = 15;
	bulletLeft2.spriteHeight = 30;
	bullet_t bulletRight2 = {};
	bulletRight2.pos = {};
	bulletRight2.spacing = { 11.0f,5.0f };
	bulletRight2.speed = { 1.0f,20.0f };
	bulletRight2.damage = 3;
	bulletRight2.angle = 0.0f;
	bulletRight2.hitboxRadius = 10.0f;
	bulletRight2.isShot = false;
	bulletRight2.isHit = false;
	bulletRight2.spriteWidth = 15;
	bulletRight2.spriteHeight = 30;
	int bullet2DelayTimer = 10;
	bullet_t bulletLeft3 = {};
	bulletLeft3.pos = {};
	bulletLeft3.spacing = { 19.0f,10.0f };
	bulletLeft3.speed = { -2.0f,20.0f };
	bulletLeft3.damage = 3;
	bulletLeft3.angle = 0.0f;
	bulletLeft3.hitboxRadius = 10.0f;
	bulletLeft3.isShot = false;
	bulletLeft3.isHit = false;
	bulletLeft3.spriteWidth = 15;
	bulletLeft3.spriteHeight = 30;
	bullet_t bulletRight3 = {};
	bulletRight3.pos = {};
	bulletRight3.spacing = { 18.0f,10.0f };
	bulletRight3.speed = { 2.0f,20.0f };
	bulletRight3.damage = 3;
	bulletRight3.angle = 0.0f;
	bulletRight3.hitboxRadius = 10.0f;
	bulletRight3.isShot = false;
	bulletRight3.isHit = false;
	bulletRight3.spriteWidth = 15;
	bulletRight3.spriteHeight = 30;
	int bullet3DelayTimer = 10;
#pragma endregion
	WPNOC_t wPNOC_t = {};
	wPNOC_t.timer = 0;
	wPNOC_t.coolDownTimer = 0;
	wPNOC_t.isCoolDown = false;
	
	/*int WPNOC_Timer_3 = 0;*/
#pragma region HUD
    vector2_t radarOriginal = { 178.5f,901.5f };
	vector<HUD_t> radarEnemyHUDs;
	HUD_t radarEnemyHUD = {};
    radarEnemyHUD.pos = {};
	radarEnemyHUD.color = 0xFFFFFFFF;
	radarEnemyHUD.flashSpeed = 10;
	radarEnemyHUD.isFlash = true;
	HUD_t oC_1HUD = {};
	oC_1HUD.pos = { 1864.0f,101.0f };
	oC_1HUD.drawPosX = 0;
	oC_1HUD.color = 0xFFFFFFFF;
	oC_1HUD.flashSpeed = 15;
	oC_1HUD.isFlash = false;
	oC_1HUD.spriteWidth = 80;
	oC_1HUD.spriteHeight = 26;
	HUD_t oC_2HUD = {};
	oC_2HUD.pos = { 1864.0f,152.0f };
	oC_2HUD.drawPosX = 0;
	oC_2HUD.color = 0xFFFFFFFF;
	oC_2HUD.flashSpeed = 15;
	oC_2HUD.isFlash = false;
	oC_2HUD.spriteWidth = 80;
	oC_2HUD.spriteHeight = 26;
	HUD_t oC_3HUD = {};
	oC_3HUD.pos = { 1864.0f,203.0f };
	oC_3HUD.drawPosX = 0;
	oC_3HUD.color = 0xFFFFFFFF;
	oC_3HUD.flashSpeed = 15;
	oC_3HUD.isFlash = false;
	oC_3HUD.spriteWidth = 80;
	oC_3HUD.spriteHeight = 26;
	HUD_t vTOL_HUD = {};
	vTOL_HUD.pos = { 1571.0f,680.0f };
	vTOL_HUD.drawPosX = 0;
	vTOL_HUD.color = 0xFFFFFFFF;
	vTOL_HUD.flashSpeed = 15;
	vTOL_HUD.isFlash = false;
	vTOL_HUD.spriteWidth = 166;
	vTOL_HUD.spriteHeight = 44;
	HUD_t cPLD_HUD = {};
	cPLD_HUD.pos = { 1657.0f,680.0f };
	cPLD_HUD.drawPosX = 0;
	cPLD_HUD.color = 0xFFFFFFFF;
	cPLD_HUD.flashSpeed = 15;
	cPLD_HUD.isFlash = false;
	cPLD_HUD.spriteWidth = 166;
	cPLD_HUD.spriteHeight = 44;
	HUD_t eSP_HUD = {};
	eSP_HUD.pos = { 1743.0f,680.0f };
	eSP_HUD.drawPosX = 0;
	eSP_HUD.color = 0xFFFFFFFF;
	eSP_HUD.flashSpeed = 15;
	eSP_HUD.isFlash = true;
	eSP_HUD.spriteWidth = 166;
	eSP_HUD.spriteHeight = 44;
	HUD_t gEAR_HUD = {};
	gEAR_HUD.pos = { 1829.0f,680.0f };
	gEAR_HUD.drawPosX = 0;
	gEAR_HUD.color = 0xFFFFFFFF;
	gEAR_HUD.flashSpeed = 15;
	gEAR_HUD.isFlash = true;
	gEAR_HUD.spriteWidth = 166;
	gEAR_HUD.spriteHeight = 44;
	HUD_t pROXWARN_HUD = {};
	pROXWARN_HUD.pos = { 6.0f,647.0f };
	pROXWARN_HUD.drawPosX = 0;
	pROXWARN_HUD.color = 0xFFFFFFFF;
	pROXWARN_HUD.flashSpeed = 15;
	pROXWARN_HUD.isFlash = false;
	pROXWARN_HUD.spriteWidth = 176;
	pROXWARN_HUD.spriteHeight = 88;
	HUD_t qTMFAIL_HUD = {};
	qTMFAIL_HUD.pos = { 92.0f,647.0f };
	qTMFAIL_HUD.drawPosX = 0;
	qTMFAIL_HUD.color = 0xFFFFFFFF;
	qTMFAIL_HUD.flashSpeed = 15;
	qTMFAIL_HUD.isFlash = false;
	qTMFAIL_HUD.spriteWidth = 176;
	qTMFAIL_HUD.spriteHeight = 88;
	HUD_t rDRLOCK_HUD = {};
	rDRLOCK_HUD.pos = { 178.0f,647.0f };
	rDRLOCK_HUD.drawPosX = 0;
	rDRLOCK_HUD.color = 0xFFFFFFFF;
	rDRLOCK_HUD.flashSpeed = 15;
	rDRLOCK_HUD.isFlash = false;
	rDRLOCK_HUD.spriteWidth = 176;
	rDRLOCK_HUD.spriteHeight = 88;
	HUD_t mISLWARN_HUD = {};
	mISLWARN_HUD.pos = { 264.0f,647.0f };
	mISLWARN_HUD.drawPosX = 0;
	mISLWARN_HUD.color = 0xFFFFFFFF;
	mISLWARN_HUD.flashSpeed = 15;
	mISLWARN_HUD.isFlash = false;
	mISLWARN_HUD.spriteWidth = 176;
	mISLWARN_HUD.spriteHeight = 88;
	HUD_t cOOLFAIL_HUD = {};
	cOOLFAIL_HUD.pos = { 264.0f,647.0f };
	cOOLFAIL_HUD.drawPosX = 0;
	cOOLFAIL_HUD.color = 0xFFFFFFFF;
	cOOLFAIL_HUD.flashSpeed = 15;
	cOOLFAIL_HUD.isFlash = false;
	cOOLFAIL_HUD.spriteWidth = 176;
	cOOLFAIL_HUD.spriteHeight = 88;
	HUD_t mISLINCM_HUD = {};
	mISLINCM_HUD.pos = { 6.0f,572.0f };
	mISLINCM_HUD.drawPosX = 0;
	mISLINCM_HUD.color = 0xFFFFFFFF;
	mISLINCM_HUD.flashSpeed = 15;
	mISLINCM_HUD.isFlash = false;
	mISLINCM_HUD.spriteWidth = 690;
	mISLINCM_HUD.spriteHeight = 78;
	HUD_t eMPINCM_HUD = {};
	eMPINCM_HUD.pos = { 6.0f,497.0f };
	eMPINCM_HUD.drawPosX = 0;
	eMPINCM_HUD.color = 0xFFFFFFFF;
	eMPINCM_HUD.flashSpeed = 15;
	eMPINCM_HUD.isFlash = false;
	eMPINCM_HUD.spriteWidth = 690;
	eMPINCM_HUD.spriteHeight = 78;
	HUD_t menuHUD = {};
	menuHUD.pos = { 6.0f,179.0f };
	menuHUD.drawPosX = 0;
	menuHUD.color = 0xFFFFFFFF;
	menuHUD.flashSpeed = 15;
	menuHUD.isFlash = false;
	menuHUD.spriteWidth = 345;
	menuHUD.spriteHeight = 321;
	HUD_t cOMMS_HUD = {};
	cOMMS_HUD.pos = { 6.0f,6.0f };
	cOMMS_HUD.drawPosX = 0;
	cOMMS_HUD.color = 0xFFFFFFFF;
	cOMMS_HUD.flashSpeed = 15;
	cOMMS_HUD.isFlash = false;
	cOMMS_HUD.spriteWidth = 345;
	cOMMS_HUD.spriteHeight = 177;
	HUD_t wPNHEAT_HUD = {};
	wPNHEAT_HUD.pos = { 1752.0f,12.0f };
	wPNHEAT_HUD.drawPosX = 0;
	wPNHEAT_HUD.color = 0xFFFFFFFF;
	wPNHEAT_HUD.flashSpeed = 15;
	wPNHEAT_HUD.isFlash = false;
	wPNHEAT_HUD.spriteWidth = 312;
	wPNHEAT_HUD.spriteHeight = 42;
	HUD_t sHIELDDOWN_HUD = {};
	sHIELDDOWN_HUD.pos = { 1569.0f,723.0f };
	sHIELDDOWN_HUD.drawPosX = 0;
	sHIELDDOWN_HUD.color = 0xFFFFFFFF;
	sHIELDDOWN_HUD.flashSpeed = 15;
	sHIELDDOWN_HUD.isFlash = false;
	sHIELDDOWN_HUD.spriteWidth = 690;
	sHIELDDOWN_HUD.spriteHeight = 60;
    HUD_t tHRHEAT_HUD = {};
	tHRHEAT_HUD.pos = { 1569.0f,780.0f };
	tHRHEAT_HUD.drawPosX = 0;
	tHRHEAT_HUD.color = 0xFFFFFFFF;
	tHRHEAT_HUD.flashSpeed = 15;
	tHRHEAT_HUD.isFlash = false;
	tHRHEAT_HUD.spriteWidth = 348;
	tHRHEAT_HUD.spriteHeight = 60;
	HUD_t pWRHEAT_HUD = {};
	pWRHEAT_HUD.pos = { 1740.0f,780.0f };
	pWRHEAT_HUD.drawPosX = 0;
	pWRHEAT_HUD.color = 0xFFFFFFFF;
	pWRHEAT_HUD.flashSpeed = 15;
	pWRHEAT_HUD.isFlash = false;
	pWRHEAT_HUD.spriteWidth = 348;
	pWRHEAT_HUD.spriteHeight = 60;
	HUD_t pWRLOW_HUD = {};
	pWRLOW_HUD.pos = { 1758.0f,840.0f };
	pWRLOW_HUD.drawPosX = 0;
	pWRLOW_HUD.color = 0xFFFFFFFF;
	pWRLOW_HUD.flashSpeed = 15;
	pWRLOW_HUD.isFlash = false;
	pWRLOW_HUD.spriteWidth = 288;
	pWRLOW_HUD.spriteHeight = 42;
	HUD_t hYDLOW_HUD = {};
	hYDLOW_HUD.pos = { 1758.0f,915.0f };
	hYDLOW_HUD.drawPosX = 0;
	hYDLOW_HUD.color = 0xFFFFFFFF;
	hYDLOW_HUD.flashSpeed = 15;
	hYDLOW_HUD.isFlash = false;
	hYDLOW_HUD.spriteWidth = 288;
	hYDLOW_HUD.spriteHeight = 42;
	HUD_t qUALOW_HUD = {};
	qUALOW_HUD.pos = { 1758.0f,990.0f };
	qUALOW_HUD.drawPosX = 0;
	qUALOW_HUD.color = 0xFFFFFFFF;
	qUALOW_HUD.flashSpeed = 15;
	qUALOW_HUD.isFlash = false;
	qUALOW_HUD.spriteWidth = 288;
	qUALOW_HUD.spriteHeight = 42;
	
	item_t upgradeItem_1 = {};//total8000/2000~3000/5000~7000
	upgradeItem_1.pos = { 703,-30 };
	upgradeItem_1.speed = { 3.0f,5.0f };
	upgradeItem_1.hitboxRadius = 25.0f;
	upgradeItem_1.randSpawn = 0;
	upgradeItem_1.isSpawn = false;
	item_t upgradeItem_2 = {};
	upgradeItem_2.pos = { 934,-30 };
	upgradeItem_2.speed = { 3.0f,5.0f };
	upgradeItem_2.hitboxRadius = 25.0f;
	upgradeItem_2.randSpawn = 0;
	upgradeItem_2.isSpawn = false;

	int gunsAmmoRemaining_1 = 30000;
	int gunsAmmoRem_1 = gunsAmmoRemaining_1;
	int gunsAmmoRemNumArr_1[5] = {};
	int gunsAmmoRemaining_2 = 30000;
	int gunsAmmoRem_2 = gunsAmmoRemaining_2;
	int gunsAmmoRemNumArr_2[5] = {};
	int gunsAmmoRemaining_3 = 30000;
	int gunsAmmoRem_3 = gunsAmmoRemaining_3;
	int gunsAmmoRemNumArr_3[5] = {};

	int mislRemaining = 9;
	int mislRem = mislRemaining;
	int mislRemNumArr[1] = {};

	int vel = 300;
	int vEL = vel;
	int velArr[3] = {};
	int tHR = 0;



	float pWR = 242.0f;
	float hYD = 310.0f;
	float qUA = 270.0f;


	float randX{};
	float randY{};


	
	int hUDShakeTimer = 0;
	int coolFailTimer = 0;


	int timer = 0;

	int edgeLeft = -20;
	int edgeRight = windowLength + 20;
	int edgeTop = -20;
	int edgeBottom = windowHeight + 20;

#pragma region Number
	/*int NumTH[10] = { Novice::LoadTexture("./RS/HUD_t/Number/HUD_Number_0.png"),Novice::LoadTexture("./RS/HUD_t/Number/HUD_Number_1.png") ,Novice::LoadTexture("./RS/HUD_t/Number/HUD_Number_2.png") ,
		Novice::LoadTexture("./RS/HUD_t/Number/HUD_Number_3.png") ,Novice::LoadTexture("./RS/HUD_t/Number/HUD_Number_4.png") ,Novice::LoadTexture("./RS/HUD_t/Number/HUD_Number_5.png") ,
		Novice::LoadTexture("./RS/HUD_t/Number/HUD_Number_6.png"),Novice::LoadTexture("./RS/HUD_t/Number/HUD_Number_7.png"),Novice::LoadTexture("./RS/HUD_t/Number/HUD_Number_8.png"),
	    Novice::LoadTexture("./RS/HUD_t/Number/HUD_Number_9.png") };
	int HEAT_EachNum[4] = {};
	int EM_EachNum[4] = {};
	int IR_EachNum[4] = {};*/
#pragma endregion
#pragma endregion
	
	float tSpeed = 0.03f;
	vector<missile_t>missiles;
	missile_t missile = {};
	/*mis.dir = {};
	mis.target = {};*/
	missile.t = 0.0f;
	/*mis.angle = 0.0f;*/
	missile.isShot = false;
	missile.isHit = false;
	missile.hitboxRadius = 15;
	missile.spriteWidth = 84;
	missile.spriteHeight = 42;
	/*int NumSegments = 100;*/
	
	vector<object_t>objs1;
	object_t object1 = {};
	object1.radius = 2;
	vector2_t obj1SpeedMin = {-5,10};
	vector2_t obj1SpeedMax = { 11,5 };

	enum scene_t {
		title,
		gameplay,
		gameover,
		gameclear,
		instructions,
	};
	scene_t scene = title;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		Novice::DrawSprite(0, 0, defaultBackgroundTH, 1, 1, 0, WHITE);
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition(&mousePosX, &mousePosY);
		
		switch (scene) {
		case title:
			player->Initalize({ 960.0f,800.0f }, { 0.0f,0.0f }, 30, 10, 1, 78.0f, true, false);
			if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
				scene = gameplay;
			}
			Novice::DrawSprite(0, 0, titleBackgroundTH, 1.0f, 1.0f, 0.0f, WHITE);
			break;
		case gameplay:
		    /*P2 = { enemy.Pos.x,enemy.Pos.y };*/
		    /*P = { mis.Pos.x,mis.Pos.y };*/
		    
		    bullet1DelayTimer++;
		    bullet2DelayTimer++;
		    bullet3DelayTimer++;
		    enemySpawnTimer++;
		    hUDShakeTimer--;
		    backGround_1.y++;
		    backGround_2.y++;
		    timer++;
		    
		    
		    if (backGround_1.y >= 1080) {
		    	backGround_1.y = 0;
		    }
		    if (backGround_2.y >= 0) {
		    	backGround_2.y = -1080;
		    }
		    Novice::DrawSprite((int)backGround_1.x, (int)backGround_1.y, backgroundTH, 1, 1, 0.0f, WHITE);
		    Novice::DrawSprite((int)backGround_2.x, (int)backGround_2.y, backgroundTH, 1, 1, 0.0f, WHITE);
		    for (int i = 0; i < enemies.size(); i++) {
		    	
                if (enemies[i].isAlive) {
		    		float enemyX = enemies[i].pos.x;
		    		float enemyY = enemies[i].pos.y;
		    		float dX = (float)mousePosX - enemyX;
		    		float dY = (float)mousePosY - enemyY;
		    		float distance = sqrt(dX * dX + dY * dY);
		    		if (distance <= enemies[i].indexR&&isMislShot==false) {
		    			targetEnemyIndex = i;
		    
		    			break;
		            }
		    		
		    	}
		    	
		    	
		    }
		    for (int i = 0; i < enemies.size(); i++) {
		    	if (enemies[i].isAlive) {
                    if (pow((player->GetPos().x - enemies[i].pos.x), 2) + pow((player->GetPos().y - enemies[i].pos.y), 2) <= pow((player->GetHitboxRadius() + 55 + enemies[i].hitboxRadius), 2)) {
		    			pROXWARN_HUD.isFlash = true;
		    			break;
		    		}
		    		else {
		    			pROXWARN_HUD.isFlash = false;
		    		}
		    	}
		    }
		    for (int i = 0; i < enemies.size(); i++) {
		    	if (enemies[i].isAlive) {
		    		if (HitCheck(*player,enemies[i])) {
		    			player->OnCollision(-8);
		    			hUDShakeTimer = 12;
		    			enemies[i].isAlive = false;
		    			break;
		    		}
		    		
		    	}
		    }
		    for (int i = 0; i < elites.size(); i++) {
		    	if (elites[i].isAlive) {
		    		if (HitCheck(*player, elites[i])) {
		    			player->OnCollision(-8);
		    			hUDShakeTimer = 12;
		    			elites[i].isAlive = false;
		    			break;
		    		}
		    
		    	}
		    }
		    //========GunsAmmoRemaining 1==================================================
		    gunsAmmoRemNumArr_1[0] = gunsAmmoRemaining_1 / 10000;
		    gunsAmmoRemaining_1 = gunsAmmoRemaining_1 % 10000;
		    gunsAmmoRemNumArr_1[1] = gunsAmmoRemaining_1 / 1000;
		    gunsAmmoRemaining_1 = gunsAmmoRemaining_1 % 1000;
		    gunsAmmoRemNumArr_1[2] = gunsAmmoRemaining_1 / 100;
		    gunsAmmoRemaining_1 = gunsAmmoRemaining_1 % 100;
		    gunsAmmoRemNumArr_1[3] = gunsAmmoRemaining_1 / 10;
		    gunsAmmoRemaining_1 = gunsAmmoRemaining_1 % 10;
		    gunsAmmoRemNumArr_1[4] = gunsAmmoRemaining_1;
		    gunsAmmoRemaining_1 = gunsAmmoRem_1;
		    //========GunsAmmoRemaining 2==================================================
		    gunsAmmoRemNumArr_2[0] = gunsAmmoRemaining_2 / 10000;
		    gunsAmmoRemaining_2 = gunsAmmoRemaining_2 % 10000;
		    gunsAmmoRemNumArr_2[1] = gunsAmmoRemaining_2 / 1000;
		    gunsAmmoRemaining_2 = gunsAmmoRemaining_2 % 1000;
		    gunsAmmoRemNumArr_2[2] = gunsAmmoRemaining_2 / 100;
		    gunsAmmoRemaining_2 = gunsAmmoRemaining_2 % 100;
		    gunsAmmoRemNumArr_2[3] = gunsAmmoRemaining_2 / 10;
		    gunsAmmoRemaining_2 = gunsAmmoRemaining_2 % 10;
		    gunsAmmoRemNumArr_2[4] = gunsAmmoRemaining_2;
		    gunsAmmoRemaining_2 = gunsAmmoRem_2;
		    //========GunsAmmoRemaining 3==================================================
		    gunsAmmoRemNumArr_3[0] = gunsAmmoRemaining_3 / 10000;
		    gunsAmmoRemaining_3 = gunsAmmoRemaining_3 % 10000;
		    gunsAmmoRemNumArr_3[1] = gunsAmmoRemaining_3 / 1000;
		    gunsAmmoRemaining_3 = gunsAmmoRemaining_3 % 1000;
		    gunsAmmoRemNumArr_3[2] = gunsAmmoRemaining_3 / 100;
		    gunsAmmoRemaining_3 = gunsAmmoRemaining_3 % 100;
		    gunsAmmoRemNumArr_3[3] = gunsAmmoRemaining_3 / 10;
		    gunsAmmoRemaining_3 = gunsAmmoRemaining_3 % 10;
		    gunsAmmoRemNumArr_3[4] = gunsAmmoRemaining_3;
		    gunsAmmoRemaining_3 = gunsAmmoRem_3;
		    //===============mis===================================================
		    mislRemNumArr[0] = mislRemaining;
		    mislRemaining = mislRem;
		    //===============vEL===================================================
		    velArr[0] = vel / 100;
		    vel = vel % 100;
		    velArr[1] = vel / 10;
		    vel = vel % 10;
		    velArr[2] = vel;
		    vel = vEL;
		    
		    
		    pWR -= 0.003f;
		    hYD -= 0.005f;
		    
		    
		    
#pragma region HUD Debug

		    /*if (keys[DIK_TAB] && !preKeys[DIK_1] && keys[DIK_1]) {
		    	pROXWARN_HUD.isFlash = true;
		    }
		    if (keys[DIK_TAB] && !preKeys[DIK_2] && keys[DIK_2]) {
		    	qTMFAIL_HUD.isFlash = true;
		    }
		    if (keys[DIK_TAB] && !preKeys[DIK_3] && keys[DIK_3]) {
		    	rDRLOCK_HUD.isFlash = true;
		    }
		    if (keys[DIK_TAB] && !preKeys[DIK_4] && keys[DIK_4]) {
		    	cOOLFAIL_HUD.isFlash = true;
		    }
		    if (keys[DIK_TAB] && !preKeys[DIK_5] && keys[DIK_5]) {
		    	wPNHEAT_HUD.isFlash = true;
		    }
		    if (keys[DIK_TAB] && !preKeys[DIK_6] && keys[DIK_6]) {
				player->SetHP(player->GetHP() - 5);
		    }
		    if (keys[DIK_TAB] && !preKeys[DIK_7] && keys[DIK_7]) {
		    	tHRHEAT_HUD.isFlash = true;
		    }
		    if (keys[DIK_TAB] && !preKeys[DIK_8] && keys[DIK_8]) {
		    	pWRHEAT_HUD.isFlash = true;
		    }
		    if (keys[DIK_TAB] && !preKeys[DIK_9] && keys[DIK_9]) {
		    	pWRLOW_HUD.isFlash = true;
		    }
		    if (keys[DIK_TAB] && !preKeys[DIK_0] && keys[DIK_0]) {
		    	hYDLOW_HUD.isFlash = true;
		    }
		    if (keys[DIK_TAB] && !preKeys[DIK_MINUS] && keys[DIK_MINUS]) {
		    	qUALOW_HUD.isFlash = true;
		    }
		    if (keys[DIK_L] && keys[DIK_2]) {
		    	player->SetWeaponLV(2);
		    }
		    if (keys[DIK_L] && keys[DIK_3]) {
		    	player->SetWeaponLV(3);
		    }*/
#pragma endregion
		    if (Novice::IsTriggerMouse(0)&&isMislShot==false&& mislRem!=0) {
		    	if (targetEnemyIndex != -1 && enemies[targetEnemyIndex].isAlive) {
                p0 = { player->GetPos().x,player->GetPos().y + 10.0f};
		    	missile.isShot = true;
		    	isMislShot = true;
		    	missiles.push_back(missile);
		    	mislRem--;
		    	}
		    	
		    
		    
		    }
		    if (timer >= 2000 && timer <= 3000&& upgradeItem_1.randSpawn!=-1) {
		    	upgradeItem_1.randSpawn = (rand() % 350 + 1);
		    	if (upgradeItem_1.randSpawn == 320) {
		    		upgradeItem_1.isSpawn = true;
		    	}
		    }
		    if (upgradeItem_1.isSpawn) {
		    	upgradeItem_1.pos.y += upgradeItem_1.speed.y;
		    	if (pow((player->GetPos().x - upgradeItem_1.pos.x), 2) + pow((player->GetPos().y - upgradeItem_1.pos.y), 2) <= pow((player->GetHitboxRadius() + 80 + upgradeItem_1.hitboxRadius), 2)) {
		    		upgradeItem_1.isSpawn = false;
		    		if (player->GetWeaponLV() == 1) {
		    			player->SetWeaponLV(2);
		    		}
		    		upgradeItem_1.randSpawn = -1;
		    	}
		    }
		    if (timer >= 5000 && timer <= 7000&& upgradeItem_2.randSpawn!=-1) {
		    	upgradeItem_2.randSpawn = (rand() % 350 + 1);
		    	if (upgradeItem_2.randSpawn == 320) {
		    		upgradeItem_2.isSpawn = true;
		    	}
		    }
		    if (upgradeItem_2.isSpawn) {
		    	upgradeItem_2.pos.y += upgradeItem_2.speed.y;
		    	if (pow((player->GetPos().x - upgradeItem_2.pos.x), 2) + pow((player->GetPos().y - upgradeItem_2.pos.y), 2) <= pow((player->GetHitboxRadius() + 80 + upgradeItem_2.hitboxRadius), 2)) {
		    		upgradeItem_2.isSpawn = false;
		    		if (player->GetWeaponLV() == 1) {
		    			player->SetWeaponLV(2);
		    		}
		    		if (player->GetWeaponLV() == 2) {
		    			player->SetWeaponLV(3);
		    		}
		    		upgradeItem_2.randSpawn = -1;
		    	}
		    }
		    //================Shack==========================================================
		    /*if (!preKeys[DIK_RETURN] && keys[DIK_RETURN]) {
		    	player.hp -= 5;
		    	hUDShakeTimer = 12;
		    
		    }*/
		    if (hUDShakeTimer > 0) {
		    	randX = (float)(rand() % 17 - 8);
		    	randY = (float)(rand() % 17 - 8);
		    }
		    else {
		    	randX = 0;
		    	randY = 0;
		    }
		    //==================================================================================
		    for (auto& mis : missiles) {
                
		    	if (mis.isShot) {
		    		
		    		if (enemies[targetEnemyIndex].isAlive) {
		    			mis.target = { enemies[targetEnemyIndex].pos.x,enemies[targetEnemyIndex].pos.y };
		    		}
		    		if (enemies[targetEnemyIndex].pos.x - p0.x > 0) {
		    			p1 = { p0.x + 350.0f,p0.y - 100.0f };
		    		}
		    		else if (enemies[targetEnemyIndex].pos.x - p0.x < 0) {
		    			p1 = { p0.x - 350.0f,p0.y - 100.0f };
		    		     }
		    		else {
		    			p1 = { p0.x,p0.y - 100.0f };
		    		}
		    		
		    	    mis.dir = BezierPDirection(mis.pos, p0, p1, mis.target, mis.t, tSpeed);
                    mis.pos = Set3PointBezier(p0, p1, mis.target, mis.t, tSpeed);
		    		if (!enemies[targetEnemyIndex].isAlive&&mis.pos.x==mis.target.x&& mis.pos.y == mis.target.y) {
		    			mis.isShot = false;
		    			isMislShot = false;
		    		}
		    	   
		        for (auto& ene : enemies) {
		    		if (ene.isAlive) {
						
                        if (pow((mis.pos.x - ene.pos.x), 2) + pow((mis.pos.y - ene.pos.y), 2) <= pow((mis.hitboxRadius + ene.hitboxRadius), 2)) {
		    				ene.hp -= 15;
							mis.isShot = false;
		    				isMislShot = false;
		                }
		    		}
                    
		    	}
                    mis.angle = atan2f(mis.dir.y, mis.dir.x) - 80.0f;
		    	    
		    
		    	}
		    	
		        
		    }
		    
		    /*for (int i = 0; i < NumSegments; i++) {
		    	float t1 = i / static_cast<float>(NumSegments);
		    	float t2 = (i + 1) / static_cast<float>(NumSegments);
		    
		    
		    	vector2_t Start;
		    	Start.x = (1 - t1) * (1 - t1) * p0.x + 2 * (1 - t1) * t1 * p1.x + t1 * t1 * P2.x;
		    	Start.y = (1 - t1) * (1 - t1) * p0.y + 2 * (1 - t1) * t1 * p1.y + t1 * t1 * P2.y;
		    
		    	vector2_t End;
		    	End.x = (1 - t2) * (1 - t2) * p0.x + 2 * (1 - t2) * t2 * p1.x + t2 * t2 * P2.x;
		    	End.y = (1 - t2) * (1 - t2) * p0.y + 2 * (1 - t2) * t2 * p1.y + t2 * t2 * P2.y;
		    
		    	Novice::DrawLine((int)Start.x, (int)Start.y, (int)End.x, (int)End.y, WHITE);
		    }*/
		    
#pragma region Normalrize
		    /*float length = sqrtf(MissileDir.x * MissileDir.x + MissileDir.y * MissileDir.y);
		    float MdirX = MissileDir.x;
		    float MdirY = MissileDir.y;
		    if (length != 0.0f) {
		    	MdirX = MissileDir.x / length;
		    	MdirY = MissileDir.y / length;
		    }*/
#pragma endregion
		
		    player->Move(keys, tHRHEAT_HUD);
		    
		    //=================================================================================== playerFlame =====================================================================================================
		    playerFlame.timer++;
		    if (playerFlame.timer >= 9) {
		    	playerFlame.currentFrame++;
		    	if (playerFlame.currentFrame > 3) {
		    		playerFlame.currentFrame = 0;
		    	}
		    	playerFlame.timer = 0;
		    }
		    
		    if (player->GetSpeed().x == 0 && player->GetSpeed().y < 0) {
		    	playerFlameAniNum = 1;
		    }
		    else if (player->GetSpeed().x == 0 && player->GetSpeed().y > 0) {
		    	playerFlameAniNum = 2;
		    }
		    else if (player->GetSpeed().x < 0 && player->GetSpeed().y == 0) {
		    	playerFlameAniNum = 3;
		    }
		    else if (player->GetSpeed().x > 0 && player->GetSpeed().y == 0) {
		    	playerFlameAniNum = 4;
		    }
		    else if (player->GetSpeed().x < 0 && player->GetSpeed().y < 0) {
		    	playerFlameAniNum = 5;
		    }
		    else if (player->GetSpeed().x < 0 && player->GetSpeed().y > 0) {
		    	playerFlameAniNum = 6;
		    }
		    else if (player->GetSpeed().x > 0 && player->GetSpeed().y < 0) {
		    	playerFlameAniNum = 7;
		    }
		    else if (player->GetSpeed().x > 0 && player->GetSpeed().y > 0) {
		    	playerFlameAniNum = 8;
		    }
		    else if (player->GetSpeed().x == 0 && player->GetSpeed().y == 0) {
		    	playerFlameAniNum = 0;
		    }
		
#pragma region HUD



		    if (player->GetHP() <= 20) {
		    	sHIELDDOWN_HUD.flashTimer++;
		        if (sHIELDDOWN_HUD.flashTimer<=20) {
		    		sHIELDDOWN_HUD.isFlash = true;
		        }
		    	if (sHIELDDOWN_HUD.flashTimer > 20 && sHIELDDOWN_HUD.flashTimer <= 40) {
		    		sHIELDDOWN_HUD.isFlash = false;
		    	}
		    	if (sHIELDDOWN_HUD.flashTimer > 40 && sHIELDDOWN_HUD.flashTimer <= 60) {
		    		sHIELDDOWN_HUD.isFlash = true;
		    	}
		    	if (sHIELDDOWN_HUD.flashTimer > 60 && sHIELDDOWN_HUD.flashTimer <= 80) {
		    		sHIELDDOWN_HUD.isFlash = false;
		    	}
		    	if (sHIELDDOWN_HUD.flashTimer > 80) {
		    		sHIELDDOWN_HUD.isFlash = true;
		    	}
		    }
		    if (sHIELDDOWN_HUD.flashTimer >= 90) {
		    	sHIELDDOWN_HUD.flashTimer = 90;
		    }
		    if (player->GetHP() <= 9) {
		    	cOOLFAIL_HUD.flashTimer++;
		    	coolFailTimer++;
		    	if (cOOLFAIL_HUD.flashTimer <= 20) {
		    		cOOLFAIL_HUD.isFlash = true;
		    	}
		    	if (cOOLFAIL_HUD.flashTimer > 20 && cOOLFAIL_HUD.flashTimer <= 40) {
		    		cOOLFAIL_HUD.isFlash = false;
		    	}
		    	if (cOOLFAIL_HUD.flashTimer > 40 && cOOLFAIL_HUD.flashTimer <= 60) {
		    		cOOLFAIL_HUD.isFlash = true;
		    	}
		    	if (cOOLFAIL_HUD.flashTimer > 60 && cOOLFAIL_HUD.flashTimer <= 80) {
		    		cOOLFAIL_HUD.isFlash = false;
		    	}
		    	if (cOOLFAIL_HUD.flashTimer > 80) {
		    		cOOLFAIL_HUD.isFlash = true;
		    	}
		    }
		    if (cOOLFAIL_HUD.flashTimer >= 90) {
		    	cOOLFAIL_HUD.flashTimer = 90;
		    }
		    if (coolFailTimer >= 600) {
		    	tHRHEAT_HUD.flashTimer++;
		    	if (tHRHEAT_HUD.flashTimer <= 20) {
		    		tHRHEAT_HUD.isFlash = true;
		    	}
		    	if (tHRHEAT_HUD.flashTimer > 20 && tHRHEAT_HUD.flashTimer <= 40) {
		    		tHRHEAT_HUD.isFlash = false;
		    	}
		    	if (tHRHEAT_HUD.flashTimer > 40 && tHRHEAT_HUD.flashTimer <= 60) {
		    		tHRHEAT_HUD.isFlash = true;
		    	}
		    	if (tHRHEAT_HUD.flashTimer > 60 && tHRHEAT_HUD.flashTimer <= 80) {
		    		tHRHEAT_HUD.isFlash = false;
		    	}
		    	if (tHRHEAT_HUD.flashTimer > 80) {
		    		tHRHEAT_HUD.isFlash = true;
		    	}
		    }
		    if (tHRHEAT_HUD.flashTimer >= 90) {
		    	tHRHEAT_HUD.flashTimer = 90;
		    }
		    if (coolFailTimer >= 1000) {
		    	coolFailTimer = 1000;
		    	pWRHEAT_HUD.flashTimer++;
		    	if (pWRHEAT_HUD.flashTimer <= 20) {
		    		pWRHEAT_HUD.isFlash = true;
		    	}
		    	if (pWRHEAT_HUD.flashTimer > 20 && pWRHEAT_HUD.flashTimer <= 40) {
		    		pWRHEAT_HUD.isFlash = false;
		    	}
		    	if (pWRHEAT_HUD.flashTimer > 40 && pWRHEAT_HUD.flashTimer <= 60) {
		    		pWRHEAT_HUD.isFlash = true;
		    	}
		    	if (pWRHEAT_HUD.flashTimer > 60 && pWRHEAT_HUD.flashTimer <= 80) {
		    		pWRHEAT_HUD.isFlash = false;
		    	}
		    	if (pWRHEAT_HUD.flashTimer > 80) {
		    		pWRHEAT_HUD.isFlash = true;
		    	}
		    }
		    if (pWRHEAT_HUD.flashTimer >= 90) {
		    	pWRHEAT_HUD.flashTimer = 90;
		    }
		    //============================================================================
		    if (pROXWARN_HUD.isFlash) {
		    	pROXWARN_HUD.drawPosX = 88;
		    }
		    else {
		    	pROXWARN_HUD.drawPosX = 0;
		    }
		    if (qTMFAIL_HUD.isFlash) {
		    	qTMFAIL_HUD.drawPosX = 88;
		    }
		    else {
		    	qTMFAIL_HUD.drawPosX = 0;
		    }
		    if (rDRLOCK_HUD.isFlash) {
		    	rDRLOCK_HUD.drawPosX = 88;
		    }
		    else {
		    	rDRLOCK_HUD.drawPosX = 0;
		    }
		    if (cOOLFAIL_HUD.isFlash) {
		    	cOOLFAIL_HUD.drawPosX = 88;
		    }
		    else {
		    	cOOLFAIL_HUD.drawPosX = 0;
		    }
		    if (wPNHEAT_HUD.isFlash) {
		    	wPNHEAT_HUD.drawPosX = 156;
		    }
		    else {
		    	wPNHEAT_HUD.drawPosX = 0;
		    }
		    if (sHIELDDOWN_HUD.isFlash) {
		    	sHIELDDOWN_HUD.drawPosX = 345;
		    }
		    else {
		    	sHIELDDOWN_HUD.drawPosX = 0;
		    }
		    if (tHRHEAT_HUD.isFlash) {
		    	tHRHEAT_HUD.drawPosX = 174;
		    }
		    else {
		    	tHRHEAT_HUD.drawPosX = 0;
		    }
		    if (pWRHEAT_HUD.isFlash) {
		    	pWRHEAT_HUD.drawPosX = 174;
		    }
		    else {
		    	pWRHEAT_HUD.drawPosX = 0;
		    }
		    if (pWRLOW_HUD.isFlash) {
		    	pWRLOW_HUD.drawPosX = 144;
		    }
		    else {
		    	pWRLOW_HUD.drawPosX = 0;
		    }
		    if (hYDLOW_HUD.isFlash) {
		    	hYDLOW_HUD.drawPosX = 144;
		    }
		    else {
		    	hYDLOW_HUD.drawPosX = 0;
		    }
		    if (qUALOW_HUD.isFlash) {
		    	qUALOW_HUD.drawPosX = 144;
		    }
		    else {
		    	qUALOW_HUD.drawPosX = 0;
		    }
		    if (vTOL_HUD.isFlash) {
		    	vTOL_HUD.drawPosX = 83;
		    }
		    else {
		    	vTOL_HUD.drawPosX = 0;
		    }
		    if (cPLD_HUD.isFlash) {
		    	cPLD_HUD.drawPosX = 83;
		    }
		    else {
		    	cPLD_HUD.drawPosX = 0;
		    }
		    if (eSP_HUD.isFlash) {
		    	eSP_HUD.drawPosX = 83;
		    }
		    else {
		    	eSP_HUD.drawPosX = 0;
		    }
		    if (gEAR_HUD.isFlash) {
		    	gEAR_HUD.drawPosX = 83;
		    }
		    else {
		    	gEAR_HUD.drawPosX = 0;
		    }
		    if (oC_1HUD.isFlash) {
		    	oC_1HUD.drawPosX = 40;
		    }
		    else {
		    	oC_1HUD.drawPosX = 0;
		    }
		    if (oC_2HUD.isFlash) {
		    	oC_2HUD.drawPosX = 40;
		    }
		    else {
		    	oC_2HUD.drawPosX = 0;
		    }
		    if (oC_3HUD.isFlash) {
		    	oC_3HUD.drawPosX = 40;
		    }
		    else {
		    	oC_3HUD.drawPosX = 0;
		    }
#pragma endregion
		    if (preKeys[DIK_V] && keys[DIK_V] && wPNOC_t.timer == 0) {
		    	player->SetIsOC(true);
		    }
		    if (player->GetIsOC() && wPNOC_t.timer < 300) {
		    	wPNOC_t.timer++;
		    	player->SetWeaponRate(5);
                if (player->GetWeaponLV() == 1) {
		    		oC_1HUD.isFlash = false;
		    	}
		    	else if (player->GetWeaponLV() == 2) {
		    		oC_1HUD.isFlash = false;
		    		oC_2HUD.isFlash = false;
		    	}
		    	else if (player->GetWeaponLV() == 3) {
		    		oC_1HUD.isFlash = false;
		    		oC_2HUD.isFlash = false;
		    		oC_3HUD.isFlash = false;
		    	}
		    }
		    if (wPNOC_t.timer >= 300) {
		    	player->SetIsOC(false);
		    	player->SetWeaponRate(10);
		    	wPNOC_t.timer = 300;
		    	wPNOC_t.isCoolDown = true;
		    }
		    if (wPNOC_t.timer < 300) {
		    	wPNOC_t.isCoolDown = false;
		    }
		    if (!wPNOC_t.isCoolDown) {
		    	wPNOC_t.coolDownTimer = 0;
		    }
		    if (wPNOC_t.isCoolDown) {
		    	wPNOC_t.coolDownTimer++;
		    	wPNHEAT_HUD.flashTimer++;
		    	if (wPNHEAT_HUD.flashTimer <= 20) {
		    		wPNHEAT_HUD.isFlash = true;
		    	}
		    	if (wPNHEAT_HUD.flashTimer > 20 && sHIELDDOWN_HUD.flashTimer <= 40) {
		    		wPNHEAT_HUD.isFlash = false;
		    	}
		    	if (wPNHEAT_HUD.flashTimer > 40 && sHIELDDOWN_HUD.flashTimer <= 60) {
		    		wPNHEAT_HUD.isFlash = true;
		    	}
		    	if (wPNHEAT_HUD.flashTimer > 60 && sHIELDDOWN_HUD.flashTimer <= 80) {
		    		wPNHEAT_HUD.isFlash = false;
		    	}
		    	if (wPNHEAT_HUD.flashTimer > 80) {
		    		wPNHEAT_HUD.isFlash = true;
		    	}
		    }
		    if (wPNOC_t.coolDownTimer >= 900) {
		    	wPNOC_t.timer = 0;
		    	wPNHEAT_HUD.flashTimer = 0;
		    	wPNHEAT_HUD.isFlash = false;
		    }
		    if (!player->GetIsOC()) {
                oC_1HUD.isFlash = true;
		    	oC_2HUD.isFlash = true;
		    	oC_3HUD.isFlash = true;
		    	
		    }
		    if (player->GetWeaponLV() == 1) {
		    	ShootBullet(keys, *player, bullets, bulletLeft1, bulletRight1, bullet1DelayTimer, gunsAmmoRem_1);
		    }
		    else if (player->GetWeaponLV() == 2) {
		    	ShootBullet(keys, *player, bullets, bulletLeft1, bulletRight1, bullet1DelayTimer, gunsAmmoRem_1);
		    	ShootBullet(keys, *player, bullets, bulletLeft2, bulletRight2, bullet2DelayTimer, gunsAmmoRem_2);
		    }
		    else if (player->GetWeaponLV() == 3) {
		    	ShootBullet(keys, *player, bullets, bulletLeft1, bulletRight1, bullet1DelayTimer, gunsAmmoRem_1);
		    	ShootBullet(keys, *player, bullets, bulletLeft2, bulletRight2, bullet2DelayTimer, gunsAmmoRem_2);
		    	ShootBullet(keys, *player, bullets, bulletLeft3, bulletRight3, bullet3DelayTimer, gunsAmmoRem_3);
		    }
		    
		    //============vEL Indicator=====================================================
		    if (player->GetSpeed().y < 0) {
		    	vEL_Indicator_DrawPosY -= 9;
		    	vEL += 17;
		    	tHR += 20;
		    }
		    else if (player->GetSpeed().y == 0) {
		    	if (vEL_Indicator_DrawPosY > 344) {
		    		vEL_Indicator_DrawPosY -= 9;
		    		
		    	}
		    	else if (vEL_Indicator_DrawPosY < 334) {
		    		vEL_Indicator_DrawPosY += 9;
		    		
		    	}
		    	else if (vEL_Indicator_DrawPosY <= 344 && vEL_Indicator_DrawPosY >= 334) {
		    		vEL_Indicator_DrawPosY = 339;
		    		
		    	}
		    	if (tHR > 70) {
		    		tHR -= 20;
		    	}
		    	else if (tHR < 30) {
		    		tHR += 20;
		    	     }
		    	else if(tHR <= 70 && tHR >= 30) {
		    		tHR = 50;
		    	     }
		    	if (vEL > 317) {
		    		vEL -= 17;
		    	}
		    	else if (vEL < 283) {
		    		vEL += 17;
		    	     }
		    	else if (vEL <= 317 && vEL >= 283) {
		    		vEL = 300;
		    	     }
		    }
		    else if (player->GetSpeed().y > 0) {
		    	vEL_Indicator_DrawPosY += 9;
		    	vEL -= 17;
		    	tHR -= 20;
		    }
		    if (vEL_Indicator_DrawPosY <= 242) {
		    	vEL_Indicator_DrawPosY = 242;
		    	
		    }
		    if (vEL_Indicator_DrawPosY >= 434) {
		    	vEL_Indicator_DrawPosY = 434;
		    	
		    }
		    if (player->GetSpeed().x == 0) {
		    	player->SetDrawPosX(78);
		    }
		    else if (player->GetSpeed().x < 0) {
		    	player->SetDrawPosX(0);
		    }
		    else if (player->GetSpeed().x > 0) {
		    	player->SetDrawPosX(156);
		    }
		    if (tHR >= 167) {
		    	tHR = 167;
		    }
		    if (tHRHEAT_HUD.isFlash) {
		    	if (tHR >= 100) {
		    		tHR = 100;
		    	}
		    }
		    if (tHR <= 10) {
		    	tHR = 10;
		    }
		    if (vEL <= 150) {
		    	vEL = 150;
		    }
		    if (vEL >= 450) {
		    	vEL = 450;
		    }
		    
		    
		    
		    //=========================================================================
		    
		    for (auto& bul : bullets) {
		    	/*if (bul.isShot == false) {
		    		bullets.erase(bullets.begin());
		    	}*/

		    	if (bul.isShot) {
		    		bul.pos.x += bul.speed.x;
		    		bul.pos.y -= bul.speed.y;
                    if (bul.pos.y <= edgeTop) {
		    			bul.isShot = false;
		    			
		    			
		    		}
		    	    for (auto& ene : enemies) {
						
		    		    bul.isHit = HitCheck(bul, ene);
                        if (bul.isHit) {
		    				ene.hp -= bul.damage;
							ene.colorChangeTimer = 10;
		    				object1.pos.x = bul.pos.x;
		    				object1.pos.y = bul.pos.y;
		    				for (int i = 0; i < 5; i++) {
		    					object1.isShot = true;
		    					object1.speed.x = (float)(rand() % (int)obj1SpeedMax.x + (int)obj1SpeedMin.x);
		    					object1.speed.y = (float)(rand() % (int)obj1SpeedMax.y + (int)obj1SpeedMin.y);
		    					objs1.push_back(object1);
		    				}
		    
		    		        bul.isShot = false;
		    	        }
		    
		    	    }
		    		for (auto& eli : elites) {
		    			bul.isHit = HitCheck(bul, eli);
		    			if (bul.isHit) {
		    				eli.hp -= bul.damage;
		    				object1.pos.x = bul.pos.x;
		    				object1.pos.y = bul.pos.y;
		    				for (int i = 0; i < 5; i++) {
		    					object1.isShot = true;
		    					object1.speed.x = (float)(rand() % (int)obj1SpeedMax.x + (int)obj1SpeedMin.x);
		    					object1.speed.y = (float)(rand() % (int)obj1SpeedMax.y + (int)obj1SpeedMin.y);
		    					objs1.push_back(object1);
		    				}
		    
		    				bul.isShot = false;
		    			}
		    		}
		    	}
				for (auto& ene : enemies) {
					ene.colorChangeTimer--;
					if (ene.colorChangeTimer<=0) {
						ene.colorChangeTimer = 0;
						ene.color = WHITE;
					}
					else {
						ene.color = 0xFF770EFF;
					}
				}

		    }
		    
		    
		    
		    for (auto& ene : enemies) {
		    	
		    	
		    	if (ene.hp <= 0) {
		    		ene.isAlive = false;
		    	}
		    	if (ene.isAlive) {
		    		ene.pos.y += ene.speed.y;
		    		ene.shotTimer--;
		    		if (ene.shotTimer <= 0) {
		    			enemyBullet.pos = { ene.pos.x,ene.pos.y };
		    			enemyBullets.push_back(enemyBullet);
		    			ene.shotTimer = ene.rate;
		    		}
                    
		    	}
		    	if (ene.pos.x > edgeRight || ene.pos.x < edgeLeft || ene.pos.y>edgeBottom+720 || ene.pos.y < edgeTop-725) {
		    		ene.isAlive = false;
		    	}
		    	if (targetEnemyIndex != -1 && enemies[targetEnemyIndex].isAlive) {
		    		
		    		mislLockOn.x = enemies[targetEnemyIndex].pos.x;
		    		mislLockOn.y = enemies[targetEnemyIndex].pos.y;
		    		
		    	}
		    	
		    		
		    	
		    	
		    }
		    
		    	
		    
		    	
		    
		    for (auto& obj1 : objs1) {
		    	if (obj1.isShot) {
		    		obj1.pos.x += obj1.speed.x;
		    		obj1.pos.y += obj1.speed.y;
		    		obj1.timer++;
		    	}
		    	if (obj1.timer > 3) {
		    		obj1.isShot = false;
		    	}
		    }
		    
            if (enemySpawnTimer > 90) {
		    	enemy.pos.x = static_cast<float>(rand() % 1145 + 360);
		    	enemies.push_back(enemy);
		    	enemySpawnTimer = 0;
		    }
		    
		    
		    if (enemies.size() > radarEnemyHUDs.size()) {
		    	radarEnemyHUDs.push_back(radarEnemyHUD);
	        }
		    
		    for (auto& enemyBul : enemyBullets) {
		    	if (enemyBul.isShot) {
		    		enemyBul.pos.y += enemyBul.speed.y;
		    	}
		    	if (enemyBul.pos.x > edgeRight || enemyBul.pos.x < edgeLeft || enemyBul.pos.y>edgeBottom || enemyBul.pos.y < edgeTop) {
		    		enemyBul.isShot = false;
		    	}
		    	enemyBul.isHit = HitCheck(enemyBul, *player);
		    	if (enemyBul.isHit) {
		    		player->OnCollision(-enemyBul.damage);
		    		hUDShakeTimer = 12;
		    		enemyBul.isShot = false;
		    	}
		    }
		    
		    
		    
		    //=======================Elite====================================================
		    if (timer==2000) {
		    	elite.target = { player->GetPos().x,player->GetPos().y};
		    	elite.pos = {-30.0f,100.0f};
                elites.push_back(elite);
		    }
		    if (timer == 2200) {
		    	elite.target = { player->GetPos().x,player->GetPos().y};
		    	elite.pos = { 1950.0f,100.0f };
		    	elites.push_back(elite);
		    }
		    if (timer == 3200) {
		    	elite.target = { player->GetPos().x,player->GetPos().y};
		    	elite.pos = { -30.0f,100.0f };
		    	elites.push_back(elite);
		    }
		    if (timer == 3800) {
		    	elite.target = { player->GetPos().x,player->GetPos().y};
		    	elite.pos = { 1950.0f,100.0f };
		    	elites.push_back(elite);
		    }
		    if (timer == 4500) {
		    	elite.target = { player->GetPos().x,player->GetPos().y};
		    	elite.pos = { -30.0f,100.0f };
		    	elites.push_back(elite);
		    }
		    if (timer == 4700) {
		    	elite.target = { player->GetPos().x,player->GetPos().y};
		    	elite.pos = { 1950.0f,100.0f };
		    	elites.push_back(elite);
		    }
		    
		    for (auto& eli : elites) {
		    
		    	if (eli.hp <= 0) {
		    		eli.isAlive = false;
		    	}
		    	if (eli.isAlive) {
		    	if (eli.pos.x > 1955 || eli.pos.x < -35 || eli.pos.y>1820 || eli.pos.y < -745) {
		    		eli.moveCase = 1;
		    		eli.pos.x = player->GetPos().x;
		    		eli.pos.y = 1815.0f;
		    	}
		    	if (eli.moveCase == 1) {
		    		eli.speed.y = -3.0f;
		    		eli.angle=3.15f;
		    		if (eli.pos.y > player->GetPos().y + 150.0f) {
                        if (eli.pos.x - player->GetPos().x > 4) {
		    		    	eli.speed.x = -2.0f;
		    		    }
		    		    else if (eli.pos.x - player->GetPos().x < -4) {
		    		    	eli.speed.x = 2.0f;
		    		    }
		    
		    		    else {
		    		    	eli.speed.x = 0.0f;
		    		    }
		    		}
		    		else {
		    			eli.speed.x = 0.0f;
		    
		    		}
		    
		    		eli.pos.x += eli.speed.x;
		    		eli.pos.y += eli.speed.y;
		    
		    	}
		    	if (eli.moveCase == 0) {
		    		float dX = eli.target.x - eli.pos.x;
		    		float dY = eli.target.y - eli.pos.y;
		    		float length = sqrtf(dX * dX + dY * dY);
		    		float dirX = dX;
		    		float dirY = dY;
		    		if (length != 0.0f) {
		    			dirX = dX / length;
		    			dirY = dY / length;
		    		}
		    		eli.speed = { 4.0f,3.0f };
		    		eli.pos.x += dirX * eli.speed.x;
		    		eli.pos.y += dirY * eli.speed.y;
		    
		    		eli.target.x = eli.pos.x + dirX;
		    		eli.target.y = eli.pos.y + dirY;
		    
		    		}
		    
		    		eli.shotTimer--;
		    		if (eli.shotTimer <= 0) {
		    			if (eli.moveCase == 0) {
		    				eliteBullet.speed.y = 10.0f;
		    			}
		    			if (eli.moveCase == 1) {
		    				eliteBullet.speed.y = -10.0f;
		    			}
		    			eliteBullet.pos = { eli.pos.x - 12.0f,eli.pos.y };
		    			eliteBullets.push_back(eliteBullet);
		    			eliteBullet.pos = { eli.pos.x + 12.0f,eli.pos.y };
		    			eliteBullets.push_back(eliteBullet);
		    			eli.shotTimer = eli.rate;
		    		}
		    	}
		    	//eli.leftTopRotated.x = eli.kLeftTopX * cosf(eli.theta) - eli.kLeftTopY * sinf(eli.theta);
		     //   eli.leftTopRotated.y = eli.kLeftTopY * cosf(eli.theta) + eli.kLeftTopX * sinf(eli.theta);
		    	//eli.leftTopPos.x = eli.leftTopRotated.x + eli.pos.x,
		     //   eli.leftTopPos.y = eli.leftTopRotated.y + eli.pos.y;
		    
		    }
		    
		    for (auto& eliteBul : eliteBullets) {
		    	if (eliteBul.isShot) {
		    		eliteBul.pos.y += eliteBul.speed.y;
		    	}
		    	if (eliteBul.pos.x > edgeRight || eliteBul.pos.x < edgeLeft || eliteBul.pos.y>edgeBottom || eliteBul.pos.y < edgeTop) {
		    		eliteBul.isShot = false;
		    	}
		    	eliteBul.isHit = HitCheck(eliteBul, *player);
		    	if (eliteBul.isHit) {
		    		player->OnCollision(-eliteBul.damage);
		    		hUDShakeTimer = 12;
		    		eliteBul.isShot = false;
		    	}
		    }
		    

			//===========================================================================================
			if (upgradeItem_1.isSpawn) {
				Novice::DrawSprite((int)upgradeItem_1.pos.x, (int)upgradeItem_1.pos.y, itemTH, 1, 1, 0, WHITE);
			}
			if (upgradeItem_2.isSpawn) {
				Novice::DrawSprite((int)upgradeItem_2.pos.x, (int)upgradeItem_2.pos.y, itemTH, 1, 1, 0, WHITE);
			}


			for (auto& mis : missiles) {
                if (mis.isShot) {
					if (mis.pos.y < p0.y - 5.0f) {
						Novice::DrawSpriteRect((int)mis.pos.x - 21 / 2, (int)mis.pos.y - 42 / 2, 0, 0, 21, 42, missileTH, 1.0f / 4.0f, 1, mis.angle, WHITE);
					}
				}
			}

			for (auto& bul : bullets) {
				if (bul.isShot) {
		    	    Novice::DrawSprite((int)bul.pos.x - bul.spriteWidth / 2, (int)bul.pos.y - bul.spriteHeight / 3, playerBullet1TH, 1.0f, 1.0f, bul.angle, WHITE);
				}
			}
			//==========================================================================================================================

		    for (auto& enemyBul : enemyBullets) {
		    	if (enemyBul.isShot) {
		    		Novice::DrawSprite((int)enemyBul.pos.x-15/2, (int)enemyBul.pos.y-30/2, enemyBulletTH, 1, 1, enemyBul.angle, WHITE);
		    	}
		    }
		    for (auto& ene : enemies) {
		    	if (ene.isAlive) {
		    		Novice::DrawSprite((int)ene.pos.x - 60 / 2, (int)ene.pos.y - 78 / 2, enemy1TH, 1, 1, ene.angle, ene.color);
		    	}
		    	if (targetEnemyIndex != -1 && enemies[targetEnemyIndex].isAlive) {
		    		Novice::DrawSprite((int)mislLockOn.x - 22, (int)mislLockOn.y - 26, lockonTH, 1, 1, 0.0f, WHITE);
		    	}
		    }
		    
		    for (auto& eliteBul : eliteBullets) {
		    	if (eliteBul.isShot) {
		    		Novice::DrawSprite((int)eliteBul.pos.x - 15 / 2, (int)eliteBul.pos.y - 30 / 2, enemyBulletTH, 1, 1, eliteBul.angle, WHITE);
                }
		    }
		    for (auto& eli : elites) {
		    	if (eli.isAlive&&eli.moveCase==0) {
		    		Novice::DrawSprite((int)eli.pos.x-eli.spriteWidth/2, (int)eli.pos.y-eli.spriteHeight/2, eliteTH, 1, 1, eli.angle, WHITE);
		    	}
		    	if (eli.isAlive && eli.moveCase == 1) {
		    		Novice::DrawSprite((int)eli.pos.x + eli.spriteWidth / 2, (int)eli.pos.y + eli.spriteHeight / 2, eliteTH, 1, 1, eli.angle, WHITE);
		    	}
		    
		    }
		    //==============================================================================================
		    
		    for (auto& obj1 : objs1) {
		    	if (obj1.isShot) {
		    		Novice::DrawEllipse((int)obj1.pos.x, (int)obj1.pos.y, obj1.radius, obj1.radius, 0, WHITE, kFillModeSolid);
		    	}
		    }
		    
		    //=====================================================================================
		    Novice::DrawSprite(0+ (int)randX, 0 + (int)randY, leftHUD_TH, 1, 1, 0, WHITE);
#pragma region Radar
		    for (auto& rEHUD : radarEnemyHUDs) {
		    
		    	for (auto& ene : enemies) {
		    		if (ene.isAlive) {
		    			rEHUD.pos = { radarOriginal.x + (ene.pos.x - player->GetPos().x) / 5,radarOriginal.y + (ene.pos.y - player->GetPos().y) / 5};
		    			if (rEHUD.pos.x >= 15 && rEHUD.pos.x <= 336 && rEHUD.pos.y >= 742 && rEHUD.pos.y <= 1064) {
		    				Novice::DrawSprite((int)rEHUD.pos.x - 21 / 2 + (int)randX, (int)rEHUD.pos.y - 21 / 2 + (int)randY, radarEnemyHUD_TH, 1, 1, 0, rEHUD.color);
		    			}
		    
		    		}
		    
		    	}
		    }
		    
#pragma endregion

#pragma region HUD
		    Novice::DrawSpriteRect((int)pROXWARN_HUD.pos.x + (int)randX, (int)pROXWARN_HUD.pos.y + (int)randY, (int)pROXWARN_HUD.drawPosX, 0, pROXWARN_HUD.spriteWidth / 2, pROXWARN_HUD.spriteHeight, pROXWARN_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)qTMFAIL_HUD.pos.x + (int)randX, (int)qTMFAIL_HUD.pos.y + (int)randY, (int)qTMFAIL_HUD.drawPosX, 0, qTMFAIL_HUD.spriteWidth / 2, qTMFAIL_HUD.spriteHeight, qTMFAIL_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)rDRLOCK_HUD.pos.x + (int)randX, (int)rDRLOCK_HUD.pos.y + (int)randY, (int)rDRLOCK_HUD.drawPosX, 0, rDRLOCK_HUD.spriteWidth / 2, rDRLOCK_HUD.spriteHeight, qDRLOCK_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)cOOLFAIL_HUD.pos.x + (int)randX, (int)cOOLFAIL_HUD.pos.y + (int)randY, (int)cOOLFAIL_HUD.drawPosX, 0, cOOLFAIL_HUD.spriteWidth / 2, cOOLFAIL_HUD.spriteHeight, coolFailTH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)mISLINCM_HUD.pos.x + (int)randX, (int)mISLINCM_HUD.pos.y + (int)randY, (int)mISLINCM_HUD.drawPosX, 0, mISLINCM_HUD.spriteWidth / 2 , mISLINCM_HUD.spriteHeight, mSLINCM_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)eMPINCM_HUD.pos.x + (int)randX, (int)eMPINCM_HUD.pos.y + (int)randY, (int)eMPINCM_HUD.drawPosX, 0, eMPINCM_HUD.spriteWidth / 2 , eMPINCM_HUD.spriteHeight, eMPINCM_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)menuHUD.pos.x + (int)randX, (int)menuHUD.pos.y + (int)randY, (int)menuHUD.drawPosX, 0, menuHUD.spriteWidth, menuHUD.spriteHeight, menuTH, 1, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)cOMMS_HUD.pos.x + (int)randX, (int)cOMMS_HUD.pos.y + (int)randY, (int)cOMMS_HUD.drawPosX, 0, cOMMS_HUD.spriteWidth, cOMMS_HUD.spriteHeight, cOMMS_TH, 1, 1, 0, WHITE);
		    
		    Novice::DrawSprite(1563 + (int)randX, 0 + (int)randY, rightHUD_TH, 1, 1, 0, WHITE);
		    
		    //=============GunsAmmoNumber 1==============================================
		    Novice::DrawSprite(1786+ (int)randX, 105+ (int)randY, y24NumTH[gunsAmmoRemNumArr_1[0]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1799+ (int)randX, 105+ (int)randY, y24NumTH[gunsAmmoRemNumArr_1[1]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1812+ (int)randX, 105+ (int)randY, y24NumTH[gunsAmmoRemNumArr_1[2]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1825+ (int)randX, 105+ (int)randY, y24NumTH[gunsAmmoRemNumArr_1[3]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1838+ (int)randX, 105+ (int)randY, y24NumTH[gunsAmmoRemNumArr_1[4]], 1, 1, 0, WHITE);
		    //=============GunsAmmoNumber 2==============================================
		    Novice::DrawSprite(1786+ (int)randX, 156+ (int)randY, y24NumTH[gunsAmmoRemNumArr_2[0]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1799+ (int)randX, 156+ (int)randY, y24NumTH[gunsAmmoRemNumArr_2[1]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1812+ (int)randX, 156+ (int)randY, y24NumTH[gunsAmmoRemNumArr_2[2]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1825+ (int)randX, 156+ (int)randY, y24NumTH[gunsAmmoRemNumArr_2[3]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1838+ (int)randX, 156+ (int)randY, y24NumTH[gunsAmmoRemNumArr_2[4]], 1, 1, 0, WHITE);
            //=============GunsAmmoNumber 3==============================================
		    Novice::DrawSprite(1786+ (int)randX, 207+ (int)randY, y24NumTH[gunsAmmoRemNumArr_3[0]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1799+ (int)randX, 207+ (int)randY, y24NumTH[gunsAmmoRemNumArr_3[1]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1812+ (int)randX, 207+ (int)randY, y24NumTH[gunsAmmoRemNumArr_3[2]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1825+ (int)randX, 207+ (int)randY, y24NumTH[gunsAmmoRemNumArr_3[3]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1838+ (int)randX, 207+ (int)randY, y24NumTH[gunsAmmoRemNumArr_3[4]], 1, 1, 0, WHITE);
		    //==================MissileNum===============================================
		    Novice::DrawSprite(1873 + (int)randX, 335 + (int)randY, y36NumTH[mislRemNumArr[0]], 1, 1, 0, WHITE);
		    //===============vEL=========================================================
		    Novice::DrawSprite(1601+ (int)randX, 541+ (int)randY, y36NumTH[velArr[0]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1620+ (int)randX, 541+ (int)randY, y36NumTH[velArr[1]], 1, 1, 0, WHITE);
		    Novice::DrawSprite(1639+ (int)randX, 541+ (int)randY, y36NumTH[velArr[2]], 1, 1, 0, WHITE);
		    //================================================================================================================
		    Novice::DrawSpriteRect((int)oC_1HUD.pos.x+ (int)randX, (int)oC_1HUD.pos.y+ (int)randY, (int)oC_1HUD.drawPosX,0, oC_1HUD.spriteWidth/2, oC_1HUD.spriteHeight, oN_OFF_TH, 0.5f,1, 0, WHITE);
		    Novice::DrawSpriteRect((int)oC_2HUD.pos.x+ (int)randX, (int)oC_2HUD.pos.y+ (int)randY, (int)oC_2HUD.drawPosX, 0, oC_2HUD.spriteWidth / 2, oC_2HUD.spriteHeight, oN_OFF_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)oC_3HUD.pos.x+ (int)randX, (int)oC_3HUD.pos.y+ (int)randY, (int)oC_3HUD.drawPosX, 0, oC_3HUD.spriteWidth / 2, oC_3HUD.spriteHeight, oN_OFF_TH, 0.5f, 1, 0, WHITE);
		    
		    
		    
		    Novice::DrawQuad(1788 + (int)randX, 675 - tHR + (int)randY, 1803 + (int)randX, 675 - tHR + (int)randY, 1788 + (int)randX, 675 + (int)randY, 1803 + (int)randX, 675 + (int)randY, 0, 0, 15, tHR, tHR_BarTH, WHITE);
		    Novice::DrawSprite(1686 + (int)randX, 429 + (int)randY, vEL_Indicator_1TH, 1, 1, 0, WHITE);
		    Novice::DrawSpriteRect(1660 + (int)randX, 436 + (int)randY, 0, vEL_Indicator_DrawPosY, 83, 236, vEL_indicator_2TH, 1, 236.0f / 789.0f, 0, WHITE);
		    
		    
		    
		    //=========================================================================================================
		    Novice::DrawSpriteRect((int)vTOL_HUD.pos.x + (int)randX, (int)vTOL_HUD.pos.y + (int)randY, (int)vTOL_HUD.drawPosX, 0, vTOL_HUD.spriteWidth / 2, vTOL_HUD.spriteHeight, vTOL_TH, 0.5, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)cPLD_HUD.pos.x + (int)randX, (int)cPLD_HUD.pos.y + (int)randY, (int)cPLD_HUD.drawPosX, 0, cPLD_HUD.spriteWidth / 2, cPLD_HUD.spriteHeight, cPLD_TH, 0.5, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)eSP_HUD.pos.x + (int)randX, (int)eSP_HUD.pos.y + (int)randY, (int)eSP_HUD.drawPosX, 0, eSP_HUD.spriteWidth / 2, eSP_HUD.spriteHeight, eSP_TH, 0.5, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)gEAR_HUD.pos.x + (int)randX, (int)gEAR_HUD.pos.y + (int)randY, (int)gEAR_HUD.drawPosX, 0, gEAR_HUD.spriteWidth / 2, gEAR_HUD.spriteHeight, gEAR_TH, 0.5, 1, 0, WHITE);
		    
		    //==================================================================================================================================================
		    Novice::DrawSpriteRect((int)wPNHEAT_HUD.pos.x + (int)randX, (int)wPNHEAT_HUD.pos.y + (int)randY, (int)wPNHEAT_HUD.drawPosX, 0, wPNHEAT_HUD.spriteWidth / 2, wPNHEAT_HUD.spriteHeight, wPNHEAT_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)sHIELDDOWN_HUD.pos.x + (int)randX, (int)sHIELDDOWN_HUD.pos.y + (int)randY, (int)sHIELDDOWN_HUD.drawPosX, 0, sHIELDDOWN_HUD.spriteWidth / 2, sHIELDDOWN_HUD.spriteHeight, sHIELDDOWN_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)tHRHEAT_HUD.pos.x + (int)randX, (int)tHRHEAT_HUD.pos.y + (int)randY, (int)tHRHEAT_HUD.drawPosX, 0, tHRHEAT_HUD.spriteWidth / 2, tHRHEAT_HUD.spriteHeight, tHRHEAT_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)pWRHEAT_HUD.pos.x + (int)randX, (int)pWRHEAT_HUD.pos.y + (int)randY, (int)pWRHEAT_HUD.drawPosX, 0, pWRHEAT_HUD.spriteWidth / 2, pWRHEAT_HUD.spriteHeight, pWRHEAT_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)pWRLOW_HUD.pos.x + (int)randX, (int)pWRLOW_HUD.pos.y + (int)randY, (int)pWRLOW_HUD.drawPosX, 0, pWRLOW_HUD.spriteWidth / 2, pWRLOW_HUD.spriteHeight, pWRLOW_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)hYDLOW_HUD.pos.x + (int)randX, (int)hYDLOW_HUD.pos.y + (int)randY, (int)hYDLOW_HUD.drawPosX, 0, hYDLOW_HUD.spriteWidth / 2, hYDLOW_HUD.spriteHeight, hYDLOW_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawSpriteRect((int)qUALOW_HUD.pos.x + (int)randX, (int)qUALOW_HUD.pos.y + (int)randY, (int)qUALOW_HUD.drawPosX, 0, qUALOW_HUD.spriteWidth / 2, qUALOW_HUD.spriteHeight, qUALOW_TH, 0.5f, 1, 0, WHITE);
		    Novice::DrawQuad(1584 + (int)randX, 885 + (int)randY, 1584 + (int)pWR + (int)randX, 885 + (int)randY, 1584 + (int)randX, 885 + 27 + (int)randY, 1584 + (int)pWR + (int)randX, 885 + 27 + (int)randY, 0, 0, (int)pWR, 27, pWR_HYD_QUA_BarTH, WHITE);
		    Novice::DrawQuad(1584 + (int)randX, 960 + (int)randY, 1584 + (int)hYD + (int)randX, 960 + (int)randY, 1584 + (int)randX, 960 + 27 + (int)randY, 1584 + (int)hYD + (int)randX, 960 + 27 + (int)randY, 0, 0, (int)hYD, 27, pWR_HYD_QUA_BarTH, WHITE);
		    Novice::DrawQuad(1584 + (int)randX, 1035 + (int)randY, 1584 + (int)qUA + (int)randX, 1035 + (int)randY, 1584 + (int)randX, 1035 + 27 + (int)randY, 1584 + (int)qUA + (int)randX, 1035 + 27 + (int)randY, 0, 0, (int)qUA, 27, pWR_HYD_QUA_BarTH, WHITE);
		    
#pragma endregion

		    if (player->GetIsAlive()) {
		    	if (playerFlameAniNum <= 2) {
		    		Novice::DrawSpriteRect(int(player->GetPos().x - 18), int(player->GetPos().y + 28), playerFlame.currentFrame * 36, 0, 36, 30, playerFlameAni[playerFlameAniNum], 1.0f / 4.0f, 1, 0, WHITE);
		    	}
		    	else {
		    		Novice::DrawSpriteRect(int(player->GetPos().x - 16), int(player->GetPos().y + 28), playerFlame.currentFrame * 30, 0, 30, 30, playerFlameAni[playerFlameAniNum], 1.0f / 4.0f, 1, 0, WHITE);
		    	}
				player->Draw();
		    }
		    
		    /*Novice::DrawEllipse((int)mis.Pos.x, (int)mis.Pos.y, 5, 5, 0, WHITE, kFillModeSolid);*/
#pragma region ScreenPrintf
		    Novice::ScreenPrintf(359, 5, "RadarEnemyHUDs.size %d", radarEnemyHUDs.size());
		    Novice::ScreenPrintf(359, 25, "%d", wPNOC_t.timer);
		    Novice::ScreenPrintf(359, 45, "%d", wPNOC_t.coolDownTimer);
		    Novice::ScreenPrintf(359, 65, "TargetEnemyIndex %d", targetEnemyIndex);
		    Novice::ScreenPrintf(359, 85, "Timer %d", timer);
		    Novice::ScreenPrintf(359, 105, "Rand %d", upgradeItem_1.randSpawn);
		    Novice::ScreenPrintf(359, 125, "Player HP %d", player->GetHP());
		    Novice::ScreenPrintf(359, 145, "%d", sHIELDDOWN_HUD.flashTimer);

			break;
		}


#pragma endregion
		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
