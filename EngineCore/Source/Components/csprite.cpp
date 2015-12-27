#include "csprite.h"

namespace engine {	namespace component {

	CSprite::CSprite(maths::Vec4 color) {
		m_sprite = new graphics::Sprite(0, 0, 1, 1, color);
	}

	CSprite::CSprite(graphics::Texture* texture)
	{
		m_sprite = new graphics::Sprite(0, 0, 1, 1, texture);
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