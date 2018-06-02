#include "Camera2D.h"


Camera2D::Camera2D(): 
	_position(0,0), 
	_cameraMatrix(1.0f),
	_scale(1.0f),
	_needsMatrixUpdate(true), 
	_orthoMatrix(1.0f),
	_screenWidth(500),_screenHeight(500)
{

}

glm::vec2 Camera2D::convertScreenToWorl(glm::vec2 screenScoords) {
	screenScoords.y = _screenHeight - screenScoords.y;
	screenScoords -= glm::vec2(_screenWidth / 2, _screenHeight / 2);
	screenScoords /= _scale;
	screenScoords += _position;
	return screenScoords;
}

void Camera2D::init(int screenWidth, int screenHeight) {
	_screenWidth = screenWidth;
	_screenHeight = screenHeight;
	_orthoMatrix = glm::ortho(0.0f, (float)_screenWidth, 0.0f, (float)_screenHeight);
}

bool Camera2D::isBoxInView(const glm::vec2& position,
	const glm::vec2& dimensions) {
	glm::vec2 scaledScreenDimensions =
		glm::vec2(_screenWidth, _screenHeight) / _scale;
	const float MIN_DISTANCE_X = dimensions.x / 2.0f 
					+ scaledScreenDimensions.x / 2.0f;
	const float MIN_DISTANCE_Y = dimensions.y / 2.0f +
		scaledScreenDimensions.y / 2.0f;

	glm::vec2 centerPos = position + dimensions / 2.0f;
	glm::vec2 centerCameraPos = _position;

	glm::vec2 distVec = centerPos - centerCameraPos;
	float xDepth = MIN_DISTANCE_X - abs(distVec.x);
	float yDepth = MIN_DISTANCE_Y - abs(distVec.y);

	if (xDepth > 0 && yDepth > 0) {
		return true;
	}
	return false;

}

void Camera2D::update() {
	if(_needsMatrixUpdate){
		/*glm::vec3 translate(-_position.x, -_position.y, 0.0f);
		_cameraMatrix = glm::translate(_orthoMatrix, translate);
		glm::vec3 scale(_scale, _scale, 0.0f);
		_cameraMatrix = glm::scale(_cameraMatrix,scale);
		*/

		glm::vec3 translate(-_position.x + _screenWidth / 2, -_position.y + _screenHeight/2, 0.0f);
		_cameraMatrix = glm::translate(_orthoMatrix, translate);

		glm::vec3 scale(_scale, _scale, 0.0f);
		_cameraMatrix = glm::scale(glm::mat4(1.0f), scale) * _cameraMatrix;

		_needsMatrixUpdate = false;
	}
}

Camera2D::~Camera2D()
{
}
