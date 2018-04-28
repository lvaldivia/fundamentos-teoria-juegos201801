#include "TextureCache.h"
#include "ImageLoader.h"

GLTexture TextureCache::getTexture(std::string texturePath) {
	auto mit = _textureMap.find(texturePath);
	if (mit == _textureMap.end()) {
		GLTexture textue = 
				ImageLoader::loadPNG(texturePath);
		_textureMap[texturePath] = textue;

		/*std::pair<std::string, GLTexture>
			newPair(texturePath, textue);
		_textureMap.insert(newPair);*/
		return textue;
	}
	return mit->second;
}

TextureCache::TextureCache()
{
}


TextureCache::~TextureCache()
{
}
