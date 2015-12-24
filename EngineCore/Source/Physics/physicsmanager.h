#pragma once

#include <map>
#include <vector>

#include "collider.h"
#include "rigidbody.h"

namespace engine {	namespace physics {

	class PhysicsManager {
	private:
		static std::map<Collider*, RigidBody*> m_collidables;
		static std::vector<Collider*> m_colliders;
	public:
		static void Init();
		static void Add(Collider* collider, RigidBody* rigidbody);
		static void Remove(Collider* collider);
		static void Clean();
		static void Update();
	private:
		PhysicsManager();

	};

}	}