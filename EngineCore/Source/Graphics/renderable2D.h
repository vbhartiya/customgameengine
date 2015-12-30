#pragma once

#include "../Maths/Maths.h"

#include "texture.h"
#include "shader.h"
#include "Buffers/buffer.h"
#include "Buffers/indexbuffer.h"
#include "Buffers/vertexarray.h"

#include "renderer2D.h"

namespace engine {	namespace graphics {

	struct VertexData {
		maths::Vec3 vertex;
		maths::Vec2 uv;
		float texID;
		unsigned int color;
	};

	class Renderable2D {
	protected:
		maths::Vec3 m_position;
		maths::Vec2 m_size;
		unsigned int m_color;
		std::vector<maths::Vec2> m_uv;
		Texture* m_texture;
	protected:
		Renderable2D() : m_texture(nullptr) {
			SetUVDefaults();
		}
	public:
		Renderable2D(maths::Vec3 position, maths::Vec2 size, maths::Vec4 color)
			: m_position(position), m_size(size), m_texture(nullptr)
		{
			SetColor(color);
			SetUVDefaults();
		}

		Renderable2D(maths::Vec3 position, maths::Vec2 size, unsigned int color) 
			: m_position(position), m_size(size), m_texture(nullptr), m_color(color)
		{
			SetUVDefaults();
		}

		~Renderable2D() {}

		virtual void Submit(Renderer2D* renderer, const maths::Vec2& fontScale) const {
			renderer->Submit(this);
		}

		void SetColor(unsigned int color) { m_color = color; }
		void SetColor(const maths::Vec4& color) { 
			int r = (int) (color.x * 255.0f);
			int g = (int) (color.y * 255.0f);
			int b = (int) (color.z * 255.0f);
			int a = (int) (color.w * 255.0f);

			m_color = a << 24 | b << 16 | g << 8 | r;
		}

		inline void SetPosition(const maths::Vec3& position) { m_position = position; }
		inline void SetSize(const maths::Vec2& scale) { m_size = scale; }

		inline const maths::Vec3& GetPosition() const { return m_position; }
		inline const maths::Vec2& GetSize() const { return m_size; }
		inline const unsigned int GetColor() const { return m_color; }
		inline const std::vector<maths::Vec2>& GetUV() const { return m_uv; }
		inline const GLuint GetTexID() const { return m_texture == nullptr ? 0 : m_texture->GetID(); }
	private:
		void SetUVDefaults() {
			m_uv.push_back(maths::Vec2(0, 0));
			m_uv.push_back(maths::Vec2(0, 1));
			m_uv.push_back(maths::Vec2(1, 1));
			m_uv.push_back(maths::Vec2(1, 0));
		}
	};

}	}