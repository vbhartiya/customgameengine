#pragma once

#include <vector>
#include "Texture.h"
#include "../Maths/Maths.h"

namespace engine {	namespace graphics {

	class TextureManager {
	private:
		static std::vector<Texture*> m_textures;
	public:
		static void Add(Texture* texture);
		static Texture* Get(const std::string& name);
		static void Clean();
	private:
		TextureManager() {};

	};

}	}