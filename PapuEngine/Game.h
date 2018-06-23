#pragma once
#include <memory>
#include "Window.h"
#include "InputManager.h"

class IGameScreen;
class ScreenList;

class Game
{
protected:
	bool init();
	float _fps = 0.0f;
	void update();
	void draw();
	bool initSystems();
	std::unique_ptr<ScreenList> _screenList = nullptr;
	bool _isRunning;
	Window _window;
	IGameScreen* _currentScreen = nullptr;
	InputManager _inputManager;
public:
	Game();
	void run();
	void exit();
	virtual void onInit() = 0;
	virtual void addScreens() = 0;
	virtual void onExit() = 0;
	InputManager InputManager;
	void onSDLEvent(SDL_Event& event);
	const float getFps()const {
		return _fps;
	}
	virtual ~Game();
};

