#include "MainGame.h"
#include <iostream>

using namespace std;

MainGame::MainGame()
{
	_window = nullptr;
	_width = 800;
	_height = 600;
	_gameState = GameState::PLAY;
}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow(
		"Clase2",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width,
		_height,
		SDL_WINDOW_OPENGL
	);
	if (_window == nullptr) {
		
	}
	SDL_GLContext glContext =
		SDL_GL_CreateContext(_window);

	GLenum error = glewInit();
	if (error != GLEW_OK) {

	}
	SDL_GL_SetAttribute(
		SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT
		| GL_DEPTH_BUFFER_BIT);
	//draw de los elementos que creamos
	SDL_GL_SwapWindow(_window);

}

void MainGame::processInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
			break;
			case SDL_MOUSEMOTION:

				cout << event.motion.x 
					<< event.motion.y << endl;
				break;
		}
	}

}

void MainGame::run() {
	init();
	update();
}

void MainGame::update() {
	if (_gameState != GameState::EXIT) {
		processInput();
		draw();
	}
}

MainGame::~MainGame()
{
}
