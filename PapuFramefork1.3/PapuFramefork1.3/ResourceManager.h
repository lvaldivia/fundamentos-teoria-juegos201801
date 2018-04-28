#pragma once
#include "GLTexture.h"
#include <string>
#include "TextureCache.h"

class ResourceManager
{
private:
	static TextureCache _textureCache;
public:
	static GLTexture 
		getTexture(std::string texturePath);
};

