#include "Sprite.h"
#include "Vertex.h"
#include <cstddef>
#include "ResourceManager.h"

Sprite::Sprite()
{
	_vboID = 0;
}

void Sprite::init(float x,float y,
	int width, int height, string texturePath) {
	_x = x;
	_y = _y;
	_width = width;
	_height = height;

	if (_vboID == 0) {
		glGenBuffers(1, &_vboID);
	}

	_texture = ResourceManager::getTexture(texturePath);

	Vertex vertexData[6];

	vertexData[0].setUV(1.0f,1.0f);
	vertexData[1].setUV(0.0f,1.0f);
	vertexData[2].setUV(0.0f, 0.0f);
	vertexData[3].setUV(0.0f, 0.0f);
	vertexData[4].setUV(1.0f, 0.0f);
	vertexData[5].setUV(1.0f, 1.0f);


	vertexData[0].setPosition(_x+_width,_y+_height);
	vertexData[1].setPosition(_x, _y + _height);
	vertexData[2].setPosition(_x, _y);
	vertexData[3].setPosition(_x, _y);
	vertexData[4].setPosition(_x + _width, _y);
	vertexData[5].setPosition(_x + _width, _y + _height);

	for (int i = 0; i < 6; i++)
	{
		vertexData[i].setColorRGBA(255, 0, 0, 255);
	}
	vertexData[1].setColorRGBA(0, 0, 255, 255);
	vertexData[4].setColorRGBA(0, 255, 0, 255);
	

	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	glBufferData(GL_ARRAY_BUFFER, 
		sizeof(vertexData), 
		vertexData,
		GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Sprite::draw() {
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	glEnableVertexAttribArray(0);

	//position
	glVertexAttribPointer(
		0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)offsetof(Vertex, position)
	);
	//color
	glVertexAttribPointer(
		1, 4, GL_UNSIGNED_BYTE, GL_TRUE, 
				sizeof(Vertex), 
			(void*)offsetof(Vertex,color)
	);
	//uv
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
		sizeof(Vertex),
		(void*)offsetof(Vertex, uv)
	);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Sprite::~Sprite()
{
	if (_vboID != 0) {
		glDeleteBuffers(1, &_vboID);
	}

}
