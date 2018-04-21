#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Sprite.h"
#include "GLS_Program.h"
#include "Window.h"
#include "Camera2D.h"

enum class GameState {
	PLAY,EXIT
};

class MainGame
{
private:
	int _width;
	int _height;
	GLS_Program _program;
	Sprite _sprite;
	void init();
	void initShaders();
	float _time;
	void processInput();
	Window _window;
	Camera2D _camera;
	const float CAMERA_SPEED = 0.05f;
	const float SCALE_SPEED = 0.1f;
public:
	GameState _gameState;
	MainGame();
	~MainGame();
	void run();
	void draw();
	void update();
};

