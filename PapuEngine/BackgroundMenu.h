#pragma once
#include "SpriteBacth.h"
#include <glm\glm.hpp>
#include "GLTexture.h"
#include <string>

class BackgroundMenu
{
private:
	std::string _texture;
	int _textureID;
public:
	BackgroundMenu(std::string texture);
	void draw(SpriteBacth& spritebatch);
	~BackgroundMenu();
};

