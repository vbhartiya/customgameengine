#include "buffer.h"

namespace engine {	namespace graphics {

	Buffer::Buffer(GLfloat* data, GLuint count, GLuint componentCount) 
		: m_componentCount(componentCount)
	{
		glGenBuffers(1, &m_bufferID);

		Bind();
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
		Unbind();

	}

	Buffer::~Buffer() {
		glDeleteBuffers(1, &m_bufferID);
	}

	void Buffer::Bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
	}

	void Buffer::Unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}	}
