#ifndef FDWGAME_H
#define FDWGAME_H

#include "Warrior.h"
using namespace std;

class FDWGame
{
public:
	FDWGame(HINSTANCE hAppInst, HWND hMainWnd);
	~FDWGame();

	void updateScreen(float dt);

	void drawScreen(HDC hBackBufferDC, HDC hSpriteDC);

	wstring Title();
	wstring Player1();
	wstring Player2();
	wstring Match();

	int leftClickScreen(int CaseID);
	void rightClickScreen();

	void pressQWER(wchar_t key);
	bool pressP();

	void useMenu(int CaseID);

	void turnMusicOn();
	void turnMusicOff();

private:
	// General
	HINSTANCE fdwAppInst;
	HWND fdwMainWnd;

	enum CurrScreen { StrScreen, ModeScreen, LvlScreen, SltScreen, MtpScreen, GameScreen, RsltScreen };
	CurrScreen fdwCurrScreen;

	enum CurrMode { ChallengerMode, QuickMode, PracticeMode };
	CurrMode fdwCurrMode;

	enum CurrLevel { EasyLevel, HardLevel };
	CurrLevel fdwCurrLevel;

	wstring fdwTitle;

	float fdwTimeElapsed[11];
	int fdwFrame[2];

	void fdwPlayMusic();
	void songChange(int SongOn, int SongOff);

	bool fdwMusicOn;
	bool fdwSongOn[6];
	int fdwCurrSong;

	// Start Screen
	Sprite* fdwStrScreen;
	Sprite* fdwStrTitle;
	Sprite* fdwStrPlay;
	Sprite* fdwStrExit;

	Rect fdwStrPlayBut;
	Rect fdwStrExitBut;

	Sprite* fdwQuattroAtk[9];
	Sprite* fdwSeraphinaAtk[3];
	Sprite* fdwDimitriAtk[6];
	Sprite* fdwLiuJiaoAtk[12];

	Rect fdwScreenBounds;
	Rect fdwAttackBounds;

	bool fdwAttackStage[3];
	int fdwRandNumber[6];
	
	bool fdwAttackOn[4];
	int fdwAttackFrame[4];
	bool fdwSpotlightOn[4];

	float fdwStartSide;
	int fdwLiuJiaoStage;
	bool fdwStartAnimation;

	void fdwStrScreenAnimation(float dt);
	void fdwResetStrScreen();

	// Select Screen
	Sprite* fdwSltScreen;
	Sprite* fdwSltSign;

	bool fdwSignDrop;

	Sprite* fdwQuattro[4];
	Sprite* fdwSeraphina[4];
	Sprite* fdwDimitri[4];
	Sprite* fdwLiuJiao[4];

	Rect fdwRectQuattro;
	Rect fdwRectSeraphina;
	Rect fdwRectDimitri;
	Rect fdwRectLiuJiao;

	wstring fdwPlayer1;
	wstring fdwPlayer2;

	int fdwRandOppt;
	int fdwArena;

	// Game Screen
	Warrior* fdwWarriors;

	Sprite* fdwBattleArena[3];
	Sprite* fdwBattleBar;
	Sprite* fdwP1Name[4];
	Sprite* fdwP2Name[4];

	Rect fdwBattleBounds;

	POINT fdwMousePos;
	Vec2 fdwNewMousePos;
	Vec2 fdwNewTargetPos;

	bool fdwStartGame;
	
	// Challenger & Quick Mode
	int fdwP2Level;

	wstring fdwMatch;
	int fdwChallenge;
	
	Sprite* fdwAnnouncement[6];
	bool fdwAnnounce[3];

	Sprite* fdwP1Winner[5];
	Sprite* fdwP2Winner[5];
	bool fdwFlashWinner;

	// Practice Mode
	Sprite* fdwPracticeSign;
};

#endif // FDWGAME_H