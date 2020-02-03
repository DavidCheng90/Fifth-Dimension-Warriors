#include "Warrior.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "resource.h"

Warrior::Warrior(HINSTANCE hAppInst)
{
	// General Inputs
	Vec2 p0(175.0f, 305.0f);
	Vec2 v0(0.0f, 0.0f);
	Circle bc(38.0f, p0);

	wNewMousePos = p0;

	wBattleBounds = Rect(-10, 9, 1008, 601);

	wP1Frame = 0;
	wP1LifePoints = 304;
	wP1DmgTaken = 0;
	wP1MoveSpeed = 100.0f;
	wP1SlowTime = 0.0f;

	wP2Frame = 0;
	wP2LifePoints = 304;
	wP2DmgTaken = 0;
	wP2MoveSpeed = 100.0f;
	wP2SlowTime = 0.0f;

	wP2Start = false;

	// Player 1
	wP1Position = p0;
	wP1BoundingCircle.r = 38.0f;
	wP1BoundingCircle.c = wP1Position;

	wP1Quattro[0] = new Sprite(hAppInst, IDB_QUATTRO_1A, IDB_QUATTRO_1AMASK, bc, p0, v0);
	wP1Quattro[1] = new Sprite(hAppInst, IDB_QUATTRO_1B, IDB_QUATTRO_1BMASK, bc, p0, v0);
	wP1Quattro[2] = new Sprite(hAppInst, IDB_QUATTRO_1C, IDB_QUATTRO_1CMASK, bc, p0, v0);
	wP1Quattro[3] = new Sprite(hAppInst, IDB_QUATTRO_1D, IDB_QUATTRO_1DMASK, bc, p0, v0);
	wP1Quattro[4] = new Sprite(hAppInst, IDB_QUATTRO_2A, IDB_QUATTRO_2AMASK, bc, p0, v0);
	wP1Quattro[5] = new Sprite(hAppInst, IDB_QUATTRO_2B, IDB_QUATTRO_2BMASK, bc, p0, v0);
	wP1Quattro[6] = new Sprite(hAppInst, IDB_QUATTRO_2C, IDB_QUATTRO_2CMASK, bc, p0, v0);
	wP1Quattro[7] = new Sprite(hAppInst, IDB_QUATTRO_2D, IDB_QUATTRO_2DMASK, bc, p0, v0);
	wP1Quattro[8] = new Sprite(hAppInst, IDB_QUATTRO_3A, IDB_QUATTRO_3AMASK, bc, p0, v0);
	wP1Quattro[9] = new Sprite(hAppInst, IDB_QUATTRO_3B, IDB_QUATTRO_3BMASK, bc, p0, v0);
	wP1Quattro[10] = new Sprite(hAppInst, IDB_QUATTRO_3C, IDB_QUATTRO_3CMASK, bc, p0, v0);
	wP1Quattro[11] = new Sprite(hAppInst, IDB_QUATTRO_3D, IDB_QUATTRO_3DMASK, bc, p0, v0);
	wP1Quattro[12] = new Sprite(hAppInst, IDB_QUATTRO_4A, IDB_QUATTRO_4AMASK, bc, p0, v0);
	wP1Quattro[13] = new Sprite(hAppInst, IDB_QUATTRO_4B, IDB_QUATTRO_4BMASK, bc, p0, v0);
	wP1Quattro[14] = new Sprite(hAppInst, IDB_QUATTRO_4C, IDB_QUATTRO_4CMASK, bc, p0, v0);
	wP1Quattro[15] = new Sprite(hAppInst, IDB_QUATTRO_4D, IDB_QUATTRO_4DMASK, bc, p0, v0);

	wP1Seraphina[0] = new Sprite(hAppInst, IDB_SERAPHINA_1A, IDB_SERAPHINA_1AMASK, bc, p0, v0);
	wP1Seraphina[1] = new Sprite(hAppInst, IDB_SERAPHINA_1B, IDB_SERAPHINA_1BMASK, bc, p0, v0);
	wP1Seraphina[2] = new Sprite(hAppInst, IDB_SERAPHINA_1C, IDB_SERAPHINA_1CMASK, bc, p0, v0);
	wP1Seraphina[3] = new Sprite(hAppInst, IDB_SERAPHINA_1D, IDB_SERAPHINA_1DMASK, bc, p0, v0);
	wP1Seraphina[4] = new Sprite(hAppInst, IDB_SERAPHINA_2A, IDB_SERAPHINA_2AMASK, bc, p0, v0);
	wP1Seraphina[5] = new Sprite(hAppInst, IDB_SERAPHINA_2B, IDB_SERAPHINA_2BMASK, bc, p0, v0);
	wP1Seraphina[6] = new Sprite(hAppInst, IDB_SERAPHINA_2C, IDB_SERAPHINA_2CMASK, bc, p0, v0);
	wP1Seraphina[7] = new Sprite(hAppInst, IDB_SERAPHINA_2D, IDB_SERAPHINA_2DMASK, bc, p0, v0);
	wP1Seraphina[8] = new Sprite(hAppInst, IDB_SERAPHINA_3A, IDB_SERAPHINA_3AMASK, bc, p0, v0);
	wP1Seraphina[9] = new Sprite(hAppInst, IDB_SERAPHINA_3B, IDB_SERAPHINA_3BMASK, bc, p0, v0);
	wP1Seraphina[10] = new Sprite(hAppInst, IDB_SERAPHINA_3C, IDB_SERAPHINA_3CMASK, bc, p0, v0);
	wP1Seraphina[11] = new Sprite(hAppInst, IDB_SERAPHINA_3D, IDB_SERAPHINA_3DMASK, bc, p0, v0);
	wP1Seraphina[12] = new Sprite(hAppInst, IDB_SERAPHINA_4A, IDB_SERAPHINA_4AMASK, bc, p0, v0);
	wP1Seraphina[13] = new Sprite(hAppInst, IDB_SERAPHINA_4B, IDB_SERAPHINA_4BMASK, bc, p0, v0);
	wP1Seraphina[14] = new Sprite(hAppInst, IDB_SERAPHINA_4C, IDB_SERAPHINA_4CMASK, bc, p0, v0);
	wP1Seraphina[15] = new Sprite(hAppInst, IDB_SERAPHINA_4D, IDB_SERAPHINA_4DMASK, bc, p0, v0);

	wP1Dimitri[0] = new Sprite(hAppInst, IDB_DIMITRI_1A, IDB_DIMITRI_1AMASK, bc, p0, v0);
	wP1Dimitri[1] = new Sprite(hAppInst, IDB_DIMITRI_1B, IDB_DIMITRI_1BMASK, bc, p0, v0);
	wP1Dimitri[2] = new Sprite(hAppInst, IDB_DIMITRI_1C, IDB_DIMITRI_1CMASK, bc, p0, v0);
	wP1Dimitri[3] = new Sprite(hAppInst, IDB_DIMITRI_1D, IDB_DIMITRI_1DMASK, bc, p0, v0);
	wP1Dimitri[4] = new Sprite(hAppInst, IDB_DIMITRI_2A, IDB_DIMITRI_2AMASK, bc, p0, v0);
	wP1Dimitri[5] = new Sprite(hAppInst, IDB_DIMITRI_2B, IDB_DIMITRI_2BMASK, bc, p0, v0);
	wP1Dimitri[6] = new Sprite(hAppInst, IDB_DIMITRI_2C, IDB_DIMITRI_2CMASK, bc, p0, v0);
	wP1Dimitri[7] = new Sprite(hAppInst, IDB_DIMITRI_2D, IDB_DIMITRI_2DMASK, bc, p0, v0);
	wP1Dimitri[8] = new Sprite(hAppInst, IDB_DIMITRI_3A, IDB_DIMITRI_3AMASK, bc, p0, v0);
	wP1Dimitri[9] = new Sprite(hAppInst, IDB_DIMITRI_3B, IDB_DIMITRI_3BMASK, bc, p0, v0);
	wP1Dimitri[10] = new Sprite(hAppInst, IDB_DIMITRI_3C, IDB_DIMITRI_3CMASK, bc, p0, v0);
	wP1Dimitri[11] = new Sprite(hAppInst, IDB_DIMITRI_3D, IDB_DIMITRI_3DMASK, bc, p0, v0);
	wP1Dimitri[12] = new Sprite(hAppInst, IDB_DIMITRI_4A, IDB_DIMITRI_4AMASK, bc, p0, v0);
	wP1Dimitri[13] = new Sprite(hAppInst, IDB_DIMITRI_4B, IDB_DIMITRI_4BMASK, bc, p0, v0);
	wP1Dimitri[14] = new Sprite(hAppInst, IDB_DIMITRI_4C, IDB_DIMITRI_4CMASK, bc, p0, v0);
	wP1Dimitri[15] = new Sprite(hAppInst, IDB_DIMITRI_4D, IDB_DIMITRI_4DMASK, bc, p0, v0);

	wP1LiuJiao[0] = new Sprite(hAppInst, IDB_LIUJIAO_1A, IDB_LIUJIAO_1AMASK, bc, p0, v0);
	wP1LiuJiao[1] = new Sprite(hAppInst, IDB_LIUJIAO_1B, IDB_LIUJIAO_1BMASK, bc, p0, v0);
	wP1LiuJiao[2] = new Sprite(hAppInst, IDB_LIUJIAO_1C, IDB_LIUJIAO_1CMASK, bc, p0, v0);
	wP1LiuJiao[3] = new Sprite(hAppInst, IDB_LIUJIAO_1D, IDB_LIUJIAO_1DMASK, bc, p0, v0);
	wP1LiuJiao[4] = new Sprite(hAppInst, IDB_LIUJIAO_2A, IDB_LIUJIAO_2AMASK, bc, p0, v0);
	wP1LiuJiao[5] = new Sprite(hAppInst, IDB_LIUJIAO_2B, IDB_LIUJIAO_2BMASK, bc, p0, v0);
	wP1LiuJiao[6] = new Sprite(hAppInst, IDB_LIUJIAO_2C, IDB_LIUJIAO_2CMASK, bc, p0, v0);
	wP1LiuJiao[7] = new Sprite(hAppInst, IDB_LIUJIAO_2D, IDB_LIUJIAO_2DMASK, bc, p0, v0);
	wP1LiuJiao[8] = new Sprite(hAppInst, IDB_LIUJIAO_3A, IDB_LIUJIAO_3AMASK, bc, p0, v0);
	wP1LiuJiao[9] = new Sprite(hAppInst, IDB_LIUJIAO_3B, IDB_LIUJIAO_3BMASK, bc, p0, v0);
	wP1LiuJiao[10] = new Sprite(hAppInst, IDB_LIUJIAO_3C, IDB_LIUJIAO_3CMASK, bc, p0, v0);
	wP1LiuJiao[11] = new Sprite(hAppInst, IDB_LIUJIAO_3D, IDB_LIUJIAO_3DMASK, bc, p0, v0);
	wP1LiuJiao[12] = new Sprite(hAppInst, IDB_LIUJIAO_4A, IDB_LIUJIAO_4AMASK, bc, p0, v0);
	wP1LiuJiao[13] = new Sprite(hAppInst, IDB_LIUJIAO_4B, IDB_LIUJIAO_4BMASK, bc, p0, v0);
	wP1LiuJiao[14] = new Sprite(hAppInst, IDB_LIUJIAO_4C, IDB_LIUJIAO_4CMASK, bc, p0, v0);
	wP1LiuJiao[15] = new Sprite(hAppInst, IDB_LIUJIAO_4D, IDB_LIUJIAO_4DMASK, bc, p0, v0);

	// Player 2
	p0.x = 825.0f;
	bc.c = p0;

	wP2Position = p0;
	wP2BoundingCircle.r = 38.0f;
	wP2BoundingCircle.c = wP2Position;

	wP2Quattro[0] = new Sprite(hAppInst, IDB_QUATTRO_1A, IDB_QUATTRO_1AMASK, bc, p0, v0);
	wP2Quattro[1] = new Sprite(hAppInst, IDB_QUATTRO_1B, IDB_QUATTRO_1BMASK, bc, p0, v0);
	wP2Quattro[2] = new Sprite(hAppInst, IDB_QUATTRO_1C, IDB_QUATTRO_1CMASK, bc, p0, v0);
	wP2Quattro[3] = new Sprite(hAppInst, IDB_QUATTRO_1D, IDB_QUATTRO_1DMASK, bc, p0, v0);
	wP2Quattro[4] = new Sprite(hAppInst, IDB_QUATTRO_2A, IDB_QUATTRO_2AMASK, bc, p0, v0);
	wP2Quattro[5] = new Sprite(hAppInst, IDB_QUATTRO_2B, IDB_QUATTRO_2BMASK, bc, p0, v0);
	wP2Quattro[6] = new Sprite(hAppInst, IDB_QUATTRO_2C, IDB_QUATTRO_2CMASK, bc, p0, v0);
	wP2Quattro[7] = new Sprite(hAppInst, IDB_QUATTRO_2D, IDB_QUATTRO_2DMASK, bc, p0, v0);
	wP2Quattro[8] = new Sprite(hAppInst, IDB_QUATTRO_3A, IDB_QUATTRO_3AMASK, bc, p0, v0);
	wP2Quattro[9] = new Sprite(hAppInst, IDB_QUATTRO_3B, IDB_QUATTRO_3BMASK, bc, p0, v0);
	wP2Quattro[10] = new Sprite(hAppInst, IDB_QUATTRO_3C, IDB_QUATTRO_3CMASK, bc, p0, v0);
	wP2Quattro[11] = new Sprite(hAppInst, IDB_QUATTRO_3D, IDB_QUATTRO_3DMASK, bc, p0, v0);
	wP2Quattro[12] = new Sprite(hAppInst, IDB_QUATTRO_4A, IDB_QUATTRO_4AMASK, bc, p0, v0);
	wP2Quattro[13] = new Sprite(hAppInst, IDB_QUATTRO_4B, IDB_QUATTRO_4BMASK, bc, p0, v0);
	wP2Quattro[14] = new Sprite(hAppInst, IDB_QUATTRO_4C, IDB_QUATTRO_4CMASK, bc, p0, v0);
	wP2Quattro[15] = new Sprite(hAppInst, IDB_QUATTRO_4D, IDB_QUATTRO_4DMASK, bc, p0, v0);

	wP2Seraphina[0] = new Sprite(hAppInst, IDB_SERAPHINA_1A, IDB_SERAPHINA_1AMASK, bc, p0, v0);
	wP2Seraphina[1] = new Sprite(hAppInst, IDB_SERAPHINA_1B, IDB_SERAPHINA_1BMASK, bc, p0, v0);
	wP2Seraphina[2] = new Sprite(hAppInst, IDB_SERAPHINA_1C, IDB_SERAPHINA_1CMASK, bc, p0, v0);
	wP2Seraphina[3] = new Sprite(hAppInst, IDB_SERAPHINA_1D, IDB_SERAPHINA_1DMASK, bc, p0, v0);
	wP2Seraphina[4] = new Sprite(hAppInst, IDB_SERAPHINA_2A, IDB_SERAPHINA_2AMASK, bc, p0, v0);
	wP2Seraphina[5] = new Sprite(hAppInst, IDB_SERAPHINA_2B, IDB_SERAPHINA_2BMASK, bc, p0, v0);
	wP2Seraphina[6] = new Sprite(hAppInst, IDB_SERAPHINA_2C, IDB_SERAPHINA_2CMASK, bc, p0, v0);
	wP2Seraphina[7] = new Sprite(hAppInst, IDB_SERAPHINA_2D, IDB_SERAPHINA_2DMASK, bc, p0, v0);
	wP2Seraphina[8] = new Sprite(hAppInst, IDB_SERAPHINA_3A, IDB_SERAPHINA_3AMASK, bc, p0, v0);
	wP2Seraphina[9] = new Sprite(hAppInst, IDB_SERAPHINA_3B, IDB_SERAPHINA_3BMASK, bc, p0, v0);
	wP2Seraphina[10] = new Sprite(hAppInst, IDB_SERAPHINA_3C, IDB_SERAPHINA_3CMASK, bc, p0, v0);
	wP2Seraphina[11] = new Sprite(hAppInst, IDB_SERAPHINA_3D, IDB_SERAPHINA_3DMASK, bc, p0, v0);
	wP2Seraphina[12] = new Sprite(hAppInst, IDB_SERAPHINA_4A, IDB_SERAPHINA_4AMASK, bc, p0, v0);
	wP2Seraphina[13] = new Sprite(hAppInst, IDB_SERAPHINA_4B, IDB_SERAPHINA_4BMASK, bc, p0, v0);
	wP2Seraphina[14] = new Sprite(hAppInst, IDB_SERAPHINA_4C, IDB_SERAPHINA_4CMASK, bc, p0, v0);
	wP2Seraphina[15] = new Sprite(hAppInst, IDB_SERAPHINA_4D, IDB_SERAPHINA_4DMASK, bc, p0, v0);

	wP2Dimitri[0] = new Sprite(hAppInst, IDB_DIMITRI_1A, IDB_DIMITRI_1AMASK, bc, p0, v0);
	wP2Dimitri[1] = new Sprite(hAppInst, IDB_DIMITRI_1B, IDB_DIMITRI_1BMASK, bc, p0, v0);
	wP2Dimitri[2] = new Sprite(hAppInst, IDB_DIMITRI_1C, IDB_DIMITRI_1CMASK, bc, p0, v0);
	wP2Dimitri[3] = new Sprite(hAppInst, IDB_DIMITRI_1D, IDB_DIMITRI_1DMASK, bc, p0, v0);
	wP2Dimitri[4] = new Sprite(hAppInst, IDB_DIMITRI_2A, IDB_DIMITRI_2AMASK, bc, p0, v0);
	wP2Dimitri[5] = new Sprite(hAppInst, IDB_DIMITRI_2B, IDB_DIMITRI_2BMASK, bc, p0, v0);
	wP2Dimitri[6] = new Sprite(hAppInst, IDB_DIMITRI_2C, IDB_DIMITRI_2CMASK, bc, p0, v0);
	wP2Dimitri[7] = new Sprite(hAppInst, IDB_DIMITRI_2D, IDB_DIMITRI_2DMASK, bc, p0, v0);
	wP2Dimitri[8] = new Sprite(hAppInst, IDB_DIMITRI_3A, IDB_DIMITRI_3AMASK, bc, p0, v0);
	wP2Dimitri[9] = new Sprite(hAppInst, IDB_DIMITRI_3B, IDB_DIMITRI_3BMASK, bc, p0, v0);
	wP2Dimitri[10] = new Sprite(hAppInst, IDB_DIMITRI_3C, IDB_DIMITRI_3CMASK, bc, p0, v0);
	wP2Dimitri[11] = new Sprite(hAppInst, IDB_DIMITRI_3D, IDB_DIMITRI_3DMASK, bc, p0, v0);
	wP2Dimitri[12] = new Sprite(hAppInst, IDB_DIMITRI_4A, IDB_DIMITRI_4AMASK, bc, p0, v0);
	wP2Dimitri[13] = new Sprite(hAppInst, IDB_DIMITRI_4B, IDB_DIMITRI_4BMASK, bc, p0, v0);
	wP2Dimitri[14] = new Sprite(hAppInst, IDB_DIMITRI_4C, IDB_DIMITRI_4CMASK, bc, p0, v0);
	wP2Dimitri[15] = new Sprite(hAppInst, IDB_DIMITRI_4D, IDB_DIMITRI_4DMASK, bc, p0, v0);

	wP2LiuJiao[0] = new Sprite(hAppInst, IDB_LIUJIAO_1A, IDB_LIUJIAO_1AMASK, bc, p0, v0);
	wP2LiuJiao[1] = new Sprite(hAppInst, IDB_LIUJIAO_1B, IDB_LIUJIAO_1BMASK, bc, p0, v0);
	wP2LiuJiao[2] = new Sprite(hAppInst, IDB_LIUJIAO_1C, IDB_LIUJIAO_1CMASK, bc, p0, v0);
	wP2LiuJiao[3] = new Sprite(hAppInst, IDB_LIUJIAO_1D, IDB_LIUJIAO_1DMASK, bc, p0, v0);
	wP2LiuJiao[4] = new Sprite(hAppInst, IDB_LIUJIAO_2A, IDB_LIUJIAO_2AMASK, bc, p0, v0);
	wP2LiuJiao[5] = new Sprite(hAppInst, IDB_LIUJIAO_2B, IDB_LIUJIAO_2BMASK, bc, p0, v0);
	wP2LiuJiao[6] = new Sprite(hAppInst, IDB_LIUJIAO_2C, IDB_LIUJIAO_2CMASK, bc, p0, v0);
	wP2LiuJiao[7] = new Sprite(hAppInst, IDB_LIUJIAO_2D, IDB_LIUJIAO_2DMASK, bc, p0, v0);
	wP2LiuJiao[8] = new Sprite(hAppInst, IDB_LIUJIAO_3A, IDB_LIUJIAO_3AMASK, bc, p0, v0);
	wP2LiuJiao[9] = new Sprite(hAppInst, IDB_LIUJIAO_3B, IDB_LIUJIAO_3BMASK, bc, p0, v0);
	wP2LiuJiao[10] = new Sprite(hAppInst, IDB_LIUJIAO_3C, IDB_LIUJIAO_3CMASK, bc, p0, v0);
	wP2LiuJiao[11] = new Sprite(hAppInst, IDB_LIUJIAO_3D, IDB_LIUJIAO_3DMASK, bc, p0, v0);
	wP2LiuJiao[12] = new Sprite(hAppInst, IDB_LIUJIAO_4A, IDB_LIUJIAO_4AMASK, bc, p0, v0);
	wP2LiuJiao[13] = new Sprite(hAppInst, IDB_LIUJIAO_4B, IDB_LIUJIAO_4BMASK, bc, p0, v0);
	wP2LiuJiao[14] = new Sprite(hAppInst, IDB_LIUJIAO_4C, IDB_LIUJIAO_4CMASK, bc, p0, v0);
	wP2LiuJiao[15] = new Sprite(hAppInst, IDB_LIUJIAO_4D, IDB_LIUJIAO_4DMASK, bc, p0, v0);

	// General Attack Settings

	wP1UseQ = wP1UseW = wP1UseE = wP1UseR = false;
	wP2UseQ = wP2UseE = wP2UseE = wP2UseR = false;

	for (int a = 0; a < 4; ++a)
	{
		wP1AtkFrameSet[a] = 0;
		wP1AttackVel[a].x = 0.0f;
		wP1AttackVel[a].y = 0.0f;

		wP2AtkFrameSet[a] = 0;
		wP2AttackVel[a].x = 0.0f;
		wP2AttackVel[a].y = 0.0f;

		wP2TimeElapsed[a] = 0.0f;

		// Warrior Attack Timers
		for (int b = 0; b < 3; ++b)
			QuattroTimeElapsed[a][b] = 0.0f;

		SeraphinaTimeElapsed[a] = 0.0f;

		DimitriTimeElapsed[a] = 0.0f;

		for (int c = 0; c < 2; ++c)
			LiuJiaoTimeElapsed[a][c] = 0.0f;
	}

	// Quattro's Attacks
	p0 = wP1Position;

	bc.r = 15.0f;
	bc.c = p0;
	QuattroQAtk[0] = new Sprite(hAppInst, IDB_QUATTRO_Q1, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	QuattroQAtk[1] = new Sprite(hAppInst, IDB_QUATTRO_Q2, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	QuattroQAtk[2] = new Sprite(hAppInst, IDB_QUATTRO_Q3, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	QuattroQAtk[3] = new Sprite(hAppInst, IDB_QUATTRO_Q4, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	QuattroQAtk[4] = new Sprite(hAppInst, IDB_QUATTRO_Q5, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	QuattroQAtk[5] = new Sprite(hAppInst, IDB_QUATTRO_Q6, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	bc.r = 25.0f;
	QuattroQAtk[6] = new Sprite(hAppInst, IDB_QUATTRO_Q7, IDB_QUATTRO_Q7MASK, bc, p0, v0);
	QuattroQAtk[7] = new Sprite(hAppInst, IDB_QUATTRO_Q8, IDB_QUATTRO_Q7MASK, bc, p0, v0);
	QuattroQAtk[8] = new Sprite(hAppInst, IDB_QUATTRO_Q9, IDB_QUATTRO_Q7MASK, bc, p0, v0);

	QuattroWisOn = false;
	QuattroWAtk[0] = new Sprite(hAppInst, IDB_QUATTRO_W1, IDB_QUATTRO_W1MASK, bc, p0, v0);
	QuattroWAtk[1] = new Sprite(hAppInst, IDB_QUATTRO_W2, IDB_QUATTRO_W2MASK, bc, p0, v0);
	QuattroWAtk[2] = new Sprite(hAppInst, IDB_QUATTRO_W3, IDB_QUATTRO_W2MASK, bc, p0, v0);
	QuattroWAtk[3] = new Sprite(hAppInst, IDB_QUATTRO_W4, IDB_QUATTRO_W1MASK, bc, p0, v0);

	bc.r = 100.0f;
	QuattroEAtk = new Sprite(hAppInst, IDB_QUATTRO_E1, IDB_QUATTRO_E1MASK, bc, p0, v0);

	QuattroRisOn = false;
	bc.r = 94.5f;
	QuattroRAtk[0] = new Sprite(hAppInst, IDB_QUATTRO_R1, IDB_QUATTRO_R1MASK, bc, p0, v0);
	QuattroRAtk[1] = new Sprite(hAppInst, IDB_QUATTRO_R2, IDB_QUATTRO_R1MASK, bc, p0, v0);
	QuattroRAtk[2] = new Sprite(hAppInst, IDB_QUATTRO_R3, IDB_QUATTRO_R1MASK, bc, p0, v0);
	QuattroRAtk[3] = new Sprite(hAppInst, IDB_QUATTRO_R4, IDB_QUATTRO_R1MASK, bc, p0, v0);

	// Seraphina's Attacks
	for (int d = 0; d < 5; ++d)
		SeraphinaQisOn[d] = false;
	bc.r = 20.5f;
	SeraphinaQAtk[0] = new Sprite(hAppInst, IDB_SERAPHINA_Q1, IDB_SERAPHINA_Q1MASK, bc, p0, v0);
	SeraphinaQAtk[1] = new Sprite(hAppInst, IDB_SERAPHINA_Q2, IDB_SERAPHINA_Q1MASK, bc, p0, v0);
	SeraphinaQAtk[2] = new Sprite(hAppInst, IDB_SERAPHINA_Q3, IDB_SERAPHINA_Q1MASK, bc, p0, v0);
	SeraphinaQAtk[3] = new Sprite(hAppInst, IDB_SERAPHINA_Q4, IDB_SERAPHINA_Q1MASK, bc, p0, v0);
	SeraphinaQAtk[4] = new Sprite(hAppInst, IDB_SERAPHINA_Q5, IDB_SERAPHINA_Q1MASK, bc, p0, v0);

	for (int e = 0; e < 4; ++e)
		SeraphinaWisOn[e] = false;
	SeraphinaWNew = true;
	SeraphinaWSet = 0;
	bc.r = 33.0f;
	SeraphinaWAtk[0] = new Sprite(hAppInst, IDB_SERAPHINA_W1, IDB_SERAPHINA_W1MASK, bc, p0, v0);
	SeraphinaWAtk[1] = new Sprite(hAppInst, IDB_SERAPHINA_W2, IDB_SERAPHINA_W1MASK, bc, p0, v0);
	SeraphinaWAtk[2] = new Sprite(hAppInst, IDB_SERAPHINA_W1, IDB_SERAPHINA_W1MASK, bc, p0, v0);
	SeraphinaWAtk[3] = new Sprite(hAppInst, IDB_SERAPHINA_W2, IDB_SERAPHINA_W1MASK, bc, p0, v0);
	SeraphinaWAtk[4] = new Sprite(hAppInst, IDB_SERAPHINA_W1, IDB_SERAPHINA_W1MASK, bc, p0, v0);
	SeraphinaWAtk[5] = new Sprite(hAppInst, IDB_SERAPHINA_W2, IDB_SERAPHINA_W1MASK, bc, p0, v0);
	SeraphinaWAtk[6] = new Sprite(hAppInst, IDB_SERAPHINA_W1, IDB_SERAPHINA_W1MASK, bc, p0, v0);
	SeraphinaWAtk[7] = new Sprite(hAppInst, IDB_SERAPHINA_W2, IDB_SERAPHINA_W1MASK, bc, p0, v0);

	SeraphinaEisOn = false;
	bc.r = 51.5f;
	SeraphinaEAtk = new Sprite(hAppInst, IDB_SERAPHINA_E1, IDB_SERAPHINA_E1MASK, bc, p0, v0);

	for (int f = 0; f < 8; ++f)
		SeraphinaRisOn[f] = false;
	SeraphinaRNew = true;
	bc.r = 13.5f;
	SeraphinaRAtk[0] = new Sprite(hAppInst, IDB_SERAPHINA_R1, IDB_SERAPHINA_R1MASK, bc, p0, v0);
	SeraphinaRAtk[1] = new Sprite(hAppInst, IDB_SERAPHINA_R1, IDB_SERAPHINA_R1MASK, bc, p0, v0);
	SeraphinaRAtk[2] = new Sprite(hAppInst, IDB_SERAPHINA_R1, IDB_SERAPHINA_R1MASK, bc, p0, v0);
	SeraphinaRAtk[3] = new Sprite(hAppInst, IDB_SERAPHINA_R1, IDB_SERAPHINA_R1MASK, bc, p0, v0);
	SeraphinaRAtk[4] = new Sprite(hAppInst, IDB_SERAPHINA_R1, IDB_SERAPHINA_R1MASK, bc, p0, v0);
	SeraphinaRAtk[5] = new Sprite(hAppInst, IDB_SERAPHINA_R1, IDB_SERAPHINA_R1MASK, bc, p0, v0);
	SeraphinaRAtk[6] = new Sprite(hAppInst, IDB_SERAPHINA_R1, IDB_SERAPHINA_R1MASK, bc, p0, v0);
	SeraphinaRAtk[7] = new Sprite(hAppInst, IDB_SERAPHINA_R1, IDB_SERAPHINA_R1MASK, bc, p0, v0);

	// Dimitri's Attacks
	for (int g = 0; g < 3; ++g)
		DimitriQisOn[g] = false;
	DimitriQNew = true;
	bc.r = 26.0f;
	DimitriQAtk[0] = new Sprite(hAppInst, IDB_DIMITRI_Q1, IDB_DIMITRI_Q1MASK, bc, p0, v0);
	DimitriQAtk[1] = new Sprite(hAppInst, IDB_DIMITRI_Q2, IDB_DIMITRI_Q2MASK, bc, p0, v0);
	DimitriQAtk[2] = new Sprite(hAppInst, IDB_DIMITRI_Q3, IDB_DIMITRI_Q3MASK, bc, p0, v0);
	DimitriQAtk[3] = new Sprite(hAppInst, IDB_DIMITRI_Q1, IDB_DIMITRI_Q1MASK, bc, p0, v0);
	DimitriQAtk[4] = new Sprite(hAppInst, IDB_DIMITRI_Q2, IDB_DIMITRI_Q2MASK, bc, p0, v0);
	DimitriQAtk[5] = new Sprite(hAppInst, IDB_DIMITRI_Q3, IDB_DIMITRI_Q3MASK, bc, p0, v0);
	DimitriQAtk[6] = new Sprite(hAppInst, IDB_DIMITRI_Q1, IDB_DIMITRI_Q1MASK, bc, p0, v0);
	DimitriQAtk[7] = new Sprite(hAppInst, IDB_DIMITRI_Q2, IDB_DIMITRI_Q2MASK, bc, p0, v0);
	DimitriQAtk[8] = new Sprite(hAppInst, IDB_DIMITRI_Q3, IDB_DIMITRI_Q3MASK, bc, p0, v0);

	DimitriWTriangles = 0;
	DimitriWNew = true;
	bc.r = 18.0f;
	DimitriWAtk[0] = new Sprite(hAppInst, IDB_DIMITRI_W1, IDB_DIMITRI_W1MASK, bc, p0, v0);
	DimitriWAtk[1] = new Sprite(hAppInst, IDB_DIMITRI_W2, IDB_DIMITRI_W1MASK, bc, p0, v0);
	DimitriWAtk[2] = new Sprite(hAppInst, IDB_DIMITRI_W3, IDB_DIMITRI_W1MASK, bc, p0, v0);
	DimitriWAtk[3] = new Sprite(hAppInst, IDB_DIMITRI_W4, IDB_DIMITRI_W1MASK, bc, p0, v0);
	DimitriWAtk[4] = new Sprite(hAppInst, IDB_DIMITRI_W5, IDB_DIMITRI_W1MASK, bc, p0, v0);
	DimitriWAtk[5] = new Sprite(hAppInst, IDB_DIMITRI_W6, IDB_DIMITRI_W1MASK, bc, p0, v0);
	DimitriWAtk[6] = new Sprite(hAppInst, IDB_DIMITRI_W7, IDB_DIMITRI_W1MASK, bc, p0, v0);
	DimitriWAtk[7] = new Sprite(hAppInst, IDB_DIMITRI_W8, IDB_DIMITRI_W1MASK, bc, p0, v0);
	DimitriWAtk[8] = new Sprite(hAppInst, IDB_DIMITRI_W9, IDB_DIMITRI_W1MASK, bc, p0, v0);
	DimitriWAtk[9] = new Sprite(hAppInst, IDB_DIMITRI_W10, IDB_DIMITRI_W1MASK, bc, p0, v0);
	DimitriWAtk[10] = new Sprite(hAppInst, IDB_DIMITRI_W11, IDB_DIMITRI_W11MASK, bc, p0, v0);

	for (int h = 0; h < 10; ++h)
		DimitriWRAmmoList.push_back(DimitriWAtk[h]);

	bc.r = 17.0f;
	DimitriEAtk[0] = new Sprite(hAppInst, IDB_DIMITRI_E1, IDB_DIMITRI_E1MASK, bc, p0, v0);
	DimitriEAtk[1] = new Sprite(hAppInst, IDB_DIMITRI_E2, IDB_DIMITRI_E2MASK, bc, p0, v0);

	DimitriRTriangles = 0;
	DimitriRisOn = false;

	DimitriPenColor.lopnStyle = PS_SOLID;
	DimitriPenColor.lopnColor = RGB(255, 0, 0);
	DimitriPenColor.lopnWidth.x = 1;
	DimitriPen = CreatePenIndirect(&DimitriPenColor);

	DimitriOldPen = 0;

	for (int i = 0; i < 3; ++i)
	{
		DimitriRPoints[i].x = 0.0f;
		DimitriRPoints[i].y = 0.0f;
	}

	// Liu Jiao's Attacks
	for (int j = 0; j < 6; ++j)
		LiuJiaoQisOn[j] = false;
	LiuJiaoQStage = 0;
	bc.r = 17.5f;
	LiuJiaoQAtk[0] = new Sprite(hAppInst, IDB_LIUJIAO_Q1, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[1] = new Sprite(hAppInst, IDB_LIUJIAO_Q2, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[2] = new Sprite(hAppInst, IDB_LIUJIAO_Q3, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[3] = new Sprite(hAppInst, IDB_LIUJIAO_Q1, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[4] = new Sprite(hAppInst, IDB_LIUJIAO_Q2, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[5] = new Sprite(hAppInst, IDB_LIUJIAO_Q3, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[6] = new Sprite(hAppInst, IDB_LIUJIAO_Q1, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[7] = new Sprite(hAppInst, IDB_LIUJIAO_Q2, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[8] = new Sprite(hAppInst, IDB_LIUJIAO_Q3, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[9] = new Sprite(hAppInst, IDB_LIUJIAO_Q1, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[10] = new Sprite(hAppInst, IDB_LIUJIAO_Q2, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[11] = new Sprite(hAppInst, IDB_LIUJIAO_Q3, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[12] = new Sprite(hAppInst, IDB_LIUJIAO_Q1, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[13] = new Sprite(hAppInst, IDB_LIUJIAO_Q2, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[14] = new Sprite(hAppInst, IDB_LIUJIAO_Q3, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[15] = new Sprite(hAppInst, IDB_LIUJIAO_Q1, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[16] = new Sprite(hAppInst, IDB_LIUJIAO_Q2, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	LiuJiaoQAtk[17] = new Sprite(hAppInst, IDB_LIUJIAO_Q3, IDB_LIUJIAO_Q1MASK, bc, p0, v0);

	bc.r = 20.0f;
	LiuJiaoEAtk = new Sprite(hAppInst, IDB_LIUJIAO_E1, IDB_LIUJIAO_E1MASK, bc, p0, v0);

	LiuJiaoRisOn = false;
	LiuJiaoRStage = 0;
	bc.r = 15.0f;
	LiuJiaoRAtk[0] = new Sprite(hAppInst, IDB_LIUJIAO_R1, IDB_LIUJIAO_R1MASK, bc, p0, v0);
	LiuJiaoRAtk[1] = new Sprite(hAppInst, IDB_LIUJIAO_R2, IDB_LIUJIAO_R1MASK, bc, p0, v0);
	bc.r = 132.5f;
	LiuJiaoRAtk[2] = new Sprite(hAppInst, IDB_LIUJIAO_R3, IDB_LIUJIAO_R3MASK, bc, p0, v0);

	// Counters
	wQuattroCounterQ = 2;
	p0.x = 362.0f;
	p0.y = 623.0f;
	bc.r = 6.5f;
	QuattroQCounter[0] = new Sprite(hAppInst, IDB_COUNTER_1, IDB_COUNTER_1MASK, bc, p0, v0);
	p0.x = 389.0f;
	QuattroQCounter[1] = new Sprite(hAppInst, IDB_COUNTER_1, IDB_COUNTER_1MASK, bc, p0, v0);

	p0.x = 458.5f;
	SeraphinaWCounter = new Sprite(hAppInst, IDB_COUNTER_2, IDB_COUNTER_2MASK, bc, p0, v0);

	wDimitriCounterW = 2;
	p0.x = 444.0f;
	DimitriWRCounter[0] = new Sprite(hAppInst, IDB_COUNTER_3, IDB_COUNTER_3MASK, bc, p0, v0);
	p0.x = 472.0f;
	DimitriWRCounter[1] = new Sprite(hAppInst, IDB_COUNTER_3, IDB_COUNTER_3MASK, bc, p0, v0);
	p0.x = 604.5f;
	DimitriWRCounter[2] = new Sprite(hAppInst, IDB_COUNTER_3, IDB_COUNTER_3MASK, bc, p0, v0);
	p0.x = 624.5f;
	DimitriWRCounter[3] = new Sprite(hAppInst, IDB_COUNTER_3, IDB_COUNTER_3MASK, bc, p0, v0);
	p0.x = 644.5f;
	DimitriWRCounter[4] = new Sprite(hAppInst, IDB_COUNTER_3, IDB_COUNTER_3MASK, bc, p0, v0);

	// Cooldowns
	wP1CDtimeElapsedQ = wP1CDtimeElapsedW = wP1CDtimeElapsedE = wP1CDtimeElapsedR = 0.0f;
	wP2CDtimeElapsedQ = wP2CDtimeElapsedW = wP2CDtimeElapsedE = wP2CDtimeElapsedR = 0.0f;

	wP1QisonCD = wP1WisonCD = wP1EisonCD = wP1RisonCD = false;
	wP2QisonCD = wP2WisonCD = wP2EisonCD = wP2RisonCD = false;
	
	wP1Qcooldown = wP1Wcooldown = wP1Ecooldown = wP1Rcooldown = 0;
	wP2Qcooldown = wP2Wcooldown = wP2Ecooldown = wP2Rcooldown = 0;

	p0.x = 375.5f;
	p0.y = 654.5f;
	bc.r = 35.0f;
	QCooldown[0] = new Sprite(hAppInst, IDB_COOLDOWN_01, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[1] = new Sprite(hAppInst, IDB_COOLDOWN_02, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[2] = new Sprite(hAppInst, IDB_COOLDOWN_03, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[3] = new Sprite(hAppInst, IDB_COOLDOWN_04, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[4] = new Sprite(hAppInst, IDB_COOLDOWN_05, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[5] = new Sprite(hAppInst, IDB_COOLDOWN_06, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[6] = new Sprite(hAppInst, IDB_COOLDOWN_07, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[7] = new Sprite(hAppInst, IDB_COOLDOWN_08, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[8] = new Sprite(hAppInst, IDB_COOLDOWN_09, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[9] = new Sprite(hAppInst, IDB_COOLDOWN_10, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[10] = new Sprite(hAppInst, IDB_COOLDOWN_11, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[11] = new Sprite(hAppInst, IDB_COOLDOWN_12, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[12] = new Sprite(hAppInst, IDB_COOLDOWN_13, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[13] = new Sprite(hAppInst, IDB_COOLDOWN_14, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[14] = new Sprite(hAppInst, IDB_COOLDOWN_15, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[15] = new Sprite(hAppInst, IDB_COOLDOWN_16, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[16] = new Sprite(hAppInst, IDB_COOLDOWN_17, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[17] = new Sprite(hAppInst, IDB_COOLDOWN_18, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[18] = new Sprite(hAppInst, IDB_COOLDOWN_19, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[19] = new Sprite(hAppInst, IDB_COOLDOWN_20, IDB_COOLDOWN_MASK, bc, p0, v0);
	QCooldown[20] = new Sprite(hAppInst, IDB_COOLDOWN_20, IDB_COOLDOWN_MASK, bc, p0, v0);

	p0.x = 458.5f;
	WCooldown[0] = new Sprite(hAppInst, IDB_COOLDOWN_01, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[1] = new Sprite(hAppInst, IDB_COOLDOWN_02, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[2] = new Sprite(hAppInst, IDB_COOLDOWN_03, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[3] = new Sprite(hAppInst, IDB_COOLDOWN_04, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[4] = new Sprite(hAppInst, IDB_COOLDOWN_05, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[5] = new Sprite(hAppInst, IDB_COOLDOWN_06, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[6] = new Sprite(hAppInst, IDB_COOLDOWN_07, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[7] = new Sprite(hAppInst, IDB_COOLDOWN_08, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[8] = new Sprite(hAppInst, IDB_COOLDOWN_09, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[9] = new Sprite(hAppInst, IDB_COOLDOWN_10, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[10] = new Sprite(hAppInst, IDB_COOLDOWN_11, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[11] = new Sprite(hAppInst, IDB_COOLDOWN_12, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[12] = new Sprite(hAppInst, IDB_COOLDOWN_13, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[13] = new Sprite(hAppInst, IDB_COOLDOWN_14, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[14] = new Sprite(hAppInst, IDB_COOLDOWN_15, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[15] = new Sprite(hAppInst, IDB_COOLDOWN_16, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[16] = new Sprite(hAppInst, IDB_COOLDOWN_17, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[17] = new Sprite(hAppInst, IDB_COOLDOWN_18, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[18] = new Sprite(hAppInst, IDB_COOLDOWN_19, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[19] = new Sprite(hAppInst, IDB_COOLDOWN_20, IDB_COOLDOWN_MASK, bc, p0, v0);
	WCooldown[20] = new Sprite(hAppInst, IDB_COOLDOWN_20, IDB_COOLDOWN_MASK, bc, p0, v0);

	p0.x = 541.5f;
	ECooldown[0] = new Sprite(hAppInst, IDB_COOLDOWN_01, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[1] = new Sprite(hAppInst, IDB_COOLDOWN_02, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[2] = new Sprite(hAppInst, IDB_COOLDOWN_03, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[3] = new Sprite(hAppInst, IDB_COOLDOWN_04, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[4] = new Sprite(hAppInst, IDB_COOLDOWN_05, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[5] = new Sprite(hAppInst, IDB_COOLDOWN_06, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[6] = new Sprite(hAppInst, IDB_COOLDOWN_07, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[7] = new Sprite(hAppInst, IDB_COOLDOWN_08, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[8] = new Sprite(hAppInst, IDB_COOLDOWN_09, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[9] = new Sprite(hAppInst, IDB_COOLDOWN_10, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[10] = new Sprite(hAppInst, IDB_COOLDOWN_11, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[11] = new Sprite(hAppInst, IDB_COOLDOWN_12, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[12] = new Sprite(hAppInst, IDB_COOLDOWN_13, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[13] = new Sprite(hAppInst, IDB_COOLDOWN_14, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[14] = new Sprite(hAppInst, IDB_COOLDOWN_15, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[15] = new Sprite(hAppInst, IDB_COOLDOWN_16, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[16] = new Sprite(hAppInst, IDB_COOLDOWN_17, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[17] = new Sprite(hAppInst, IDB_COOLDOWN_18, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[18] = new Sprite(hAppInst, IDB_COOLDOWN_19, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[19] = new Sprite(hAppInst, IDB_COOLDOWN_20, IDB_COOLDOWN_MASK, bc, p0, v0);
	ECooldown[20] = new Sprite(hAppInst, IDB_COOLDOWN_20, IDB_COOLDOWN_MASK, bc, p0, v0);

	p0.x = 624.5f;
	RCooldown[0] = new Sprite(hAppInst, IDB_COOLDOWN_01, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[1] = new Sprite(hAppInst, IDB_COOLDOWN_02, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[2] = new Sprite(hAppInst, IDB_COOLDOWN_03, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[3] = new Sprite(hAppInst, IDB_COOLDOWN_04, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[4] = new Sprite(hAppInst, IDB_COOLDOWN_05, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[5] = new Sprite(hAppInst, IDB_COOLDOWN_06, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[6] = new Sprite(hAppInst, IDB_COOLDOWN_07, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[7] = new Sprite(hAppInst, IDB_COOLDOWN_08, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[8] = new Sprite(hAppInst, IDB_COOLDOWN_09, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[9] = new Sprite(hAppInst, IDB_COOLDOWN_10, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[10] = new Sprite(hAppInst, IDB_COOLDOWN_11, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[11] = new Sprite(hAppInst, IDB_COOLDOWN_12, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[12] = new Sprite(hAppInst, IDB_COOLDOWN_13, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[13] = new Sprite(hAppInst, IDB_COOLDOWN_14, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[14] = new Sprite(hAppInst, IDB_COOLDOWN_15, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[15] = new Sprite(hAppInst, IDB_COOLDOWN_16, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[16] = new Sprite(hAppInst, IDB_COOLDOWN_17, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[17] = new Sprite(hAppInst, IDB_COOLDOWN_18, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[18] = new Sprite(hAppInst, IDB_COOLDOWN_19, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[19] = new Sprite(hAppInst, IDB_COOLDOWN_20, IDB_COOLDOWN_MASK, bc, p0, v0);
	RCooldown[20] = new Sprite(hAppInst, IDB_COOLDOWN_20, IDB_COOLDOWN_MASK, bc, p0, v0);

	// Life Bars
	wP1BrushColor.lbStyle = BS_SOLID;
	wP1BrushColor.lbColor = RGB(255, 250, 0);
	wP1Brush = CreateBrushIndirect(&wP1BrushColor);

	wP1PenColor.lopnStyle = PS_SOLID;
	wP1PenColor.lopnColor = RGB(255, 250, 0);
	wP1PenColor.lopnWidth.x = 1;
	wP1Pen = CreatePenIndirect(&wP1PenColor);

	wP2BrushColor.lbStyle = BS_SOLID;
	wP2BrushColor.lbColor = RGB(255, 250, 0);
	wP2Brush = CreateBrushIndirect(&wP2BrushColor);

	wP2PenColor.lopnStyle = PS_SOLID;
	wP2PenColor.lopnColor = RGB(255, 250, 0);
	wP2PenColor.lopnWidth.x = 1;
	wP2Pen = CreatePenIndirect(&wP2PenColor);

	wOldBrush = 0;
	wOldPen = 0;
}

Warrior::~Warrior()
{
	// Warriors
	for (int a = 0; a < 16; ++a)
	{
		delete wP1Quattro[a];
		delete wP1Seraphina[a];
		delete wP1Dimitri[a];
		delete wP1LiuJiao[a];

		delete wP2Quattro[a];
		delete wP2Seraphina[a];
		delete wP2Dimitri[a];
		delete wP2LiuJiao[a];
	}

	// Quattro's Attacks
	for (int b = 0; b < 9; ++b)
		delete QuattroQAtk[b];
	for (int c = 0; c < 4; ++c)
	{
		delete QuattroWAtk[c];
		delete QuattroRAtk[c];
	}
	delete QuattroEAtk;

	// Seraphina's Attacks
	for (int d = 0; d < 5; ++d)
		delete SeraphinaQAtk[d];
	for (int e = 0; e < 8; ++e)
	{
		delete SeraphinaWAtk[e];
		delete SeraphinaRAtk[e];
	}
	delete SeraphinaEAtk;

	// Dimitri's Attacks
	for (int f = 0; f < 9; ++f)
		delete DimitriQAtk[f];
	for (int g = 0; g < 11; ++g)
		delete DimitriWAtk[g];
	for (int h = 0; h < 2; ++h)
		delete DimitriEAtk[h];

	DeleteObject(DimitriPen);

	// Liu Jiao's Attacks
	for (int i = 0; i < 18; ++i)
		delete LiuJiaoQAtk[i];
	delete LiuJiaoEAtk;
	for (int j = 0; j < 3; ++j)
		delete LiuJiaoRAtk[j];

	// Counters
	for (int k = 0; k < 2; ++k)
		delete QuattroQCounter[k];

	delete SeraphinaWCounter;

	for (int l = 0; l < 5; ++l)
		delete DimitriWRCounter[l];

	// Cooldowns
	for (int m = 0; m < 21; ++m)
	{
		delete QCooldown[m];
		delete WCooldown[m];
		delete ECooldown[m];
		delete RCooldown[m];
	}

	//Life Bars
	DeleteObject(wP1Brush);
	DeleteObject(wP1Pen);

	DeleteObject(wP2Brush);
	DeleteObject(wP2Pen);
}

// ***** Public Member Functions *****

void Warrior::updateWarriors(float dt)
{
	// Update Player 1
	if (wPlayer1 == L"Quattro")
	{
		updatePlayer1(dt, wP1Quattro, wP1MoveSpeed);
		updateQuattroAtks(dt, wPlayer1, wP1UseQ, wP1UseW, wP1UseE, wP1UseR,
			wP1AtkFrameSet, wP1Position, wP1TargetPos, wP1AttackVel, wP1LifePoints,
			wP2Position, wP2BoundingCircle, wP2DmgTaken, wP2MoveSpeed);
	}
	if (wPlayer1 == L"Seraphina")
	{
		updatePlayer1(dt, wP1Seraphina, wP1MoveSpeed);
		updateSeraphinaAtks(dt, wPlayer1, wP1UseQ, wP1UseW, wP1UseE, wP1UseR,
			wP1AtkFrameSet, wP1Position, wP1TargetPos, wP1AttackVel, wP1LifePoints,
			wP2Position, wP2BoundingCircle, wP2DmgTaken, wP2MoveSpeed);
	}
	if (wPlayer1 == L"Dimitri")
	{
		updatePlayer1(dt, wP1Dimitri, wP1MoveSpeed);
		updateDimitriAtks(dt, wPlayer1, wP1UseQ, wP1UseW, wP1UseE, wP1UseR,
			wP1AtkFrameSet, wP1Position, wP1TargetPos, wP1AttackVel, wP1LifePoints,
			wP2Position, wP2BoundingCircle, wP2DmgTaken, wP2MoveSpeed);
	}
	if (wPlayer1 == L"Liu Jiao")
	{
		updatePlayer1(dt, wP1LiuJiao, wP1MoveSpeed);
		updateLiuJiaoAtks(dt, wPlayer1, wP1UseQ, wP1UseW, wP1UseE, wP1UseR,
			wP1AtkFrameSet, wP1Position, wP1TargetPos, wP1AttackVel, wP1LifePoints,
			wP2Position, wP2BoundingCircle, wP2DmgTaken, wP2MoveSpeed);
	}

	// Update Player 2
	if (!wP2TurnOff)
	{
		if (wPlayer2 == L"Quattro")
		{
			updatePlayer2(dt, wP2Quattro, wP2MoveSpeed);
			updateQuattroAtks(dt, wPlayer2, wP2UseQ, wP2UseW, wP2UseE, wP2UseR,
				wP2AtkFrameSet, wP2Position, wP2TargetPos, wP2AttackVel, wP2LifePoints,
				wP1Position, wP1BoundingCircle, wP1DmgTaken, wP1MoveSpeed);
		}
		if (wPlayer2 == L"Seraphina")
		{
			updatePlayer2(dt, wP2Seraphina, wP2MoveSpeed);
			updateSeraphinaAtks(dt, wPlayer2, wP2UseQ, wP2UseW, wP2UseE, wP2UseR,
				wP2AtkFrameSet, wP2Position, wP2TargetPos, wP2AttackVel, wP2LifePoints,
				wP1Position, wP1BoundingCircle, wP1DmgTaken, wP1MoveSpeed);
		}
		if (wPlayer2 == L"Dimitri")
		{
			updatePlayer2(dt, wP2Dimitri, wP2MoveSpeed);
			updateDimitriAtks(dt, wPlayer2, wP2UseQ, wP2UseW, wP2UseE, wP2UseR,
				wP2AtkFrameSet, wP2Position, wP2TargetPos, wP2AttackVel, wP2LifePoints,
				wP1Position, wP1BoundingCircle, wP1DmgTaken, wP1MoveSpeed);
		}
		if (wPlayer2 == L"Liu Jiao")
		{
			updatePlayer2(dt, wP2LiuJiao, wP2MoveSpeed);
			updateLiuJiaoAtks(dt, wPlayer2, wP2UseQ, wP2UseW, wP2UseE, wP2UseR,
				wP2AtkFrameSet, wP2Position, wP2TargetPos, wP2AttackVel, wP2LifePoints,
				wP1Position, wP1BoundingCircle, wP1DmgTaken, wP1MoveSpeed);
		}
	}

	updateCooldowns(dt, wPlayer1, wP1CDtimeElapsedQ, wP1CDtimeElapsedW, wP1CDtimeElapsedE, wP1CDtimeElapsedR,
		wP1QisonCD, wP1WisonCD, wP1EisonCD, wP1RisonCD, wP1Qcooldown, wP1Wcooldown, wP1Ecooldown, wP1Rcooldown);
	updateCooldowns(dt, wPlayer2, wP2CDtimeElapsedQ, wP2CDtimeElapsedW, wP2CDtimeElapsedE, wP2CDtimeElapsedR,
		wP2QisonCD, wP2WisonCD, wP2EisonCD, wP2RisonCD, wP2Qcooldown, wP2Wcooldown, wP2Ecooldown, wP2Rcooldown);

	updateLifeBars(dt, wP1LBtimeElapsed, wP1DmgTaken, wP1LifePoints, wPlayer1, wP1Brush, wP1BrushColor, wP1Pen, wP1PenColor);
	updateLifeBars(dt, wP2LBtimeElapsed, wP2DmgTaken, wP2LifePoints, wPlayer2, wP2Brush, wP2BrushColor, wP2Pen, wP2PenColor);

	updateMoveSpeed(dt, wP1MoveSpeed, wP1SlowTime);
	updateMoveSpeed(dt, wP2MoveSpeed, wP2SlowTime);
}

void Warrior::getPlayerNames(wstring player1, wstring player2)
{
	wPlayer1 = player1;
	wPlayer2 = player2;
}

void Warrior::turnP2off(bool offSwitch)
{
	wP2TurnOff = offSwitch;
}

void Warrior::getP2Level(int level)
{
	wP2Level = level;
}

void Warrior::getNewMousePos(Vec2 newMousePos)
{
	wNewMousePos.x = newMousePos.x;
	wNewMousePos.y = newMousePos.y;
}

void Warrior::getNewTargetPos(wchar_t key, Vec2 newTargetPos)
{
	playerUseAttack(key, newTargetPos, wPlayer1, wP1TargetPos, wP1AtkFrameSet, wP1UseQ, wP1UseW, wP1UseE, wP1UseR,
		            wP1QisonCD, wP1WisonCD, wP1EisonCD, wP1RisonCD, wP1Qcooldown, wP1Wcooldown, wP1Ecooldown, wP1Rcooldown);
}

void Warrior::drawWarriors(HDC hBackBufferDC, HDC hSpriteDC)
{
	drawSprites(hBackBufferDC, hSpriteDC, wPlayer2, wP2Frame, wP2AtkFrameSet, wP2UseQ, wP2UseW, wP2UseE, wP2UseR);
	drawSprites(hBackBufferDC, hSpriteDC, wPlayer1, wP1Frame, wP1AtkFrameSet, wP1UseQ, wP1UseW, wP1UseE, wP1UseR);
}

void Warrior::drawBarTools(HDC hBackBufferDC, HDC hSpriteDC)
{
	drawLifeBars(hBackBufferDC);

	if (wPlayer1 == L"Quattro")
		for (int a = 0; a < wQuattroCounterQ; ++a)
			QuattroQCounter[a]->draw(hBackBufferDC, hSpriteDC);

	if (wPlayer1 == L"Seraphina")
		if (!wP1WisonCD && SeraphinaWAtkList.size() < 8)
			SeraphinaWCounter->draw(hBackBufferDC, hSpriteDC);

	if (wPlayer1 == L"Dimitri")
	{
		if (!wP1WisonCD)
			for (int b = 0; b < wDimitriCounterW; ++b)
				DimitriWRCounter[b]->draw(hBackBufferDC, hSpriteDC);
		if (!wP1RisonCD)
			for (int c = 2; c < 5 - DimitriRTriangles; ++c)
				DimitriWRCounter[c]->draw(hBackBufferDC, hSpriteDC);
	}

	if (wP1QisonCD)
		QCooldown[wP1Qcooldown]->draw(hBackBufferDC, hSpriteDC);
	if (wP1WisonCD)
		WCooldown[wP1Wcooldown]->draw(hBackBufferDC, hSpriteDC);
	if (wP1EisonCD)
		ECooldown[wP1Ecooldown]->draw(hBackBufferDC, hSpriteDC);
	if (wP1RisonCD)
		RCooldown[wP1Rcooldown]->draw(hBackBufferDC, hSpriteDC);
}

int Warrior::endGame()
{
	if (wP2LifePoints <= 0)
		return 1;
	else if (wP1LifePoints <= 0)
		return 2;
	else
		return 0;
}

// ***** Private Member Functions *****

void Warrior::drawSprites(HDC hBackBufferDC, HDC hSpriteDC, wstring playerName, int warriorFrame, int atkFrameSet[4],
	                      bool playerUseQ, bool playerUseW, bool playerUseE, bool playerUseR)
{
	// Draw Warriors
	if (playerName == L"Quattro")
	{
		if (wPlayer2 == L"Quattro")
			wP2Quattro[warriorFrame]->draw(hBackBufferDC, hSpriteDC);
		if (wPlayer1 == L"Quattro")
			wP1Quattro[warriorFrame]->draw(hBackBufferDC, hSpriteDC);
	}
	if (playerName == L"Seraphina")
	{
		if (wPlayer2 == L"Seraphina")
			wP2Seraphina[warriorFrame]->draw(hBackBufferDC, hSpriteDC);
		if (wPlayer1 == L"Seraphina")
			wP1Seraphina[warriorFrame]->draw(hBackBufferDC, hSpriteDC);
	}
	if (playerName == L"Dimitri")
	{
		if (wPlayer2 == L"Dimitri")
			wP2Dimitri[warriorFrame]->draw(hBackBufferDC, hSpriteDC);
		if (wPlayer1 == L"Dimitri")
			wP1Dimitri[warriorFrame]->draw(hBackBufferDC, hSpriteDC);
	}
	if (playerName == L"Liu Jiao")
	{
		if (wPlayer2 == L"Liu Jiao")
			wP2LiuJiao[warriorFrame]->draw(hBackBufferDC, hSpriteDC);
		if (wPlayer1 == L"Liu Jiao")
			wP1LiuJiao[warriorFrame]->draw(hBackBufferDC, hSpriteDC);
	}

	// Draw Attacks
	if (playerName == L"Quattro")
	{
		if (playerUseQ)
			QuattroQAtk[atkFrameSet[0]]->draw(hBackBufferDC, hSpriteDC);
		if (playerUseW)
			QuattroWAtk[atkFrameSet[1]]->draw(hBackBufferDC, hSpriteDC);
		if (playerUseE)
			QuattroEAtk->draw(hBackBufferDC, hSpriteDC);
		if (playerUseR)
			QuattroRAtk[atkFrameSet[3]]->draw(hBackBufferDC, hSpriteDC);
	}
	if (playerName == L"Seraphina")
	{
		if (playerUseQ)
			for (int a = 0; a < 5; ++a)
				if (SeraphinaQAtk[a]->mVelocity.x != 0.0f && SeraphinaQAtk[a]->mVelocity.y != 0.0f)
					SeraphinaQAtk[a]->draw(hBackBufferDC, hSpriteDC);
		for (int b = 0; b < 4; ++b)
			if (SeraphinaWisOn[b])
				SeraphinaWAtk[atkFrameSet[1] + b * 2]->draw(hBackBufferDC, hSpriteDC);
		if (playerUseE)
			SeraphinaEAtk->draw(hBackBufferDC, hSpriteDC);
		if (playerUseR)
			for (int c = 0; c < 8; ++c)
				if (SeraphinaRisOn[c])
					SeraphinaRAtk[c]->draw(hBackBufferDC, hSpriteDC);
	}
	if (playerName == L"Dimitri")
	{
		if (playerUseQ)
			for (int d = 0; d < 3; ++d)
				if (DimitriQisOn[d])
					DimitriQAtk[atkFrameSet[0] + d * 3]->draw(hBackBufferDC, hSpriteDC);
		if (playerUseW)
			DimitriWAtk[10]->draw(hBackBufferDC, hSpriteDC);
		if (DimitriWAtkList.size() > 0)
		{
			list<Sprite*>::iterator DimitriWDrawIt;
			for (DimitriWDrawIt = DimitriWAtkList.begin(); DimitriWDrawIt != DimitriWAtkList.end(); ++DimitriWDrawIt)
			{
				DimitriWDraw = *DimitriWDrawIt;
				DimitriWDraw->draw(hBackBufferDC, hSpriteDC);
			}
		}
		if (playerUseE)
			DimitriEAtk[atkFrameSet[2]]->draw(hBackBufferDC, hSpriteDC);
		if (DimitriRAtkList.size() > 0)
		{
			list<Sprite*>::iterator DimitriRDrawIt;
			for (DimitriRDrawIt = DimitriRAtkList.begin(); DimitriRDrawIt != DimitriRAtkList.end(); ++DimitriRDrawIt)
			{
				DimitriRDraw = *DimitriRDrawIt;
				DimitriRDraw->draw(hBackBufferDC, hSpriteDC);
			}
		}
		if (DimitriRisOn)
		{
			DimitriOldPen = (HPEN)SelectObject(hBackBufferDC, DimitriPen);

			MoveToEx(hBackBufferDC, (int)DimitriRPoints[0].x, (int)DimitriRPoints[0].y, 0);
			LineTo(hBackBufferDC, (int)DimitriRPoints[1].x, (int)DimitriRPoints[1].y);

			MoveToEx(hBackBufferDC, (int)DimitriRPoints[1].x, (int)DimitriRPoints[1].y, 0);
			LineTo(hBackBufferDC, (int)DimitriRPoints[2].x, (int)DimitriRPoints[2].y);

			MoveToEx(hBackBufferDC, (int)DimitriRPoints[2].x, (int)DimitriRPoints[2].y, 0);
			LineTo(hBackBufferDC, (int)DimitriRPoints[0].x, (int)DimitriRPoints[0].y);

			SelectObject(hBackBufferDC, DimitriOldPen);
		}
	}
	if (playerName == L"Liu Jiao")
	{
		if (playerUseQ)
			for (int e = 0; e < 6; ++e)
				if (LiuJiaoQisOn[e])
					LiuJiaoQAtk[atkFrameSet[0] + e * 3]->draw(hBackBufferDC, hSpriteDC);
		if (playerUseE)
			LiuJiaoEAtk->draw(hBackBufferDC, hSpriteDC);
		if (LiuJiaoRStage != 0)
			LiuJiaoRAtk[atkFrameSet[3]]->draw(hBackBufferDC, hSpriteDC);
	}
}

// Player 1
void Warrior::updatePlayer1(float dt, Sprite* P1warrior[16], float moveSpeed)
{
	wP1Velocity = (wNewMousePos - wP1Position) * 100.0f;
	if (wP1Velocity.length() > 100.0f)
		wP1Velocity.normalize() *= moveSpeed;

	Vec2 normal;

	for (int a = 0; a < 16; ++a)
	{
		P1warrior[a]->mVelocity = wP1Velocity;
		P1warrior[a]->update(dt);

		wBattleBounds.forceInside(P1warrior[a]->mBoundingCircle);
		if (wPlayer2 == L"Liu Jiao" && LiuJiaoRisOn)
			LiuJiaoRBounds.forceInside(P1warrior[a]->mBoundingCircle);
		P1warrior[a]->mPosition = P1warrior[a]->mBoundingCircle.c;
	}

	wP1BoundingCircle.c = P1warrior[wP1Frame]->mPosition;

	if (wP2BoundingCircle.hits(wP1BoundingCircle, normal))
		for (int b = 0; b < 16; ++b)
			P1warrior[b]->mPosition = wP1BoundingCircle.c;

	wP1Position = P1warrior[wP1Frame]->mPosition;

	static float P1TimeElapsed = 0.0f;
	updateAnimationFrame(dt, P1TimeElapsed, wP1Position, wNewMousePos, wP1Frame);
}

// Player 2
void Warrior::updatePlayer2(float dt, Sprite* P2warrior[16], float moveSpeed)
{
	static Vec2 P2NewPosition;
	static Vec2 P2DistanceToP1;
	Vec2 NullPlaceholder(0.0f, 0.0f);
	srand((unsigned)time(NULL));

	if (wP2TimeElapsed[0] < 0.5f && !wP2Start)
		wP2TimeElapsed[0] += dt;
	if (wP2TimeElapsed[0] >= 0.5f)
	{
		wP2Start = true;
		wP2TimeElapsed[0] = 0.0f;
	}

	if (wP2Start)
	{
		wP2TimeElapsed[1] += dt;

		if (wP2TimeElapsed[1] >= (rand() % 3) + 1)
		{
			P2NewPosition.x = float((rand() % 1000) + 1);
			P2NewPosition.y = float((rand() % 700) + 1);
			wP2TimeElapsed[1] = 0.0f;
		}

		wP2Velocity = (P2NewPosition - wP2Position) * 100.0f;

		// P2 Dodge Attacks
		if (wPlayer1 == L"Quattro")
		{
			P2DodgeAttacks(wP1AttackVel[0], 0, QuattroQAtk[wP1AtkFrameSet[0]]->mPosition, 300.0f, P2NewPosition);
			P2DodgeAttacks(NullPlaceholder, QuattroWisOn, QuattroWAtk[wP1AtkFrameSet[1]]->mPosition, 100.0f, P2NewPosition);
			P2DodgeAttacks(wP1AttackVel[2], 0, QuattroEAtk->mPosition, 400.0f, P2NewPosition);
			P2DodgeAttacks(NullPlaceholder, QuattroRisOn, QuattroRAtk[wP1AtkFrameSet[3]]->mPosition, 300.0f, P2NewPosition);
		}
		if (wPlayer1 == L"Seraphina")
		{
			for (int a = 0; a < 5; ++a)
				P2DodgeAttacks(wP1AttackVel[0], 0, SeraphinaQAtk[a]->mPosition, 300.0f, P2NewPosition);
			for (int c = 0; c < 8; ++c)
				P2DodgeAttacks(NullPlaceholder, SeraphinaRisOn[c], SeraphinaRAtk[c]->mPosition, 300.0f, P2NewPosition);
		}
		if (wPlayer1 == L"Dimitri")
		{
			for (int a = 0; a < 3; ++a)
				P2DodgeAttacks(NullPlaceholder, DimitriQisOn[a], DimitriQAtk[a]->mPosition, 300.0f, P2NewPosition);
			P2DodgeAttacks(wP1AttackVel[2], 0, DimitriEAtk[wP1AtkFrameSet[2]]->mPosition, 300.0f, P2NewPosition);
		}
		if (wPlayer1 == L"Liu Jiao")
		{
			for (int a = 0; a < 6; ++a)
				P2DodgeAttacks(NullPlaceholder, LiuJiaoQisOn[a], LiuJiaoQAtk[wP1AtkFrameSet[0] + a * 3]->mPosition, 200.0f, P2NewPosition);
			P2DodgeAttacks(wP1AttackVel[2], 0, LiuJiaoEAtk->mPosition, 200.0f, P2NewPosition);
			P2DodgeAttacks(wP1AttackVel[3], 0, LiuJiaoRAtk[0]->mPosition, 400.0f, P2NewPosition);
		}

		// P2 Use Attacks
		P2DistanceToP1 = wP1Position - wP2Position;

		if (wPlayer2 == L"Quattro")
		{
			if (P2DistanceToP1.length() <= 600.0f)
				P2UseAttack('Q');
			if (wP1UseQ)
			{
				wP2TimeElapsed[2] += dt;
				if (wP2TimeElapsed[2] >= 0.5f)
				{
					P2UseAttack('W');
					wP2TimeElapsed[2] = 0.0f;
				}
			}
			if (P2DistanceToP1.length() <= 550.0f)
				P2UseAttack('E');
			if (P2DistanceToP1.length() <= 300.0f)
				P2UseAttack('R');
			if (QuattroRisOn)
				wP2Velocity = (wP1Position - wP2Position) * 100.0f;
		}
		if (wPlayer2 == L"Seraphina")
		{
			if (P2DistanceToP1.length() <= 600.0f)
				P2UseAttack('Q');
			if (P2DistanceToP1.length() <= 350.0f)
				P2UseAttack('W');
			if (wP1UseQ)
			{
				wP2TimeElapsed[2] += dt;
				if (wP2TimeElapsed[2] >= 0.5f)
				{
					P2UseAttack('E');
					wP2TimeElapsed[2] = 0.0f;
				}
			}
			if (P2DistanceToP1.length() <= 600.0f)
				P2UseAttack('R');
		}
		if (wPlayer2 == L"Dimitri")
		{
			if (P2DistanceToP1.length() <= 650.0f)
				P2UseAttack('Q');
			if (P2DistanceToP1.length() <= 400.0f)
				P2UseAttack('W');
			if (P2DistanceToP1.length() <= 600.0f)
				P2UseAttack('E');
			if (P2DistanceToP1.length() <= 900.0f && DimitriRTriangles < 2)
				P2UseAttack('R');
			if (P2DistanceToP1.length() <= 600.0f && DimitriRTriangles == 2)
				P2UseAttack('R');
		}
		if (wPlayer2 == L"Liu Jiao")
		{
			if (P2DistanceToP1.length() <= 800.0f)
				P2UseAttack('Q');
			if (P2DistanceToP1.length() <= 400.0f && (wP2Position.x <= 300.0f || wP2Position.x >= 700.0f) && (wP1UseQ || wP1UseR))
			{
				wP2TimeElapsed[2] += dt;
				if (wP2TimeElapsed[2] >= 0.5f)
				{
					P2UseAttack('W');
					wP2TimeElapsed[2] = 0.0f;
				}
			}
			if (P2DistanceToP1.length() <= 350.0f)
				P2UseAttack('E');
			if (P2DistanceToP1.length() <= 950.0f && LiuJiaoRStage == 0)
				P2UseAttack('R');
			if (LiuJiaoRBounds.isPtInside(wP1Position) && LiuJiaoRStage == 1)
				P2UseAttack('R');
		}

		// P2 Sprite Animation
		if (wP2Velocity.length() > 100.0f)
			wP2Velocity.normalize() *= moveSpeed;

		Vec2 normal;

		for (int a = 0; a < 16; ++a)
		{
			P2warrior[a]->mVelocity = wP2Velocity;
			P2warrior[a]->update(dt);

			wBattleBounds.forceInside(P2warrior[a]->mBoundingCircle);
			if (wPlayer1 == L"Liu Jiao" && LiuJiaoRisOn)
				LiuJiaoRBounds.forceInside(P2warrior[a]->mBoundingCircle);
			P2warrior[a]->mPosition = P2warrior[a]->mBoundingCircle.c;
		}

		wP2BoundingCircle.c = P2warrior[wP2Frame]->mPosition;

		if (wP1BoundingCircle.hits(wP2BoundingCircle, normal))
			for (int b = 0; b < 16; ++b)
				P2warrior[b]->mPosition = wP2BoundingCircle.c;

		wP2Position = P2warrior[wP2Frame]->mPosition;

		updateAnimationFrame(dt, wP2TimeElapsed[3], wP2Position, P2NewPosition, wP2Frame);
	}
}

void Warrior::P2DodgeAttacks(Vec2 detectedVel, bool detectedAtk, Vec2 P1AttackPos, float detectDistance, Vec2& P2NewPosition)
{
	Vec2 P2Distance;

	if ((detectedVel.x != 0.0f && detectedVel.y != 0.0f) || detectedAtk == true)
	{
		P2Distance = P1AttackPos - wP2Position;

		if (P2Distance.length() <= detectDistance)
		{
			wP2Velocity = P2Distance * 100.0f;

			int Dodge = rand() % 4;

			if (Dodge == 0)
				wP2Velocity.rotate(80);
			if (Dodge == 1)
				wP2Velocity.rotate(90);
			if (Dodge == 2)
				wP2Velocity.rotate(-80);
			if (Dodge == 3)
				wP2Velocity.rotate(-90);

			P2NewPosition.x = wP2Velocity.x;
			P2NewPosition.y = wP2Velocity.y;
		}
	}
}

void Warrior::P2UseAttack(wchar_t key)
{
	playerUseAttack(key, wP1Position, wPlayer2, wP2TargetPos, wP2AtkFrameSet, wP2UseQ, wP2UseW, wP2UseE, wP2UseR,
		wP2QisonCD, wP2WisonCD, wP2EisonCD, wP2RisonCD, wP2Qcooldown, wP2Wcooldown, wP2Ecooldown, wP2Rcooldown);
}

// Frame Animation
void Warrior::updateAnimationFrame(float dt, float& timeElapsed, Vec2 startPos, Vec2 endPos, int& frame)
{
	timeElapsed += dt;

	if (startPos.x == endPos.x && startPos.y == endPos.y)
		frame = 0;
	else
	{
		if (timeElapsed >= 0.2f)
		{
			++frame;
			if (frame > 15)
				frame = 0;
			timeElapsed = 0.0f;
		}
		if (endPos.y > startPos.y && fabsf(endPos.x - startPos.x) <= fabsf(endPos.y - startPos.y))
			if (frame > 3)
				frame = 0;
		if (endPos.x < startPos.x && fabsf(endPos.x - startPos.x) > fabsf(endPos.y - startPos.y))
			if (frame < 4 || frame > 7)
				frame = 4;
		if (endPos.x > startPos.x && fabsf(endPos.x - startPos.x) > fabsf(endPos.y - startPos.y))
			if (frame < 8 || frame > 11)
				frame = 8;
		if (endPos.y < startPos.y && fabsf(endPos.x - startPos.x) <= fabsf(endPos.y - startPos.y))
			if (frame < 12)
				frame = 12;
	}
}

void Warrior::playerUseAttack(wchar_t key, Vec2 newTargetPos, wstring playerName, Vec2 targetPos[4], int atkFrameSet[4],
	                          bool& playerUseQ, bool& playerUseW, bool& playerUseE, bool& playerUseR,
	                          bool& QisonCD, bool& WisonCD, bool& EisonCD, bool& RisonCD,
	                          int& QSeconds, int& WSeconds, int& ESeconds, int& RSeconds)
{
	if (key == 'Q')
		if (!playerUseQ && !QisonCD)
		{
			playerUseQ = true;
			targetPos[0] = newTargetPos;

			if (playerName == L"Quattro")
			{
				--wQuattroCounterQ;
				if (wQuattroCounterQ == 1)
					atkFrameSet[0] = 0;
				if (wQuattroCounterQ == 0)
				{
					atkFrameSet[0] = 6;
					QisonCD = startCooldown(QSeconds, 6);
				}
			}
			if (playerName == L"Seraphina")
				QisonCD = startCooldown(QSeconds, 6);
			if (playerName == L"Dimitri")
				QisonCD = startCooldown(QSeconds, 3);
			if (playerName == L"Liu Jiao")
				QisonCD = startCooldown(QSeconds, 8);
		}
	if (key == 'W')
		if (!playerUseW && !WisonCD)
		{
			playerUseW = true;
			targetPos[1] = newTargetPos;

			if (playerName == L"Quattro")
				WisonCD = startCooldown(WSeconds, 20);
			if (playerName == L"Seraphina")
			{
				if (SeraphinaWAtkList.size() == 8)
					playerUseW = false;
				else
					WisonCD = startCooldown(WSeconds, 9);
			}
			if (playerName == L"Dimitri")
			{
				if (DimitriWTriangles == 7)
					playerUseW = false;
				else
				{
					--wDimitriCounterW;
					if (wDimitriCounterW == 0)
						WisonCD = startCooldown(WSeconds, 7);
				}
			}
			if (playerName == L"Liu Jiao")
				WisonCD = startCooldown(WSeconds, 20);
		}
	if (key == 'E')
		if (!playerUseE && !EisonCD)
		{
			playerUseE = true;
			targetPos[2] = newTargetPos;

			if (playerName == L"Quattro")
				EisonCD = startCooldown(ESeconds, 10);
			if (playerName == L"Seraphina")
				EisonCD = startCooldown(ESeconds, 20);
			if (playerName == L"Dimitri")
				EisonCD = startCooldown(ESeconds, 7);
			if (playerName == L"Liu Jiao")
				EisonCD = startCooldown(ESeconds, 9);
		}
	if (key == 'R')
		if (!playerUseR && !RisonCD)
		{
			playerUseR = true;
			targetPos[3] = newTargetPos;

			if (playerName == L"Quattro")
				RisonCD = startCooldown(RSeconds, 13);
			if (playerName == L"Seraphina")
				RisonCD = startCooldown(RSeconds, 13);
			if (playerName == L"Dimitri")
			{
				if (DimitriRTriangles == 3)
					playerUseR = false;
				else
					RisonCD = startCooldown(RSeconds, 6);
			}
			if (playerName == L"Liu Jiao")
			{
				++LiuJiaoRStage;

				if (LiuJiaoRStage == 2)
					RisonCD = startCooldown(RSeconds, 16);
			}
		}
}

// Quattro's Attacks
void Warrior::updateQuattroAtks(float dt, wstring playerName, bool& playerUseQ, bool& playerUseW, bool& playerUseE, bool& playerUseR,
	                            int frameSet[4], Vec2 startPos, Vec2 targetPos[4], Vec2 attackVel[4], int& lifePoints,
	                            Vec2 opptPos, Circle& opptHitBox, int& opptDmgTaken, float& opptMoveSpeed)
{
	// Quattro's Q Attack: "Loaded Dice"
	if (playerName == L"Quattro" && playerUseQ)
	{
		if (attackVel[0].x == 0.0f && attackVel[0].y == 0.0f)
		{
			for (int a = 0; a < 9; ++a)
			{
				QuattroQAtk[a]->mPosition = startPos;
				QuattroQAtk[a]->mBoundingCircle.c = QuattroQAtk[a]->mPosition;
			}

			attackVel[0] = targetPos[0] - startPos;
			if (wQuattroCounterQ == 1)
				attackVel[0].normalize() *= 350.0f;
			else
				attackVel[0].normalize() *= 300.0f;
		}

		for (int b = 0; b < 9; ++b)
		{
			QuattroQAtk[b]->mVelocity = attackVel[0];
			QuattroQAtk[b]->update(dt);
		}

		QuattroTimeElapsed[0][0] += dt;

		if (QuattroTimeElapsed[0][0] >= 0.15f)
		{
			++frameSet[0];
			if (wQuattroCounterQ == 1 && frameSet[0] > 5)
				frameSet[0] = 0;
			if (wQuattroCounterQ == 0 && frameSet[0] > 8)
				frameSet[0] = 6;
			QuattroTimeElapsed[0][0] = 0.0f;
		}

		if (opptHitBox.hitBy(QuattroQAtk[frameSet[0]]->mBoundingCircle))
		{
			attackVel[0].x = 0.0f;
			attackVel[0].y = 0.0f;
			opptDmgTaken += 1 + (frameSet[0] * 3);
			QuattroTimeElapsed[0][0] = 0.0f;
			playerUseQ = false;
		}
		if (!wBattleBounds.isPtInside(QuattroQAtk[frameSet[0]]->mPosition))
		{
			attackVel[0].x = 0.0f;
			attackVel[0].y = 0.0f;
			QuattroTimeElapsed[0][0] = 0.0f;
			playerUseQ = false;
		}
	}

	// Quattro's W Attack: "Block Fort"
	if (playerName == L"Quattro" && playerUseW)
	{
		static Vec2 WCurrLength;

		if (!QuattroWisOn)
		{
			if (attackVel[1].x == 0.0f && attackVel[1].y == 0.0f)
			{
				for (int a = 0; a < 4; ++a)
					QuattroWAtk[a]->mPosition = startPos;

				if (targetPos[1].y > startPos.y && fabsf(targetPos[1].x - startPos.x) < fabsf(targetPos[1].y - startPos.y))
					frameSet[1] = 0;
				if (targetPos[1].x <= startPos.x && fabsf(targetPos[1].x - startPos.x) >= fabsf(targetPos[1].y - startPos.y))
					frameSet[1] = 1;
				if (targetPos[1].x >= startPos.x && fabsf(targetPos[1].x - startPos.x) >= fabsf(targetPos[1].y - startPos.y))
					frameSet[1] = 2;
				if (targetPos[1].y < startPos.y && fabsf(targetPos[1].x - startPos.x) < fabsf(targetPos[1].y - startPos.y))
					frameSet[1] = 3;

				attackVel[1] = targetPos[1] - startPos;
				attackVel[1].normalize() *= 400.0f;
			}
		
			QuattroWAtk[frameSet[1]]->mVelocity = attackVel[1];
			QuattroWAtk[frameSet[1]]->update(dt);

			if (frameSet[1] == 0)
				QuattroWBounds = Rect(QuattroWAtk[frameSet[1]]->mPosition.x - 100.5f, QuattroWAtk[frameSet[1]]->mPosition.y - 29.5f,
					                  QuattroWAtk[frameSet[1]]->mPosition.x + 100.5f, QuattroWAtk[frameSet[1]]->mPosition.y + 29.5f);
			if (frameSet[1] == 1)
				QuattroWBounds = Rect(QuattroWAtk[frameSet[1]]->mPosition.x - 29.5f, QuattroWAtk[frameSet[1]]->mPosition.y - 100.5f,
					                  QuattroWAtk[frameSet[1]]->mPosition.x + 29.5f, QuattroWAtk[frameSet[1]]->mPosition.y + 100.5f);
			if (frameSet[1] == 2)
				QuattroWBounds = Rect(QuattroWAtk[frameSet[1]]->mPosition.x - 29.5f, QuattroWAtk[frameSet[1]]->mPosition.y - 100.5f,
					                  QuattroWAtk[frameSet[1]]->mPosition.x + 29.5f, QuattroWAtk[frameSet[1]]->mPosition.y + 100.5f);
			if (frameSet[1] == 3)
				QuattroWBounds = Rect(QuattroWAtk[frameSet[1]]->mPosition.x - 100.5f, QuattroWAtk[frameSet[1]]->mPosition.y - 29.5f,
					                  QuattroWAtk[frameSet[1]]->mPosition.x + 100.5f, QuattroWAtk[frameSet[1]]->mPosition.y + 29.5f);

			WCurrLength = QuattroWAtk[frameSet[1]]->mPosition - startPos;
			if (WCurrLength.length() >= 100.0f)
				QuattroWisOn = true;
		}

		QuattroTimeElapsed[1][0] += dt;

		if (QuattroTimeElapsed[1][0] >= 3.0f)
		{
			attackVel[1].x = 0.0f;
			attackVel[1].y = 0.0f;
			QuattroTimeElapsed[1][0] = 0.0f;
			QuattroWisOn = false;
			playerUseW = false;
		}
	}

	// Quattro's E Attack: "Cubic Crusher"
	if (playerName == L"Quattro" && playerUseE)
	{
		if (attackVel[2].x == 0.0f && attackVel[2].y == 0.0f)
		{
			QuattroEAtk->mPosition = startPos;
			QuattroEAtk->mBoundingCircle.c = QuattroEAtk->mPosition;

			attackVel[2] = targetPos[2] - startPos;
			attackVel[2].normalize() *= 30.0f;
		}

		QuattroEAtk->mVelocity = attackVel[2];
		QuattroEAtk->update(dt);

		QuattroTimeElapsed[2][0] += dt;

		if (QuattroTimeElapsed[2][0] >= 0.2f && attackVel[2].length() <= 350.0f)
		{
			attackVel[2] *= 1.5f;
			QuattroTimeElapsed[2][0] = 0.0f;
		}

		QuattroTimeElapsed[2][1] += dt;

		if (QuattroTimeElapsed[2][1] >= 0.5f)
		{
			if (opptHitBox.hitBy(QuattroEAtk->mBoundingCircle))
			{
				attackVel[2].x = 0.0f;
				attackVel[2].y = 0.0f;
				opptDmgTaken += 30;
				QuattroTimeElapsed[2][0] = 0.0f;
				QuattroTimeElapsed[2][1] = 0.0f;
				playerUseE = false;
			}
			if (!wBattleBounds.isPtInside(QuattroEAtk->mPosition))
			{
				attackVel[2].x = 0.0f;
				attackVel[2].y = 0.0f;
				QuattroTimeElapsed[2][0] = 0.0f;
				QuattroTimeElapsed[2][1] = 0.0f;
				playerUseE = false;
			}
		}
	}

	// Quattro's R Attack: "War Tank"
	if (playerName == L"Quattro" && playerUseR)
	{
		for (int a = 0; a < 4; ++a)
		{
			QuattroRAtk[a]->mPosition = startPos;
			QuattroRAtk[a]->mBoundingCircle.c = QuattroRAtk[a]->mPosition;

			QuattroRisOn = true;
		}

		QuattroTimeElapsed[3][0] += dt;

		if (QuattroTimeElapsed[3][0] >= 0.15f)
		{
			++frameSet[3];
			if (frameSet[3] > 3)
				frameSet[3] = 0;
			QuattroTimeElapsed[3][0] = 0.0f;
		}

		QuattroTimeElapsed[3][1] += dt;

		if (QuattroTimeElapsed[3][1] >= 0.5f && opptHitBox.hitBy(QuattroRAtk[frameSet[3]]->mBoundingCircle))
		{
			opptDmgTaken += 5;
			QuattroTimeElapsed[3][1] = 0.0f;
		}

		QuattroTimeElapsed[3][2] += dt;

		if (QuattroTimeElapsed[3][2] >= 4.5f)
		{
			QuattroRisOn = false;
			QuattroTimeElapsed[3][0] = 0.0f;
			QuattroTimeElapsed[3][1] = 0.0f;
			QuattroTimeElapsed[3][2] = 0.0f;
			playerUseR = false;
		}
	}
}

bool Warrior::QuattroWCollision(Circle opptAttack)
{
	if (QuattroWisOn)
		return QuattroWBounds.isHitBy(opptAttack);
	else
		return false;
}

 // Seraphina's Attacks
void Warrior::updateSeraphinaAtks(float dt, wstring playerName, bool& playerUseQ, bool& playerUseW, bool& playerUseE, bool& playerUseR,
	                              int frameSet[4], Vec2 startPos, Vec2 targetPos[4], Vec2 attackVel[4], int& lifePoints,
	                              Vec2 opptPos, Circle& opptHitBox, int& opptDmgTaken, float& opptMoveSpeed)
{
	// Seraphina's Q Attack: "Bubble Gun"
	if (playerName == L"Seraphina" && playerUseQ)
	{
		if (attackVel[0].x == 0.0f && attackVel[0].y == 0.0f)
		{
			for (int a = 0; a < 5; ++a)
			{
				SeraphinaQAtk[a]->mPosition = startPos;
				SeraphinaQAtk[a]->mBoundingCircle.c = SeraphinaQAtk[a]->mPosition;

				SeraphinaQisOn[a] = true;
			}

			attackVel[0] = targetPos[0] - startPos;
			attackVel[0].normalize() *= 300.0f;
		}

		SeraphinaTimeElapsed[0] += dt;

		for (int b = 0; b < 5; ++b)
		{
			if (SeraphinaTimeElapsed[0] >= b * 0.2f && SeraphinaQisOn[b])
			{
				SeraphinaQAtk[b]->mVelocity = attackVel[0];
				SeraphinaQAtk[b]->update(dt);
			}
		}

		for (int c = 0; c < 5; ++c)
		{
			if (opptHitBox.hitBy(SeraphinaQAtk[c]->mBoundingCircle))
			{
				SeraphinaQAtk[c]->mVelocity.x = 0.0f;
				SeraphinaQAtk[c]->mVelocity.y = 0.0f;
				if (SeraphinaQisOn[c])
					opptDmgTaken += 6;
				SeraphinaQisOn[c] = false;
			}
			if (!wBattleBounds.isPtInside(SeraphinaQAtk[c]->mPosition) || QuattroWCollision(SeraphinaQAtk[c]->mBoundingCircle))
			{
				SeraphinaQAtk[c]->mVelocity.x = 0.0f;
				SeraphinaQAtk[c]->mVelocity.y = 0.0f;
				SeraphinaQisOn[c] = false;
			}
		}

		if(!SeraphinaQisOn[0] && !SeraphinaQisOn[1] && !SeraphinaQisOn[2] && !SeraphinaQisOn[3] && !SeraphinaQisOn[4])
		{
			attackVel[0].x = 0.0f;
			attackVel[0].y = 0.0f;
			SeraphinaTimeElapsed[0] = 0.0f;
			playerUseQ = false;
		}
	}

	// Seraphina's W Attack: "Sphere Factor"
	if (playerName == L"Seraphina" && playerUseW)
	{
		static int WCurrSphere = 0;
		static Vec2 WCurrLength;

		if (SeraphinaWNew)
		{
			SeraphinaWNew = false;

			while (SeraphinaWisOn[SeraphinaWSet])
			{
				++SeraphinaWSet;
				if (SeraphinaWSet > 3)
					SeraphinaWSet = 0;

				if (!SeraphinaWisOn[SeraphinaWSet])
				{
					SeraphinaWisOn[SeraphinaWSet] = true;
					break;
				}
			}

			if (!SeraphinaWisOn[SeraphinaWSet])
				SeraphinaWisOn[SeraphinaWSet] = true;

			WCurrSphere = SeraphinaWSet * 2;

			for (int a = WCurrSphere; a < WCurrSphere + 2; ++a)
			{
				SeraphinaWAtk[a]->mPosition = startPos;
				SeraphinaWAtk[a]->mBoundingCircle.c = SeraphinaWAtk[a]->mPosition;
			}

			SeraphinaWAtkList.push_back(SeraphinaWAtk[WCurrSphere]);
			SeraphinaWAtkList.push_back(SeraphinaWAtk[WCurrSphere + 1]);
		}

		attackVel[1] = (targetPos[1] - SeraphinaWAtk[WCurrSphere]->mPosition) * 100.0f;
		if (attackVel[1].length() >= 300.0f)
			attackVel[1].normalize() *= 300.0f;

		for (int b = WCurrSphere; b < WCurrSphere + 2; ++b)
		{
			SeraphinaWAtk[b]->mVelocity = attackVel[1];
			SeraphinaWAtk[b]->update(dt);
		}

		WCurrLength = SeraphinaWAtk[WCurrSphere]->mPosition - startPos;

		if ((SeraphinaWAtk[WCurrSphere]->mPosition.x == targetPos[1].x && SeraphinaWAtk[WCurrSphere]->mPosition.y == targetPos[1].y) || WCurrLength.length() >= 150.0f)
		{
			attackVel[1].x = 0.0f;
			attackVel[1].y = 0.0f;
			SeraphinaWNew = true;
			playerUseW = false;
		}
	}

	if (SeraphinaWisOn[0] || SeraphinaWisOn[1] || SeraphinaWisOn[2] || SeraphinaWisOn[3])
	{
		SeraphinaTimeElapsed[1] += dt;

		if (SeraphinaTimeElapsed[1] >= 1.0f)
		{
			++frameSet[1];
			if (frameSet[1] > 1)
				frameSet[1] = 0;
			SeraphinaTimeElapsed[1] = 0.0f;
		}

		for (int c = 0; c < 8; c += 2)
		{
			if (SeraphinaWisOn[c / 2] && opptHitBox.hitBy(SeraphinaWAtk[c]->mBoundingCircle))
			{
				SeraphinaWAtkList.remove(SeraphinaWAtk[c]);
				SeraphinaWAtkList.remove(SeraphinaWAtk[c + 1]);
				opptDmgTaken += 8;
				opptMoveSpeed = 50.0f;
				SeraphinaWisOn[c / 2] = false;
			}
			if (SeraphinaWisOn[c / 2] && !wBattleBounds.isPtInside(SeraphinaWAtk[c]->mPosition))
			{
				SeraphinaWAtkList.remove(SeraphinaWAtk[c]);
				SeraphinaWAtkList.remove(SeraphinaWAtk[c + 1]);
				SeraphinaWisOn[c / 2] = false;
			}
		}
	}

	// Seraphina's E Attack: "Celestial Halo"
	if (playerName == L"Seraphina" && playerUseE)
	{
		SeraphinaEAtk->mPosition = startPos;
		SeraphinaEAtk->mBoundingCircle.c = SeraphinaEAtk->mPosition;

		SeraphinaEisOn = true;

		SeraphinaTimeElapsed[2] += dt;

		if (SeraphinaTimeElapsed[2] >= 3.0f)
		{
			SeraphinaEisOn = false;
			SeraphinaTimeElapsed[2] = 0.0f;
			playerUseE = false;
		}
	}

	// Seraphina's R Attack: "Circle of Life"
	if (playerName == L"Seraphina" && playerUseR)
	{
		static int RBounce[8];
		static Vec2 RAtkVelocity[8];

		if (SeraphinaRNew)
		{
			SeraphinaRNew = false;

			for (int a = 0; a < 8; ++a)
			{
				SeraphinaRisOn[a] = true;
				SeraphinaRAtk[a]->mPosition = startPos;
			}

			SeraphinaRAtk[0]->mPosition.y -= 50.0f;
			SeraphinaRAtk[1]->mPosition.x += 37.0f;
			SeraphinaRAtk[1]->mPosition.y -= 37.0f;
			SeraphinaRAtk[2]->mPosition.x += 50.0f;
			SeraphinaRAtk[3]->mPosition.x += 37.0f;
			SeraphinaRAtk[3]->mPosition.y += 37.0f;
			SeraphinaRAtk[4]->mPosition.y += 50.0f;
			SeraphinaRAtk[5]->mPosition.x -= 37.0f;
			SeraphinaRAtk[5]->mPosition.y += 37.0f;
			SeraphinaRAtk[6]->mPosition.x -= 50.0f;
			SeraphinaRAtk[7]->mPosition.x -= 37.0f;
			SeraphinaRAtk[7]->mPosition.y -= 37.0f;

			for (int b = 0; b < 8; ++b)
			{
				SeraphinaRAtk[b]->mBoundingCircle.c = SeraphinaRAtk[b]->mPosition;

				if (b % 2 == 0)
					RBounce[b] = 1;
				else
					RBounce[b] = 2;

				RAtkVelocity[b] = SeraphinaRAtk[b]->mPosition - startPos;
				RAtkVelocity[b].normalize() *= 400.0f;
			}
		}

		SeraphinaTimeElapsed[3] += dt;

		for (int c = 0; c < 8; ++c)
		{
			if (SeraphinaRisOn[c])
			{
				if (SeraphinaTimeElapsed[3] >= 0.2f)
				{
					SeraphinaRAtk[c]->mVelocity = RAtkVelocity[c];
					SeraphinaRAtk[c]->update(dt);
				}

				if (opptHitBox.hitBy(SeraphinaRAtk[c]->mBoundingCircle))
				{
					SeraphinaRAtk[c]->mVelocity.x = 0.0f;
					SeraphinaRAtk[c]->mVelocity.y = 0.0f;
					opptDmgTaken += 10;
					lifePoints += 5;
					if (lifePoints > 304)
						lifePoints = 304;
					SeraphinaRisOn[c] = false;
				}
				if (QuattroWCollision(SeraphinaRAtk[c]->mBoundingCircle))
				{
					SeraphinaRAtk[c]->mVelocity.x = 0.0f;
					SeraphinaRAtk[c]->mVelocity.y = 0.0f;
					SeraphinaRisOn[c] = false;
				}
				if (!wBattleBounds.isPtInside(SeraphinaRAtk[c]->mPosition))
				{
					if (RBounce[c] > 0)
					{
						if (SeraphinaRAtk[c]->mPosition.x < wBattleBounds.minPt.x || SeraphinaRAtk[c]->mPosition.x > wBattleBounds.maxPt.x)
							RAtkVelocity[c].x *= -1;
						if (SeraphinaRAtk[c]->mPosition.y < wBattleBounds.minPt.y || SeraphinaRAtk[c]->mPosition.y > wBattleBounds.maxPt.y)
							RAtkVelocity[c].y *= -1;
						RBounce[c] -= 1;
					}
					else
					{
						SeraphinaRAtk[c]->mVelocity.x = 0.0f;
						SeraphinaRAtk[c]->mVelocity.y = 0.0f;
						SeraphinaRisOn[c] = false;
					}
				}
			}

			if (!SeraphinaRisOn[0] && !SeraphinaRisOn[1] && !SeraphinaRisOn[2] && !SeraphinaRisOn[3] && !SeraphinaRisOn[4] && !SeraphinaRisOn[5] && !SeraphinaRisOn[6] && !SeraphinaRisOn[7])
			{
				SeraphinaTimeElapsed[3] = 0.0f;
				SeraphinaRNew = true;
				playerUseR = false;
			}
		}
	}
}

// Dimitri's Attacks
void Warrior::updateDimitriAtks(float dt, wstring playerName, bool& playerUseQ, bool& playerUseW, bool& playerUseE, bool& playerUseR,
	                            int frameSet[4], Vec2 startPos, Vec2 targetPos[4], Vec2 attackVel[4], int& lifePoints,
	                            Vec2 opptPos, Circle& opptHitBox, int& opptDmgTaken, float& opptMoveSpeed)
{
	// Dimitri's Q Attack: "Triple Threat"
	if (playerName == L"Dimitri" && playerUseQ)
	{
		static Vec2 QAtkVelocity[3];
		static int QCurrSet = 0;

		if (DimitriQNew)
		{
			DimitriQNew = false;

			for (int a = 0; a < 9; ++a)
			{
				DimitriQAtk[a]->mPosition = startPos;
				DimitriQAtk[a]->mBoundingCircle.c = DimitriQAtk[a]->mPosition;
			}

			for (int b = 0; b < 3; ++b)
			{
				DimitriQisOn[b] = true;

				QAtkVelocity[b] = targetPos[0] - startPos;
				if (b == 1)
					QAtkVelocity[b].rotate(-157.5f);
				if (b == 2)
					QAtkVelocity[b].rotate(157.5f);
				QAtkVelocity[b].normalize() *= 300.0f;
			}
		}

		DimitriTimeElapsed[0] += dt;

		if (DimitriTimeElapsed[0] >= 0.05f)
		{
			++frameSet[0];
			if (frameSet[0] > 2)
				frameSet[0] = 0;
			DimitriTimeElapsed[0] = 0.0f;
		}

		for (int c = 0; c < 9; ++c)
		{
			if (c < 3)
				QCurrSet = 0;
			if (c > 2 && c < 6)
				QCurrSet = 1;
			if (c > 5)
				QCurrSet = 2;
			
			if (DimitriQisOn[QCurrSet])
			{
				DimitriQAtk[c]->mVelocity = QAtkVelocity[QCurrSet];
				DimitriQAtk[c]->update(dt);

				if (opptHitBox.hitBy(DimitriQAtk[c]->mBoundingCircle))
				{
					DimitriQAtk[c]->mVelocity.x = 0.0f;
					DimitriQAtk[c]->mVelocity.y = 0.0f;
					opptDmgTaken += 10;
					DimitriQisOn[QCurrSet] = false;
				}
				if (!wBattleBounds.isPtInside(DimitriQAtk[c]->mPosition) || QuattroWCollision(DimitriQAtk[c]->mBoundingCircle))
				{
					DimitriQAtk[c]->mVelocity.x = 0.0f;
					DimitriQAtk[c]->mVelocity.y = 0.0f;
					DimitriQisOn[QCurrSet] = false;
				}
			}

			if (!DimitriQisOn[0] && !DimitriQisOn[1] && !DimitriQisOn[2])
			{
				DimitriQNew = true;
				playerUseQ = false;
			}
		}
	}

	// Dimitri's W Attack: "Pyramid Scheme"
	if (playerName == L"Dimitri" && playerUseW)
	{
		static bool WUpdateTriangle = true;
		static int WRandTriangle;
		srand((unsigned)time(NULL));
		list<Sprite*>::iterator DimitriWHoldIt1;
		static Vec2 WCurrLength;

		if (DimitriWNew)
		{
			DimitriWNew = false;

			WRandTriangle = rand() % DimitriWRAmmoList.size();

			DimitriWHoldIt1 = DimitriWRAmmoList.begin();
			advance(DimitriWHoldIt1, WRandTriangle);

			DimitriWHolder1 = *DimitriWHoldIt1;

			DimitriWRAmmoList.erase(DimitriWHoldIt1);

			DimitriWHolder1->mPosition = startPos;
			DimitriWHolder1->mBoundingCircle.c = DimitriWHolder1->mPosition;

			DimitriWAtkList.push_back(DimitriWHolder1);

			WUpdateTriangle = true;
		}

		DimitriTimeElapsed[1] += dt;

		DimitriWAtk[10]->mPosition.x = startPos.x + 25.0f;
		DimitriWAtk[10]->mPosition.y = startPos.y - 42.0f;

		attackVel[1] = (targetPos[1] - DimitriWHolder1->mPosition) * 100.0f;
		if (attackVel[1].length() >= 300.0f)
			attackVel[1].normalize() *= 300.0f;

		DimitriWHolder1->mVelocity = attackVel[1];
		if (WUpdateTriangle)
			DimitriWHolder1->update(dt);

		WCurrLength = DimitriWHolder1->mPosition - startPos;

		if ((DimitriWHolder1->mPosition.x == targetPos[1].x && DimitriWHolder1->mPosition.y == targetPos[1].y) || WCurrLength.length() >= 150.0f)
		{
			attackVel[1].x = 0.0f;
			attackVel[1].y = 0.0f;
			WUpdateTriangle = false;

			if (DimitriTimeElapsed[1] >= 1.5f)
			{
				DimitriWTriangles += 1;
				DimitriTimeElapsed[1] = 0.0f;
				DimitriWNew = true;
				WUpdateTriangle = true;
				playerUseW = false;
			}
		}
	}

	if (DimitriWAtkList.size() > 0)
	{
		list<Sprite*>::iterator DimitriWHoldIt2;

		for (DimitriWHoldIt2 = DimitriWAtkList.begin(); DimitriWHoldIt2 != DimitriWAtkList.end(); ++DimitriWHoldIt2)
		{
			DimitriWHolder2 = *DimitriWHoldIt2;

			if (opptHitBox.hitBy(DimitriWHolder2->mBoundingCircle))
			{
				DimitriWTrash.push_back(DimitriWHolder2);
				opptDmgTaken += 8;
				if (wDimitriCounterW < 2)
					++wDimitriCounterW;
				DimitriWTriangles -= 1;
			}
			if (!wBattleBounds.isPtInside(DimitriWHolder2->mPosition))
			{
				DimitriWTrash.push_back(DimitriWHolder2);
				if (wDimitriCounterW < 2)
					++wDimitriCounterW;
				DimitriWTriangles -= 1;
			}
		}

		for (DimitriWHoldIt2 = DimitriWTrash.begin(); DimitriWHoldIt2 != DimitriWTrash.end(); ++DimitriWHoldIt2)
		{
			DimitriWHolder2 = *DimitriWHoldIt2;
			DimitriWRAmmoList.push_back(DimitriWHolder2);
			DimitriWAtkList.remove(DimitriWHolder2);
		}

		DimitriWTrash.clear();
	}

	// Dimitri's E Attack: "Sharp Attack"
	if (playerName == L"Dimitri" && playerUseE)
	{
		if (attackVel[2].x == 0.0f && attackVel[2].y == 0.0f)
		{
			for (int a = 0; a < 2; ++a)
			{
				DimitriEAtk[a]->mPosition = startPos;
				DimitriEAtk[a]->mBoundingCircle.c = DimitriEAtk[a]->mPosition;
			}

			attackVel[2] = targetPos[2] - startPos;
			attackVel[2].normalize() *= 350.0f;
		}

		for (int b = 0; b < 2; ++b)
		{
			DimitriEAtk[b]->mVelocity = attackVel[2];
			DimitriEAtk[b]->update(dt);
		}

		DimitriTimeElapsed[2] += dt;

		if (DimitriTimeElapsed[2] >= 0.15f)
		{
			++frameSet[2];
			if (frameSet[2] > 1)
				frameSet[2] = 0;
			DimitriTimeElapsed[2] = 0.0f;
		}

		if (opptHitBox.hitBy(DimitriEAtk[frameSet[2]]->mBoundingCircle))
		{
			attackVel[2].x = 0.0f;
			attackVel[2].y = 0.0f;
			opptDmgTaken += 10;
			opptMoveSpeed = 30.0f;
			DimitriTimeElapsed[2] = 0.0f;
			playerUseE = false;
		}
		if (!wBattleBounds.isPtInside(DimitriEAtk[frameSet[2]]->mPosition) || QuattroWCollision(DimitriEAtk[frameSet[2]]->mBoundingCircle))
		{
			attackVel[2].x = 0.0f;
			attackVel[2].y = 0.0f;
			DimitriTimeElapsed[2] = 0.0f;
			playerUseE = false;
		}
	}

	// Dimitri's R Attack: "Bermuda Triangle"
	if (playerName == L"Dimitri" && playerUseR)
	{
		static int RRandTriangle;
		srand((unsigned)time(NULL));
		list<Sprite*>::iterator DimitriRHoldIt1;
		list<Sprite*>::iterator DimitriRHoldIt2;
		static Vec2 RCurrLength;
		static float RMaxLength = 150.0f;
		static bool RBermudaTriangle = true;
		float RBermudaCoordinates[3];

		if (DimitriRTriangles < 3)
		{
			if (attackVel[3].x == 0.0f && attackVel[3].y == 0.0f)
			{
				RRandTriangle = rand() % DimitriWRAmmoList.size();

				DimitriRHoldIt1 = DimitriWRAmmoList.begin();
				advance(DimitriRHoldIt1, RRandTriangle);

				DimitriRHolder1 = *DimitriRHoldIt1;

				DimitriWRAmmoList.erase(DimitriRHoldIt1);

				DimitriRHolder1->mPosition = startPos;
				DimitriRHolder1->mBoundingCircle.c = DimitriRHolder1->mPosition;

				DimitriRAtkList.push_back(DimitriRHolder1);

				RBermudaTriangle = true;
			}

			attackVel[3] = (targetPos[3] - DimitriRHolder1->mPosition) * 100.0f;
			if (wPlayer2 == L"Dimitri")
			{
				if (attackVel[3].length() >= 1000.0f)
					attackVel[3].normalize() *= 1000.0f;
			}
			else
			{
				if (attackVel[3].length() >= 300.0f)
					attackVel[3].normalize() *= 300.0f;
			}

			DimitriRHolder1->mVelocity = attackVel[3];
			DimitriRHolder1->update(dt);

			RCurrLength = DimitriRHolder1->mPosition - startPos;

			if (wPlayer2 == L"Dimitri" && DimitriRTriangles > 0)
				RMaxLength = 900.0f;
			else
				RMaxLength = 150.0f;
		}

		if ((DimitriRHolder1->mPosition.x == targetPos[3].x && DimitriRHolder1->mPosition.y == targetPos[3].y) || RCurrLength.length() >= RMaxLength)
		{
			attackVel[3].x = 0.0f;
			attackVel[3].y = 0.0f;

			if (DimitriRTriangles < 3)
			{
				DimitriRPoints[DimitriRTriangles].x = DimitriRHolder1->mPosition.x;
				DimitriRPoints[DimitriRTriangles].y = DimitriRHolder1->mPosition.y;

				DimitriRTriangles += 1;
			}

			if (DimitriRTriangles == 3)
			{
				DimitriRisOn = true;

				DimitriTimeElapsed[3] += dt;

				if (RBermudaTriangle)
				{
					RBermudaCoordinates[0] = ((DimitriRPoints[1].y - DimitriRPoints[2].y) * (opptPos.x - DimitriRPoints[2].x)
						                   + (DimitriRPoints[2].x - DimitriRPoints[1].x) * (opptPos.y - DimitriRPoints[2].y))
						                   / ((DimitriRPoints[1].y - DimitriRPoints[2].y) * (DimitriRPoints[0].x - DimitriRPoints[2].x)
						                   + (DimitriRPoints[2].x - DimitriRPoints[1].x) * (DimitriRPoints[0].y - DimitriRPoints[2].y));

					RBermudaCoordinates[1] = ((DimitriRPoints[2].y - DimitriRPoints[0].y) * (opptPos.x - DimitriRPoints[2].x)
										   + (DimitriRPoints[0].x - DimitriRPoints[2].x) * (opptPos.y - DimitriRPoints[2].y))
										   / ((DimitriRPoints[1].y - DimitriRPoints[2].y) * (DimitriRPoints[0].x - DimitriRPoints[2].x)
										   + (DimitriRPoints[2].x - DimitriRPoints[1].x) * (DimitriRPoints[0].y - DimitriRPoints[2].y));

					RBermudaCoordinates[2] = 1.0f - RBermudaCoordinates[0] - RBermudaCoordinates[1];

					if (RBermudaCoordinates[0] > 0.0f && RBermudaCoordinates[1] > 0.0f && RBermudaCoordinates[2] > 0.0f)
						opptDmgTaken += 50;

					RBermudaTriangle = false;
				}

				if (DimitriTimeElapsed[3] >= 3.0f)
				{
					for (DimitriRHoldIt2 = DimitriRAtkList.begin(); DimitriRHoldIt2 != DimitriRAtkList.end(); ++DimitriRHoldIt2)
					{
						DimitriRHolder2 = *DimitriRHoldIt2;
						DimitriWRAmmoList.push_back(DimitriRHolder2);
					}
					DimitriRAtkList.clear();
					DimitriRTriangles -= 3;
					DimitriTimeElapsed[3] = 0.0f;
					DimitriRisOn = false;
					playerUseR = false;
				}
			}
			else
				playerUseR = false;
		}
	}
}

// Liu Jiao's Attacks
void Warrior::updateLiuJiaoAtks(float dt, wstring playerName, bool& playerUseQ, bool& playerUseW, bool& playerUseE, bool& playerUseR,
	                            int frameSet[4], Vec2 startPos, Vec2 targetPos[4], Vec2 attackVel[4], int& lifePoints,
	                            Vec2 opptPos, Circle& opptHitBox, int& opptDmgTaken, float& opptMoveSpeed)
{
	// Liu Jiao's Q Attack: "Hexagon Havoc"
	if (playerName == L"Liu Jiao" && playerUseQ)
	{
		static Vec2 QStartPoint[6];
		static Vec2 QAtkVelocity[6];
		static int QCurrSet;

		LiuJiaoTimeElapsed[0][0] += dt;

		if (LiuJiaoTimeElapsed[0][0] >= 0.15f)
		{
			++frameSet[0];
			if (frameSet[0] > 2)
				frameSet[0] = 0;
			LiuJiaoTimeElapsed[0][0] = 0.0f;
		}

		if (LiuJiaoQStage == 0)
		{
			for (int a = 0; a < 18; ++a)
			{
				if (a < 6)
				{
					LiuJiaoQisOn[a] = true;

					if (a < 3)
						QStartPoint[a].y = 20.0f;
					if (a > 2)
						QStartPoint[a].y = 590.0f;
					QStartPoint[0].x = 20.0f;
					QStartPoint[1].x = 500.0f;
					QStartPoint[2].x = 980.0f;
					QStartPoint[3].x = 20.0f;
					QStartPoint[4].x = 500.0f;
					QStartPoint[5].x = 980.0f;
				}

				if (a < 9)
				{
					LiuJiaoQAtk[a]->mPosition.y = -50.0f;
					if (a < 3)
						LiuJiaoQAtk[a]->mPosition.x = -50.0f;
					if (a > 2 && a < 6)
						LiuJiaoQAtk[a]->mPosition.x = 500.0f;
					if (a > 5)
						LiuJiaoQAtk[a]->mPosition.x = 1050.0f;
				}
				else
				{
					LiuJiaoQAtk[a]->mPosition.y = 650.0f;
					if (a < 12)
						LiuJiaoQAtk[a]->mPosition.x = -50.0f;
					if (a > 11 && a < 15)
						LiuJiaoQAtk[a]->mPosition.x = 500.0f;
					if (a > 14)
						LiuJiaoQAtk[a]->mPosition.x = 1050.0f;
				}

				LiuJiaoQAtk[a]->mBoundingCircle.c = LiuJiaoQAtk[a]->mPosition;
			}

			LiuJiaoQStage = 1;
		}

		if (LiuJiaoQStage == 1)
		{
			LiuJiaoTimeElapsed[0][1] += dt;

			for (int b = 0; b < 18; ++b)
			{
				if (b < 6)
					QAtkVelocity[b] = (QStartPoint[b] - LiuJiaoQAtk[b * 3]->mPosition) * 25.0f;

				if (b < 3)
					LiuJiaoQAtk[b]->mVelocity = QAtkVelocity[0];
				if (b > 2 && b < 6)
					LiuJiaoQAtk[b]->mVelocity = QAtkVelocity[1];
				if (b > 5 && b < 9)
					LiuJiaoQAtk[b]->mVelocity = QAtkVelocity[2];
				if (b > 8 && b < 12)
					LiuJiaoQAtk[b]->mVelocity = QAtkVelocity[3];
				if (b > 11 && b < 15)
					LiuJiaoQAtk[b]->mVelocity = QAtkVelocity[4];
				if (b > 14)
					LiuJiaoQAtk[b]->mVelocity = QAtkVelocity[5];

				LiuJiaoQAtk[b]->update(dt);
			}

			if (LiuJiaoTimeElapsed[0][1] >= 0.65f)
			{
				for (int c = 0; c < 6; ++c)
				{
					QAtkVelocity[c] = targetPos[0] - LiuJiaoQAtk[c * 3]->mPosition;
					QAtkVelocity[c].normalize() *= 300.0f;
				}
				LiuJiaoQStage = 2;
				LiuJiaoTimeElapsed[0][1] = 0.0f;
			}
		}

		if (LiuJiaoQStage == 2)
		{
			for (int d = 0; d < 18; ++d)
			{
				if (d < 3)
					QCurrSet = 0;
				if (d > 2 && d < 6)
					QCurrSet = 1;
				if (d > 5 && d < 9)
					QCurrSet = 2;
				if (d > 8 && d < 12)
					QCurrSet = 3;
				if (d > 11 && d < 15)
					QCurrSet = 4;
				if (d > 14)
					QCurrSet = 5;

				if (LiuJiaoQisOn[QCurrSet])
				{
					LiuJiaoQAtk[d]->mVelocity = QAtkVelocity[QCurrSet];
					LiuJiaoQAtk[d]->update(dt);

					if (opptHitBox.hitBy(LiuJiaoQAtk[d]->mBoundingCircle))
					{
						LiuJiaoQAtk[d]->mVelocity.x = 0.0f;
						LiuJiaoQAtk[d]->mVelocity.y = 0.0f;
						opptDmgTaken += 5;
						LiuJiaoQisOn[QCurrSet] = false;
					}
					if (!wBattleBounds.isPtInside(LiuJiaoQAtk[d]->mPosition) || QuattroWCollision(LiuJiaoQAtk[d]->mBoundingCircle))
					{
						LiuJiaoQAtk[d]->mVelocity.x = 0.0f;
						LiuJiaoQAtk[d]->mVelocity.y = 0.0f;
						LiuJiaoQisOn[QCurrSet] = false;
					}
				}

				if (!LiuJiaoQisOn[0] && !LiuJiaoQisOn[1] && !LiuJiaoQisOn[2] && !LiuJiaoQisOn[3] && !LiuJiaoQisOn[4] && !LiuJiaoQisOn[5])
				{
					LiuJiaoTimeElapsed[0][0] = 0.0f;
					LiuJiaoQStage = 0;
					playerUseQ = false;
				}
			}
		}
	}

	// Liu Jiao's W Attack: "Six Degrees"
	if (wPlayer1 == L"Liu Jiao" && playerUseW)
	{
		for (int a = 0; a < 16; ++a)
			wP1LiuJiao[a]->mPosition = targetPos[1];
		wP1Position = wP1LiuJiao[wP1Frame]->mPosition;
		wNewMousePos = wP1Position;

		if (wP1Position.x == targetPos[1].x && wP1Position.y == targetPos[1].y)
			playerUseW = false;
	}

	if (wPlayer2 == L"Liu Jiao" && playerUseW)
	{
		Vec2 WRandomPoint;
		srand((unsigned)time(NULL));
		
		if (wP2Position.x <= 500.0f)
		{
			WRandomPoint.x = 800.0f;
			WRandomPoint.y = float((rand() % 301) + 200);
		}
		else if (wP2Position.x > 500.0f)
		{
			WRandomPoint.x = 200.0f;
			WRandomPoint.y = float((rand() % 301) + 200);
		}

		for (int a = 0; a < 16; ++a)
			wP2LiuJiao[a]->mPosition = WRandomPoint;
		wP2Position = wP2LiuJiao[wP2Frame]->mPosition;

		if (wP2Position.x == WRandomPoint.x && wP2Position.y == WRandomPoint.y)
			playerUseW = false;
	}

	// Liu Jiao's E Attack: "Warlock's Hex"
	if (playerName == L"Liu Jiao" && playerUseE)
	{
		if (attackVel[2].x == 0.0f && attackVel[2].y == 0.0f)
		{
			LiuJiaoEAtk->mPosition = startPos;
			LiuJiaoEAtk->mBoundingCircle.c = LiuJiaoEAtk->mPosition;

			attackVel[2] = targetPos[2] - startPos;
			attackVel[2].normalize() *= 250.0f;
		}

		LiuJiaoEAtk->mVelocity = attackVel[2];
		LiuJiaoEAtk->update(dt);

		if (opptHitBox.hitBy(LiuJiaoEAtk->mBoundingCircle))
		{
			attackVel[2].x = 0.0f;
			attackVel[2].y = 0.0f;
			opptDmgTaken += 10;
			lifePoints += 10;
			if (lifePoints > 304)
				lifePoints = 304;
			playerUseE = false;
		}
		if (!wBattleBounds.isPtInside(LiuJiaoEAtk->mPosition) || QuattroWCollision(LiuJiaoEAtk->mBoundingCircle))
		{
			attackVel[2].x = 0.0f;
			attackVel[2].y = 0.0f;
			playerUseE = false;
		}
	}

	// Liu Jiao's R Attack: "Call of The Beast"
	if (playerName == L"Liu Jiao" && playerUseR)
	{
		if (LiuJiaoRStage == 1)
		{
			if (attackVel[3].x == 0.0f && attackVel[3].y == 0.0f)
			{
				for (int a = 0; a < 3; ++a)
				{
					LiuJiaoRAtk[a]->mPosition = startPos;
					LiuJiaoRAtk[a]->mBoundingCircle.c = LiuJiaoRAtk[a]->mPosition;
				}

				attackVel[3] = targetPos[3] - startPos;
				attackVel[3].normalize() *= 275.0f;
			}

			playerUseR = false;
		}

		if (LiuJiaoRStage == 2)
		{
			frameSet[3] = 2;
			attackVel[3].x = 0.0f;
			attackVel[3].y = 0.0f;

			LiuJiaoRBounds = Rect(LiuJiaoRAtk[2]->mPosition.x - LiuJiaoRAtk[2]->mBoundingCircle.r,
				                  LiuJiaoRAtk[2]->mPosition.y - LiuJiaoRAtk[2]->mBoundingCircle.r,
				                  LiuJiaoRAtk[2]->mPosition.x + LiuJiaoRAtk[2]->mBoundingCircle.r,
				                  LiuJiaoRAtk[2]->mPosition.y + LiuJiaoRAtk[2]->mBoundingCircle.r);
			
			if (LiuJiaoRBounds.isPtInside(opptPos) && LiuJiaoTimeElapsed[3][1] <= 0.0f)
			{
				LiuJiaoRisOn = true;
				opptDmgTaken += 25;
			}
			if (!LiuJiaoRBounds.isPtInside(opptPos) && LiuJiaoTimeElapsed[3][1] <= 0.0f)
				LiuJiaoTimeElapsed[3][1] = 4.5f;

			LiuJiaoTimeElapsed[3][1] += dt;

			if (LiuJiaoTimeElapsed[3][1] >= 5.0f)
			{
				frameSet[3] = 0;
				LiuJiaoTimeElapsed[3][1] = 0.0f;
				LiuJiaoRisOn = false;
				LiuJiaoRStage = 0;
				playerUseR = false;
			}
		}
	}

	if (LiuJiaoRStage == 1)
	{
		if (attackVel[3].x != 0.0f && attackVel[3].y != 0.0f)
		{
			for (int b = 0; b < 3; ++b)
			{
				LiuJiaoRAtk[b]->mVelocity = attackVel[3];
				LiuJiaoRAtk[b]->update(dt);
			}

			LiuJiaoRBounds = Rect(LiuJiaoRAtk[2]->mPosition.x - LiuJiaoRAtk[2]->mBoundingCircle.r,
				                  LiuJiaoRAtk[2]->mPosition.y - LiuJiaoRAtk[2]->mBoundingCircle.r,
				                  LiuJiaoRAtk[2]->mPosition.x + LiuJiaoRAtk[2]->mBoundingCircle.r,
				                  LiuJiaoRAtk[2]->mPosition.y + LiuJiaoRAtk[2]->mBoundingCircle.r);

			LiuJiaoTimeElapsed[3][0] += dt;

			if (LiuJiaoTimeElapsed[3][0] >= 0.15f)
			{
				++frameSet[3];
				if (frameSet[3] > 1)
					frameSet[3] = 0;
				LiuJiaoTimeElapsed[3][0] = 0.0f;
			}

			if (!wBattleBounds.isPtInside(LiuJiaoRAtk[frameSet[3]]->mPosition) || QuattroWCollision(LiuJiaoRAtk[frameSet[3]]->mBoundingCircle))
			{
				attackVel[3].x = 0.0f;
				attackVel[3].y = 0.0f;
				LiuJiaoTimeElapsed[3][0] = 0.0f;
				LiuJiaoRStage = 0;
				if (wPlayer1 == L"Liu Jiao")
				{
					wP1Rcooldown += 12;
					wP1RisonCD = true;
				}
				if (wPlayer2 == L"Liu Jiao")
				{
					wP2Rcooldown += 12;
					wP2RisonCD = true;
				}
				playerUseR = false;
			}
		}
	}
}

// Cooldowns
bool Warrior::startCooldown(int& playerCD, int seconds)
{
	playerCD += seconds;
	return true;
}

void Warrior::updateCooldowns(float dt, wstring playerName, float& QtimeElapsed, float& WtimeElapsed, float& EtimeElapsed, float& RtimeElapsed,
	                          bool& QisonCD, bool& WisonCD, bool& EisonCD, bool& RisonCD, int& QSeconds, int& WSeconds, int& ESeconds, int& RSeconds)
{
	QtimeElapsed += dt;
	if (QisonCD)
	{
		if (QSeconds >= 0 && QtimeElapsed >= 1.0f)
		{
			QSeconds -= 1;
			QtimeElapsed = 0.0f;
		}
		if (QSeconds < 0)
		{
			QisonCD = false;
			QSeconds = 0;

			if (playerName == L"Quattro")
				wQuattroCounterQ = 2;
		}
	}

	WtimeElapsed += dt;
	if (WisonCD)
	{
		if (WSeconds >= 0 && WtimeElapsed >= 1.0f)
		{
			WSeconds -= 1;
			WtimeElapsed = 0.0f;
		}
		if (WSeconds < 0)
		{
			WisonCD = false;
			WSeconds = 0;

			if (playerName == L"Dimitri")
			{
				if (DimitriWAtkList.size() <= 5)
					wDimitriCounterW = 2;
				if (DimitriWAtkList.size() == 6)
					wDimitriCounterW = 1;
			}
		}
	}

	EtimeElapsed += dt;
	if (EisonCD)
	{
		if (ESeconds >= 0 && EtimeElapsed >= 1.0f)
		{
			ESeconds -= 1;
			EtimeElapsed = 0.0f;
		}
		if (ESeconds < 0)
		{
			EisonCD = false;
			ESeconds = 0;
		}
	}

	RtimeElapsed += dt;
	if (RisonCD)
	{
		if (RSeconds >= 0 && RtimeElapsed >= 1.0f)
		{
			RSeconds -= 1;
			RtimeElapsed = 0.0f;
		}
		if (RSeconds < 0)
		{
			RisonCD = false;
			RSeconds = 0;
		}
	}
}

// Life Bars
void Warrior::updateLifeBars(float dt, float& timeElapsed, int& playerDmgTaken, int& playerLifePoints, wstring playerName,
	                         HBRUSH& playerBrush, LOGBRUSH& brushColor, HPEN& playerPen, LOGPEN& penColor)
{
	timeElapsed += dt;

	if (playerDmgTaken > 0 && timeElapsed >= 0.01f)
	{
		if (playerName == wPlayer1)
			playerLifePoints -= wP2Level;
		else
			playerLifePoints -= 1;

		if (playerName == L"Quattro" && QuattroRisOn)
		{
			playerDmgTaken -= 10;
			if (playerDmgTaken < 0)
				playerDmgTaken = 0;
		}
		else if (playerName == L"Seraphina" && SeraphinaEisOn)
		{
			playerDmgTaken -= 5;
			if (playerDmgTaken < 0)
				playerDmgTaken = 0;
		}
		else
			playerDmgTaken -= 1;

		timeElapsed = 0.0f;
	}

	DeleteObject(playerBrush);
	DeleteObject(playerPen);

	if (playerLifePoints >= 301)
		brushColor.lbColor = RGB(255, 250, 0);
	if (playerLifePoints <= 300 && playerLifePoints >= 201)
		brushColor.lbColor = RGB(255, 200, 0);
	if (playerLifePoints <= 200 && playerLifePoints >= 101)
		brushColor.lbColor = RGB(255, 150, 0);
	if (playerLifePoints <= 100 && playerLifePoints >= 51)
		brushColor.lbColor = RGB(255, 80, 0);
	if (playerLifePoints <= 50 && playerLifePoints >= 1)
		brushColor.lbColor = RGB(255, 0, 0);
	if (playerLifePoints <= 0)
		brushColor.lbColor = RGB(75, 75, 75);

	penColor.lopnColor = brushColor.lbColor;

	playerBrush = CreateBrushIndirect(&brushColor);
	playerPen = CreatePenIndirect(&penColor);
}

void Warrior::drawLifeBars(HDC hBackBufferDC)
{
	wOldBrush = (HBRUSH)SelectObject(hBackBufferDC, wP1Brush);
	wOldPen = (HPEN)SelectObject(hBackBufferDC, wP1Pen);

	if (wP1LifePoints > 0)
		Rectangle(hBackBufferDC, 21, 624, wP1LifePoints + 21, 650);
	else
		Rectangle(hBackBufferDC, 21, 624, 325, 650);

	SelectObject(hBackBufferDC, wOldBrush);
	SelectObject(hBackBufferDC, wOldPen);

	wOldBrush = (HBRUSH)SelectObject(hBackBufferDC, wP2Brush);
	wOldPen = (HPEN)SelectObject(hBackBufferDC, wP2Pen);

	if (wP2LifePoints > 0)
		Rectangle(hBackBufferDC, 675, 624, wP2LifePoints + 675, 650);
	else
		Rectangle(hBackBufferDC, 675, 624, 979, 650);

	SelectObject(hBackBufferDC, wOldBrush);
	SelectObject(hBackBufferDC, wOldPen);
}

// Move Speed
void Warrior::updateMoveSpeed(float dt, float& moveSpeed, float& slowTime)
{
	if (moveSpeed == 50.0f)
	{
		slowTime += dt;

		if (slowTime >= 3.0f)
		{
			moveSpeed = 100.0f;
			slowTime = 0.0f;
		}
	}

	if (moveSpeed == 30.0f)
	{
		slowTime += dt;

		if (slowTime >= 5.0f)
		{
			moveSpeed = 100.0f;
			slowTime = 0.0f;
		}
	}
}