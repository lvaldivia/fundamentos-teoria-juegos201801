#include "MainGame.h"
#include <iostream>
#include <glm\glm.hpp>

using namespace std;

MainGame::MainGame(): 
			_width(800),_height(600),
			_gameState(GameState::PLAY),
			_time(0)
{
	_camera.init(_width, _height);
}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	_window.create("Motor",_width, _height, 0);

	/*SDL_GL_SetAttribute(
		SDL_GL_DOUBLEBUFFER, 1);*/
	initShaders();
}

void MainGame::initShaders() {
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT
		| GL_DEPTH_BUFFER_BIT);
	_program.use();
	glActiveTexture(GL_TEXTURE0);
	GLuint timeLocation = _program.getUniformLocation("time");
	glUniform1f(timeLocation, _time);
	GLuint imageLocation = 
			_program.getUniformLocation("image");
	glUniform1i(imageLocation,0);
	glm::mat4 cameraMatrix = _camera.getCameraMatrix();
	/*GLuint pLocation =
		_program.getUniformLocation("P");
	glUniformMatrix4fv(pLocation, 1, GL_FALSE,
		&(cameraMatrix[0][0]));*/

	for (int i = 0; i < _sprites.size(); i++)
	{
		_sprites[i]->draw();
	}


	//_sprite.draw();
	_program.unuse();
	//draw de los elementos que creamos

	_window.swapBuffer();
	

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
				break;
		}
	}
}

void MainGame::run() {
	init();
	_sprites.push_back(new Sprite());
	_sprites.back()->init(-1, -1, 1, 1, "Textures/mario.png");

	_sprites.push_back(new Sprite());
	_sprites.back()->init(0, -1, 1, 1, "Textures/mario.png");
	update();
}

void MainGame::update() {
	while (_gameState != GameState::EXIT) {
		_time += 0.002f;
		processInput();
		draw();
		_camera.update();
	}
}

MainGame::~MainGame()
{
}
