#include "group.h"

namespace engine {	namespace graphics {

	Group::Group(const maths::Mat4& transformation)
		: m_transformationMatrix(transformation)
	{

	}

	Group::~Group() {
		for (Renderable2D* r : m_renderables) {
			delete r;
		}
	}

	void Group::Submit(Renderer2D* renderer, const maths::Vec2& scale) const {
		renderer->Push(m_transformationMatrix);
		for (const Renderable2D* r : m_renderables) {
			r->Submit(renderer, scale);
		}
		renderer->Pop();
	}

	void Group::Add(Renderable2D* renderable) {
		m_renderables.push_back(renderable);
	}

}	}