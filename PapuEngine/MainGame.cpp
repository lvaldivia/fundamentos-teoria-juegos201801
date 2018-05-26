#include "MainGame.h"
#include "ImageLoader.h"
#include <iostream>
#include "ResourceManager.h"
#include "PapuEngine.h"
#include <random>
#include <ctime>

using namespace std;

void MainGame::run() {
	init();
	update();
}

void MainGame::init() {
	Papu::init();
	_window.create("Zombies V2", _witdh, _height, 0);
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
	initLevel();
	initShaders();
}

void MainGame::initLevel() {
	_levels.push_back(new Level("Levels/level1.txt"));
	_currenLevel = 0;
	_spriteBacth.init();
	_player = new Player();
	_player->init
		(1.0f, _levels[_currenLevel]->getPlayerPosition(), 
				&_inputManager);
	_humans.push_back(_player);
	
	std::mt19937 randomEngine(time(nullptr));
	std::uniform_int_distribution<int>randomPox(
		1,_levels[_currenLevel]->getWidth()-2
		);
	std::uniform_int_distribution<int>randomPoY(
		1, _levels[_currenLevel]->getWidth() - 2
	);
	for (size_t i = 0; i < _levels[_currenLevel]->getZombiesPosition().size();i++) {
		_zombies.push_back(new Zombie());
		_zombies.back()->init(1.0f, _levels[_currenLevel]->getZombiesPosition()[i]);
	}
	for (size_t i = 0; i < 
			_levels[_currenLevel]->getNumHumans(); i++)
	{
		_humans.push_back(new Human());
		glm::vec2 pos(randomPox(randomEngine) *TILE_WIDTH,
					randomPoY(randomEngine) * TILE_WIDTH);
		_humans.back()->init(1.0f, pos);
	}
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();

	glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, _texture.id);

	/*GLuint timeLocation = 
		_program.getUniformLocation("time");

	glUniform1f(timeLocation,_time);*/

	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1,GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);

	_spriteBacth.begin();
	_levels[_currenLevel]->draw();
	for (size_t i = 0; i < _humans.size(); i++)
	{
		_humans[i]->draw(_spriteBacth);
	}

	for (size_t i = 0; i < _zombies.size(); i++)
	{
		_zombies[i]->draw(_spriteBacth);
	}
	_spriteBacth.end();
	_spriteBacth.renderBatch();

	glBindTexture(GL_TEXTURE_2D, 0);

	_program.unuse();
	_window.swapBuffer();
}

void MainGame::procesInput() {
	SDL_Event event;
	const float CAMERA_SPEED = 20.0f;
	const float SCALE_SPEED = 0.1f;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				_inputManager.setMouseCoords((float)event.motion.x,(float)event.motion.y);
			break;
			case  SDL_KEYUP:
				_inputManager.releaseKey(event.key.keysym.sym);
				break;
			case  SDL_KEYDOWN:
				_inputManager.pressKey(event.key.keysym.sym);
				break;
			case SDL_MOUSEBUTTONDOWN:
				_inputManager.pressKey(event.button.button);
				break;
			case SDL_MOUSEBUTTONUP:
				_inputManager.releaseKey(event.button.button);
				break;
		}
		if (_inputManager.isKeyPressed(SDLK_q)) {
			_camera.setScale(_camera.getScale() + SCALE_SPEED);
		}
		if (_inputManager.isKeyPressed(SDLK_e)) {
			_camera.setScale(_camera.getScale() - SCALE_SPEED);
		}
	}
}

void MainGame::update() {

	while (_gameState != GameState::EXIT) {
		procesInput();
		draw();
		_camera.update();
		for (size_t i = 0; i < _humans.size(); i++) {
			_humans[i]->
					update(
					_levels[_currenLevel]->getLevelData(),
					_humans,_zombies);
		}
		for (size_t i = 0; i < _zombies.size(); i++) {
			_zombies[i]->
				update(
					_levels[_currenLevel]->getLevelData(),
					_humans, _zombies);
		}
		_camera.setPosition(_player->getPosition());
		_time += 0.002f;
	}
}

MainGame::MainGame(): 
					  _witdh(800),
					  _height(600),
					  _gameState(GameState::PLAY),
					  _time(0),
					  _player(nullptr)
{
	_camera.init(_witdh, _height);
}


MainGame::~MainGame()
{
}
