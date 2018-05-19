#include "Human.h"

Human::Human()
{
}


void Human::init(float speed, glm::vec2 position) {
	_speed = speed;
	_position = position;

}
void Human::update(const std::vector<std::string>& levelData) {

}

Human::~Human()
{
}
