#pragma once
#include "Window.h";
#include "InputManager.h"
#include <memory>
#include "IGameScreen.h"
#include "ScreenList.h"
class IMainGame
{
protected:
	virtual void update();
	virtual void draw();
	bool init();
	bool initSystem();
	std::unique_ptr<ScreenList> 
				_mScreenList = nullptr;
	IGameScreen* _currentScreen = nullptr;
	bool _isRunning = false;
	float _fps = 0.0f;
	Window _window;

public:
	void run();
	void exitGame();
	virtual void onInit() = 0;
	virtual void addScreen() = 0;
	virtual void onExit() = 0;
	void onSDLEvent(SDL_Event& evt);
	const float getfps() const{
		return _fps;
	}
	InputManager _inputManager;
	IMainGame();
	virtual ~IMainGame();

};

