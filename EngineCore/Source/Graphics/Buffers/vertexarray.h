#pragma once

#include <GLEW/glew.h>
#include <vector>

#include "buffer.h"

namespace engine {	namespace graphics {

	class VertexArray {
	private:
		GLuint m_arrayID;
		std::vector<Buffer*> m_buffers;
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(Buffer *buffer, GLuint index);
		void Bind() const;
		void Unbind() const;
	};

}	}