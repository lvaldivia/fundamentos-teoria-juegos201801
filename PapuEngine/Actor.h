#pragma once
#include <glm\glm.hpp>
#include "SpriteBacth.h"
#include "GLTexture.h"

const int AGENT_WIDTH = 60;
class Actor
{
protected:
	glm::vec2 _position;
	float _speed;
	Color color;
public:
	Actor();
	glm::vec2 getPosition()const {
		return _position;
	}
	virtual void update() = 0;
	void draw(SpriteBacth& spritebatch);
	virtual ~Actor();
};

