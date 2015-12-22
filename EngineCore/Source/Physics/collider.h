#pragma once

#include "../Maths/Maths.h"

namespace engine {	namespace physics {

	struct Collision {
		maths::Vec2 normal;
		float depth;
	};

	class Collider {
	private:
		enum ColliderType {AABB, Circle};

		struct AxisAlignedBoundingBox {
			maths::Vec3 m_bottomLeft;
			maths::Vec3 m_topRight;
		};

		struct CircleCollider {
			maths::Vec3 m_position;
			float m_raidus;
		};

		union {
			AxisAlignedBoundingBox m_aabb;
			CircleCollider m_circle;
		};

		ColliderType m_type;
	public:
		Collider(const maths::Vec3& bottomLeft, const maths::Vec3& topRight);
		Collider(const maths::Vec3& position, const float& radius);

		bool IsColliding(const Collider& other);
	private:
		bool AABBvsAABB(const Collider& other);
		bool CirclevsCircle(const Collider& other);

		//inline const ColliderType& GetType() const { return m_type; }
	};

}	}