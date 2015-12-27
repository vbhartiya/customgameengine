#pragma once

#include "component.h"
#include "ctransform.h"
#include "actor.h"

#include "../Graphics/sprite.h"
#include "../Graphics/texture.h"

namespace engine {	namespace component {

	class CSprite : public Component {
		friend class Actor;
	private:
		graphics::Sprite* m_sprite;
	public:
		CSprite(maths::Vec4 color);
		CSprite(graphics::Texture* texture);

		void Start() override;
		void Update(float deltaTime) override;

		inline void SetSpriteColor(unsigned int color) { m_sprite->SetColor(color); }

		inline const graphics::Sprite& GetSprite() { return *m_sprite; }
	};

}	}
