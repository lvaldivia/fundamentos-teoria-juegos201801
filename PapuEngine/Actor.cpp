#include "Actor.h"
#include "ResourceManager.h"
#include "Level.h"
#include <algorithm>

Actor::Actor()
{

}

void Actor::draw(SpriteBacth& spritebatch) {
	static int textureID = ResourceManager::getTexture("Images/circle.png").id;
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	glm::vec4 destRect(_position.x, _position.y, AGENT_WIDTH, AGENT_WIDTH);
	spritebatch.draw(destRect, uvRect, textureID, 0.0f, color);
}

void Actor::checkTilePosition(
	const std::vector<std::string>& levelData,
	std::vector<glm::vec2>& collideTilePosition,
	float x, float y) {
	glm::vec2 cornerPos =
		glm::vec2(floor(x / (float)TILE_WIDTH));
	if (cornerPos.x< 0
		|| cornerPos.x > levelData[0].size()
		|| cornerPos.y < 0
		|| cornerPos.y > levelData.size()) {
		return;
	}
	if (levelData[cornerPos.y][cornerPos.x] != '.') {
		
	}
}

void Actor::collideWithTile(glm::vec2 tilePos) {

}


bool Actor::collideWithLevel(
	const std::vector<std::string>& levelData) {

}

Actor::~Actor()
{
}