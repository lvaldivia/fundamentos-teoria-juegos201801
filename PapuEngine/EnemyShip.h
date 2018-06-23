#pragma 
#include "Ship.h"
class EnemyShip : public Ship
{
private:
	float elapsed;
	int _enemyType;
	bool directionX;
	glm::vec2 directionShip;
public:
	EnemyShip(float agent_width,
			float agent_height, glm::vec2 position, 
		int enemyType,std::string texturePath);
	void update(float deltaTime);
	bool collideWidthShip(Ship* sh);
	~EnemyShip();
};

