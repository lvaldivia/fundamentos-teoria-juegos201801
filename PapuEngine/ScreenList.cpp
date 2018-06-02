#include "ScreenList.h"



ScreenList::ScreenList(Game* game) :
	_game(game)
{
}

IGameScreen* ScreenList::moveNext() {
	return nullptr;
}

IGameScreen* ScreenList::movePreviuos() {
	return nullptr;
}

void ScreenList::setScreen(int nextScreen) {
	_currentIndex = nextScreen;
}

void ScreenList::addScreen(
	IGameScreen* newScreen) {
	
}

ScreenList::~ScreenList()
{
}
