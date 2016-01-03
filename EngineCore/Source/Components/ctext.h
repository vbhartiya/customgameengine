#pragma once

#include "component.h"

#include "../Graphics/label.h"

namespace engine {	namespace component {

	class CText : public Component {
		friend class Actor;
	private:
		static ComponentRegistry reg;
		graphics::Label* m_label;
		graphics::Font* m_font;
	public:
		static Component* CreateFromXML(tinyxml2::XMLElement* element);

		CText(const char* fontName, const char* fontPath, int size);
		~CText();

		inline void PostAdd() override { m_parent->ComponentAdded(this); }

		inline void SetText(const std::string& text) { m_label->SetText(text); }
		inline void SetColor(const unsigned int color) { m_label->SetColor(color); }
	};

}	}