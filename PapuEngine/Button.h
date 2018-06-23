#pragma once
#include <glm\glm.hpp>
#include "GLTexture.h"
#include <string>
#include "SpriteBacth.h"

class Button
{
private:
	std::string _texture;
	int _width;
	int _height;
	glm::vec2 _position;
public:
	void draw(SpriteBacth& spritebatch);
	Button(std::string texture,int width, int height);
	bool clicked(glm::vec2 position);
	~Button();
};

