#include "texturemanager.h"

namespace engine {	namespace graphics {

	std::vector<Texture*> TextureManager::m_textures;

	void TextureManager::Add(Texture* texture) {
		m_textures.push_back(texture);
	}

	Texture*TextureManager::Get(const std::string& name) {
		for (Texture* t : m_textures) {
			if (t->GetName() == name)
				return t;
		}

		return nullptr;
	}

	void TextureManager::Clean() {
		for (int i = 0; i < m_textures.size(); i++) {
			delete m_textures[i];
		}
	}

}	}