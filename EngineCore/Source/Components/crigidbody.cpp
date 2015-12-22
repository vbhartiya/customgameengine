#include "crigidbody.h"

namespace engine {	namespace component {

	CRigidBody::CRigidBody(float mass) {
		m_rigidbody = new physics::RigidBody(mass, mass);		
	}

	CRigidBody::~CRigidBody() {
		delete m_rigidbody;
	}

	void CRigidBody::Update(float deltaTime) {
		m_rigidbody->Update(deltaTime);
		m_parent->GetTransform()->Translate(m_rigidbody->GetVelocity() * deltaTime);
	}

}	}