#pragma once
#include "Actor.h"
class Human : public Actor
{
protected:
	glm::vec2 _direction;
public:
	Human();
	void init(float speed, glm::vec2 position);
	void update(const std::vector<std::string>& levelData);
	~Human();
};

