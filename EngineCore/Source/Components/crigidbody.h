#pragma once

#include "component.h"
#include "ctransform.h"

#include "../Maths/Maths.h"
#include "../Physics/rigidbody.h"

namespace engine {	namespace component {
	class CRigidBody : public Component {
		friend class Actor;
	private:
		physics::RigidBody* m_rigidbody;
	public:
		static CRigidBody* CreateFromXML(tinyxml2::XMLElement* element);

		CRigidBody(float mass);
		~CRigidBody();

		void Update(float deltaTime) override;
		
		inline const maths::Vec3& GetVelocity() const { return m_rigidbody->GetVelocity(); }

		inline void SetGravityScale(float gravityScale) { m_rigidbody->SetGravityScale(gravityScale); }
		inline void AddForce(const maths::Vec3& force) { m_rigidbody->AddForce(force); }
	};

}	}
