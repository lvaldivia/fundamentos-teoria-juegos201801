#pragma once
#include "Ship.h"

const float ENEMY_RADIUS = 23.0f;
class EnemyShip : public Ship
{
private:
	float _elapsed;
	int _tipoenemigo;
	bool _direccionx;
	glm::vec2 _directionShip;
public:
	EnemyShip(float agent_width, float agent_height, glm::vec2 position, int tipoenemigo, bool _direccionx, glm::vec2 _directionShip, std::string texture);
	void update(float deltaTime);

	void CambioDireccion();

	bool collideWithShip(Ship* shipi);

	void getNearestShip(std::vector<Ship*>& ships);

	int getTipoEnemigo() { return _tipoenemigo; };

	~EnemyShip();
};

