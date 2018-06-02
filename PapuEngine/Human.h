#pragma once
#include "Actor.h"

class Human : public Actor
{

protected:
	glm::vec2 _direction;
private:
	int _frames;
public:
	Human();
	~Human();
	void init(float speed, glm::vec2 position);

	void update(const std::vector<std::string>& levelData,
		std::vector<Human*> &humans,
		std::vector<Zombie*> &zombies);
};

