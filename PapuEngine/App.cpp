#include "App.h"
#include "ScreenList.h"


App::App()
{
}

void App::onInit() {

}

void App::addScreens() {
	_gameScreen = std::make_unique<GameScreen>(&_window);
	_menuScreen = std::make_unique<MenuScreen>(&_window);

	_screenList->addScreen(_menuScreen.get());
	_screenList->addScreen(_gameScreen.get());
	_screenList->setScreen(_menuScreen->getIndex());

}


void App::onExit() {

}

App::~App()
{
}
