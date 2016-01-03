#pragma once

#include "renderable2D.h"
#include "fontmanager.h"

namespace engine {	namespace graphics {
	
	class Label : public Renderable2D {
	private:
		Font* m_font;
		std::string m_text;
	public:
		Label(const std::string& text, float x, float y, unsigned int color, Font* font);
		Label(const std::string& text, float x, float y, unsigned int color, const std::string& font);
		Label(const std::string& text, float x, float y, unsigned int color, const std::string& font, unsigned int size);

		void Submit(Renderer2D* renderer, const maths::Vec2& scale) const override;
		void ValidateFont(const std::string& name, unsigned int size = 0);

		inline const void SetText(const std::string& text) { m_text = text; }
	};

}	}