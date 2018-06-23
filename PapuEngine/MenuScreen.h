#pragma once

#include "IGameScreen.h"
#include "Window.h"
#include "SpriteBacth.h"
#include "GLS_Program.h"
#include "Camera2D.h"
#include "BackgroundMenu.h"

class MenuScreen : public IGameScreen
{
private:
	Window* _window = nullptr;
	SpriteBacth _spritebatch;
	GLS_Program _program;
	Camera2D _camera2D;
	float _elapsed;
	BackgroundMenu* _background;
public:

	MenuScreen(Window* window);
	virtual void build() override;
	virtual void destroy() override;
	virtual void onExit() override;
	virtual void onEntry() override;
	virtual void draw() override;
	virtual void update() override;
	virtual void initSystem() override;
	virtual int getNextScreen() const override;
	virtual int getPrevScreen() const override;
	virtual void checkInput() override;
	~MenuScreen();
};

