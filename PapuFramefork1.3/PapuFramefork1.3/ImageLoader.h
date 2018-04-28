#pragma once
#include <string>
#include "GLTexture.h"
#include <vector>

using namespace std;

class ImageLoader
{
public:
	
	static GLTexture loadPNG(string filepath);
};

