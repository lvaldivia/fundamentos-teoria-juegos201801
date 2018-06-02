#pragma once

#include <SDL/SDL_mixer.h>
#include <string>
#include <map>

class SoundEffect {
private:

public:
	friend class AudioEngine;
	void play(int loops = 1);
private:
	Mix_Chunk* _music = nullptr;
};

class Music {
public:
	friend class AudioEngine;
	void play(int loops = 1);
	static void pause();
	static void stop();
	static void resumen();
private:
	Mix_Music* _music = nullptr;

};

class AudioEngine
{
public:
	AudioEngine();
	~AudioEngine();
	void init();
	void destroy();
	SoundEffect loadSound(const std::string& filePath);
	Music loudMusic(const std::string& filePath);
private:
	bool _isInitialized;
	std::map<std::string, Mix_Chunk*> _effectMap;
	std::map<std::string, Mix_Music*> _musicMap;
};

