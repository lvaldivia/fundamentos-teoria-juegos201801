#include "Bullet.h"
#include "ResourceManager.h"
#include "Level.h"


Bullet::Bullet(glm::vec2 position,
	glm::vec2 direction, float damage,
	float speed): _position(position),
	_direction(direction),_damage(damage)
{
}


void Bullet::draw(SpriteBacth& spritebatch) {

	glm::vec4 destRect(_position.x + BULLET_RADIUS,
		_position.y + BULLET_RADIUS, BULLET_RADIUS * 2,
		BULLET_RADIUS * 2);
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	Color color;
	color.set(75, 75, 75, 255);
	spritebatch.draw(destRect, uvRect,
	ResourceManager::getTexture("Textures/circle.png").id,
		0.0f, color);
}
bool Bullet::update(
	const std::vector<std::string>& levelData){
	_position += _direction * _speed;
	
	return collideWithWorld(levelData);
}


bool Bullet::collideWithWorld(
	const std::vector<std::string>&
	levelData
) {
	glm::vec2 gridPosition;
	gridPosition.x =

		floor(_position.x / (float)TILE_WIDTH);
	gridPosition.y = 
		floor(_position.y / (float)TILE_WIDTH);

	if (gridPosition.x < 0 || gridPosition.x
		>= levelData[0].size()
		|| gridPosition.y < 0 || gridPosition.y >=
		levelData[0].size()
		) {
		return true;
	}

	return (levelData[gridPosition.y][gridPosition.y]
		!= '.');

}

bool Bullet::collideWithAgent(Actor* actor) {
	
	const float MIN_DISTANCE =

		AGENT_RADIUS + BULLET_RADIUS;

	glm::vec2 centerPosA = _position;
	glm::vec2 centerPosB =
		actor->getPosition();

	glm::vec2 distVec =
		centerPosA - centerPosB;
	float distance = glm::length(distVec);

	float collisionDepth = MIN_DISTANCE -
		distance;
	if(collisionDepth>0)
	{
		return true;
	}
	return false;
}

Bullet::~Bullet()
{
}
