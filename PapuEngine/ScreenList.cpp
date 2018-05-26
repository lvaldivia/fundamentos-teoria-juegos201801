#include "ScreenList.h"



ScreenList::ScreenList(Game* game) :
	_game(game)
{
}

IGameScreen* ScreenList::moveNext() {

}

IGameScreen* ScreenList::movePreviuos() {

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
