#include "Player.h"
#include <SDL\SDL.h>
#include <iostream>


void Player::init(float speed, 
	glm::vec2 position, 
	InputManager* inputManager,
	Camera2D* camera) {

	_speed = speed;
	_position = position;
	_inputManager = inputManager;
	_camera = camera;
	color.set(0, 0, 255, 255);
}


void Player::addGun(Gun* gun) {
	_guns.push_back(gun);
	_currentGun = _currentGun == -1 
					? 0 : _currentGun;
}

void Player::update(const std::vector<std::string>& levelData,
	std::vector<Human*> &humans,
	std::vector<Zombie*> &zombies,
	std::vector<Bullet> &bullets) {

	if (_inputManager->isKeyPressed(SDLK_w)) {
		_position.y += _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_s)) {
		_position.y -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_a)) {
		_position.x -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_d)) {
		_position.x += _speed;
	}
	collideWithLevel(levelData);
	
	if (_inputManager->isKeyPressed(SDLK_1)
		&& _guns.size() >= 0) {
		_currentGun = 0;
	}
	else if (_inputManager->isKeyPressed(SDLK_2)
		&& _guns.size() >= 1) {
		_currentGun = 1;
	}
	else if (_inputManager->isKeyPressed(SDLK_3)
		&& _guns.size() >= 2) {
		_currentGun = 2;
	}
	glm::vec2 mouseCoords =
		_camera->convertScreenToWorl(
			_inputManager->getMouseCoords());
	glm::vec2 centerPos = _position
		* glm::vec2(AGENT_RADIUS);
	glm::vec2 direction = glm::normalize(

		mouseCoords - centerPos
	);
	if (_currentGun != -1) {
		
		
		_guns[_currentGun]->update(
			_inputManager->isKeyPressed(SDL_BUTTON_LEFT),
			centerPos, direction, bullets
		);
	}
}


Player::Player():_currentGun(-1)
{
}


Player::~Player()
{
}
