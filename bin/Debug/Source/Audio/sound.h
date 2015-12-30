#pragma once

#include <string>
#include "../Utility/stringutils.h"
#include "../../Ext/GorillaAudio/src/gorilla/ga.h"
#include "../../Ext/GorillaAudio/src/gorilla/gau.h"

namespace engine {	namespace audio {

		class Sound {

			friend void setFlagAndDestroyOnFinish(ga_Handle* in_handle, void* in_context);
		private:
			std::string m_name;
			std::string m_filename;
			ga_Sound* m_sound;
			ga_Handle* m_handle;
			float m_gain;
			bool m_playing;
						
		public:
			Sound(const std::string& m_name, const std::string& filename);
			~Sound();

			void Play();
			void Pause();
			void Resume();
			void Stop();
			void Loop();
			void SetGain(float gain);
			
			inline const bool IsPlaying() const { return m_playing; };
			inline const float GetGain() const { return m_gain; }
			inline const std::string& GetName() const { return m_name; }
			inline const std::string& GetFilename() const { return m_filename; }
		};

}	}

