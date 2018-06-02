#pragma once
#define SCREEN_INDEX_NO_SCREEN = -1;

enum class ScreenState {
	NONE,
	RUNNING,
	EXIT_APPLICATION,
	CHANGE_NEXT,
	CHANGE_PREVIOUS

};
class IMainGame;
class IGameScreen
{
protected: 
	ScreenState _currentState 
			= ScreenState::NONE;
	IMainGame* _game = nullptr;
	int _screenIndex = 1;

public:
	friend class ScreenList;
	void setParentGame(IMainGame* game) { _game = game; };
	virtual void checkInput() = 0;
	virtual void initSystem() = 0;
	virtual void build() = 0;
	virtual void destroy() = 0;
	virtual void onExit() = 0;
	virtual void onEntry() = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual int getNextScreen() const = 0;
	virtual int getPrevScreen() const = 0;
	ScreenState getState() const {
		return _currentState;
	}
	int getIndex() const {
		return _screenIndex;
	}
	void setRunning() {
		_currentState = ScreenState::RUNNING;
	}

	IGameScreen() {
	
	}

	virtual ~IGameScreen() {
	}
};

