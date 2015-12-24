#include "ccoliider.h"

namespace engine {	namespace component {

	CCollider::CCollider(const maths::Vec3& bottomLeft, const maths::Vec3& topRight) {
		m_collider = new physics::Collider(bottomLeft, topRight);
		m_normalized = maths::Vec2(topRight.x, topRight.y);
	}

	CCollider::CCollider(const maths::Vec3& position, const float& radius) {
		m_collider = new physics::Collider(position, radius);
		m_normalized = maths::Vec2(radius, radius);
	}

	void CCollider::Start() {
		m_collider->UpdatePosition(m_parent->GetTransform()->GetPosition());
		m_collider->UpdateSize(m_parent->GetTransform()->GetScale() * m_normalized);
	}

	void CCollider::Update(float deltaTime) {
		m_collider->UpdatePosition(m_parent->GetTransform()->GetPosition());
		m_collider->UpdateSize(m_parent->GetTransform()->GetScale() * m_normalized);
	}
	

}	}