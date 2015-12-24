#pragma once

#include <map>

#include "collider.h"
#include "rigidbody.h"

namespace engine {	namespace physics {

	class PhysicsManager {
	private:
		static std::map<Collider*, RigidBody*> m_collidables;
	public:
		void Init();
		void Add(Collider* collider, RigidBody* rigidbody);
		void Remove(Collider* collider);
		void Clean();
		void Update();
	};

}	}