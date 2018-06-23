#pragma once
#include "Actor.h"
#include "InputManager.h"
const float SHIP_RADIUS = 15.0f;
class Ship: public Actor
{
private:
	InputManager* _inpurtManager;
public:
	Ship(float agent_width, 
		float agent_height, 
		glm::vec2 position,
		std::string texture
		);

	Ship(float agent_width,
		float agent_height,
		glm::vec2 position,
		std::string texture,
		InputManager* inputManager
	);
	void update(float deltaTime);
	~Ship();
};

