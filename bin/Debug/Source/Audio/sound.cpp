#include "sound.h"
#include "audiomanager.h"

namespace engine {	namespace audio {

	void setFlagAndDestroyOnFinish(ga_Handle* in_handle, void* in_context);
	void loopOnFinish(ga_Handle* in_handle, void* in_context);

	Sound::Sound(const std::string& name, const std::string& filename)
		: m_name(name), m_filename(filename) {

		std::vector<std::string> split = StringUtil::SplitString(filename, '.');

		m_sound = gau_load_sound_file(m_filename.c_str(), split.back().c_str());
		m_handle = nullptr;
		m_playing = false;
	}

	Sound::~Sound() {
		if(m_sound != nullptr)
			ga_sound_release(m_sound);
	}

	void Sound::Play() {
		gc_int32 quit = 0;
		m_handle = gau_create_handle_sound(AudioManager::m_mixer, m_sound, &setFlagAndDestroyOnFinish, &quit, NULL);
		m_handle->sound = this;
		ga_handle_play(m_handle);
		m_playing = true;
	}

	void Sound::Pause() {
		if (m_handle != nullptr && !ga_handle_destroyed(m_handle)) {
			ga_handle_stop(m_handle);
			m_playing = false;
		}
	}

	void Sound::Resume() {
		if (m_handle != nullptr && !ga_handle_destroyed(m_handle)) {
			ga_handle_play(m_handle);
			m_playing = true;
		}
	}

	void Sound::Stop() {
		if (m_handle != nullptr && !ga_handle_destroyed(m_handle)) {
			ga_handle_stop(m_handle);
			m_playing = false;
		}
	}

	void Sound::SetGain(float gain) {
		if (!m_playing)
			return;

		m_gain = gain;
		ga_handle_setParamf(m_handle, GA_HANDLE_PARAM_GAIN, m_gain);
	}

	void Sound::Loop() {
		gc_int32 quit = 0;
		m_handle = gau_create_handle_sound(AudioManager::m_mixer, m_sound, &loopOnFinish, &quit, NULL);
		m_handle->sound = this;
		ga_handle_play(m_handle);
		m_playing = true;
	}
	

	void setFlagAndDestroyOnFinish(ga_Handle* in_handle, void* in_context)
	{
		((Sound*)in_handle->sound)->m_playing = false;
		ga_handle_destroy(in_handle);
	}

	void loopOnFinish(ga_Handle* in_handle, void* in_context)
	{
		((Sound*)in_handle->sound)->Loop();
		ga_handle_destroy(in_handle);
	}
}	}