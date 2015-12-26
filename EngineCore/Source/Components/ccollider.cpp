#include "ccoliider.h"

namespace engine {	namespace component {

	CCollider::CCollider(const maths::Vec3& center, const maths::Vec3& size)
		: m_normalizedCenter(center), m_size(size)
	{
		m_collider = new physics::Collider(center - size/2.0f, center + size/2.0f);
	}

	CCollider::CCollider(const maths::Vec3& position, const float& diameter) 
		: m_normalizedCenter(position), m_size(maths::Vec3(diameter/2.0f, diameter / 2.0f))
	{
		m_collider = new physics::Collider(position, diameter/2.0f);
	}

	void CCollider::Start() {
		Update(0);
	}

	void CCollider::Update(float deltaTime) {
		maths::Vec3 size = maths::Vec3(m_parent->GetTransform()->GetScale().x, 
									   m_parent->GetTransform()->GetScale().y) * m_size;
		m_collider->UpdateSize(maths::Vec2(size.x, size.y));
		maths::Vec3 pos = maths::Vec3(m_parent->GetTransform()->GetScale().x,
									  m_parent->GetTransform()->GetScale().y) * m_normalizedCenter;
		m_collider->UpdatePosition(m_parent->GetTransform()->GetPosition() + pos);
	}
	

}	}