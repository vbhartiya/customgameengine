#include "collider.h"

namespace engine {	namespace physics {

	Collider::Collider(const maths::Vec3& bottomLeft, const maths::Vec3& topRight) {
		m_aabb.m_bottomLeft = bottomLeft;
		m_aabb.m_topRight = topRight;

		m_type = ColliderType::AABB;
	}

	Collider::Collider(const maths::Vec3& position, const float& radius) {
		m_circle.m_position = position;
		m_circle.m_raidus = radius;

		m_type = ColliderType::Circle;
	}

	bool Collider::IsColliding(const Collider& other) {
		if (m_type == ColliderType::AABB && other.m_type == ColliderType::AABB)
			return AABBvsAABB(other);
		else if (m_type == ColliderType::Circle && other.m_type == ColliderType::Circle)
			return CirclevsCircle(other);

		return false;
	}

	void Collider::UpdatePosition(const maths::Vec3& position) {
		switch (m_type) {
		case ColliderType::Circle:
			m_circle.m_position = position;
			break;
		case ColliderType::AABB:
			m_aabb.m_topRight = position + (m_aabb.m_topRight - m_aabb.m_bottomLeft);
			m_aabb.m_bottomLeft = position;
			break;
		}
	}

	void Collider::UpdateSize(const maths::Vec2& size) {
		switch (m_type) {
		case ColliderType::Circle:
			m_circle.m_raidus = (size.x > size.y) ? size.x : size.y;
			break;
		case ColliderType::AABB:
			m_aabb.m_topRight = m_aabb.m_bottomLeft + maths::Vec3(size.x, size.y);
			break;
		}
	}

	bool Collider::AABBvsAABB(const Collider& other) {
		if (m_aabb.m_topRight.x < other.m_aabb.m_bottomLeft.x || m_aabb.m_bottomLeft.x > other.m_aabb.m_topRight.x)
			return false;

		if (m_aabb.m_topRight.y < other.m_aabb.m_bottomLeft.y || m_aabb.m_bottomLeft.y > other.m_aabb.m_topRight.y)
			return false;

		return true;
	}

	bool Collider::CirclevsCircle(const Collider& other) {
		float radiusSum = m_circle.m_raidus + other.m_circle.m_raidus;
		float distSqrd = (m_circle.m_position.x - other.m_circle.m_position.x) * (m_circle.m_position.x - other.m_circle.m_position.x)
						+(m_circle.m_position.y - other.m_circle.m_position.y) * (m_circle.m_position.y - other.m_circle.m_position.y);

		return (radiusSum*radiusSum) < distSqrd;
	}

}	}