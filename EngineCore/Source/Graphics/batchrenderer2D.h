#pragma once

#include "renderable2D.h"
#include "Buffers/indexbuffer.h"

#include <cstddef>

namespace engine {	namespace graphics {

#define RENDERER_MAX_SPRITES	16384 // (2^16 / 4)
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6
#define RENDERER_MAX_TEXTURES	32

#define SHADER_VERTEX_INDEX 0
#define SHADER_UV_INDEX	1
#define SHADER_TEXID_INDEX	2
#define SHADER_COLOR_INDEX	3

	class BatchRenderer2D : public Renderer2D {
	private:
		IndexBuffer* m_ibo;
		GLuint m_indexCount;
		GLuint m_vao, m_vbo;
		VertexData* m_buffer;

		std::vector<GLuint> m_textureSlots;

	public:
		BatchRenderer2D();
		~BatchRenderer2D();

		void Begin() override;
		void End() override;

		void Submit(const Renderable2D *renderable) override;
		void Flush() override;

		void DrawString(const std::string& text, const maths::Vec3& position, const unsigned int col, Font& font, const maths::Vec2& scale) override;
	private:
		void Init();
	};

}	}