#pragma once

#include "../Utility/fileutil.h"
#include "../Maths/Maths.h"

#include <GLEW/glew.h>
#include <vector>
#include <iostream>

namespace engine {	namespace graphics {

	class Shader {
	private:
		GLuint m_shaderID;
		const char *m_vertpath, *m_fragpath;
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void SetUniform1f(const char* name, float val);
		void SetUniform1i(const char* name, int val);
		void SetUniform1fv(const char* name, float* val, int count);
		void SetUniform1iv(const char* name, int* val, int count);

		void SetUniform2f(const char* name, const maths::Vec2& vector);
		void SetUniform3f(const char* name, const maths::Vec3& vector);
		void SetUniform4f(const char* name, const maths::Vec4& vector);

		void SetUniformMat4(const char* name, const maths::Mat4& matrix);

		void Enable() const;
		void Disable() const;
	private:
		GLuint Load();
		GLint GetUniformLocation(const GLchar* name);
	};

}	}