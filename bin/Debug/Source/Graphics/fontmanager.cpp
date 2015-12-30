#include "fontmanager.h"

namespace engine {	namespace graphics {

	std::vector<Font*> FontManager::m_fonts;

	void FontManager::Add(Font* font) {
		m_fonts.push_back(font);
	}

	Font* FontManager::Get(const std::string& name) {
		for (Font* f : m_fonts) {
			if (f->GetName() == name)
				return f;
		}

		return nullptr;
	}

	Font* FontManager::Get(const std::string& name, unsigned int size) {
		for (Font* f : m_fonts) {
			if (f->GetSize() == size && f->GetName() == name)
				return f;
		}

		return nullptr;
	}

	void FontManager::Clean() {
		for (int i = 0; i < m_fonts.size(); i++) {
			delete m_fonts[i];
		}
	}

}	}