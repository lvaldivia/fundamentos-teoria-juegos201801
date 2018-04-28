#include "Spritebach.h"
#include <algorithm>


void Spritebach::init() {
	createVertexArray();
}
void Spritebach::begin(GlypSortType sortType = GlypSortType::TEXTURE) {
}
void Spritebach::end() {
	sortGlyphs();
	createRenderBatches();
}
void Spritebach::draw(const glm::vec4& destRect,
	const glm::vec4& uvRect, GLuint texture,
	float depth, const Color& color) {

}

void Spritebach::renderBatch() {

}

bool Spritebach::compareBackToFront(Glyph* a, Glyph* b) {
	return a->depth > b->depth;

}
bool Spritebach::compareFrontToBack(Glyph* a, Glyph* b) {
	return a->depth < b->depth;
}
bool Spritebach::compareTexture(Glyph* a, Glyph* b) {
	return a->texture < b->texture;
}


void Spritebach::createVertexArray() {
	if (_vba == 0) {
		glGenVertexArrays(1, &_vba);
	}
	glBindVertexArray(_vba);
	if (_vbo == 0) {
		glGenBuffers(1, &_vbo);
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(
		0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)offsetof(Vertex, position)
	);
	//color
	glVertexAttribPointer(
		1, 4, GL_UNSIGNED_BYTE, GL_TRUE,
		sizeof(Vertex),
		(void*)offsetof(Vertex, color)
	);
	//uv
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
		sizeof(Vertex),
		(void*)offsetof(Vertex, uv)
	);
	glBindVertexArray(0);

}
void Spritebach::sortGlyphs() {
	switch (_sortType)
	{
	case GlypSortType::BACK_TO_FRONT:
		std::stable_sort(_glyphs.begin(), _glyphs.end(), compareBackToFront);
		break;
	case GlypSortType::FRONT_TO_BACK:
		std::stable_sort(_glyphs.begin(), _glyphs.end(), compareFrontToBack);
		break;
	case GlypSortType::TEXTURE:
		std::stable_sort(_glyphs.begin(), _glyphs.end(), compareTexture);
		break;
	}
}


void Spritebach::createRenderBatches() {

}


Spritebach::Spritebach()
{
}


Spritebach::~Spritebach()
{
}
