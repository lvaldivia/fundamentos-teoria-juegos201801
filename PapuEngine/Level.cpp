#include "Level.h"
#include <fstream>
#include "ResourceManager.h"
#include "Error.h"


Level::Level(const std::string& fileName)
{
	std::ifstream file;
	file.open(fileName);
	if (file.fail()) {
		fatalError("failed to opem " + fileName);
	}
	std::string tmp;

	file >> tmp >> _numHumans;

	std::getline(file, tmp);
	while (std::getline(file, tmp)) {
		_levelData.push_back(tmp);
	}
	parseLevel();

}

void Level::draw() {
	_spriteBatch.renderBatch();
}


void Level::parseLevel() {
	_spriteBatch.init();
	_spriteBatch.begin();

	glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	Color color;
	color.set(255, 255, 255, 255);
	for (int y = 0; y < _levelData.size(); y++)
	{
		for (int x = 0; x < _levelData[y].size(); x++)
		{
			char tile = _levelData[y][x];
			glm::vec4 destRect(x*TILE_WIDTH, y*TILE_WIDTH,
							   TILE_WIDTH, TILE_WIDTH);
			switch (tile)
			{
			case 'R':
			case 'B':
				_spriteBatch.draw(destRect, uvRect, 
					ResourceManager::getTexture("Images/red_bricks.png").id
					,0.0f,color);
				break;
			case 'G':
				_spriteBatch.draw(destRect, uvRect,
					ResourceManager::getTexture("Images/glass.png").id
					, 0.0f, color);
				break;
			case 'L':_spriteBatch.draw(destRect, uvRect,
				ResourceManager::getTexture("Images/light_bricks.png").id
				, 0.0f, color);				
				break;
			case '@':
				break;
			case 'Z':
				break;
			case '.':
				break;
			default:
				break;
			}
		}
	}
	_spriteBatch.end();
}


Level::~Level()
{
}
