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

	Collision Collider::IsColliding(const Collider& other) {
		Collision col;
		
		if (m_type == ColliderType::AABB && other.m_type == ColliderType::AABB)
			col =  AABBvsAABB(other);
		else if (m_type == ColliderType::Circle && other.m_type == ColliderType::Circle)
			col = CirclevsCircle(other);

		return col;
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

	Collision Collider::AABBvsAABB(const Collider& other) {
		Collision col;

		if (m_aabb.m_topRight.x < other.m_aabb.m_bottomLeft.x || m_aabb.m_bottomLeft.x > other.m_aabb.m_topRight.x)
			return col;

		if (m_aabb.m_topRight.y < other.m_aabb.m_bottomLeft.y || m_aabb.m_bottomLeft.y > other.m_aabb.m_topRight.y)
			return col;

		maths::Vec3 normal = (m_aabb.m_bottomLeft + (m_aabb.m_topRight - m_aabb.m_bottomLeft)/2.0f)
							-(other.m_aabb.m_bottomLeft + (other.m_aabb.m_topRight - other.m_aabb.m_bottomLeft) / 2.0f);

		float a_half_width = (m_aabb.m_topRight.x - m_aabb.m_bottomLeft.x) / 2.0f;
		float b_half_width = (other.m_aabb.m_topRight.x - other.m_aabb.m_bottomLeft.x) / 2.0f;

		float x_overlap = a_half_width + b_half_width - abs(normal.x);

		if (x_overlap > 0) {
			float a_half_height = (m_aabb.m_topRight.y - m_aabb.m_bottomLeft.y) / 2.0f;
			float b_half_height = (other.m_aabb.m_topRight.y - other.m_aabb.m_bottomLeft.y) / 2.0f;

			float y_overlap = a_half_height + b_half_height - abs(normal.y);

			if (y_overlap > 0) {
				if (x_overlap > y_overlap && x_overlap < a_half_width*2 && x_overlap < b_half_width*2) {
					if (normal.x < 0)
						col.normal = maths::Vec3(-1, 0, 0);
					else
						col.normal = maths::Vec3(1, 0, 0);

					col.depth = x_overlap;
				}
				else {
					if (normal.y < 0)
						col.normal = maths::Vec3(0, -1, 0);
					else 
						col.normal = maths::Vec3(0, 1, 0);

					col.depth = y_overlap;
				}
			}
		}

		return col;
	}

	Collision Collider::CirclevsCircle(const Collider& other) {
		Collision col;

		float radiusSum = m_circle.m_raidus + other.m_circle.m_raidus;
		float distSqrd = (m_circle.m_position.x - other.m_circle.m_position.x) * (m_circle.m_position.x - other.m_circle.m_position.x)
						+(m_circle.m_position.y - other.m_circle.m_position.y) * (m_circle.m_position.y - other.m_circle.m_position.y);

		if ((radiusSum*radiusSum) > distSqrd) return col;

		maths::Vec3 normal = other.m_circle.m_position - m_circle.m_position;
		float depth = normal.length();

		if (depth != 0) {
			col.depth = depth;
			col.normal = normal / depth;
		} else {
			col.depth = m_circle.m_raidus;
			col.normal = maths::Vec3(1, 0, 0);
		}

		return col;
	}

}	}