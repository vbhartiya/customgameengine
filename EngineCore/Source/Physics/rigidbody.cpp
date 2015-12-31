#include "rigidbody.h"

namespace engine {	namespace physics {

	maths::Vec3 RigidBody::m_gravity(0, -9.8f, 0);

	RigidBody::RigidBody(float mass, float inertia)	
		: m_massData(mass, inertia), m_gravityScale(1), m_restitution(0)
	{	
	}

	void RigidBody::AddForce(const maths::Vec3& force) {
		m_forceSum += force;
	}

	void RigidBody::ResolveCollision(const Collision& collision, const RigidBody* other) {
		maths::Vec3 otherVel;
		float otherRes = 0, otherMassInv = 0;

		if (other != nullptr) {
			otherVel = other->GetVelocity();
			otherRes = other->GetRestitution();
			otherMassInv = other->m_massData.invMass;
		}

		maths::Vec3 relVel = m_velocity - otherVel;
		float velAlongNormal = relVel.dot(collision.normal);

		if (velAlongNormal > 0) return;

		float e = (m_restitution < otherRes) ? m_restitution : otherRes;
		float j = -(1 + e) * velAlongNormal;
		j /= (m_massData.invMass + otherMassInv);

		maths::Vec3 impulse = j * collision.normal;
		m_velocity += m_massData.invMass * impulse;

		float percentFix = 0.2f;
		maths::Vec3 correction = collision.normal * (collision.depth / (m_massData.invMass + otherMassInv)) * percentFix;
		m_positionCorrection = correction * m_massData.invMass;
	}

	void RigidBody::Update(float deltaTime) {		
		m_forceSum += m_gravity * m_gravityScale * m_massData.mass;
		m_acceleration = m_forceSum * m_massData.invMass;
		m_velocity += m_acceleration * deltaTime + m_positionCorrection * (1/deltaTime);

		m_positionCorrection -= m_positionCorrection;
		m_forceSum -= m_forceSum;
	}

}	}