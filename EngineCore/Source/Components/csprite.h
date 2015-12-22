#pragma once

#include "component.h"
#include "ctransform.h"
#include "actor.h"

#include "../Graphics/sprite.h"
#include "../Graphics/texture.h"
#include "../Graphics/Layers/layer.h"

namespace engine {	namespace component {

	class CSprite : public Component {
	private:
		graphics::Sprite* m_sprite;
	public:
		CSprite(graphics::Layer& layer);
		CSprite(graphics::Layer& layer, graphics::Texture* texture);

		void Start() override;
		void Update(float deltaTime) override;

		inline void SetSpriteColor(unsigned int color) { m_sprite->SetColor(color); }

		inline const graphics::Sprite& GetSprite() { return *m_sprite; }
	};

}	}
