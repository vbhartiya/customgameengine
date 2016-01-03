#pragma once

#include "component.h"
#include "ctransform.h"
#include "actor.h"

#include "../Graphics/texturemanager.h"
#include "../Graphics/sprite.h"
#include "../Graphics/texture.h"

namespace engine {	namespace component {

	class CSprite : public Component {
		friend class Actor;
	private:
		static ComponentRegistry reg;
		graphics::Sprite* m_sprite;
	public:
		static Component* CreateFromXML(tinyxml2::XMLElement* element);

		CSprite(maths::Vec4 color);
		CSprite(unsigned int color);
		CSprite(graphics::Texture* texture);
		
		inline void PostAdd() override { m_parent->ComponentAdded(this); }
		inline void SetSpriteColor(unsigned int color) { m_sprite->SetColor(color); }

		inline const graphics::Sprite& GetSprite() { return *m_sprite; }
	};

}	}
