#include "Player.h"
#include <SDL\SDL.h>


void Player::init(float speed, glm::vec2 position, InputManager* inputManager) {
	_speed = speed;
	_position = position;
	_inputManager = inputManager;
	color.set(0, 0, 185, 255);
}
void Player::update(const std::vector<std::string>& levelData) {
}


Player::Player()
{
}


Player::~Player()
{
}
