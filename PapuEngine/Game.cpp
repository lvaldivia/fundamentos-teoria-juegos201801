#include "Game.h"
#include "ScreenList.h"
#include "Timing.h"
#include "IGameScreen.h"
#include <iostream>
#include "GameEngine.h"


Game::Game()
{
	_screenList = std::make_unique<ScreenList>(this);
}

bool Game::init() {
	MyEngine::init();
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	initSystems();
	addScreens();
	_currentScreen = _screenList->getCurrent();
	_currentScreen->onEntry();
	_currentScreen->setRunning();
	return true;
}

void Game::draw() {
	glViewport(0, 0, _window.getScreenWidth(), _window.getScreenHeight());
	if (_currentScreen && _currentScreen->getState() == ScreenState::RUNNING) {
		_currentScreen->draw();
	}
}

void Game::onSDLEvent(SDL_Event& event) {
	switch (event.type)
	{
	case SDL_QUIT:
		break;
	case SDL_KEYDOWN:
		_inputManager.pressKey(event.key.keysym.sym);
		break;
	case SDL_KEYUP:
		_inputManager.releaseKey(event.key.keysym.sym);
		break;
	case SDL_MOUSEBUTTONDOWN:
		_inputManager.pressKey(event.button.button);
		break;
	case SDL_MOUSEBUTTONUP:
		_inputManager.releaseKey(event.button.button);
		break;
	default:
		break;
	}
}

void Game::run() {
	if (!init())return;
	_isRunning = true;
	FpsLimiter fpsLimiter;
	fpsLimiter.setMaxFps(60.0f);

	while (_isRunning) {
		fpsLimiter.begin();
		_inputManager.update();
		update();
		draw();
		_window.swapBuffer();
		_fps = fpsLimiter.end();
	}
}

void Game::onExit() {
	
}

void Game::exit() {
	_currentScreen->onExit();
	if (_screenList) {
		_screenList->destroy();
		_screenList.reset();
	}
	_isRunning = false;
}

void Game::update() {
	if (_currentScreen) {
		switch (_currentScreen->getState())
		{
		case ScreenState::RUNNING:
			_currentScreen->update();
			break;
		case ScreenState::CHANGE_NEXT:
			_currentScreen->onExit();
			if (_currentScreen->getIndex() == 2){
				_screenList->destroy();
				addScreens();
				_currentScreen = _screenList->getCurrent();
			}
			else {
				_currentScreen = _screenList->moveNext();
			}
			if (_currentScreen) {
				_currentScreen->setRunning();
				_currentScreen->onEntry();
			}
			break;
		case ScreenState::CHANGE_PREVIOUS:
			_currentScreen->onExit();
			_currentScreen = _screenList->movePreviuos();
			if (_currentScreen) {
				_currentScreen->setRunning();
				_currentScreen->onEntry();
			}
			break;
		case ScreenState::EXIT_APPLICATION:
			exit();
			break;
		}

		
	}
}


bool Game::initSystems() {
	_window.create("Demo Juego 1", 760, 500, 0);
	return true;
}


Game::~Game()
{
}
