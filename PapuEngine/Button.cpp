#include "Button.h"
#include "ResourceManager.h"


Button::Button(std::string texture, int width, int height)
			: _texture(texture), _width(width),_height(height) {
	_position = glm::vec2(400, 300);
}

void Button::draw(SpriteBacth& spritebatch) {
	static int textureID = ResourceManager::getTexture(_texture).id;
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	Color color;
	color.set(255, 255, 255, 255);
	glm::vec4 destRect(_position.x, _position.y, _width, _height);
	spritebatch.draw(destRect, uvRect, textureID, 0.0f, color);
}

bool Button::clicked(glm::vec2 position) {
	return ((position.x > _position.x - _width)
		&& (position.x < _position.x + _width)
		&& (position.y > _position.y - _height)
		&& (position.y < _position.y + _height)

		);
}




Button::~Button()
{
}
