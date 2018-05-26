#pragma once
#include "Actor.h"
class Zombie :public Actor
{
public:
	Zombie();
	~Zombie();

	void init(float speed, glm::vec2 position);

	void update(const std::vector<std::string>& levelData,
		std::vector<Human*> &humans,
		std::vector<Zombie*> &zombies);

	Human* getClosestHuman(
			std::vector<Human*>& humans);
};

