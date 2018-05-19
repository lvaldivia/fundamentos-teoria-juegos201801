#pragma once
#include "Human.h"
#include "InputManager.h"

class Player : public Human
{
private:
	InputManager* _inputmanager;

public:
	Player();
	~Player();
	void init(glm::vec2 position, 
			InputManager* inputmanager);
	void update(
		const std::vector<std::string> levelData);
};

