#pragma once

#include <vector>
#include "../Maths/Maths.h"
#include "Font.h"

namespace engine {	namespace graphics {
	
	class Renderable2D;

	class Renderer2D {
	protected:
		std::vector<maths::Mat4> m_transformationStack;
		const maths::Mat4 *m_transformationBack;
	protected:
		Renderer2D() {
			m_transformationStack.push_back(maths::Mat4::Identity());
			m_transformationBack = &m_transformationStack.back();
		}
	public:
		void Push(const maths::Mat4& matrix, bool overrideLast = false) {
			if(overrideLast)
				m_transformationStack.push_back(matrix);
			else
				m_transformationStack.push_back(matrix * m_transformationStack.back());

			m_transformationBack = &m_transformationStack.back();
		}

		void Pop() {
			if (m_transformationStack.size() > 1)
				m_transformationStack.pop_back();

			m_transformationBack = &m_transformationStack.back();

			// TODO: Add to log
		}

		virtual void Submit(const Renderable2D *renderable) = 0;
		virtual void Flush() = 0;

		virtual void DrawString(const std::string& text, const maths::Vec3& position, const unsigned int col, Font& font, const maths::Vec2& scale) { };
		virtual void Begin() {};
		virtual void End() {};
	};

}	}