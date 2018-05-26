#include "Bullet.h"
#include "ResourceManager.h"


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
void Bullet::update(std::vector<Human*> & humans,
	std::vector<Zombie*>& zombies){
	_position += _direction * _speed;
}

Bullet::~Bullet()
{
}
