//================================================================================
// "Fifth Dimension Warriors" by David Cheng (04/05/2019 - 09/04/2019)
//================================================================================
#include "FDWGame.h"
#include "BackBuffer.h"
#include "resource.h"

HWND ghMainWnd = 0;
HINSTANCE ghAppInst = 0;
HMENU ghMainMenu = 0;
HDC ghSpriteDC = 0;

FDWGame* mainFDWGame = 0;
BackBuffer* mainBackBuffer = 0;

bool InitMainWindow();
int Run();
void DrawFramesPerSecond(float deltaTime);

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ModeBoxProc(HWND hMode, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK LevelBoxProc(HWND hLevel, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK MatchBoxProc(HWND hMatch, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ResultBoxProc(HWND hBattle, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AboutProc(HWND hAbout, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd)
{
	ghAppInst = hInstance;

	if (!InitMainWindow())
	{
		MessageBox(0, L"Fifth Dimension Warriors failed to load.", L"Error", MB_OK);
		return 0;
	}

	return Run();
}

bool InitMainWindow()
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = ghAppInst;
	wc.hIcon = ::LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = ::LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)::GetStockObject(NULL_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"MyWndClassName";

	RegisterClass(&wc);

	ghMainMenu = LoadMenu(ghAppInst, MAKEINTRESOURCE(IDR_MENU1));
	ghMainWnd = ::CreateWindow(L"MyWndClassName", L"Welcome to Fifth Dimension Warriors!", WS_OVERLAPPED | WS_SYSMENU, 350, 90, 1016, 759, 0, ghMainMenu, ghAppInst, 0);

	if (ghMainMenu == 0)
	{
		::MessageBox(0, L"Fifth Dimension Warriors failed to load.", L"Error", 0);
		return 0;
	}

	ShowWindow(ghMainWnd, SW_NORMAL);
	UpdateWindow(ghMainWnd);
	return true;
}

int Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	__int64 CntsPerSec = 0;
	bool perfExists = QueryPerformanceFrequency((LARGE_INTEGER*)&CntsPerSec) != 0;

	if (!perfExists)
	{
		MessageBox(0, L"Performance timer is not working!", 0, 0);
		return 0;
	}

	double timeScale = 1.0 / (double)CntsPerSec;

	__int64 lastTime = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);

	double timeElapsed = 0.0f;

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			__int64 currTime = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

			double deltaTime = (double)(currTime - lastTime) * timeScale;
			timeElapsed += deltaTime;

			if (timeElapsed >= 0.01f)
			{
				mainFDWGame->updateScreen((float)timeElapsed);

				mainFDWGame->drawScreen(mainBackBuffer->getDC(), ghSpriteDC);

				DrawFramesPerSecond(timeElapsed);

				mainBackBuffer->present();

				timeElapsed = 0.0f;
			}

			lastTime = currTime;
		}
	}
	return (int)msg.wParam;
}

void DrawFramesPerSecond(float deltaTime)
{
	static int frameCnt = 0;
	static float timeElapsed = 0.0f;
	static wchar_t buffer[256];

	++frameCnt;
	timeElapsed += deltaTime;

	if (timeElapsed >= 1.0f)
	{
		wsprintf(buffer, L" (fps: %d)", frameCnt);

		wstring newCaption = mainFDWGame->Title() + buffer;

		SetWindowText(ghMainWnd, newCaption.c_str());

		frameCnt = 0;
		timeElapsed = 0.0f;
	}
}

LRESULT CALLBACK
WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:

		mainFDWGame = new FDWGame(ghAppInst, hWnd);
		ghSpriteDC = CreateCompatibleDC(0);
		mainBackBuffer = new BackBuffer(hWnd, 1000, 700);
		CheckMenuItem(ghMainMenu, ID_SOUND_ON, MF_CHECKED);
		return 0;

	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case ID_FILE_STRSCREEN:
			mainFDWGame->useMenu(ID_FILE_STRSCREEN);
			return 0;
		case ID_FILE_EXIT:
			DestroyWindow(ghMainWnd);
			return 0;
		case ID_ABOUT_HOWTOPLAY:
			CreateDialog(ghAppInst, MAKEINTRESOURCE(IDD_ABOUT_PLAY), hWnd, AboutProc);
			return 0;
		case ID_MOVESET_QUATTRO:
			CreateDialog(ghAppInst, MAKEINTRESOURCE(IDD_ABOUT_QUATTRO), hWnd, AboutProc);
			return 0;
		case ID_MOVESET_SERAPHINA:
			CreateDialog(ghAppInst, MAKEINTRESOURCE(IDD_ABOUT_SERAPHINA), hWnd, AboutProc);
			return 0;
		case ID_MOVESET_DIMITRI:
			CreateDialog(ghAppInst, MAKEINTRESOURCE(IDD_ABOUT_DIMITRI), hWnd, AboutProc);
			return 0;
		case ID_MOVESET_LIUJIAO:
			CreateDialog(ghAppInst, MAKEINTRESOURCE(IDD_ABOUT_LIUJIAO), hWnd, AboutProc);
			return 0;
		case ID_ABOUT_CREDITS:
			CreateDialog(ghAppInst, MAKEINTRESOURCE(IDD_ABOUT_CREDITS), hWnd, AboutProc);
			return 0;
		case ID_SOUND_ON:
			CheckMenuItem(ghMainMenu, ID_SOUND_ON, MF_CHECKED);
			CheckMenuItem(ghMainMenu, ID_SOUND_OFF, MF_UNCHECKED);
			mainFDWGame->turnMusicOn();
			return 0;
		case ID_SOUND_OFF:
			CheckMenuItem(ghMainMenu, ID_SOUND_OFF, MF_CHECKED);
			CheckMenuItem(ghMainMenu, ID_SOUND_ON, MF_UNCHECKED);
			mainFDWGame->turnMusicOff();
			return 0;
		}
		break;

	case WM_LBUTTONDOWN:

		switch (mainFDWGame->leftClickScreen(0))
		{
		case 1:
			DialogBox(ghAppInst, MAKEINTRESOURCE(IDD_MODEBOX), hWnd, ModeBoxProc);
			break;
		case 2:
			DialogBox(ghAppInst, MAKEINTRESOURCE(IDD_MATCHBOX), hWnd, MatchBoxProc);
			break;
		case 3:
			DialogBox(ghAppInst, MAKEINTRESOURCE(IDD_RESULTBOX), hWnd, ResultBoxProc);
			break;
		case 4:
			int exitGame = MessageBox(hWnd, L"Are you sure?", L"Exit", MB_YESNO);
			if (exitGame == IDYES)
				DestroyWindow(ghMainWnd);
			break;
		}
		return 0;

	case WM_RBUTTONDOWN:

		mainFDWGame->rightClickScreen();
		return 0;

	case WM_KEYDOWN:

		switch (wParam)
		{
		case 'Q':
			mainFDWGame->pressQWER('Q');
			break;
		case 'W':
			mainFDWGame->pressQWER('W');
			break;
		case 'E':
			mainFDWGame->pressQWER('E');
			break;
		case 'R':
			mainFDWGame->pressQWER('R');
			break;
		case 'P':
			if (mainFDWGame->pressP())
				DialogBox(ghAppInst, MAKEINTRESOURCE(IDD_RESULTBOX), hWnd, ResultBoxProc);
			break;
		}
		return 0;

	case WM_DESTROY:

		delete mainFDWGame;
		delete mainBackBuffer;
		DeleteDC(ghSpriteDC);
		PostQuitMessage(0);
		return 0;

	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

BOOL CALLBACK
ModeBoxProc(HWND hMode, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:

		CheckRadioButton(hMode, IDC_CHALLENGERMODE, IDC_PRACTICEMODE, IDC_CHALLENGERMODE);
		return true;

	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_CHALLENGERMODE:
			mainFDWGame->leftClickScreen(IDC_CHALLENGERMODE);
			CheckRadioButton(hMode, IDC_CHALLENGERMODE, IDC_PRACTICEMODE, LOWORD(wParam));
			return true;
		case IDC_QUICKMODE:
			mainFDWGame->leftClickScreen(IDC_QUICKMODE);
			CheckRadioButton(hMode, IDC_CHALLENGERMODE, IDC_PRACTICEMODE, LOWORD(wParam));
			return true;
		case IDC_PRACTICEMODE:
			mainFDWGame->leftClickScreen(IDC_PRACTICEMODE);
			CheckRadioButton(hMode, IDC_CHALLENGERMODE, IDC_PRACTICEMODE, LOWORD(wParam));
			return true;
		case ID_MODEBOX_OK:
			if (mainFDWGame->leftClickScreen(ID_MODEBOX_OK))
			{
				DialogBox(ghAppInst, MAKEINTRESOURCE(IDD_LEVELBOX), hMode, LevelBoxProc);
				if (mainFDWGame->Title() == L"Fifth Dimension Warriors: Select Your Warrior")
					EndDialog(hMode, 0);
				return true;
			}
			else
				EndDialog(hMode, 0);
			return true;
		case ID_MODEBOX_BACK:
			mainFDWGame->leftClickScreen(ID_MODEBOX_BACK);
			EndDialog(hMode, 0);
			return true;
		}
		break;

	}
	return false;
}

BOOL CALLBACK
LevelBoxProc(HWND hLevel, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:

		CheckRadioButton(hLevel, IDC_EASYLEVEL, IDC_HARDLEVEL, IDC_EASYLEVEL);
		return true;

	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_EASYLEVEL:
			mainFDWGame->leftClickScreen(IDC_EASYLEVEL);
			CheckRadioButton(hLevel, IDC_EASYLEVEL, IDC_HARDLEVEL, LOWORD(wParam));
			return true;
		case IDC_HARDLEVEL:
			mainFDWGame->leftClickScreen(IDC_HARDLEVEL);
			CheckRadioButton(hLevel, IDC_EASYLEVEL, IDC_HARDLEVEL, LOWORD(wParam));
			return true;
		case ID_LEVELBOX_OK:
			mainFDWGame->leftClickScreen(ID_LEVELBOX_OK);
			EndDialog(hLevel, 0);
			return true;
		case ID_LEVELBOX_BACK:
			mainFDWGame->leftClickScreen(ID_LEVELBOX_BACK);
			EndDialog(hLevel, 0);
			return true;
		}
		break;

	}
	return false;
}

BOOL CALLBACK
MatchBoxProc(HWND hMatch, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
	{
		if (mainFDWGame->Match() != L"No Match ID")
		{
			wstring matchText = L"Ready for " + mainFDWGame->Match() + L"?";
			SetWindowText(hMatch, matchText.c_str());
			if (mainFDWGame->Match() != L"Match #1")
				SetWindowText(GetDlgItem(hMatch, ID_MATCHBOX_BACK), L"Quit");
		}
		HWND mainPlayer1 = GetDlgItem(hMatch, IDC_PLAYER1);
		SetWindowText(mainPlayer1, mainFDWGame->Player1().c_str());
		HWND mainPlayer2 = GetDlgItem(hMatch, IDC_PLAYER2);
		SetWindowText(mainPlayer2, mainFDWGame->Player2().c_str());
		return true;
	}
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case ID_MATCHBOX_OK:
			mainFDWGame->leftClickScreen(ID_MATCHBOX_OK);
			EndDialog(hMatch, 0);
			return true;
		case ID_MATCHBOX_BACK:
			mainFDWGame->leftClickScreen(ID_MATCHBOX_BACK);
			EndDialog(hMatch, 0);
			return true;
		}
		break;

	}
	return false;
}

BOOL CALLBACK
ResultBoxProc(HWND hResult, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:

		if (mainFDWGame->Match() == L"Match #1" || mainFDWGame->Match() == L"Match #2" || mainFDWGame->Match() == L"Match #3")
		{
			SetWindowText(GetDlgItem(hResult, IDC_RESULT_TEXT), L"Try Again?");
			SetWindowText(GetDlgItem(hResult, ID_RESULT_PLAYBUTTON), L"Try Again");
		}
		if (mainFDWGame->Match() == L"Congratulations!")
			SetWindowText(hResult, L"Congratulations!! You're the champion!!");
		if (mainFDWGame->Title() == L"Fifth Dimension Warriors: Practice Mode")
			SetWindowText(hResult, L"Good Practice!");
		return true;

	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case ID_RESULT_PLAYBUTTON:
			mainFDWGame->leftClickScreen(ID_RESULT_PLAYBUTTON);
			EndDialog(hResult, 0);
			return true;
		case ID_RESULT_QUITBUTTON:
			mainFDWGame->leftClickScreen(ID_RESULT_QUITBUTTON);
			EndDialog(hResult, 0);
			return true;
		}
		break;

	}
	return false;
}

BOOL CALLBACK
AboutProc(HWND hAbout, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hAbout);
		return true;
	}
	return false;
}