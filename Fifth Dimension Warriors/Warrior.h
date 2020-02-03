#ifndef WARRIOR_H
#define WARRIOR_H

#include "Sprite.h"
#include <string>
#include <list>
using namespace std;

class Warrior
{
public:
	Warrior(HINSTANCE hAppInst);
	~Warrior();

	void updateWarriors(float dt);

	void getPlayerNames(wstring player1, wstring player2);

	void turnP2off(bool offSwitch);
	void getP2Level(int level);

	void getNewMousePos(Vec2 newMousePos);
	void getNewTargetPos(wchar_t key, Vec2 newTargetPos);

	void drawWarriors(HDC hBackBufferDC, HDC hSpriteDC);
	void drawBarTools(HDC hBackBufferDC, HDC hSpriteDC);

	int endGame();

private:
	// Inputs
	Vec2 wNewMousePos;
	Vec2 wNewTargetPos;

	Rect wBattleBounds;

	// Warriors
	void drawSprites(HDC hBackBufferDC, HDC hSpriteDC, wstring playerName, int warriorFrame, int atkFrameSet[4],
		             bool playerUseQ, bool playerUseW, bool playerUseE, bool playerUseR);

	Sprite* wP1Quattro[16];
	Sprite* wP1Seraphina[16];
	Sprite* wP1Dimitri[16];
	Sprite* wP1LiuJiao[16];

	wstring wPlayer1;
	int wP1Frame;

	Sprite* wP2Quattro[16];
	Sprite* wP2Seraphina[16];
	Sprite* wP2Dimitri[16];
	Sprite* wP2LiuJiao[16];

	wstring wPlayer2;
	int wP2Frame;

	bool wP2Start;
	bool wP2TurnOff;
	int wP2Level;

	// Update Warriors
	void updatePlayer1(float dt, Sprite* P1warrior[16], float moveSpeed);

	void updatePlayer2(float dt, Sprite* P2warrior[16], float moveSpeed);
	void P2DodgeAttacks(Vec2 detectedVel, bool detectedAtk, Vec2 P1AttackPos, float detectDistance, Vec2& P2NewPosition);
	void P2UseAttack(wchar_t key);

	void updateAnimationFrame(float dt, float& timeElapsed, Vec2 startPos, Vec2 endPos, int& frame);

	Circle wP1BoundingCircle;
	Vec2 wP1Position;
	Vec2 wP1Velocity;
	int wP1LifePoints;
	int wP1DmgTaken;
	float wP1MoveSpeed;
	float wP1SlowTime;

	Circle wP2BoundingCircle;
	Vec2 wP2Position;
	Vec2 wP2Velocity;
	int wP2LifePoints;
	int wP2DmgTaken;
	float wP2MoveSpeed;
	float wP2SlowTime;

	float wP2TimeElapsed[4];

	// Update Attacks
	void playerUseAttack(wchar_t key, Vec2 newTargetPos, wstring playerName, Vec2 targetPos[4], int atkFrameSet[4],
		                 bool& playerUseQ, bool& playerUseW, bool& playerUseE, bool& playerUseR,
		                 bool& QisonCD, bool& WisonCD, bool& EisonCD, bool& RisonCD,
		                 int& QSeconds, int& WSeconds, int& ESeconds, int& RSeconds);

	void updateQuattroAtks(float dt, wstring playerName, bool& playerUseQ, bool& playerUseW, bool& playerUseE, bool& playerUseR,
		                   int frameSet[4], Vec2 startPos, Vec2 targetPos[4], Vec2 attackVel[4], int& lifePoints, 
		                   Vec2 opptPos, Circle& opptHitBox, int& opptDmgTaken, float& opptMoveSpeed);
	void updateSeraphinaAtks(float dt, wstring playerName, bool& playerUseQ, bool& playerUseW, bool& playerUseE, bool& playerUseR,
		                     int frameSet[4], Vec2 startPos, Vec2 targetPos[4], Vec2 attackVel[4], int& lifePoints,
		                     Vec2 opptPos, Circle& opptHitBox, int& opptDmgTaken, float& opptMoveSpeed);
	void updateDimitriAtks(float dt, wstring playerName, bool& playerUseQ, bool& playerUseW, bool& playerUseE, bool& playerUseR,
		                   int frameSet[4], Vec2 startPos, Vec2 targetPos[4], Vec2 attackVel[4], int& lifePoints,
		                   Vec2 opptPos, Circle& opptHitBox, int& opptDmgTaken, float& opptMoveSpeed);
	void updateLiuJiaoAtks(float dt, wstring playerName, bool& playerUseQ, bool& playerUseW, bool& playerUseE, bool& playerUseR,
		                   int frameSet[4], Vec2 startPos, Vec2 targetPos[4], Vec2 attackVel[4], int& lifePoints,
		                   Vec2 opptPos, Circle& opptHitBox, int& opptDmgTaken, float& opptMoveSpeed);

	bool wP1UseQ, wP1UseW, wP1UseE, wP1UseR;
	int wP1AtkFrameSet[4];
	Vec2 wP1TargetPos[4];
	Vec2 wP1AttackVel[4];

	bool wP2UseQ, wP2UseW, wP2UseE, wP2UseR;
	int wP2AtkFrameSet[4];
	Vec2 wP2TargetPos[4];
	Vec2 wP2AttackVel[4];

	// Quattro's Attacks
	Sprite* QuattroQAtk[9];
	Sprite* QuattroWAtk[4];
	Sprite* QuattroEAtk;
	Sprite* QuattroRAtk[4];

	float QuattroTimeElapsed[4][3];

	bool QuattroWisOn;
	Rect QuattroWBounds;
	bool QuattroRisOn;

	bool QuattroWCollision(Circle opptAttack);

	// Seraphina's Attacks
	Sprite* SeraphinaQAtk[5];
	Sprite* SeraphinaWAtk[8];
	Sprite* SeraphinaEAtk;
	Sprite* SeraphinaRAtk[8];

	float SeraphinaTimeElapsed[4];

	bool SeraphinaQisOn[5];
	bool SeraphinaWisOn[4];
	bool SeraphinaWNew;
	int SeraphinaWSet;
	list<Sprite*> SeraphinaWAtkList;
	bool SeraphinaEisOn;
	bool SeraphinaRisOn[8];
	bool SeraphinaRNew;

	// Dimitri's Attacks
	Sprite* DimitriQAtk[9];
	Sprite* DimitriWAtk[11];
	Sprite* DimitriEAtk[2];

	float DimitriTimeElapsed[4];

	bool DimitriQisOn[3];
	bool DimitriQNew;
	list<Sprite*> DimitriWRAmmoList;
	bool DimitriWNew;
	list<Sprite*> DimitriWTrash;

	int DimitriWTriangles;
	Sprite* DimitriWDraw = 0;
	Sprite* DimitriWHolder1 = 0;
	Sprite* DimitriWHolder2 = 0;
	list<Sprite*> DimitriWAtkList;

	int DimitriRTriangles;
	Sprite* DimitriRDraw = 0;
	Sprite* DimitriRHolder1 = 0;
	Sprite* DimitriRHolder2 = 0;
	list<Sprite*> DimitriRAtkList;

	bool DimitriRisOn;
	Vec2 DimitriRPoints[3];
	HPEN DimitriPen;
	LOGPEN DimitriPenColor;
	HPEN DimitriOldPen;

	// Liu Jiao's Attacks
	Sprite* LiuJiaoQAtk[18];
	Sprite* LiuJiaoEAtk;
	Sprite* LiuJiaoRAtk[3];

	float LiuJiaoTimeElapsed[4][2];

	bool LiuJiaoQisOn[6];
	int LiuJiaoQStage;
	bool LiuJiaoRisOn;
	int LiuJiaoRStage;
	Rect LiuJiaoRBounds;

	// Counters
	Sprite* QuattroQCounter[2];
	int wQuattroCounterQ;

	Sprite* SeraphinaWCounter;

	Sprite* DimitriWRCounter[5];
	int wDimitriCounterW;

	// Cooldowns
	bool startCooldown(int& playerCD, int seconds);
	void updateCooldowns(float dt, wstring playerName, float& QtimeElapsed, float& WtimeElapsed, float& EtimeElapsed, float& RtimeElapsed,
		                 bool& QisonCD, bool& WisonCD, bool& EisonCD, bool& RisonCD, int& QSeconds, int& WSeconds, int& ESeconds, int& RSeconds);

	Sprite* QCooldown[21];
	Sprite* WCooldown[21];
	Sprite* ECooldown[21];
	Sprite* RCooldown[21];

	float wP1CDtimeElapsedQ, wP1CDtimeElapsedW, wP1CDtimeElapsedE, wP1CDtimeElapsedR;
	bool wP1QisonCD, wP1WisonCD, wP1EisonCD, wP1RisonCD;
	int wP1Qcooldown, wP1Wcooldown, wP1Ecooldown, wP1Rcooldown;

	float wP2CDtimeElapsedQ, wP2CDtimeElapsedW, wP2CDtimeElapsedE, wP2CDtimeElapsedR;
	bool wP2QisonCD, wP2WisonCD, wP2EisonCD, wP2RisonCD;
	int wP2Qcooldown, wP2Wcooldown, wP2Ecooldown, wP2Rcooldown;

	// Life Bars
	void updateLifeBars(float dt, float& timeElapsed, int& playerDmgTaken, int& playerLifePoints, wstring playerName,
		                HBRUSH& playerBrush, LOGBRUSH& brushColor, HPEN& playerPen, LOGPEN& penColor);
	void drawLifeBars(HDC hBackBufferDC);

	float wP1LBtimeElapsed;
	HBRUSH wP1Brush;
	LOGBRUSH wP1BrushColor;
	HPEN wP1Pen;
	LOGPEN wP1PenColor;

	float wP2LBtimeElapsed;
	HBRUSH wP2Brush;
	LOGBRUSH wP2BrushColor;
	HPEN wP2Pen;
	LOGPEN wP2PenColor;

	HBRUSH wOldBrush;
	HPEN wOldPen;

	// Move Speed
	void updateMoveSpeed(float dt, float& moveSpeed, float& slowTime);
};

#endif // WARRIOR_H