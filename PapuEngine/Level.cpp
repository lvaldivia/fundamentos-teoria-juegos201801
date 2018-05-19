#include "Level.h"
#include <fstream>
#include "ResourceManager.h"
#include "Error.h"


Level::Level(const string& filename)
{
	std::ifstream file;
	file.open(filename);
	if (file.fail()) {
		fatalError("No se puede abrir el archivo " 
									+ filename);
	}
	string tmp;
	file >> tmp >> _numHumans;
	while (getline(file, tmp)) {
		_levelData.push_back(tmp);
	}
	parseLevel();
}

void Level::draw() {
	_spritebatch.renderBatch();
}

void Level::parseLevel() {
	_spritebatch.init();
	_spritebatch.begin();

	glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	Color color;
	color.set(255,255,255,255);
	for (int y = 0; y< _levelData.size(); y++)
	{
		for (int x = _levelData[y].size(); x >= 0; x--)
		{

			char tile = _levelData[y][x];
			glm::vec4 destRect(x*TILE_WIDTH, y*TILE_WIDTH,
				TILE_WIDTH, TILE_WIDTH);

			switch (tile)
			{
			case 'R':
			case 'B':
				_spritebatch.draw(destRect, uvRect,
					ResourceManager::getTexture
					("Images/red_bricks.png").id,
					0.0f, color);
				break;
			case 'G':
				_spritebatch.draw(destRect, uvRect,
					ResourceManager::getTexture
					("Images/glass.png").id,
					0.0f, color);
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
	_spritebatch.end();
}

Level::~Level()
{
}
