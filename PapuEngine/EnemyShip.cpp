#include "EnemyShip.h"



EnemyShip::EnemyShip(float agent_width, float agent_height, glm::vec2 position, int tipoenemigo, bool direccionx,glm::vec2 directionShip, std::string texture)
	:Ship(agent_width,agent_height,position,texture),_elapsed(0), _tipoenemigo(tipoenemigo), _direccionx(direccionx), _directionShip(directionShip)
{
	
}

void EnemyShip::update(float deltaTime) {
	_elapsed += deltaTime;
	_position.y -= 5;
}


void EnemyShip::getNearestShip(std::vector<Ship*>& ships) {
	Ship* closestShip = nullptr;

	float smallestDistance = 88888888888.0f;

	for (size_t i = 0; i < ships.size(); i++)
	{
		glm::vec2 dist = ships[i]->getPosition() - _position;
		float distance = glm::length(dist);
		if (distance < smallestDistance) {
			smallestDistance = distance;
			closestShip = ships[i];
		}
	}


	_directionShip = closestShip->getPosition()- _position;

}


bool EnemyShip::collideWithShip(Ship* shipi) {
	const float MIN_DISTANCE = SHIP_RADIUS + ENEMY_RADIUS;
	glm::vec2 centerPosA = _position + glm::vec2(SHIP_RADIUS);
	glm::vec2 centerPosB = shipi->getPosition();
	glm::vec2 distVec = centerPosB - centerPosA;
	float distance = glm::length(distVec);
	float collisionDepth = MIN_DISTANCE - distance;
	if (collisionDepth > 0) {
		return true;
	}
	return false;
}

void EnemyShip::CambioDireccion() {
	

}


EnemyShip::~EnemyShip()
{
}
