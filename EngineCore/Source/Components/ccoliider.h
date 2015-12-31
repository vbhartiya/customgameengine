#pragma once

#include "component.h"
#include "crigidbody.h"

#include "../Physics/collider.h"

namespace engine {	namespace component {

	class CCollider : public Component {
		friend class Actor;
	private:
		static ComponentRegistry regCircle, regAABB;
		physics::Collider* m_collider;
		maths::Vec3 m_normalizedCenter, m_size;
	public:
		static Component* CreateFromXML(tinyxml2::XMLElement* element);

		CCollider(const maths::Vec3& center, const maths::Vec3& size);
		CCollider(const maths::Vec3& position, const float& diameter);

		void Start() override;
		void Update(float deltaTime) override;
		inline void PostAdd() override { m_parent->ComponentAdded(this); }
	};

}	}