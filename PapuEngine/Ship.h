#pragma once
#include "Agent.h"
#include "InputManager.h"

const float SHIP_RADIUS = 15.0f;
class Ship :public Agent
{
private:
	InputManager* _inputManager;
public:
	Ship(float agent_width, 
		float agent_height, 
		glm::vec2 position,
		std::string texture);
	Ship(float agent_width, 
		float agent_height, 
		glm::vec2 position,
		std::string texture, 
		InputManager* inputManager);
	void update(float deltaTime);
	~Ship();
};

