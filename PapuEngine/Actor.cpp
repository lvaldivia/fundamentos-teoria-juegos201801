#include "Actor.h"
#include "ResourceManager.h"
#include "Level.h"
#include <algorithm>

Actor::Actor()
{

}

Actor::Actor(float agent_width, float agent_height,
	glm::vec2 position, std::string texturePath):
	_agent_width(agent_width),_agent_height(agent_height),
	_position(position), _texturePath(texturePath),
		_agent_radius(agent_width/2)

{
	
}

bool Actor::applyDamage(float damage) {
	_health -= damage;
	if (_health <= 0) {
		return true;
	}
	return false;

}

void Actor::draw(SpriteBacth& spritebatch) {
	static int textureID = ResourceManager::getTexture(_texturePath).id;
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	glm::vec4 destRect(_position.x, _position.y, _agent_width,_agent_height);
	spritebatch.draw(destRect, uvRect, textureID, 0.0f, color);
}

void Actor::checkTilePosition(
	const std::vector<std::string>& levelData,
	std::vector<glm::vec2>& collideTilePosition,
	float x, float y) {
	glm::vec2 cornerPos =
		glm::vec2(floor(x / (float)TILE_WIDTH),
			floor(y / (float)TILE_WIDTH)
			);
	if (cornerPos.x< 0
		|| cornerPos.x >= levelData[0].size()
		|| cornerPos.y < 0
		|| cornerPos.y >= levelData.size()) {
		return;
	}
	if (levelData[cornerPos.y][cornerPos.x] != '.') {
		collideTilePosition.push_back(
			cornerPos *(float)TILE_WIDTH +
			glm::vec2((float)TILE_WIDTH / 2.0f)
		);
	}
}

void Actor::collideWithTile(glm::vec2 tilePos) {
	const float TILE_RADIUS = (float)TILE_WIDTH / 2.0f;
	const float MIN_DISTANCE = AGENT_RADIUS + TILE_RADIUS;
	glm::vec2 centerPosition = 
			_position + glm::vec2(AGENT_RADIUS);
	glm::vec2 distVec = centerPosition - tilePos;
	float xDepth = MIN_DISTANCE - abs(distVec.x);
	float yDepth = MIN_DISTANCE - abs(distVec.y);
	if (xDepth > 0 || yDepth > 0) {
		if(std::max(xDepth,0.0f) < std::max(yDepth,0.0f))
		{
			if (distVec.x < 0) {
				_position.x -= xDepth;
			}else{
				_position.x += xDepth;
			}
		}
		else {
			if (distVec.y < 0) {
				_position.y -= yDepth;
			}
			else {
				_position.y += yDepth;
			}
		}
	
	}

}


bool Actor::collideWithLevel(
	const std::vector<std::string>& levelData) {

	std::vector<glm::vec2> collideTilePosition;
	checkTilePosition(levelData,
		collideTilePosition, 
		_position.x,_position.y);

	checkTilePosition(levelData,
		collideTilePosition,
		_position.x + AGENT_WIDTH,
		_position.y);

	checkTilePosition(levelData,
		collideTilePosition,
		_position.x,
		_position.y+AGENT_WIDTH);

	checkTilePosition(levelData,
		collideTilePosition,
		_position.x + AGENT_WIDTH,
		_position.y + AGENT_WIDTH);

	if (collideTilePosition.size() == 0) return false;
	for (size_t i = 0; i < collideTilePosition.size();i++) {
		collideWithTile(collideTilePosition[i]);
	}
	return true;

}

bool Actor::collideWithActor(Actor* actor) {
	glm::vec2 centerPosA = _position 
				+ glm::vec2(_agent_radius);

	glm::vec2 centerPosB = actor->getPosition() +
				glm::vec2(_agent_radius);
	glm::vec2 distance = centerPosA - centerPosB;
	const float MIN_DISTANCE = AGENT_RADIUS / 2;
	float dist = glm::length(distance);
	float collisionDepth = MIN_DISTANCE - dist;
	if (collisionDepth > 0) {
		glm::vec2 collisionDepthVec =
			glm::normalize(distance) * collisionDepth;

		_position += collisionDepthVec / 2.0f;
		actor->_position -= collisionDepthVec / 2.0f;
		return true;
	}
	return false;
}

Actor::~Actor()
{
}