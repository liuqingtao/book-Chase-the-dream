//-----------------------------------------------
//objname:GameCore
//september 1st,2016
//describe:create game frame with program
//-----------------------------------------------

//----------------------[header file]-------------
#include <windows.h>

//---------------------[macro definition]----------
#define WINDOWS_WIDTH 800
#define WINDOWS_HEIGHT 600
#define WINDOW_TITLE L"【致我们永不熄灭的游戏开发梦想】程序核心框架"

//--------------------[Global function description]----------
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lparam);

//-------------------[WinMain() functiono]-----------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//[1]design windows class
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = (HICON)::LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = L"ForTheDreamofGameDevelop";

	//[2]register
	if (!RegisterClassEx(&wndClass))
		return -1;

	//[3]create windows
	HWND hwnd = CreateWindow(L"ForTheDreamofGameDevelop", WINDOW_TITLE,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOWS_WIDTH, 
		WINDOWS_HEIGHT, NULL, NULL, hInstance, NULL);

	//[4]windows's remove、display and update
	MoveWindow(hwnd, 250,80, WINDOWS_WIDTH, WINDOWS_HEIGHT, true);
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	//[5]message loop
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	//[6]cancel windows class 
	UnregisterClass(L"ForTheDreamOfGameDevelop", wndClass.hInstance);
	return 0;
}

//---------------------[WndProc() function]----------------------
LRESULT  CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
		ValidateRect(hwnd, NULL);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
