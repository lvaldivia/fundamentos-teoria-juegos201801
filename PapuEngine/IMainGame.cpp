#include "IMainGame.h"



IMainGame::IMainGame()
{
	_mScreenList = 
		std::make_unique<ScreenList>(this);
}

void IMainGame::run() {
	if (!init())return;

	_isRunning = false;
	while (_isRunning) {
		_inputManager.update();
		update();
		draw();
		_window.swapBuffer();
	}
}

void IMainGame::exitGame() {
	_currentScreen->onExit();
	if (_mScreenList) {
		_mScreenList->destroy();
		_mScreenList.reset();
	}

}

void IMainGame::onSDLEvent(SDL_Event& evt) {
	switch (evt.type)
	{
		case SDL_QUIT:
			exitGame();
			break;
		case SDL_MOUSEMOTION:
			_inputManager.setMouseCoords(
				(float)evt.motion.x,
				(float)evt.motion.y);
			break;
		case SDL_KEYDOWN:
			_inputManager.
					pressKey(evt.key.keysym.sym);
			break;
		case SDL_KEYUP:
			_inputManager.
				releaseKey(evt.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			_inputManager.pressKey(evt.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			_inputManager.releaseKey(evt.button.button);
			break;

	}
}

void IMainGame::update() {
	if (_currentScreen) {
	
		switch (_currentScreen->getState())
		{
			case ScreenState::RUNNING:
				_currentScreen->update();
				break;
			case ScreenState::CHANGE_NEXT:
				_currentScreen->onExit();
				_currentScreen = _mScreenList->moveNext();
				if (_currentScreen) {
					_currentScreen->setRunning();
					_currentScreen->onEntry();
				}
				break;
			case ScreenState::EXIT_APPLICATION:
				exitGame();
				break;
			default:
				break;
		}
	}
	else {
		exitGame();
	}
}

void IMainGame::draw() {
	glViewport(0, 0, _window.getScreenWidth(), _window.getScreenHeight());
	if (_currentScreen && 
			_currentScreen->getState() == ScreenState::RUNNING) {
		_currentScreen->draw();
	}
}

bool IMainGame::init() {
	if (!initSystem()) return false;
	onInit();
	addScreen();

	_currentScreen = _mScreenList->getCurrent();
	_currentScreen->onEntry();
	_currentScreen->setRunning();
	return true;

}

bool IMainGame::initSystem() {
	_window.create("Zombie V3", 1920, 1080, 0);
	return true;
}


IMainGame::~IMainGame()
{
}
