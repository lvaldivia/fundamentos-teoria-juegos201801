#include "Zombie.h"



Zombie::Zombie()
{
}

void Zombie::init(float speed, 
				glm::vec2 position) {
	_speed = speed;
	_position = position;
	color.set(0, 255, 0, 255);
}

void Zombie::update(
		const std::vector<std::string>& levelData) {


}


Zombie::~Zombie()
{
}
