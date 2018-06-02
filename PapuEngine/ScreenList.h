#pragma once
#include <vector>
class IMainGame;
class IGameScreen;

class ScreenList
{
public:
	ScreenList(IMainGame* game);
	~ScreenList();
	IGameScreen* moveNext();
	IGameScreen* movePreviuos();
	void setScreen(int nextScreen);
	void addScreen(IGameScreen* newScreen);
	void destroy();
	IGameScreen* getCurrent();
protected:
	std::vector<IGameScreen*> _screens;
	IMainGame* _game=nullptr;
	int _currentIndex = -1;
};

