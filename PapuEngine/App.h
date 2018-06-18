#pragma once
#include "IMainGame.h"
#include <algorithm>
#include "GameScreen"
#include "MenuScreen"

class App : public IGameScreen
{
public:
	App();
	virtual void onInit() override;
	virtual void addScreens() override;
	virtual void onExit() override;
	~App();
private:
	std::unique_ptr<MenuScreen> _menuScreen = nullptr;
	std::unique_ptr<GameScreen> _gameScreen = nullptr;
};

