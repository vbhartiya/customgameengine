#pragma once

#include <string>
#include <GLEW/glew.h>
#include "../Utility/imageutil.h"

namespace engine { namespace graphics {

	class Texture {
	private:
		std::string m_path;
		GLuint m_texID;
		GLsizei m_width, m_height;
	public:
		Texture(const std::string& path);
		~Texture();

		void Bind() const;
		void Unbind() const;

		inline const unsigned int GetWidth() const { return m_width; }
		inline const unsigned int GetHeight() const { return m_height; }
		inline const GLuint GetID() const { return m_texID; }
	private:
		GLuint Load();
	};

}	}
