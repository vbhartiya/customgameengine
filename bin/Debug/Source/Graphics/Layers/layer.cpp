#include "layer.h"
#pragma once

namespace engine {	namespace graphics {
	Layer::Layer(Renderer2D* renderer , Shader* shader, maths::Mat4 projectionMatrix) 
		: m_renderer(renderer), m_shader(shader), m_projectionMatrix(projectionMatrix)
	{
		int texIDs[] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 
						10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
						20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 
						30, 31};

		m_shader->Enable();
		m_shader->SetUniformMat4("pr_matrix", m_projectionMatrix);
		m_shader->SetUniform1iv("tex", texIDs, 32);
		m_shader->Disable();
	}

	Layer::~Layer() {
		delete m_shader;
		delete m_renderer;

		for (Renderable2D* r : m_renderables) {
			delete r;
		}
	}

	void Layer::Add(Renderable2D *renderable) {
		m_renderables.push_back(renderable);
	};

	void Layer::Render() {

		m_shader->Enable();

		m_renderer->Begin();
		for (const Renderable2D* r : m_renderables) {
			r->Submit(m_renderer, m_scale);
		}

		m_renderer->End();

		m_renderer->Flush();

	}

	void Layer::SetScale(maths::Vec2 scale) {
		m_scale = scale;
	}

}	}
