#include "MenuScreen.h"
#include "ScreenIndices.h"
#include "Game.h"
#include <iostream>

MenuScreen::MenuScreen(Window* window) :
	_window(window), btnGameClicked(false)
{
	_screenIndex = SCREEN_INDEX_MENU;
}

void MenuScreen::initGUI() {

}

void MenuScreen::initSystem() {
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::build() 
{
}

void MenuScreen::destroy() {
	delete _background;
	delete _button;
}

void MenuScreen::onExit() {

}

void MenuScreen::onEntry() {
	initSystem();
	_camera2D.init(_window->getScreenWidth(), _window->getScreenHeight());
	_camera2D.setPosition(glm::vec2(_window->getScreenWidth() / 2.0f, _window->getScreenHeight() / 2.0f));
	_spriteBacth.init();
	_background = new Background("Textures/fondos/menu.png");
	_button = new Button("Textures/naves/menu_button.png");
	_welcomeText = new SpriteFont("Fonts/arial.ttf", 64);
}

void MenuScreen::update() {
	_camera2D.update();
	_elapsed += 0.1f;
	if (!_startClicked) {
		if (_button->clicked(_game->_inputManager.getMouseCoords())
				&& _game->_inputManager.isKeyDown(SDL_BUTTON_LEFT)) {
			std::cout << "Click en el bot�n" << std::endl;
			_startClicked = true;
			_currentState = ScreenState::CHANGE_NEXT;
		}
	}
	
	checkInput();
}

void MenuScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();
	glActiveTexture(GL_TEXTURE0);

	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera2D.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	
	_spriteBacth.begin();
	_background->draw(_spriteBacth);
	_button->draw(_spriteBacth);
	
	_spriteBacth.end();
	_spriteBacth.renderBatch();

	char buffer[256];
	_spriteBacth.begin();
	sprintf_s(buffer, "HOLA");
	_welcomeText->draw(_spriteBacth, buffer, glm::vec2(300, 100),
		glm::vec2(0, 5), 0.0f,
		ColorRGBA(255, 255, 255, 255));
	sprintf_s(buffer, "Q tal");
	_welcomeText->draw(_spriteBacth, buffer, glm::vec2(0, 0),
		glm::vec2(0, 5), 0.0f,
		ColorRGBA(120, 31, 25, 255));
	_spriteBacth.end();
	_spriteBacth.renderBatch();


	glBindTexture(GL_TEXTURE_2D, 0);
	_program.unuse();
}


void  MenuScreen::drawHUD() {

}


int MenuScreen::getNextScreen()const {
	return SCREEN_INDEX_GAMEPLAY;
}

int MenuScreen::getPreviousScreen() const{
	return SCREEN_INDEX_NO_SCREEN;
}

void MenuScreen::checkInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		_game->onSDLEvent(evnt);
	}
}


