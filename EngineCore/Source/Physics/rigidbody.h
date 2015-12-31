#pragma once

#include "../Maths/Maths.h"
#include "collider.h"

namespace engine {	namespace physics {

	struct MassData {
		float mass;
		float invMass;
		float inertia;
		float invInertia;

		MassData(float mass, float inertia) {
			this->mass = mass;
			this->invMass = 1.0f / mass;

			this->inertia = inertia;
			this->inertia = 1.0f / inertia;
		}
	};

	class RigidBody {
	private:
		static maths::Vec3 m_gravity;

		maths::Vec3 m_forceSum;
		maths::Vec3 m_acceleration;
		maths::Vec3 m_velocity, m_positionCorrection;
		MassData m_massData;
		float m_gravityScale, m_restitution;
	public:
		RigidBody(float mass, float inertia);

		void Update(float deltaTime);
		void AddForce(const maths::Vec3& force);

		void ResolveCollision(const Collision& normal, const RigidBody* other);

		inline void SetGravityScale(float gravityScale) { m_gravityScale = gravityScale; }
		inline void SetRestitution(float restitution) { m_restitution = restitution; }

		inline const maths::Vec3& GetVelocity() const { return m_velocity; }
		inline const float GetMass() const { return m_massData.mass; }
		inline const float GetRestitution() const { return m_restitution; }
	};

}	}