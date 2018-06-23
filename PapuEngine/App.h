#pragma once
#include "Game.h"
#include <algorithm>

#include "GameScreen.h"
#include "MenuScreen.h"


class App : public Game
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

