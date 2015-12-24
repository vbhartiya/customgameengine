#include "physicsmanager.h"

namespace engine {	namespace physics {

	std::map<Collider*, RigidBody*> PhysicsManager::m_collidables;

	void PhysicsManager::Init() {

	}

	void PhysicsManager::Add(Collider* collider, RigidBody* rigidbody) {
		m_collidables.insert(std::pair<Collider*, RigidBody*>(collider, rigidbody));
	}

	void PhysicsManager::Clean() {
		// delete all the colliders
	}

	void PhysicsManager::Update() {
		// Check for collisions. For all collisions found, call their respective rigid bodies to resolve
	}

	void PhysicsManager::Remove(Collider* collider) {
		m_collidables.erase(collider);
	}

}	}