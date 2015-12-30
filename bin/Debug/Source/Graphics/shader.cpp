#include "shader.h"

namespace engine {	namespace graphics {

	Shader::Shader(const char* vertPath, const char* fragPath) :
		m_vertpath(vertPath), m_fragpath(fragPath)
	{
		m_shaderID = Load();
	}

	Shader::~Shader() {
		glDeleteProgram(m_shaderID);
	}

	GLuint Shader::Load() {
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
		
		std::string vertString = FileUtil::Read_File(m_vertpath);
		std::string fragString = FileUtil::Read_File(m_fragpath);

		const char* vertSource = vertString.c_str();
		const char* fragSource = fragString.c_str();
													  
		glShaderSource(vertex, 1, &vertSource, NULL);
		glCompileShader(vertex);

		GLint result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE) {
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> log(length);
			glGetShaderInfoLog(vertex, length, &length, &log[0]);

			std::cout << "Failed to compile Vertex Shader" << std::endl << &log[0] << std::endl;
			glDeleteShader(vertex);

			return 0;
		}


		glShaderSource(fragment, 1, &fragSource, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE) {
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> log(length);
			glGetShaderInfoLog(fragment, length, &length, &log[0]);

			std::cout << "Failed to compile Fragment Shader" << std::endl << &log[0] << std::endl;
			glDeleteShader(fragment);

			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}

	void Shader::Enable() const {
		glUseProgram(m_shaderID);
	}

	void Shader::Disable() const {
		glUseProgram(0);
	}

	GLint Shader::GetUniformLocation(const GLchar* name) {
		return glGetUniformLocation(m_shaderID, name);
	}

	void Shader::SetUniform1f(const char* name, float val) {
		glUniform1f(GetUniformLocation(name), val);
	}

	void Shader::SetUniform1i(const char* name, int val) {
		glUniform1i(GetUniformLocation(name), val);
	}
	
	void Shader::SetUniform1fv(const char* name, float* val, int count) {
		glUniform1fv(GetUniformLocation(name), count, val);
	}

	void Shader::SetUniform1iv(const char* name, int* val, int count) {
		glUniform1iv(GetUniformLocation(name), count, val);
	}

	void Shader::SetUniform2f(const char* name, const maths::Vec2& vector) {
		glUniform2f(GetUniformLocation(name), vector.x, vector.y);
	}

	void Shader::SetUniform3f(const char* name, const maths::Vec3& vector) {
		glUniform3f(GetUniformLocation(name), vector.x, vector.y, vector.z);
	}

	void Shader::SetUniform4f(const char* name, const maths::Vec4& vector) {
		glUniform4f(GetUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
	}
	
	void Shader::SetUniformMat4(const char* name, const maths::Mat4& matrix) {
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, matrix.elems);
	}


}	}