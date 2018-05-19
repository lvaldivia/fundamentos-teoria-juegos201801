#include "Player.h"



Player::Player()
{
}

void Player::init(glm::vec2 position,
	InputManager* inputmanager) {
	_position = position;
	_inputmanager = inputmanager;
}
void Player::update(
	const std::vector<std::string> levelData) {

}


Player::~Player()
{
}
