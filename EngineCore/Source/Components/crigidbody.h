#pragma once

#include "component.h"
#include "actor.h"

#include "../Physics/rigidbody.h"

namespace engine {	namespace component {

	class CRigidBody : public Component {
		physics::RigidBody* m_rigidbody;
	public:
		CRigidBody(float mass);
		~CRigidBody();

		void Update(float deltaTime) override;
		
		inline void SetGravityScale(float gravityScale) { m_rigidbody->SetGravityScale(gravityScale); }
	};

}	}
