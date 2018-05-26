#pragma once
#include <glm\glm.hpp>
#include "SpriteBacth.h"

const int BULLET_RADIUS = 5;
class Human;
class Zombie;

class Bullet
{

private:
	float _speed;
	glm::vec2 _direction;
	glm::vec2 _position;
	float _damage;
public:
	Bullet(glm::vec2 position,
		glm::vec2 direction, float damage,
		float speed);
	void draw(SpriteBacth& spritebatch);
	void update(std::vector<Human*> & humans,
		std::vector<Zombie*>& zombies);
	~Bullet();
};

