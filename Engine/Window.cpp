#include "Window.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

inline void Window::setHwnd(HWND hwnd)
{
	this->hWnd = hwnd;
}

HWND Window::getHwnd() const
{
	return this->hWnd;
}

HINSTANCE Window::getHInstance() const
{
	return this->hInstance;
}

inline void Window::setHInstance(HINSTANCE hInstance)
{
	this->hInstance = hInstance;
}

Window::Window()
{
	this->isGameDone = false;
}

Window::~Window()
{
}

void Window::init(HINSTANCE hInstance, LPCWSTR windowTitle, int width, int height)
{
	//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	

	setHInstance(hInstance);

	TCHAR szAppName[] = TEXT("perspective");
	WNDCLASSEX wndclass;
	

	if (fopen_s(&gpLogFile, "Log.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("LOG FILE WAS NOT CREATED"), TEXT("ERROR"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf_s(gpLogFile, "Log File Created\n");
	}

	//wndclassinitialization
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;// | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = this->hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (RegisterClassEx(&wndclass) == 0)
	{
		//Failed to register wndclassex
	}

	//CreateWindow
	hWnd = CreateWindowEx(WS_EX_APPWINDOW,
		szAppName,
		windowTitle,
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		100,
		100,
		width, height,
		NULL,
		NULL,
		this->hInstance,
		0);

	/*ShowWindow(hwnd, SW_NORMAL);
	UpdateWindow(hwnd);
	SetFocus(hwnd);*/

}

LRESULT WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_CREATE:

		break;

	/*case WM_SETFOCUS:
		gbIsActiveWindow = true;
		break;

	case WM_KILLFOCUS:
		gbIsActiveWindow = false;
		break;*/

	/*case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		break;*/

	case WM_ERASEBKGND:
		return(0);

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void Window::startGame(MSG msg)
{
	while (GetMessage(&msg, NULL,/*Filter*/ 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}



