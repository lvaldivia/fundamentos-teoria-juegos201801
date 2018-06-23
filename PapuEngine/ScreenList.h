#pragma once
#include <vector>
class Game;
class IGameScreen;

class ScreenList
{
public:
	ScreenList(Game* game);
	~ScreenList();
	IGameScreen* moveNext();
	IGameScreen* movePreviuos();
	void setScreen(int nextScreen);
	void addScreen(IGameScreen* newScreen);
	void destroy();
	IGameScreen* getCurrent();
protected:
	std::vector<IGameScreen*> _screens;
	Game* _game = nullptr;
	int _currentIndex = -1;
};

