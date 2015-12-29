#include "texture.h"

namespace engine { namespace graphics {
	Texture::Texture(const std::string& path) 
		:m_path(path)
	{
		m_texID = Load();
	}

	Texture::~Texture() {

	}

	void Texture::Bind() const {
		glBindTexture(GL_TEXTURE_2D, m_texID);
	}

	void Texture::Unbind() const {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	GLuint Texture::Load() {
		BYTE* pixels = ImageUtil::Load_Image(m_path.c_str(), &m_width, &m_height);

		GLuint tex;
		glGenTextures(1, &tex);

		glBindTexture(GL_TEXTURE_2D, tex);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);

		glBindTexture(GL_TEXTURE_2D, 0);

		delete[] pixels;

		return tex;
	}

}	}