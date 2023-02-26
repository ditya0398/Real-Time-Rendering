#include<Windows.h>
#include "Window.h"


Window* Window::window = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
	Window* window = window->getInstance();

	MSG msg{};

    window->init(hInstance, TEXT("Engine!!!"), 800, 600);
	window->startGame(msg);


	return((int)msg.wParam);
}
