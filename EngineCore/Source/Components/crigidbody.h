#pragma once

#include "component.h"
#include "ctransform.h"

#include "../Maths/Maths.h"
#include "../Physics/rigidbody.h"

namespace engine {	namespace component {
	class CRigidBody : public Component {
		friend class Actor;
	private:
		static ComponentRegistry reg;
		physics::RigidBody* m_rigidbody;
	public:
		static Component* CreateFromXML(tinyxml2::XMLElement* element);

		CRigidBody(float mass);
		~CRigidBody();

		void Update(float deltaTime) override;
		
		inline void PostAdd() override { m_parent->ComponentAdded(this); }
		
		inline void SetVelocity(const maths::Vec3& velocity) { m_rigidbody->SetVelocity(velocity); }
		inline const maths::Vec3& GetVelocity() const { return m_rigidbody->GetVelocity(); }

		inline void SetGravityScale(float gravityScale) { m_rigidbody->SetGravityScale(gravityScale); }
		inline void AddForce(const maths::Vec3& force) { m_rigidbody->AddForce(force); }
	};

}	}
