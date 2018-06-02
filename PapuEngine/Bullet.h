#pragma once
#include <glm\glm.hpp>
#include "SpriteBacth.h"
#include <string>
#include "Actor.h"

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
	bool update(
		const std::vector<std::string>& levelData);

	bool collideWithWorld(
		const std::vector<std::string>&
		levelData
	);

	bool collideWithAgent(Actor* actor);

	float getDamge() const {
		return _damage;
	}

	glm::vec2 getPosition() const {
		return _position;
	}
	~Bullet();
};

