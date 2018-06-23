#include "MenuScreen.h"
#include "Game.h"



MenuScreen::MenuScreen(Window *window):_window(window)
{
	_screenIndex = 0;
}

void MenuScreen::initSystem() {
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}

void MenuScreen::build() {
}


void MenuScreen::destroy() {

}

void MenuScreen::onExit() {
}

void MenuScreen::checkInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		_game->onSDLEvent(event);
	}
}


void MenuScreen::onEntry() {
	initSystem();
	_camera2D.init(_window->getScreenWidth(), _window->getScreenHeight());
	_camera2D.setPosition(glm::vec2(_window->getScreenWidth() / 2.0f, _window->getScreenHeight() / 2.0f));
	_spritebatch.init();
	_background = new BackgroundMenu("Textures/fondos/menu.png");
}

void MenuScreen::update() 
{
	_camera2D.update();
	checkInput();
}

void MenuScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();

	glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, _texture.id);

	/*GLuint timeLocation =
	_program.getUniformLocation("time");

	glUniform1f(timeLocation,_time);*/

	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera2D.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);

	_spritebatch.begin();
	_background->draw(_spritebatch);
	_spritebatch.end();
	_spritebatch.renderBatch();
	glBindTexture(GL_TEXTURE_2D, 0);
	_program.unuse();
	_window->swapBuffer();
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
