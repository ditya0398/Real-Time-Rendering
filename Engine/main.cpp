#include<Windows.h>
#include "Window.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
	Window window;
	MSG msg{};

    window.init(hInstance, TEXT("Engine!!!"), 800, 600);
	window.startGame(msg);


	return((int)msg.wParam);
}
