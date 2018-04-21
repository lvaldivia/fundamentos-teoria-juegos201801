#pragma once
#include <unordered_map>

using namespace std;

class InputManager
{
private:
	std::unordered_map<unsigned int, bool> _keys;
public:
	InputManager();
	void pressKey(unsigned key);
	void releaseKey(unsigned key);
	bool isKeyPressed(unsigned key);
	~InputManager();
};

