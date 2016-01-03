#include "ctext.h"

namespace engine {	namespace component {

	ComponentRegistry CText::reg("Label", CText::CreateFromXML);

	Component* CText::CreateFromXML(tinyxml2::XMLElement* element) {
		const char* fontName = element->Attribute("fontName");
		const char* fontPath = element->Attribute("fontPath");
		int size = element->IntAttribute("fontSize");

		CText* label = new CText(fontName, fontPath, size);

		unsigned int col = 0xFFFFFFFF;
		if (element->Attribute("fontColor"))
			col = std::stoul(element->Attribute("fontColor"), NULL, 16);

		std::string text("");
		if (element->Attribute("text"))
			text = element->Attribute("text");

		label->SetColor(col);
		label->SetText(text);

		return label;
	}

	CText::CText(const char* fontName, const char* fontPath, int size) {
		m_font = graphics::FontManager::Get(fontName, size);
		if (m_font == nullptr) {
			m_font = new graphics::Font(fontName, fontPath, size);
			graphics::FontManager::Add(m_font);
		}

		m_label = new graphics::Label("", 0, 0, 0xFFFFFFFF, m_font);
	}

	CText::~CText() {
		delete m_label;
	}
	
}	}