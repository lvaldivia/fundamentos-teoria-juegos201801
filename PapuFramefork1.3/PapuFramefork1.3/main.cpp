#include<SDL\SDL.h>
#include <GL\glew.h>
#include "MainGame.h"

int main(int argc, char** argv) {
	MainGame game;
	game.run();
	system("PAUSE");
	return 0;
}
