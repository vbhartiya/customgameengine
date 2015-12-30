#include "audiomanager.h"

namespace engine {	namespace audio {

		std::vector<Sound*> AudioManager::m_sounds;
		gau_Manager* AudioManager::m_mgr = nullptr;
		ga_Mixer* AudioManager::m_mixer = nullptr;

		void AudioManager::Add(Sound* sound) {
			m_sounds.push_back(sound);
		}

		Sound* AudioManager::Get(const std::string& name) {
			for (Sound* s : m_sounds) {
				if (s->GetName() == name)
					return s;
			}

			return nullptr;
		}

		void AudioManager::Clean() {
			for (int i = 0; i < m_sounds.size(); i++) {
				delete m_sounds[i];
			}

			gau_manager_destroy(m_mgr);
			gc_shutdown();
		}

		void AudioManager::Update() {
			gau_manager_update(m_mgr);
			gc_thread_sleep(1);
		}

		void AudioManager::Init() {
			gc_initialize(0);
			m_mgr = gau_manager_create();
			m_mixer = gau_manager_mixer(m_mgr);
		}

}	}