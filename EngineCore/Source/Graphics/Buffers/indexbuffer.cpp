#include "indexbuffer.h"

namespace engine {	namespace graphics {

	IndexBuffer::IndexBuffer(GLushort* data, GLuint count)
		: m_count(count)
	{
		glGenBuffers(1, &m_bufferID);

		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
		Unbind();

	}

	IndexBuffer::~IndexBuffer() {
		glDeleteBuffers(1, &m_bufferID);
	}

	void IndexBuffer::Bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
	}

	void IndexBuffer::Unbind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}	}

