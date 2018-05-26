#pragma 
#include <glm\glm.hpp>
#include <vector>
#include "Bullet.h"
class Gun
{
private:
	int _fireRate;
	float _spread;
	int _bulletsPerShot;
	int _bulletSpeed;
	std::string _name;
	float _bulletDamage;
	int _frameCounter;
	void fire(const glm::vec2& direction,
		const glm::vec2& position,
		std::vector<Bullet>&bullets);

public:
	Gun(std::string name,
		int fireRate, int bulletPerShot,
		float spread, float bulletDamage,
		float bulletSpeed);
	void update(bool isMouseDown, 
		const glm::vec2& position,
		const glm::vec2& direction,
		std::vector<Bullet>& bullets);
	~Gun();
	
};

