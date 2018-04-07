#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>

enum class GameState {
	PLAY,EXIT
};

class MainGame
{
private:
	int _width;
	int _height;
	void init();
	void processInput();
	SDL_Window* _window;
public:
	GameState _gameState;
	MainGame();
	~MainGame();
	void run();
	void draw();
	void update();
};

