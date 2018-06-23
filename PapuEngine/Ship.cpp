#include "Ship.h"
#include <SDL\SDL.h>


Ship::Ship(float agent_width,
	float agent_height,
	glm::vec2 position,
	std::string texture): 
	Actor(agent_width,agent_height,position,texture)
{

}

Ship::Ship(float agent_width,
	float agent_height,
	glm::vec2 position,
	std::string texture,
	InputManager* inputManager):
	Actor(agent_width, agent_height, position, texture)
{
	_inpurtManager = inputManager;
}

void Ship::update(float deltaTime) {
	if (_inpurtManager->isKeyDown(SDLK_a)) {
		_position.x -= 5.0f;
	}

	if (_inpurtManager->isKeyDown(SDLK_d)) {
		_position.x += 5.0f;
	}

	if (_inpurtManager->isKeyDown(SDLK_w)) {
		_position.y += 5.0f;
	}

	if (_inpurtManager->isKeyDown(SDLK_s)) {
		_position.y -= 5.0f;
	}
}


Ship::~Ship()
{
}
