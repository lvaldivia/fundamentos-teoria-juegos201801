#include "MenuScreen.h"



MenuScreen::MenuScreen(Window *window):_window(window)
{
	_screenIndex = 1;
}

void MenuScreen::initSystem() {

}

void MenuScreen::build() {
}


void MenuScreen::destroy() {

}


void MenuScreen::onEntry() {
}

void MenuScreen::update() {
	checkInput();
}

void MenuScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int MenuScreen::getNextScreen() const {
	return 2;
}

int MenuScreen::getPrevScreen() const {
	return -1;
}




MenuScreen::~MenuScreen()
{
}
