#pragma once

#include "../renderable2D.h"
#include "../renderer2D.h"

namespace engine {	namespace graphics {

	class Layer {
	protected:
		Renderer2D* m_renderer;
		std::vector<Renderable2D*> m_renderables;
		Shader* m_shader;
		maths::Mat4 m_projectionMatrix;
		maths::Vec2 m_scale;
	protected:
	public:
		Layer(Renderer2D* renderer, Shader* shader, maths::Mat4 projectionMatrix);
		void SetScale(maths::Vec2 scale);

		virtual ~Layer();

		virtual void Add(Renderable2D *renderable);
		virtual void Render();
	};

}	}
