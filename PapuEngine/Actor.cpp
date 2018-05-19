#include "Actor.h"
#include "ResourceManager.h"


Actor::Actor()
{
}

void Actor::draw(SpriteBacth& spritebatch) {
	static int texture = 
		ResourceManager::getTexture("Images/circle.png").id;
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	glm::vec4 destRect(_position.x, _position.y, 
				AGENT_WIDTH, AGENT_WIDTH);
	spritebatch.draw(destRect, uvRect, texture, 0, color);
}


Actor::~Actor()
{
}
