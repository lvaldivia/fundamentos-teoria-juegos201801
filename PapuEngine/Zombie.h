#pragma once
#include "Actor.h"
class Zombie : public Actor
{
public:
	Zombie();
	void init(float speed, glm::vec2 position);
	void update(
		const std::vector<std::string>& levelData);
	~Zombie();
};

