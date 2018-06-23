#pragma once
#include <string>
#include <glm\glm.hpp>
#include "SpriteBacth.h"
#include "EnemyShip.h"

const float BULLET_RADIUS = 13.0f;
class Vullet
{
private:
	std::string _texture;
	glm::vec2 _position;
	int _textureID;
	float _elapsed;
public:
	glm::vec2 getPosition()const { return _position; };
	void draw(SpriteBacth& spritebatch);
	void update(float deltaTime);
	bool collideWithAgent(EnemyShip* enemy);
	Vullet(std::string texture,glm::vec2 position);
	~Vullet();
};

