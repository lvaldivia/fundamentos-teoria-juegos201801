#pragma once
#include "SpriteBacth.h"
#include <string>
#include <vector>

using namespace std;

const int TILE_WIDTH = 64;

class Level
{
private:
	vector<string> _levelData;
	int _numHumans;
	void parseLevel();
public:
	glm::vec2 _playerPosition;
	vector<glm::vec2> _zombiePosition;
	glm::vec2 getPlayerPosition()const {
		return _playerPosition;
	}
	vector<glm::vec2> getZombiePosition()const {
		return _zombiePosition;
	}
	void draw();
	SpriteBacth _spritebatch;
	Level(const string& filename);
	~Level();
};

