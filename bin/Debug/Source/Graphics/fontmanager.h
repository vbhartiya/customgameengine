#pragma once

#include <vector>
#include "Font.h"
#include "../Maths/Maths.h"

namespace engine { namespace graphics {
	
	class FontManager {
	private:
		static std::vector<Font*> m_fonts;
	public:
		static void Add(Font* font);
		static Font* Get(const std::string& name);
		static Font* Get(const std::string& name, unsigned int size);
		static void Clean();
	private:
		FontManager() {};

	};
 
}	}