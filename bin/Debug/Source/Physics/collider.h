#pragma once

#include "../Maths/Maths.h"

namespace engine {	namespace physics {

	struct Collision {
		maths::Vec3 normal;
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

		void UpdatePosition(const maths::Vec3& position);
		void UpdateSize(const maths::Vec2& size);

		Collision IsColliding(const Collider& other);
	private:
		Collision AABBvsAABB(const Collider& other);
		Collision CirclevsCircle(const Collider& other);
		Collision AABBvsCircle(const Collider& other);

		//inline const ColliderType& GetType() const { return m_type; }
	};

}	}