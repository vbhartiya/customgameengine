#include "csprite.h"

namespace engine {	namespace component {
	
	ComponentRegistry CSprite::reg("Sprite", CreateFromXML);

	Component* CSprite::CreateFromXML(tinyxml2::XMLElement* element) {
		unsigned int color = 0xFFFFFFFF;
		if (const char* s = element->Attribute("color")) {
			color = std::stoul(s, NULL, 16);
		}

		const char* texName, *texPath;
		if (texName = element->Attribute("texName")) {
			graphics::Texture* tex = graphics::TextureManager::Get(texName);
			if (tex == nullptr) {
				tex = new graphics::Texture(texName, element->Attribute("texPath"));
				graphics::TextureManager::Add(tex);
			}

			CSprite* sprite = new CSprite(tex);
			sprite->SetSpriteColor(color);
			return sprite;
		}

		return new CSprite(color);
	}

	CSprite::CSprite(maths::Vec4 color) {
		m_sprite = new graphics::Sprite(0, 0, 1, 1, color);
	}

	CSprite::CSprite(unsigned int color) {
		m_sprite = new graphics::Sprite(0, 0, 1, 1, color);
	}

	CSprite::CSprite(graphics::Texture* texture)
	{
		m_sprite = new graphics::Sprite(0, 0, 1, 1, texture);
	}

	void CSprite::Start() {
		Update(0);
	}

	void CSprite::Update(float deltaTime) {
		//m_sprite->SetPosition(m_parent->GetTransform()->GetPosition());
		//m_sprite->SetSize(m_parent->GetTransform()->GetScale());
	}
	
}	}