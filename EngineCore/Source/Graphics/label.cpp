#include "label.h"
namespace engine {	namespace graphics {

	Label::Label(const std::string& text, float x, float y, unsigned int color, Font* font)
		: Renderable2D(), m_text(text), m_font(font)
	{
		m_position = maths::Vec3(x, y, 0);
		SetColor(color);
	}

	Label::Label(const std::string& text, float x, float y, unsigned int color, const std::string& font)
		: Renderable2D(), m_text(text), m_font(FontManager::Get(font))
	{
		m_position = maths::Vec3(x, y, 0);
		SetColor(color);

		ValidateFont(font);
	}

	Label::Label(const std::string& text, float x, float y, unsigned int color, const std::string& font, unsigned int size)
		: Renderable2D(), m_text(text), m_font(FontManager::Get(font, size))
	{
		m_position = maths::Vec3(x, y, 0);
		SetColor(color);

		ValidateFont(font, size);
	}

	void Label::ValidateFont(const std::string& name, unsigned int size) {
		if (m_font == nullptr) {
			std::cout << "NULL font! Name : " << name;

			if (size > 0)
				std::cout << " Size : " << size;

			std::cout << std::endl;

			m_font = FontManager::Get("arial");
		}
	}

	void Label::Submit(Renderer2D* renderer, const maths::Vec2& scale) const {
		renderer->DrawString(m_text, m_position, m_color, *m_font, scale);
	}

}	}
