#include "rigidbody.h"

namespace engine {	namespace physics {

	maths::Vec3 RigidBody::m_gravity(0, -9.8f, 0);

	RigidBody::RigidBody(float mass, float inertia)	
		: m_massData(mass, inertia)
	{		
		m_forceSum = m_gravity * m_gravityScale;
	}

	void RigidBody::AddForce(const maths::Vec3& force) {
		m_forceSum += force;
	}

	void RigidBody::Update(float deltaTime) {
		m_acceleration = m_forceSum * m_massData.invMass;
		m_velocity += m_acceleration * deltaTime;
		m_forceSum = m_gravity * m_gravityScale;
	}

}	}