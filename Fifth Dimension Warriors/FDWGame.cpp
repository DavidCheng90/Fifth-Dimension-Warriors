#include "FDWGame.h"
#include <stdlib.h>
#include <time.h>
#include "resource.h"

FDWGame::FDWGame(HINSTANCE hAppInst, HWND hMainWnd)
{
	// General
	fdwAppInst = hAppInst;
	fdwMainWnd = hMainWnd;
	fdwCurrScreen = StrScreen;
	fdwCurrMode = ChallengerMode;
	fdwCurrLevel = EasyLevel;
	fdwTitle = L"Fifth Dimension Warriors: Start Screen";

	for (int a = 0; a < 11; ++a)
		fdwTimeElapsed[a] = 0.0f;

	fdwFrame[0] = 0;
	fdwFrame[1] = 0;

	fdwMusicOn = true;
	for (int b = 0; b < 6; ++b)
		fdwSongOn[b] = false;
	fdwCurrSong = 0;
	
	// Start Screen
	Circle bc;
	Vec2 p0(500.0f, 350.0f);
	Vec2 v0(0.0f, 0.0f);
	fdwStrScreen = new Sprite(hAppInst, IDB_STRSCREEN, IDB_STRSCREENMASK, bc, p0, v0);
	p0.x = 499.0f;
	p0.y = 349.5f;
	fdwStrTitle = new Sprite(hAppInst, IDB_STR_TITLE, IDB_STR_TITLEMASK, bc, p0, v0);
	p0.x = 501.0f;
	p0.y = 509.5f;
	fdwStrPlay = new Sprite(hAppInst, IDB_STR_PLAY, IDB_STR_PLAYMASK, bc, p0, v0);
	p0.y = 609.5f;
	fdwStrExit = new Sprite(hAppInst, IDB_STR_EXIT, IDB_STR_PLAYMASK, bc, p0, v0);

	fdwStrPlayBut = Rect(391, 474, 611, 545);
	fdwStrExitBut = Rect(391, 574, 611, 645);

	p0.x = -50.0f;
	p0.y = -50.0f;
	fdwQuattroAtk[0] = new Sprite(hAppInst, IDB_QUATTRO_Q1, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	fdwQuattroAtk[1] = new Sprite(hAppInst, IDB_QUATTRO_Q2, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	fdwQuattroAtk[2] = new Sprite(hAppInst, IDB_QUATTRO_Q3, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	fdwQuattroAtk[3] = new Sprite(hAppInst, IDB_QUATTRO_Q4, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	fdwQuattroAtk[4] = new Sprite(hAppInst, IDB_QUATTRO_Q5, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	fdwQuattroAtk[5] = new Sprite(hAppInst, IDB_QUATTRO_Q6, IDB_QUATTRO_Q1MASK, bc, p0, v0);
	fdwQuattroAtk[6] = new Sprite(hAppInst, IDB_QUATTRO_Q7, IDB_QUATTRO_Q7MASK, bc, p0, v0);
	fdwQuattroAtk[7] = new Sprite(hAppInst, IDB_QUATTRO_Q8, IDB_QUATTRO_Q7MASK, bc, p0, v0);
	fdwQuattroAtk[8] = new Sprite(hAppInst, IDB_QUATTRO_Q9, IDB_QUATTRO_Q7MASK, bc, p0, v0);
	fdwSeraphinaAtk[0] = new Sprite(hAppInst, IDB_SERAPHINA_Q1, IDB_SERAPHINA_Q1MASK, bc, p0, v0);
	fdwSeraphinaAtk[1] = new Sprite(hAppInst, IDB_SERAPHINA_Q2, IDB_SERAPHINA_Q1MASK, bc, p0, v0);
	fdwSeraphinaAtk[2] = new Sprite(hAppInst, IDB_SERAPHINA_Q4, IDB_SERAPHINA_Q1MASK, bc, p0, v0);
	fdwDimitriAtk[0] = new Sprite(hAppInst, IDB_DIMITRI_Q1, IDB_DIMITRI_Q1MASK, bc, p0, v0);
	fdwDimitriAtk[1] = new Sprite(hAppInst, IDB_DIMITRI_Q2, IDB_DIMITRI_Q2MASK, bc, p0, v0);
	fdwDimitriAtk[2] = new Sprite(hAppInst, IDB_DIMITRI_Q3, IDB_DIMITRI_Q3MASK, bc, p0, v0);
	fdwDimitriAtk[3] = new Sprite(hAppInst, IDB_DIMITRI_Q1, IDB_DIMITRI_Q1MASK, bc, p0, v0);
	fdwDimitriAtk[4] = new Sprite(hAppInst, IDB_DIMITRI_Q2, IDB_DIMITRI_Q2MASK, bc, p0, v0);
	fdwDimitriAtk[5] = new Sprite(hAppInst, IDB_DIMITRI_Q3, IDB_DIMITRI_Q3MASK, bc, p0, v0);
	fdwLiuJiaoAtk[0] = new Sprite(hAppInst, IDB_LIUJIAO_Q1, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	fdwLiuJiaoAtk[1] = new Sprite(hAppInst, IDB_LIUJIAO_Q2, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	fdwLiuJiaoAtk[2] = new Sprite(hAppInst, IDB_LIUJIAO_Q3, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	fdwLiuJiaoAtk[3] = new Sprite(hAppInst, IDB_LIUJIAO_Q1, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	fdwLiuJiaoAtk[4] = new Sprite(hAppInst, IDB_LIUJIAO_Q2, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	fdwLiuJiaoAtk[5] = new Sprite(hAppInst, IDB_LIUJIAO_Q3, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	fdwLiuJiaoAtk[6] = new Sprite(hAppInst, IDB_LIUJIAO_Q1, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	fdwLiuJiaoAtk[7] = new Sprite(hAppInst, IDB_LIUJIAO_Q2, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	fdwLiuJiaoAtk[8] = new Sprite(hAppInst, IDB_LIUJIAO_Q3, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	fdwLiuJiaoAtk[9] = new Sprite(hAppInst, IDB_LIUJIAO_Q1, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	fdwLiuJiaoAtk[10] = new Sprite(hAppInst, IDB_LIUJIAO_Q2, IDB_LIUJIAO_Q1MASK, bc, p0, v0);
	fdwLiuJiaoAtk[11] = new Sprite(hAppInst, IDB_LIUJIAO_Q3, IDB_LIUJIAO_Q1MASK, bc, p0, v0);

	fdwScreenBounds = Rect(0, 0, 1000, 700);
	fdwAttackBounds = Rect(-30, -30, 1030, 730);

	fdwAttackStage[0] = true;
	fdwAttackStage[1] = false;
	fdwAttackStage[2] = false;
	for (int b = 0; b < 6; ++b)
		fdwRandNumber[b] = 1;
	for (int c = 0; c < 4; ++c)
	{
		fdwAttackOn[c] = false;
		fdwAttackFrame[c] = 0;
		fdwSpotlightOn[c] = false;
	}
	fdwStartSide = 1020.0f;
	fdwLiuJiaoStage = 0;
	fdwStartAnimation = false;

	// Select Screen
	p0.x = 500.0f;
	p0.y = 350.0f;
	fdwSltScreen = new Sprite(hAppInst, IDB_SLTSCREEN, IDB_STRSCREENMASK, bc, p0, v0);
	p0.y = -50.0f;
	fdwSltSign = new Sprite(hAppInst, IDB_SLT_SIGN, IDB_SLT_SIGNMASK, bc, p0, v0);

	fdwSignDrop = true;

	p0.x = 126.0f;
	p0.y = 226.0f;
	fdwQuattro[0] = new Sprite(hAppInst, IDB_QUATTRO_1A, IDB_QUATTRO_1AMASK, bc, p0, v0);
	fdwQuattro[1] = new Sprite(hAppInst, IDB_QUATTRO_1B, IDB_QUATTRO_1BMASK, bc, p0, v0);
	fdwQuattro[2] = new Sprite(hAppInst, IDB_QUATTRO_1C, IDB_QUATTRO_1CMASK, bc, p0, v0);
	fdwQuattro[3] = new Sprite(hAppInst, IDB_QUATTRO_1D, IDB_QUATTRO_1DMASK, bc, p0, v0);
	p0.x = 375.0f;
	fdwSeraphina[0] = new Sprite(hAppInst, IDB_SERAPHINA_1A, IDB_SERAPHINA_1AMASK, bc, p0, v0);
	fdwSeraphina[1] = new Sprite(hAppInst, IDB_SERAPHINA_1B, IDB_SERAPHINA_1BMASK, bc, p0, v0);
	fdwSeraphina[2] = new Sprite(hAppInst, IDB_SERAPHINA_1C, IDB_SERAPHINA_1CMASK, bc, p0, v0);
	fdwSeraphina[3] = new Sprite(hAppInst, IDB_SERAPHINA_1D, IDB_SERAPHINA_1DMASK, bc, p0, v0);
	p0.x = 625.0f;
	fdwDimitri[0] = new Sprite(hAppInst, IDB_DIMITRI_1A, IDB_DIMITRI_1AMASK, bc, p0, v0);
	fdwDimitri[1] = new Sprite(hAppInst, IDB_DIMITRI_1B, IDB_DIMITRI_1BMASK, bc, p0, v0);
	fdwDimitri[2] = new Sprite(hAppInst, IDB_DIMITRI_1C, IDB_DIMITRI_1CMASK, bc, p0, v0);
	fdwDimitri[3] = new Sprite(hAppInst, IDB_DIMITRI_1D, IDB_DIMITRI_1DMASK, bc, p0, v0);
	p0.x = 876.0f;
	fdwLiuJiao[0] = new Sprite(hAppInst, IDB_LIUJIAO_1A, IDB_LIUJIAO_1AMASK, bc, p0, v0);
	fdwLiuJiao[1] = new Sprite(hAppInst, IDB_LIUJIAO_1B, IDB_LIUJIAO_1BMASK, bc, p0, v0);
	fdwLiuJiao[2] = new Sprite(hAppInst, IDB_LIUJIAO_1C, IDB_LIUJIAO_1CMASK, bc, p0, v0);
	fdwLiuJiao[3] = new Sprite(hAppInst, IDB_LIUJIAO_1D, IDB_LIUJIAO_1DMASK, bc, p0, v0);

	fdwRectQuattro = Rect(0, 0, 250, 700);
	fdwRectSeraphina = Rect(251, 0, 500, 700);
	fdwRectDimitri = Rect(501, 0, 750, 700);
	fdwRectLiuJiao = Rect(751, 0, 1000, 700);

	// Game Screen
	fdwWarriors = new Warrior(hAppInst);

	p0.x = 500.0f;
	p0.y = 305.0f;
	fdwBattleArena[0] = new Sprite(hAppInst, IDB_BATTLEARENA1, IDB_BATTLEARENAMASK, bc, p0, v0);
	fdwBattleArena[1] = new Sprite(hAppInst, IDB_BATTLEARENA2, IDB_BATTLEARENAMASK, bc, p0, v0);
	fdwBattleArena[2] = new Sprite(hAppInst, IDB_BATTLEARENA3, IDB_BATTLEARENAMASK, bc, p0, v0);
	p0.y = 655.0f;
	fdwBattleBar = new Sprite(hAppInst, IDB_BAR, IDB_BARMASK, bc, p0, v0);
	p0.x = 100.5f;
	p0.y = 674.5f;
	fdwP1Name[0] = new Sprite(hAppInst, IDB_NAME_1A, IDB_NAME_1MASK, bc, p0, v0);
	fdwP1Name[1] = new Sprite(hAppInst, IDB_NAME_1B, IDB_NAME_1MASK, bc, p0, v0);
	fdwP1Name[2] = new Sprite(hAppInst, IDB_NAME_1C, IDB_NAME_1MASK, bc, p0, v0);
	fdwP1Name[3] = new Sprite(hAppInst, IDB_NAME_1D, IDB_NAME_1MASK, bc, p0, v0);
	p0.x = 756.5f;
	p0.y = 674.5f;
	fdwP2Name[0] = new Sprite(hAppInst, IDB_NAME_2A, IDB_NAME_2MASK, bc, p0, v0);
	fdwP2Name[1] = new Sprite(hAppInst, IDB_NAME_2B, IDB_NAME_2MASK, bc, p0, v0);
	fdwP2Name[2] = new Sprite(hAppInst, IDB_NAME_2C, IDB_NAME_2MASK, bc, p0, v0);
	fdwP2Name[3] = new Sprite(hAppInst, IDB_NAME_2D, IDB_NAME_2MASK, bc, p0, v0);

	fdwBattleBounds = Rect(0, 0, 1000, 610);

	fdwStartGame = false;

	// Challenger & Quick & Practice Mode
	p0.x = 500.0f;
	p0.y = 305.0f;
	fdwAnnouncement[0] = new Sprite(hAppInst, IDB_ANNOUNCE_1, IDB_ANNOUNCE_1MASK, bc, p0, v0);
	fdwAnnouncement[1] = new Sprite(hAppInst, IDB_ANNOUNCE_2, IDB_ANNOUNCE_1MASK, bc, p0, v0);
	fdwAnnouncement[2] = new Sprite(hAppInst, IDB_ANNOUNCE_3, IDB_ANNOUNCE_1MASK, bc, p0, v0);
	fdwAnnouncement[3] = new Sprite(hAppInst, IDB_ANNOUNCE_4, IDB_ANNOUNCE_1MASK, bc, p0, v0);
	fdwAnnouncement[4] = new Sprite(hAppInst, IDB_ANNOUNCE_5, IDB_ANNOUNCE_1MASK, bc, p0, v0);
	p0.y = 457.5f;
	fdwAnnouncement[5] = new Sprite(hAppInst, IDB_ANNOUNCE_6, IDB_ANNOUNCE_6MASK, bc, p0, v0);

	for (int d = 0; d < 3; ++d)
		fdwAnnounce[d] = false;

	p0.y = 570.0f;
	fdwPracticeSign = new Sprite(hAppInst, IDB_PRACTICE_SIGN, IDB_PRACTICE_SIGNMASK, bc, p0, v0);

	p0.x = 278.5f;
	p0.y = 674.5f;
	fdwP1Winner[0] = new Sprite(hAppInst, IDB_WINNER_1, IDB_WINNER_MASK, bc, p0, v0);
	fdwP1Winner[1] = new Sprite(hAppInst, IDB_WINNER_2, IDB_WINNER_MASK, bc, p0, v0);
	fdwP1Winner[2] = new Sprite(hAppInst, IDB_WINNER_3, IDB_WINNER_MASK, bc, p0, v0);
	fdwP1Winner[3] = new Sprite(hAppInst, IDB_WINNER_4, IDB_WINNER_MASK, bc, p0, v0);
	fdwP1Winner[4] = new Sprite(hAppInst, IDB_WINNER_5, IDB_WINNER_MASK, bc, p0, v0);
	p0.x = 932.5f;
	p0.y = 674.5f;
	fdwP2Winner[0] = new Sprite(hAppInst, IDB_WINNER_1, IDB_WINNER_MASK, bc, p0, v0);
	fdwP2Winner[1] = new Sprite(hAppInst, IDB_WINNER_2, IDB_WINNER_MASK, bc, p0, v0);
	fdwP2Winner[2] = new Sprite(hAppInst, IDB_WINNER_3, IDB_WINNER_MASK, bc, p0, v0);
	fdwP2Winner[3] = new Sprite(hAppInst, IDB_WINNER_4, IDB_WINNER_MASK, bc, p0, v0);
	fdwP2Winner[4] = new Sprite(hAppInst, IDB_WINNER_5, IDB_WINNER_MASK, bc, p0, v0);
	
	fdwFlashWinner = true;
}

FDWGame::~FDWGame()
{
	delete fdwStrScreen;
	delete fdwStrTitle;
	delete fdwStrPlay;
	delete fdwStrExit;

	for (int a = 0; a < 12; ++a)
	{
		if (a < 9)
			delete fdwQuattroAtk[a];
		if (a < 3)
			delete fdwSeraphinaAtk[a];
		if (a < 6)
			delete fdwDimitriAtk[a];
		delete fdwLiuJiaoAtk[a];
	}

	delete fdwSltScreen;
	delete fdwSltSign;

	for (int b = 0; b < 4; ++b)
	{
		delete fdwQuattro[b];
		delete fdwSeraphina[b];
		delete fdwDimitri[b];
		delete fdwLiuJiao[b];

		delete fdwP1Name[b];
		delete fdwP2Name[b];
	}

	delete fdwWarriors;

	for (int c = 0; c < 3; ++c)
		delete fdwBattleArena[c];

	delete fdwBattleBar;

	for (int d = 0; d < 6; ++d)
		delete fdwAnnouncement[d];

	delete fdwPracticeSign;

	for (int e = 0; e < 5; ++e)
	{
		delete fdwP1Winner[e];
		delete fdwP2Winner[e];
	}
}

void FDWGame::updateScreen(float dt)
{
	switch (fdwCurrScreen)
	{
	case StrScreen:

		fdwPlayMusic();

		if (fdwStartAnimation)
			fdwStrScreenAnimation(dt);

		break;

	case SltScreen:

		fdwPlayMusic();

		fdwTimeElapsed[6] += dt;

		if (fdwTimeElapsed[6] >= 0.01f && fdwSignDrop)
		{
			fdwSltSign->mPosition.y += 3.0f;
			if (fdwSltSign->mPosition.y >= 750.0f)
				fdwSignDrop = false;
			fdwTimeElapsed[6] = 0.0f;
		}

		fdwTimeElapsed[7] += dt;

		if (fdwTimeElapsed[7] >= 0.2f)
		{
			++fdwFrame[0];
			if (fdwFrame[0] > 3)
				fdwFrame[0] = 0;
			fdwTimeElapsed[7] = 0.0f;
		}
		break;

	case GameScreen:

		if (fdwCurrMode == PracticeMode)
			fdwWarriors->updateWarriors(dt);
		else
		{
			if (fdwAnnounce[0])
			{
				fdwTimeElapsed[8] += dt;

				if (fdwTimeElapsed[8] < 1.5f)
					fdwFrame[0] = 0;
				if (fdwTimeElapsed[8] >= 1.5f && fdwTimeElapsed[8] < 3.0f)
					fdwFrame[0] = 1;
				if (fdwTimeElapsed[8] >= 3.0f && fdwTimeElapsed[8] < 4.0f)
					fdwFrame[0] = 2;
				if (fdwTimeElapsed[8] >= 4.0f)
				{
					fdwStartGame = true;
					fdwAnnounce[0] = false;
					fdwTimeElapsed[8] = 0.0f;
				}
			}

			if (fdwStartGame)
				fdwWarriors->updateWarriors(dt);

			if (fdwWarriors->endGame() != 0)
			{
				fdwStartGame = false;

				fdwTimeElapsed[9] += dt;

				if (fdwWarriors->endGame() == 1 && fdwTimeElapsed[9] >= 0.2f && fdwFlashWinner)
				{
					fdwFrame[0] = 3;
					fdwAnnounce[1] = true;
					if (fdwPlayer1 == L"Quattro")
						fdwFrame[1] = 0;
					if (fdwPlayer1 == L"Seraphina")
						fdwFrame[1] = 1;
					if (fdwPlayer1 == L"Dimitri")
						fdwFrame[1] = 2;
					if (fdwPlayer1 == L"Liu Jiao")
						fdwFrame[1] = 3;
					fdwFlashWinner = false;
					fdwTimeElapsed[9] = 0.0f;
				}
				else if (fdwWarriors->endGame() == 2 && fdwTimeElapsed[9] >= 0.2f && fdwFlashWinner)
				{
					fdwFrame[0] = 4;
					fdwAnnounce[1] = true;
					if (fdwPlayer2 == L"Quattro")
						fdwFrame[1] = 0;
					if (fdwPlayer2 == L"Seraphina")
						fdwFrame[1] = 1;
					if (fdwPlayer2 == L"Dimitri")
						fdwFrame[1] = 2;
					if (fdwPlayer2 == L"Liu Jiao")
						fdwFrame[1] = 3;
					fdwFlashWinner = false;
					fdwTimeElapsed[9] = 0.0f;
				}
				if (fdwTimeElapsed[9] >= 0.2f && !fdwFlashWinner)
				{
					fdwFrame[1] = 4;
					fdwFlashWinner = true;
					fdwTimeElapsed[9] = 0.0f;
				}

				if (!fdwAnnounce[2])
					fdwTimeElapsed[10] += dt;

				if (!fdwAnnounce[2] && fdwTimeElapsed[10] >= 3.0f)
				{
					if (fdwCurrMode == ChallengerMode && fdwWarriors->endGame() == 1)
					{
						++fdwChallenge;
						if (fdwChallenge == 2)
							fdwMatch = L"Match #2";
						if (fdwChallenge == 3)
							fdwMatch = L"Match #3";
						if (fdwChallenge == 4)
							fdwMatch = L"Congratulations!";
					}

					fdwAnnounce[2] = true;
					fdwTimeElapsed[10] = 0.0f;
				}
			}
		}
		break;
	}
}

void FDWGame::drawScreen(HDC hBackBufferDC, HDC hSpriteDC)
{
	GetCursorPos(&fdwMousePos);
	ScreenToClient(fdwMainWnd, &fdwMousePos);
	Vec2 MousePos((float)fdwMousePos.x, (float)fdwMousePos.y);

	switch (fdwCurrScreen)
	{
	case StrScreen:

		fdwStrScreen->draw(hBackBufferDC, hSpriteDC);

		if (fdwAttackOn[0])
			fdwQuattroAtk[fdwAttackFrame[0]]->draw(hBackBufferDC, hSpriteDC);
		if (fdwAttackOn[1])
			for (int a = 0; a < 3; ++a)
				fdwSeraphinaAtk[a]->draw(hBackBufferDC, hSpriteDC);
		if (fdwAttackOn[2])
			for (int b = 0; b < 2; ++b)
				fdwDimitriAtk[fdwAttackFrame[2] + b * 3]->draw(hBackBufferDC, hSpriteDC);
		if (fdwAttackOn[3])
			for (int c = 0; c < 4; ++c)
				fdwLiuJiaoAtk[fdwAttackFrame[3] + c * 3]->draw(hBackBufferDC, hSpriteDC);

		fdwStrTitle->draw(hBackBufferDC, hSpriteDC);
		if (fdwStrPlayBut.isPtInside(MousePos))
			fdwStrPlay->draw(hBackBufferDC, hSpriteDC);
		if (fdwStrExitBut.isPtInside(MousePos))
			fdwStrExit->draw(hBackBufferDC, hSpriteDC);

		fdwStartAnimation = true;
		break;

	case SltScreen:

		fdwSltScreen->draw(hBackBufferDC, hSpriteDC);

		if (fdwSltSign->mPosition.y >= 226.0f)
		{
			if (fdwRectQuattro.isPtInside(MousePos))
				fdwQuattro[fdwFrame[0]]->draw(hBackBufferDC, hSpriteDC);
			else
				fdwQuattro[0]->draw(hBackBufferDC, hSpriteDC);

			if (fdwRectSeraphina.isPtInside(MousePos))
				fdwSeraphina[fdwFrame[0]]->draw(hBackBufferDC, hSpriteDC);
			else
				fdwSeraphina[0]->draw(hBackBufferDC, hSpriteDC);

			if (fdwRectDimitri.isPtInside(MousePos))
				fdwDimitri[fdwFrame[0]]->draw(hBackBufferDC, hSpriteDC);
			else
				fdwDimitri[0]->draw(hBackBufferDC, hSpriteDC);

			if (fdwRectLiuJiao.isPtInside(MousePos))
				fdwLiuJiao[fdwFrame[0]]->draw(hBackBufferDC, hSpriteDC);
			else
				fdwLiuJiao[0]->draw(hBackBufferDC, hSpriteDC);
		}

		if (fdwSignDrop)
			fdwSltSign->draw(hBackBufferDC, hSpriteDC);
		break;

	case GameScreen:

		fdwBattleArena[fdwArena]->draw(hBackBufferDC, hSpriteDC);
		fdwWarriors->drawWarriors(hBackBufferDC, hSpriteDC);
		fdwBattleBar->draw(hBackBufferDC, hSpriteDC);

		if (fdwPlayer1 == L"Quattro")
			fdwP1Name[0]->draw(hBackBufferDC, hSpriteDC);
		if (fdwPlayer1 == L"Seraphina")
			fdwP1Name[1]->draw(hBackBufferDC, hSpriteDC);
		if (fdwPlayer1 == L"Dimitri")
			fdwP1Name[2]->draw(hBackBufferDC, hSpriteDC);
		if (fdwPlayer1 == L"Liu Jiao")
			fdwP1Name[3]->draw(hBackBufferDC, hSpriteDC);

		if (fdwPlayer2 == L"Quattro")
			fdwP2Name[0]->draw(hBackBufferDC, hSpriteDC);
		if (fdwPlayer2 == L"Seraphina")
			fdwP2Name[1]->draw(hBackBufferDC, hSpriteDC);
		if (fdwPlayer2 == L"Dimitri")
			fdwP2Name[2]->draw(hBackBufferDC, hSpriteDC);
		if (fdwPlayer2 == L"Liu Jiao")
			fdwP2Name[3]->draw(hBackBufferDC, hSpriteDC);

		fdwWarriors->drawBarTools(hBackBufferDC, hSpriteDC);

		if (fdwCurrMode == PracticeMode)
			fdwPracticeSign->draw(hBackBufferDC, hSpriteDC);
		else
		{
			if (!fdwStartGame && fdwWarriors->endGame() == 0)
				fdwAnnounce[0] = true;

			if (fdwAnnounce[0] || fdwAnnounce[1])
				fdwAnnouncement[fdwFrame[0]]->draw(hBackBufferDC, hSpriteDC);

			if (fdwWarriors->endGame() == 1)
				fdwP1Winner[fdwFrame[1]]->draw(hBackBufferDC, hSpriteDC);
			if (fdwWarriors->endGame() == 2)
				fdwP2Winner[fdwFrame[1]]->draw(hBackBufferDC, hSpriteDC);

			if (fdwAnnounce[2])
				fdwAnnouncement[5]->draw(hBackBufferDC, hSpriteDC);
		}
		break;
	}
}

wstring FDWGame::Title()
{
	return fdwTitle;
}

wstring FDWGame::Player1()
{
	return fdwPlayer1;
}

wstring FDWGame::Player2()
{
	return fdwPlayer2;
}

wstring FDWGame::Match()
{
	return fdwMatch;
}

int FDWGame::leftClickScreen(int CaseID)
{
	GetCursorPos(&fdwMousePos);
	ScreenToClient(fdwMainWnd, &fdwMousePos);
	Vec2 MousePos((float)fdwMousePos.x, (float)fdwMousePos.y);

	srand((unsigned)time(NULL));

	switch (fdwCurrScreen)
	{
	case StrScreen:

		if (fdwStrPlayBut.isPtInside(MousePos))
		{
			fdwCurrScreen = ModeScreen;
			fdwMatch = L"Match #1";
			fdwSignDrop = true;
			fdwSltSign->mPosition.y = -50.0f;
			return 1;
		}
		if (fdwStrExitBut.isPtInside(MousePos))
		{
			fdwResetStrScreen();
			return 4;
		}
		break;

	case ModeScreen:

		fdwResetStrScreen();

		switch (CaseID)
		{
		case IDC_CHALLENGERMODE:
			fdwCurrMode = ChallengerMode;
			fdwMatch = L"Match #1";
			return 0;
		case IDC_QUICKMODE:
			fdwCurrMode = QuickMode;
			fdwMatch = L"No Match ID";
			return 0;
		case IDC_PRACTICEMODE:
			fdwCurrMode = PracticeMode;
			fdwMatch = L"No Match ID";
			return 0;
		case ID_MODEBOX_OK:
			fdwTitle = L"Fifth Dimension Warriors: Select Your Warrior";
			if (fdwCurrMode == PracticeMode)
			{
				fdwCurrScreen = SltScreen;
				return 0;
			}
			else
			{
				fdwCurrScreen = LvlScreen;
				fdwChallenge = 1;
				fdwP2Level = 1;
				return 1;
			}
		case ID_MODEBOX_BACK:
			fdwCurrScreen = StrScreen;
			fdwMatch = L"No Match ID";
			return 0;
		}
		break;

	case LvlScreen:

		switch (CaseID)
		{
		case IDC_EASYLEVEL:
			fdwCurrLevel = EasyLevel;
			fdwP2Level = 1;
			return 0;
		case IDC_HARDLEVEL:
			fdwCurrLevel = HardLevel;
			fdwP2Level = 2;
			return 0;
		case ID_LEVELBOX_OK:
			fdwCurrScreen = SltScreen;
			return 0;
		case ID_LEVELBOX_BACK:
			fdwCurrScreen = ModeScreen;
			fdwTitle = L"Fifth Dimension Warriors: Start Screen";
			return 0;
		}
		break;

	case SltScreen:

		if (fdwSltSign->mPosition.y >= 300.0f)
		{
			bool sameName = true;

			if (fdwRectQuattro.isPtInside(MousePos))
				fdwPlayer1 = L"Quattro";
			if (fdwRectSeraphina.isPtInside(MousePos))
				fdwPlayer1 = L"Seraphina";
			if (fdwRectDimitri.isPtInside(MousePos))
				fdwPlayer1 = L"Dimitri";
			if (fdwRectLiuJiao.isPtInside(MousePos))
				fdwPlayer1 = L"Liu Jiao";

			if (fdwCurrMode == ChallengerMode)
			{
				if (fdwPlayer1 == L"Quattro" || fdwPlayer1 == L"Dimitri")
					fdwPlayer2 = L"Seraphina";
				else if (fdwPlayer1 == L"Seraphina" || fdwPlayer1 == L"Liu Jiao")
					fdwPlayer2 = L"Dimitri";
			}
			else
				while (sameName)
				{
					fdwRandOppt = rand() % 4;
					if (fdwRandOppt == 0)
						fdwPlayer2 = L"Quattro";
					if (fdwRandOppt == 1)
						fdwPlayer2 = L"Seraphina";
					if (fdwRandOppt == 2)
						fdwPlayer2 = L"Dimitri";
					if (fdwRandOppt == 3)
						fdwPlayer2 = L"Liu Jiao";
					if (fdwPlayer1 != fdwPlayer2)
						sameName = false;
				}

			fdwCurrScreen = MtpScreen;
			return 2;
		}
		else
			return 0;
		break;

	case MtpScreen:

		fdwAnnounce[0] = false;
		fdwAnnounce[1] = false;
		fdwAnnounce[2] = false;

		delete fdwWarriors;
		fdwWarriors = 0;
		fdwWarriors = new Warrior(fdwAppInst);

		fdwWarriors->getPlayerNames(fdwPlayer1, fdwPlayer2);
		fdwWarriors->getP2Level(fdwP2Level);
		if (fdwCurrMode == PracticeMode)
			fdwWarriors->turnP2off(true);

		switch (CaseID)
		{
		case ID_MATCHBOX_OK:
			fdwCurrScreen = GameScreen;

			if (fdwCurrMode == ChallengerMode)
				fdwTitle = L"Fifth Dimension Warriors: Challenger Mode - " + fdwMatch;
			if (fdwCurrMode == QuickMode)
				fdwTitle = L"Fifth Dimension Warriors: Quick Mode";
			if (fdwCurrMode == PracticeMode)
				fdwTitle = L"Fifth Dimension Warriors: Practice Mode";

			if (fdwCurrMode == ChallengerMode)
			{
				if (fdwChallenge == 1)
					fdwArena = 0;
				if (fdwChallenge == 2)
					fdwArena = 1;
				if (fdwChallenge == 3)
					fdwArena = 2;
			}
			else
				fdwArena = rand() % 3;

			fdwSignDrop = true;
			fdwSltSign->mPosition.y = -50.0f;

			fdwPlayMusic();
			return 0;

		case ID_MATCHBOX_BACK:
			if (fdwTitle != L"Fifth Dimension Warriors: Select Your Warrior")
			{
				fdwTitle = L"Fifth Dimension Warriors: Start Screen";
				fdwCurrScreen = StrScreen;
				fdwCurrMode = ChallengerMode;
				fdwCurrLevel = EasyLevel;
			}
			else
				fdwCurrScreen = SltScreen;
			return 0;
		}
		break;

	case GameScreen:

		if (fdwWarriors->endGame() != 0 && fdwAnnounce[2])
		{
			if (fdwCurrMode == ChallengerMode && fdwWarriors->endGame() == 1 && Match() != L"Congratulations!")
			{
				if (fdwPlayer1 == L"Quattro" && fdwChallenge == 2)
					fdwPlayer2 = L"Dimitri";
				if (fdwPlayer1 == L"Quattro" && fdwChallenge == 3)
					fdwPlayer2 = L"Liu Jiao";

				if (fdwPlayer1 == L"Seraphina" && fdwChallenge == 2)
					fdwPlayer2 = L"Quattro";
				if (fdwPlayer1 == L"Seraphina" && fdwChallenge == 3)
					fdwPlayer2 = L"Liu Jiao";

				if (fdwPlayer1 == L"Dimitri" && fdwChallenge == 2)
					fdwPlayer2 = L"Liu Jiao";
				if (fdwPlayer1 == L"Dimitri" && fdwChallenge == 3)
					fdwPlayer2 = L"Quattro";

				if (fdwPlayer1 == L"Liu Jiao" && fdwChallenge == 2)
					fdwPlayer2 = L"Seraphina";
				if (fdwPlayer1 == L"Liu Jiao" && fdwChallenge == 3)
					fdwPlayer2 = L"Quattro";

				fdwCurrScreen = MtpScreen;
				return 2;
			}
			else
			{
				fdwCurrScreen = RsltScreen;
				return 3;
			}
		}
		break;

	case RsltScreen:

		fdwAnnounce[0] = false;
		fdwAnnounce[1] = false;
		fdwAnnounce[2] = false;

		delete fdwWarriors;
		fdwWarriors = 0;
		fdwWarriors = new Warrior(fdwAppInst);

		switch (CaseID)
		{
		case ID_RESULT_PLAYBUTTON:
			if (fdwCurrMode == ChallengerMode && fdwChallenge == 4)
			{
				fdwChallenge = 1;
				fdwMatch = L"Match #1";
				fdwCurrScreen = SltScreen;
				fdwTitle = L"Fifth Dimension Warriors: Select Your Warrior";
			}
			else
			{
				fdwWarriors->getPlayerNames(fdwPlayer1, fdwPlayer2);
				fdwWarriors->getP2Level(fdwP2Level);
				if (fdwCurrMode == PracticeMode)
					fdwWarriors->turnP2off(true);
				fdwCurrScreen = GameScreen;
			}
			return 0;

		case ID_RESULT_QUITBUTTON:
			fdwTitle = L"Fifth Dimension Warriors: Start Screen";
			fdwCurrScreen = StrScreen;
			fdwCurrMode = ChallengerMode;
			fdwCurrLevel = EasyLevel;
			return 0;
		}
		break;
	}
	return 0;
}

void FDWGame::rightClickScreen()
{
	if (fdwCurrScreen == GameScreen && (fdwStartGame || fdwCurrMode == PracticeMode))
	{
		GetCursorPos(&fdwMousePos);
		ScreenToClient(fdwMainWnd, &fdwMousePos);

		if (fdwBattleBounds.isPtInside(fdwMousePos))
		{
			fdwNewMousePos.x = (float)fdwMousePos.x;
			fdwNewMousePos.y = (float)fdwMousePos.y;
			fdwWarriors->getNewMousePos(fdwNewMousePos);
		}
	}
}

void FDWGame::pressQWER(wchar_t key)
{
	if (fdwCurrScreen == GameScreen && (fdwStartGame || fdwCurrMode == PracticeMode))
	{
		GetCursorPos(&fdwMousePos);
		ScreenToClient(fdwMainWnd, &fdwMousePos);

		if (fdwBattleBounds.isPtInside(fdwMousePos))
		{
			fdwNewTargetPos.x = (float)fdwMousePos.x;
			fdwNewTargetPos.y = (float)fdwMousePos.y;
			fdwWarriors->getNewTargetPos(key, fdwNewTargetPos);
		}
	}
}

bool FDWGame::pressP()
{
	if (fdwCurrScreen == GameScreen && fdwCurrMode == PracticeMode)
	{
		fdwCurrScreen = RsltScreen;
		return true;
	}
	else
		return false;
}

void FDWGame::useMenu(int CaseID)
{
	if (CaseID == ID_FILE_STRSCREEN)
	{
		fdwResetStrScreen();

		fdwStartGame = false;
		fdwAnnounce[0] = false;
		fdwAnnounce[1] = false;
		fdwAnnounce[2] = false;

		delete fdwWarriors;
		fdwWarriors = 0;
		fdwWarriors = new Warrior(fdwAppInst);

		fdwTitle = L"Fifth Dimension Warriors: Start Screen";
		fdwCurrScreen = StrScreen;
		fdwCurrMode = ChallengerMode;
		fdwCurrLevel = EasyLevel;
	}
}

void FDWGame::turnMusicOn()
{
	fdwMusicOn = true;
	fdwPlayMusic();
}

void FDWGame::turnMusicOff()
{
	fdwMusicOn = false;
	for (int a = 0; a < 6; ++a)
		fdwSongOn[a] = false;
	fdwCurrSong = 0;
	fdwPlayMusic();
}

void FDWGame::fdwPlayMusic()
{
	if (!fdwMusicOn)
		PlaySound(NULL, NULL, SND_PURGE);
	else
	{
		switch (fdwCurrScreen)
		{
		case StrScreen:
		case SltScreen:
			if (!fdwSongOn[0])
			{
				PlaySound(L"SONG_1.wav", NULL, SND_ASYNC | SND_LOOP);
				songChange(0, fdwCurrSong);
			}
			break;
		case GameScreen:
			if (fdwMatch == L"Match #1" && !fdwSongOn[1])
			{
				PlaySound(L"SONG_2.wav", NULL, SND_ASYNC | SND_LOOP);
				songChange(1, fdwCurrSong);
			}
			if (fdwMatch == L"Match #2" && !fdwSongOn[2])
			{
				PlaySound(L"SONG_3.wav", NULL, SND_ASYNC | SND_LOOP);
				songChange(2, fdwCurrSong);
			}
			if (fdwMatch == L"Match #3" && !fdwSongOn[3])
			{
				PlaySound(L"SONG_4.wav", NULL, SND_ASYNC | SND_LOOP);
				songChange(3, fdwCurrSong);
			}
			if (fdwCurrMode == QuickMode && !fdwSongOn[4])
			{
				PlaySound(L"SONG_5.wav", NULL, SND_ASYNC | SND_LOOP);
				songChange(4, fdwCurrSong);
			}
			if (fdwCurrMode == PracticeMode && !fdwSongOn[5])
			{
				PlaySound(L"SONG_6.wav", NULL, SND_ASYNC | SND_LOOP);
				songChange(5, fdwCurrSong);
			}
			break;
		}
	}
}

void FDWGame::songChange(int SongOn, int SongOff)
{
	fdwSongOn[SongOn] = true;
	if (SongOn != SongOff)
		fdwSongOn[SongOff] = false;
	fdwCurrSong = SongOn;
	fdwMusicOn = true;
}

void FDWGame::fdwStrScreenAnimation(float dt)
{
	srand((unsigned)time(NULL));

	if (fdwAttackStage[0])
	{
		if (fdwStartSide == -20.0f)
			fdwStartSide = 1020.0f;
		else
			fdwStartSide = -20.0f;

		fdwRandNumber[0] = (rand() % 3) + 1;
		fdwRandNumber[2] = (rand() % 681) + 10;
		fdwRandNumber[3] = (rand() % 681) + 10;

		fdwAttackStage[1] = true;
		fdwAttackStage[0] = false;
	}

	if (fdwAttackStage[1])
	{
		fdwTimeElapsed[0] += dt;

		if (fdwTimeElapsed[0] >= fdwRandNumber[0])
		{
			fdwTimeElapsed[0] = 0.0f;
			fdwAttackStage[2] = true;
			fdwAttackStage[1] = false;
		}
	}

	if (fdwAttackStage[2])
	{
		fdwRandNumber[1] = rand() % 4;

		while (fdwAttackOn[fdwRandNumber[1]])
		{
			fdwRandNumber[1] = rand() % 4;
		}

		fdwAttackOn[fdwRandNumber[1]] = true;
		fdwAttackStage[2] = false;
	}

	// Quattro's Attack
	if (fdwAttackOn[0])
	{
		static int RandAttack = 1;

		if (fdwQuattroAtk[0]->mVelocity.x == 0.0f && fdwQuattroAtk[0]->mVelocity.y == 0.0f)
		{
			for (int a = 0; a < 9; ++a)
			{
				fdwQuattroAtk[a]->mPosition.x = fdwStartSide;
				fdwQuattroAtk[a]->mPosition.y = float(fdwRandNumber[2]);

				if (fdwQuattroAtk[a]->mPosition.x == -20.0f)
					fdwQuattroAtk[a]->mVelocity.x = 1050.0f - fdwQuattroAtk[a]->mPosition.x;
				if (fdwQuattroAtk[a]->mPosition.x == 1020.0f)
					fdwQuattroAtk[a]->mVelocity.x = -50.0f - fdwQuattroAtk[a]->mPosition.x;
				fdwQuattroAtk[a]->mVelocity.y = 0.0f;
				fdwQuattroAtk[a]->mVelocity.normalize() *= 350.0f;
			}

			RandAttack = (rand() % 2) + 1;
			if (RandAttack == 1)
				fdwAttackFrame[0] = 0;
			else
				fdwAttackFrame[0] = 6;
		}

		for (int b = 0; b < 9; ++b)
			fdwQuattroAtk[b]->update(dt);

		fdwTimeElapsed[1] += dt;

		if (fdwTimeElapsed[1] >= 0.15f)
		{
			++fdwAttackFrame[0];
			if (RandAttack == 1 && fdwAttackFrame[0] > 5)
				fdwAttackFrame[0] = 0;
			if (RandAttack == 2 && fdwAttackFrame[0] > 8)
				fdwAttackFrame[0] = 6;

			fdwTimeElapsed[1] = 0.0f;
		}

		if (fdwScreenBounds.isPtInside(fdwQuattroAtk[fdwAttackFrame[0]]->mPosition) && !fdwSpotlightOn[0])
		{
			fdwAttackStage[0] = true;
			fdwSpotlightOn[0] = true;
		}
		if (!fdwAttackBounds.isPtInside(fdwQuattroAtk[fdwAttackFrame[0]]->mPosition))
		{
			for (int c = 0; c < 9; ++c)
			{
				fdwQuattroAtk[c]->mVelocity.x = 0.0f;
				fdwQuattroAtk[c]->mVelocity.y = 0.0f;
			}
			fdwTimeElapsed[1] = 0.0f;
			fdwSpotlightOn[0] = false;
			fdwAttackOn[0] = false;
		}
	}

	// Seraphina's Attack
	if (fdwAttackOn[1])
	{
		if (fdwSeraphinaAtk[2]->mVelocity.x == 0.0f && fdwSeraphinaAtk[2]->mVelocity.y == 0.0f)
		{
			for (int a = 0; a < 3; ++a)
			{
				fdwSeraphinaAtk[a]->mPosition.x = fdwStartSide;
				fdwSeraphinaAtk[a]->mPosition.y = float(fdwRandNumber[2]);

				if (fdwSeraphinaAtk[a]->mPosition.x == -20.0f)
					fdwSeraphinaAtk[a]->mVelocity.x = 1050.0f - fdwSeraphinaAtk[a]->mPosition.x;
				if (fdwSeraphinaAtk[a]->mPosition.x == 1020.0f)
					fdwSeraphinaAtk[a]->mVelocity.x = -50.0f - fdwSeraphinaAtk[a]->mPosition.x;
				fdwSeraphinaAtk[a]->mVelocity.y = 0.0f;
				fdwSeraphinaAtk[a]->mVelocity.normalize() *= 375.0f;
			}
		}

		fdwTimeElapsed[2] += dt;

		for (int b = 0; b < 3; ++b)
			if (fdwTimeElapsed[2] >= b * 0.2f)
				fdwSeraphinaAtk[b]->update(dt);

		if (fdwScreenBounds.isPtInside(fdwSeraphinaAtk[2]->mPosition) && !fdwSpotlightOn[1])
		{
			fdwAttackStage[0] = true;
			fdwSpotlightOn[1] = true;
		}
		if (!fdwAttackBounds.isPtInside(fdwSeraphinaAtk[2]->mPosition))
		{
			for (int c = 0; c < 3; ++c)
			{
				fdwSeraphinaAtk[c]->mVelocity.x = 0.0f;
				fdwSeraphinaAtk[c]->mVelocity.y = 0.0f;
			}
			fdwTimeElapsed[2] = 0.0f;
			fdwSpotlightOn[1] = false;
			fdwAttackOn[1] = false;
		}
	}

	// Dimitri's Attack
	if (fdwAttackOn[2])
	{
		if (fdwDimitriAtk[0]->mVelocity.x == 0.0f && fdwDimitriAtk[3]->mVelocity.x == 0.0f)
		{
			fdwRandNumber[4] = (rand() % 681) + 10;
			fdwRandNumber[5] = (rand() % 681) + 10;

			for (int a = 0; a < 6; ++a)
			{
				fdwDimitriAtk[a]->mPosition.x = fdwStartSide;
				if (a < 3)
					fdwDimitriAtk[a]->mPosition.y = float(fdwRandNumber[2]);
				if (a > 2)
					fdwDimitriAtk[a]->mPosition.y = float(fdwRandNumber[3]);

				if (fdwDimitriAtk[a]->mPosition.x == -20.0f)
					fdwDimitriAtk[a]->mVelocity.x = 1050.0f - fdwDimitriAtk[a]->mPosition.x;
				if (fdwDimitriAtk[a]->mPosition.x == 1020.0f)
					fdwDimitriAtk[a]->mVelocity.x = -50.0f - fdwDimitriAtk[a]->mPosition.x;
				if (a < 3)
					fdwDimitriAtk[a]->mVelocity.y = float(fdwRandNumber[4]) - fdwDimitriAtk[a]->mPosition.y;
				if (a > 2)
					fdwDimitriAtk[a]->mVelocity.y = float(fdwRandNumber[5]) - fdwDimitriAtk[a]->mPosition.y;
				fdwDimitriAtk[a]->mVelocity.normalize() *= 350.0f;
			}
		}

		fdwTimeElapsed[3] += dt;

		if (fdwTimeElapsed[3] >= 0.05f)
		{
			++fdwAttackFrame[2];
			if (fdwAttackFrame[2] > 2)
				fdwAttackFrame[2] = 0;

			fdwTimeElapsed[3] = 0.0f;
		}

		for (int b = 0; b < 6; ++b)
		{
			if (b < 3)
				fdwDimitriAtk[b]->update(dt);
			if (b > 2)
				fdwDimitriAtk[b]->update(dt);
		}

		if (fdwScreenBounds.isPtInside(fdwDimitriAtk[0]->mPosition) && !fdwSpotlightOn[2])
		{
			fdwAttackStage[0] = true;
			fdwSpotlightOn[2] = true;
		}
		if (!fdwAttackBounds.isPtInside(fdwDimitriAtk[0]->mPosition) && !fdwAttackBounds.isPtInside(fdwDimitriAtk[3]->mPosition))
		{
			for (int c = 0; c < 6; ++c)
			{
				fdwDimitriAtk[c]->mVelocity.x = 0.0f;
				fdwDimitriAtk[c]->mVelocity.y = 0.0f;
			}
			fdwTimeElapsed[3] = 0.0f;
			fdwSpotlightOn[2] = false;
			fdwAttackOn[2] = false;
		}
	}

	// Liu Jiao's Attack
	if (fdwAttackOn[3])
	{
		static int RandAttack = 1;

		fdwTimeElapsed[4] += dt;

		if (fdwTimeElapsed[4] >= 0.15f)
		{
			++fdwAttackFrame[3];
			if (fdwAttackFrame[3] > 2)
				fdwAttackFrame[3] = 0;

			fdwTimeElapsed[4] = 0.0f;
		}

		if (fdwLiuJiaoStage == 0)
		{
			RandAttack = (rand() % 2) + 1;

			for (int a = 0; a < 12; ++a)
			{
				if (RandAttack == 1)
				{
					if (a < 6)
					{
						fdwLiuJiaoAtk[a]->mPosition.y = -20.0f;
						if (a < 3)
							fdwLiuJiaoAtk[a]->mPosition.x = -20.0f;
						if (a > 2)
							fdwLiuJiaoAtk[a]->mPosition.x = 1020.0f;
					}
					else
					{
						fdwLiuJiaoAtk[a]->mPosition.y = 720.0f;
						if (a < 9)
							fdwLiuJiaoAtk[a]->mPosition.x = -20.0f;
						if (a > 8)
							fdwLiuJiaoAtk[a]->mPosition.x = 1020.0f;
					}
				}
				else
				{
					fdwLiuJiaoAtk[a]->mPosition.y = -20.0f;
					if (a < 3)
						fdwLiuJiaoAtk[a]->mPosition.x = 20.0f;
					if (a > 2 && a < 6)
						fdwLiuJiaoAtk[a]->mPosition.x = 334.0f;
					if (a > 5 && a < 9)
						fdwLiuJiaoAtk[a]->mPosition.x = 666.0f;
					if (a > 8)
						fdwLiuJiaoAtk[a]->mPosition.x = 980.0f;
				}
			}

			fdwLiuJiaoStage = 1;
		}

		if (fdwLiuJiaoStage == 1)
		{
			fdwTimeElapsed[5] += dt;

			for (int b = 0; b < 12; ++b)
			{
				if (RandAttack == 1)
				{
					if (b < 6)
					{
						if (b < 3)
						{
							fdwLiuJiaoAtk[b]->mVelocity.x = (20.0f - fdwLiuJiaoAtk[b]->mPosition.x) * 25.0f;
							fdwLiuJiaoAtk[b]->mVelocity.y = (20.0f - fdwLiuJiaoAtk[b]->mPosition.y) * 25.0f;
						}
						if (b > 2)
						{
							fdwLiuJiaoAtk[b]->mVelocity.x = (980.0f - fdwLiuJiaoAtk[b]->mPosition.x) * 25.0f;
							fdwLiuJiaoAtk[b]->mVelocity.y = (20.0f - fdwLiuJiaoAtk[b]->mPosition.y) * 25.0f;
						}
					}
					else
					{
						if (b < 9)
						{
							fdwLiuJiaoAtk[b]->mVelocity.x = (20.0f - fdwLiuJiaoAtk[b]->mPosition.x) * 25.0f;
							fdwLiuJiaoAtk[b]->mVelocity.y = (680.0f - fdwLiuJiaoAtk[b]->mPosition.y) * 25.0f;
						}
						if (b > 8)
						{
							fdwLiuJiaoAtk[b]->mVelocity.x = (980.0f - fdwLiuJiaoAtk[b]->mPosition.x) * 25.0f;
							fdwLiuJiaoAtk[b]->mVelocity.y = (680.0f - fdwLiuJiaoAtk[b]->mPosition.y) * 25.0f;
						}
					}
				}
				else
				{
					fdwLiuJiaoAtk[b]->mVelocity.x = 0.0f;
					fdwLiuJiaoAtk[b]->mVelocity.y = (20.0f - fdwLiuJiaoAtk[b]->mPosition.y) * 25.0f;
				}

				fdwLiuJiaoAtk[b]->update(dt);
			}

			if (fdwTimeElapsed[5] >= 0.65f)
			{
				for (int c = 0; c < 12; ++c)
				{
					if (RandAttack == 1)
					{
						fdwLiuJiaoAtk[c]->mVelocity.x = 500.0f - fdwLiuJiaoAtk[c]->mPosition.x;
						fdwLiuJiaoAtk[c]->mVelocity.y = fdwRandNumber[2] - fdwLiuJiaoAtk[c]->mPosition.y;
					}
					else
					{
						fdwLiuJiaoAtk[c]->mVelocity.x = 0.0f;
						fdwLiuJiaoAtk[c]->mVelocity.y = 750.0f - fdwLiuJiaoAtk[c]->mPosition.y;
					}
					fdwLiuJiaoAtk[c]->mVelocity.normalize() *= 300.0f;
				}

				fdwLiuJiaoStage = 2;
				fdwTimeElapsed[5] = 0.0f;
			}
		}

		if (fdwLiuJiaoStage == 2)
		{
			for (int d = 0; d < 12; ++d)
				fdwLiuJiaoAtk[d]->update(dt);

			if (fdwScreenBounds.isPtInside(fdwLiuJiaoAtk[0]->mPosition) && !fdwSpotlightOn[3])
			{
				fdwAttackStage[0] = true;
				fdwSpotlightOn[3] = true;
			}
			if (!fdwAttackBounds.isPtInside(fdwLiuJiaoAtk[0]->mPosition) && !fdwAttackBounds.isPtInside(fdwLiuJiaoAtk[6]->mPosition))
			{
				for (int e = 0; e < 12; ++e)
				{
					fdwLiuJiaoAtk[e]->mVelocity.x = 0.0f;
					fdwLiuJiaoAtk[e]->mVelocity.y = 0.0f;
				}
				fdwTimeElapsed[4] = 0.0f;
				fdwSpotlightOn[3] = false;
				fdwLiuJiaoStage = 0;
				fdwAttackOn[3] = false;
			}
		}
	}
}

void FDWGame::fdwResetStrScreen()
{
	for (int a = 0; a < 6; ++a)
		fdwTimeElapsed[a] = 0.0f;

	fdwAttackStage[0] = true;
	fdwAttackStage[1] = false;
	fdwAttackStage[2] = false;
	for (int a = 0; a < 4; ++a)
	{
		fdwAttackOn[a] = false;
		fdwAttackFrame[a] = 0;
		fdwSpotlightOn[a] = false;
	}
	fdwStartSide = 1020.0f;
	fdwLiuJiaoStage = 0;
	fdwStartAnimation = false;

	for (int b = 0; b < 9; ++b)
	{
		fdwQuattroAtk[b]->mPosition.x = -50.0f;
		fdwQuattroAtk[b]->mPosition.y = -50.0f;
		fdwQuattroAtk[b]->mVelocity.x = 0.0f;
		fdwQuattroAtk[b]->mVelocity.y = 0.0f;
	}
	for (int c = 0; c < 3; ++c)
	{
		fdwSeraphinaAtk[c]->mPosition.x = -50.0f;
		fdwSeraphinaAtk[c]->mPosition.y = -50.0f;
		fdwSeraphinaAtk[c]->mVelocity.x = 0.0f;
		fdwSeraphinaAtk[c]->mVelocity.y = 0.0f;
	}
	for (int d = 0; d < 9; ++d)
	{
		fdwDimitriAtk[d]->mPosition.x = -50.0f;
		fdwDimitriAtk[d]->mPosition.y = -50.0f;
		fdwDimitriAtk[d]->mVelocity.x = 0.0f;
		fdwDimitriAtk[d]->mVelocity.y = 0.0f;
	}
	for (int e = 0; e < 9; ++e)
	{
		fdwLiuJiaoAtk[e]->mPosition.x = -50.0f;
		fdwLiuJiaoAtk[e]->mPosition.y = -50.0f;
		fdwLiuJiaoAtk[e]->mVelocity.x = 0.0f;
		fdwLiuJiaoAtk[e]->mVelocity.y = 0.0f;
	}
}