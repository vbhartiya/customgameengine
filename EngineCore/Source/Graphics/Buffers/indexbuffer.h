#pragma once

#include <GLEW/glew.h>

namespace engine {	namespace graphics {

	class IndexBuffer{

	private:
		GLuint m_bufferID;
		GLuint m_count;

	public:
		IndexBuffer(GLushort* data, GLuint count);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

		inline GLuint GetCount() const { return m_count; }

	};

}	}

