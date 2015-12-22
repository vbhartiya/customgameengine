#pragma once

#include "../renderable2D.h"

namespace engine {	namespace graphics {
	
	class Group : public Renderable2D {
	private:
		std::vector<Renderable2D*> m_renderables;
		maths::Mat4 m_transformationMatrix;
	public:
		Group(const maths::Mat4& transformation);
		~Group();
		void Submit(Renderer2D* renderer, const maths::Vec2& scale) const override;
		void Add(Renderable2D* renderable);
	};

}	}