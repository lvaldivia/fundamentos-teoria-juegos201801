#pragma once
class FpsLimiter {
public:
	FpsLimiter();
	void init(float maxFps);
	void setMaxFps(float maxFps);
	void begin();

	float end();
private:
	void calculateFPS();
	float _fps;
	float _maxFps;
	float _frameTime;
	unsigned int _startTicks;


};

