#pragma once

#include <gl/glew.h>
#include "Vertex.h"
#include <glm/glm.hpp>
#include <vector>

enum class GlypSortType {
	NONE,
	FRONT_TO_BACK,
	BACK_TO_FRONT,
	TEXTURE
};

struct Glyph {

	GLuint texture;
	float depth;
	Vertex topLeft;
	Vertex topRight;
	Vertex bottomLeft;
	Vertex bottomRight;
};

class RenderBatch {

public:
	RenderBatch(GLuint offset, GLuint numVertixes,
		GLuint texture);
	GLuint _offset;
	GLuint _numVertixes;
	GLuint _texture;

};


class Spritebach
{

private:
	GLuint _vbo;
	GLuint _vba;
	std::vector<Glyph*> _glyphs;
	void createVertexArray();
	void sortGlyphs();
	GlypSortType _sortType;
	void createRenderBatches();

public:
	void init();
	void begin(GlypSortType sortType= GlypSortType::TEXTURE);
	void end();
	void draw(const glm::vec4& destRect, 
				const glm::vec4& uvRect, GLuint texture,
		float depth, const Color& color);
	void renderBatch();

	static bool compareBackToFront(Glyph* a, Glyph* b);
	static bool compareFrontToBack(Glyph* a, Glyph* b);
	static bool compareTexture(Glyph* a, Glyph* b);

	Spritebach();
	~Spritebach();
};

