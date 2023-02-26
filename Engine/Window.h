#pragma once
#include<Windows.h>
#include <stdio.h>
#include <string>

class Window
{
	private:
		FILE* gpLogFile; 
		HWND hWnd;
		HINSTANCE hInstance;
		bool isGameDone;
		static Window* window;

		Window()
		{

		}
	public:
		
		Window(Window &other) = delete;


		static Window* getInstance()
		{
			if (window == nullptr)
				window = new Window;

			return window;
		}
		

		void init( HINSTANCE hInstance, LPCWSTR windowTitle, int width, int height);

		//getter and setter for Handle to the Window
		inline void setHwnd(HWND hwnd);
		HWND getHwnd() const;


		//getter and setter for Handle to Instance
		inline void setHInstance(HINSTANCE hInstance);
		HINSTANCE getHInstance() const;
		

		//Game Loop
		void startGame(MSG msg);
		
};

