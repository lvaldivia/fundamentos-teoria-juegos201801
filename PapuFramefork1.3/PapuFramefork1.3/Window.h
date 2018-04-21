#pragma once
#include <SDL\SDL.h>
#include <GL\/glew.h>
#include <string>

using namespace std;

enum WindowsFlags {
	INVISIBLE = 0x1,
	FULLSCREEN = 0x2,
	BORDERLESS = 0x4
};

class Window
{
private :
	SDL_Window *_window;
	int _screenWidth, _screenHeight;
public:
	void swapBuffer();
	int getScreenWidth() { return _screenWidth; }
	int getScreenHeight() { return _screenHeight; }
	int create(string windowName,
		int screenWidth, int screenHeight,
		unsigned int currentFlags);
	Window();
	~Window();
};

