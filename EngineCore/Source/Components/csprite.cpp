#include "csprite.h"

namespace engine {	namespace component {

	CSprite::CSprite(graphics::Layer& layer) {
		m_sprite = new graphics::Sprite();
		layer.Add(m_sprite);
	}

	CSprite::CSprite(graphics::Layer& layer, graphics::Texture* texture)
	{
		m_sprite = new graphics::Sprite(0, 0, 1, 1, texture);
		layer.Add(m_sprite);
	}

	void CSprite::Start() {
		m_sprite->SetPosition(m_parent->GetTransform()->GetPosition());
		m_sprite->SetSize(m_parent->GetTransform()->GetScale());
	}

	void CSprite::Update(float deltaTime) {
		m_sprite->SetPosition(m_parent->GetTransform()->GetPosition());
		m_sprite->SetSize(m_parent->GetTransform()->GetScale());
	}

}	}