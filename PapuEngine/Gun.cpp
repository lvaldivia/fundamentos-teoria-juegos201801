#include "Gun.h"
#include <random>
#include <ctime>
#include <glm\gtx\rotate_vector.hpp>

Gun::Gun(std::string name,
	int fireRate, int bulletPerShot,
	float spread, float bulletDamage,
	float bulletSpeed) : _name(name),
	_fireRate(fireRate),
	_bulletsPerShot(bulletPerShot),
	_spread(spread),
	_bulletDamage(bulletDamage),
	_bulletSpeed(bulletSpeed)

{
}


Gun::~Gun()
{
}


void Gun::fire(const glm::vec2& direction,
	const glm::vec2& position,
	std::vector<Bullet>&bullets)
{
	std::mt19937 randomEngine(time(nullptr));
	std::uniform_real_distribution<float>
		randomRotate(-_spread, _spread);
	for (size_t i = 0; i < _bulletsPerShot; i++)
	{
		bullets.emplace_back(position,
			glm::rotate(direction, 
					randomRotate(randomEngine)),
			_bulletDamage,_bulletSpeed);
	}
}

void Gun::update(bool isMouseDown,
	const glm::vec2& position,
	const glm::vec2& direction,
	std::vector<Bullet>& bullets) {
	_frameCounter++;
	if (_frameCounter >= _fireRate && isMouseDown) {
		_frameCounter = 0;
		fire(direction, position, bullets);
	}
}
