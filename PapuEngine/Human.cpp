#include "Human.h"
#include <random>
#include <ctime>
#include <glm\gtx\rotate_vector.hpp>

Human::Human()
{
}

void Human::init(float speed, glm::vec2 position) {
	_speed = speed;
	
}

void Human::update(const std::vector<std::string>& levelData) {

	
}

Human::~Human()
{
}
