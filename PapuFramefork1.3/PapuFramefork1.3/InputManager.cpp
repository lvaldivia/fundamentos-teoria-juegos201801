#include "InputManager.h"



InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}


void InputManager::pressKey(unsigned key) {
	_keys[key] = true;
}
void InputManager::releaseKey(unsigned key) {
	_keys[key] = false;
}
bool InputManager::isKeyPressed(unsigned key) {
	auto it = _keys.find(key);
	if (it != _keys.end()) {
		return it->second;
	}
	return false;
}
