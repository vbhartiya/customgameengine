#pragma once

#include "component.h"
#include "crigidbody.h"

#include "../Physics/collider.h"

namespace engine {	namespace component {

	class CCollider : public Component {
		friend class Actor;
	private:
		physics::Collider* m_collider;
		maths::Vec2 m_normalized;
	public:
		CCollider(const maths::Vec3& bottomLeft, const maths::Vec3& topRight);
		CCollider(const maths::Vec3& position, const float& radius);

		void Start() override;
		void Update(float deltaTime) override;
	};

}	}