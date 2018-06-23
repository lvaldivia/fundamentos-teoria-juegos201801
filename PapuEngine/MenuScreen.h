#pragma once
#include "IGameScreen.h"
#include "Window.h"
#include "GLS_Program.h"
#include "Background.h"
#include "Camera2D.h"
#include "Button.h"
#include "SpriteBacth.h"
#include "SpriteFont.h"

class MenuScreen : public IGameScreen
{
private:
	Window* _window = nullptr;
	bool btnGameClicked;
	GLS_Program _program;
	SpriteBacth _spriteBacth;
	Camera2D _camera2D;
	Background* _background;
	Button* _button;
	Camera2D _hudCamera;
	SpriteBacth _hudBatch;
	SpriteFont* _spriteFont;
	SpriteFont*_fontdetalles;
	float _elapsed;
	void drawHUD();

public:
	MenuScreen(Window* window);
	virtual void build() override;
	virtual void destroy() override;
	virtual void onExit() override;
	virtual void onEntry() override;

	virtual void initGUI()override;
	virtual void draw()override;
	virtual void update()override;
	virtual void initSystem() override;
	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;
	virtual void checkInput() override;
	~MenuScreen();
};

