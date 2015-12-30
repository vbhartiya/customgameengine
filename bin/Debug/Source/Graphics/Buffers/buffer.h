#pragma once

#include <GLEW/glew.h>

namespace engine {	namespace graphics {
		class Buffer {

		private:
			GLuint m_bufferID;
			GLuint m_componentCount;

		public:
			Buffer(GLfloat* data, GLuint count, GLuint componentCount);
			~Buffer();

			void Bind() const;
			void Unbind() const;

			inline GLuint GetComponentCount() const { return m_componentCount; }

		};
}	}
