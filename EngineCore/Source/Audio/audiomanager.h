#pragma once

#include <vector>
#include "sound.h"

namespace engine {	namespace audio {

	class AudioManager {
		friend class Sound;
	private:
		static std::vector<Sound*> m_sounds;
		static gau_Manager* m_mgr;
		static ga_Mixer* m_mixer;
	public:
		static void Add(Sound* sound);
		static Sound* Get(const std::string& name);
		static void Clean();
		static void Init();
		static void Update();
	private:
		AudioManager() {};

	};

}	}

