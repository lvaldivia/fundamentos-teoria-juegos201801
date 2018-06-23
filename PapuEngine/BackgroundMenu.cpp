#include "BackgroundMenu.h"
#include "ResourceManager.h"


BackgroundMenu::BackgroundMenu(std::string texture): _texture(texture)
{
	_textureID = ResourceManager::getTexture(_texture).id;
}


void BackgroundMenu::draw(SpriteBacth& spritebatch) {
	const glm::uvec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	Color color;
	color.set(255, 255, 0, 255);
	glm::vec4 destRect(0, 0, 800, 600);
	spritebatch.draw(destRect, uvRect, _textureID, 0.0f, color);

}

BackgroundMenu::~BackgroundMenu()
{
}
