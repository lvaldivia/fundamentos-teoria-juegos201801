#include "Timing.h"
#include <SDL\SDL.h>


FpsLimiter::FpsLimiter() {

}

void FpsLimiter::init(float maxFps) {
	setMaxFps(maxFps);
}

void FpsLimiter::setMaxFps(float maxFps) {
	_maxFps = maxFps;
}

void FpsLimiter::begin() {
	_startTicks = SDL_GetTicks();
}


float FpsLimiter::end() {
	calculateFPS();
	float frameTicks = 
		(float)(SDL_GetTicks() - _startTicks);
	if (1000.0f / _maxFps > frameTicks) {
		SDL_Delay((Uint32)(1000.0f / _maxFps - frameTicks));
	}
	return _fps;
}

void FpsLimiter::calculateFPS() {
	static const int NUM_SAMPLES = 10;
	static float frameTimes[NUM_SAMPLES];
	static int currentFrame = 0;
	static Uint32 prevTicks = SDL_GetTicks();
	Uint32 currentTicks = SDL_GetTicks();
	_frameTime = (float)(currentTicks - prevTicks);
	frameTimes[currentFrame%NUM_SAMPLES] = _frameTime;

	prevTicks = currentTicks;
	int count;

	currentFrame++;
	if (currentFrame < NUM_SAMPLES) {
		count = currentFrame;
	}
	else {
		count = NUM_SAMPLES;
	}

	float frameTimeAvg = 0;
	for (int i = 0; i < count; i++) {
		frameTimeAvg += frameTimes[i];
	}
	frameTimeAvg /= count;

	if (frameTimeAvg > 0) {
		_fps = 1000.0f / frameTimeAvg;
	}
	else {
		_fps = 60.0f;
	}
}