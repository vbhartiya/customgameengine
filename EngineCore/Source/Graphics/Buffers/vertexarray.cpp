#include "vertexarray.h"

namespace engine {	namespace graphics {

	VertexArray::VertexArray() {
		glGenVertexArrays(1, &m_arrayID);
	}

	VertexArray::~VertexArray() {
		for (int i = 0; i < m_buffers.size(); i++) {
			delete m_buffers[i];
		}

		glDeleteVertexArrays(1, &m_arrayID);
	}

	void VertexArray::AddBuffer(Buffer *buffer, GLuint index) {
		Bind();
		buffer->Bind();

		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

		buffer->Unbind();
		Unbind();

		m_buffers.push_back(buffer);
	}

	void VertexArray::Bind() const {
		glBindVertexArray(m_arrayID);
	}

	void VertexArray::Unbind() const {
		glBindVertexArray(0);
	}

}	}