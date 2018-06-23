#pragma once
#include <glm\glm.hpp>
#include "SpriteBacth.h"
#include "GLTexture.h"

class Zombie;
class Human;

const float AGENT_WIDTH = 60.0f;
const float AGENT_RADIUS = AGENT_WIDTH / 2.0f;

class Actor
{
protected:
	float _agent_width;
	float _agent_height;
	float _agent_radius;
	glm::vec2 _position;
	std::string _texturePath;
	float _speed;
	Color color;
	float _health;
	void checkTilePosition(
		const std::vector<std::string>& levelData,
		std::vector<glm::vec2>& collideTilePosition,
		float x,float y);

	void collideWithTile(glm::vec2 tilePos);
public:
	Actor(float agent_width, float agent_height,
		glm::vec2 position, std::string texturePath);
	Actor();
	bool applyDamage(float damage);
	glm::vec2 getPosition()const { return _position; };
	virtual void update(
		const std::vector<std::string>& levelData,
			std::vector<Human*> &humans,
			std::vector<Zombie*> &zombies
		) = 0;
	void draw(SpriteBacth& spritebatch);
	bool collideWithLevel(
			const std::vector<std::string>& levelData);

	bool collideWithActor(Actor* actor);
	virtual ~Actor();
};

