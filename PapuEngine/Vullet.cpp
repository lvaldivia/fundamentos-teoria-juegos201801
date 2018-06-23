#include "Vullet.h"
#include "ResourceManager.h"

Vullet::Vullet(std::string texture, glm::vec2 position)
				:_texture(texture),_position(position)
{
	_textureID = ResourceManager::getTexture(_texture).id;
}

void Vullet::draw(SpriteBacth& spritebatch) {
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	ColorRGBA  color;
	color.set(255, 255, 0, 255);
	glm::vec4 destRect(_position.x, _position.y - 4, 20, 25);
	spritebatch.draw(destRect, uvRect, _textureID, 0.0f, color);
}

void Vullet::update(float deltaTime) {
	_elapsed += deltaTime;
	_position.y += 5;
}

bool Vullet::collideWithAgent(EnemyShip* enemy) {
	const float MIN_DISTANCE = ENEMY_RADIUS + BULLET_RADIUS;
	glm::vec2 centerPosA = _position;
	glm::vec2 centerPosB = enemy->getPosition() + glm::vec2(ENEMY_RADIUS);
	glm::vec2 distVec = centerPosA - centerPosB;
	float distance = glm::length(distVec);
	float collisionDepth = MIN_DISTANCE - distance;
	if (collisionDepth > 0) {
		return true;
	}
	return false;
}

Vullet::~Vullet()
{
}
