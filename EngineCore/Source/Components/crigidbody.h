#pragma once

#include "component.h"
#include "ctransform.h"

#include "../Physics/rigidbody.h"

namespace engine {	namespace component {
	class CRigidBody : public Component {
		friend class Actor;
	private:
		physics::RigidBody* m_rigidbody;
	public:
		CRigidBody(float mass);
		~CRigidBody();

		void Update(float deltaTime) override;
		
		inline void SetGravityScale(float gravityScale) { m_rigidbody->SetGravityScale(gravityScale); }
	};

}	}
