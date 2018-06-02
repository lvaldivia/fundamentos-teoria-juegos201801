#include "Human.h"
#include <random>
#include <ctime>
#include <glm\gtx\rotate_vector.hpp>

Human::Human()
{
}

void Human::init(float speed, glm::vec2 position) {
	_speed = speed;
	_position = position;
	color.set(150, 0, 255, 255);
	static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float>rndDir(
		-1.0f, 1.0f);
	_direction = glm::vec2(rndDir(randomEngine),
							rndDir(randomEngine));
	if (_direction.length() == 0) {
		_direction = glm::vec2(1.0f, 1.0f);
	}
	_direction = glm::vec2(_direction);
}

void Human::update(
	const std::vector<std::string>& levelData,
	std::vector<Human*> &humans,
	std::vector<Zombie*> &zombies) {
	
	
	static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float>randRotate(
		-40.0f, 40.0f);
	_position += _direction * _speed;

	if (_frames == 200) {
		_direction = glm::rotate(
			_direction,
			randRotate(randomEngine));
		_frames = 0;
	}
	else {
		_frames++;
	}


	if (collideWithLevel(levelData)) {
		_direction = glm::rotate(_direction, 
				randRotate(randomEngine));
	}
}

Human::~Human()
{
}
