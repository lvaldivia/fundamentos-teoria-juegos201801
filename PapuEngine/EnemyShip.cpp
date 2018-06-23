#include "EnemyShip.h"



EnemyShip::EnemyShip(float agent_width,
	float agent_height, glm::vec2 position,
	int enemyType, std::string texturePath):
	Ship(agent_width,agent_height,position,texturePath),
	elapsed(0),_enemyType(enemyType)
{
}

bool collideWidthShip(Ship* sh) {

}

void EnemyShip::update(float deltaTime) {
	elapsed += deltaTime;
	switch (_enemyType)
	{
	case 1:
		_position.y -= 5;
		break;
	case 2:
		_position.y -= 10;
		break;
	default:
		break;
	}
}


EnemyShip::~EnemyShip()
{
}
