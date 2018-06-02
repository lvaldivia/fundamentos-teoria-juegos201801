#include "AudioEngine.h"
#include "Error.h"


void SoundEffect::play(int loops) {
	if (Mix_PlayChannel(-1, _music, loops) == -1) {
		if (Mix_PlayChannel(0, _music, loops) == -1) {
			fatalError("No se puede reproducir el sonido " +
				std::string(Mix_GetError()));
		}
	}
}

void Music::play(int loops) {
	Mix_PlayMusic(_music, loops);
}

void Music::pause() {
	Mix_PauseMusic();
}

void Music::stop() {
	Mix_HaltMusic();
}

void Music::resumen() {
	Mix_ResumeMusic();
}

AudioEngine::AudioEngine() {

}

AudioEngine::~AudioEngine() {
	destroy();
}

void AudioEngine::init() {
	if (_isInitialized) {
		fatalError("Audio Engine solo se puede inicializar una vez");
	}

	if(Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == -1){
		fatalError("Ocurrió un error " + std::string(Mix_GetError()));
	}

	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,2,1024) == -1) {
		fatalError("Ocurrió un problema con MixOpenAudio " 
				+ std::string(Mix_GetError()));
	}
}


void AudioEngine::destroy() {
	if (_isInitialized) {
		_isInitialized = false;
		for (auto& it : _effectMap) {
			Mix_FreeChunk(it.second);
		}

		for (auto& it : _musicMap) {
			Mix_FreeMusic(it.second);
		}
		_effectMap.clear();
		_musicMap.clear();

		Mix_CloseAudio();
		Mix_Quit();
	}
}

SoundEffect AudioEngine::loadSound(const std::string& filePath) {
	auto it = _effectMap.find(filePath);
	SoundEffect effect;
	if (it == _effectMap.end()) {
		Mix_Chunk* chunk = Mix_LoadWAV(filePath.c_str());
		if (chunk == nullptr) {
			fatalError("Ocurrió un error al cargar el sonido " 
							+ std::string(Mix_GetError()));
		}
		effect._music = chunk;
		_effectMap[filePath] = chunk;
	}
	else {
		effect._music = it->second;
	}
	return effect;
}


Music AudioEngine::loudMusic(const std::string& filePath) {
	auto it = _musicMap.find(filePath);
	Music effect;
	if (it == _musicMap.end()) {
		Mix_Music* chunk = Mix_LoadMUS(filePath.c_str());
		if (chunk == nullptr) {
			fatalError("Ocurrió un error al cargar el sonido "
				+ std::string(Mix_GetError()));
		}
		effect._music = chunk;
		_musicMap[filePath] = chunk;
	}
	else {
		effect._music = it->second;
	}
	return effect;
}




