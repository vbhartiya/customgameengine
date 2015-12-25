#include "physicsmanager.h"

namespace engine {	namespace physics {

	std::map<Collider*, RigidBody*> PhysicsManager::m_collidables;
	std::vector<Collider*> PhysicsManager::m_colliders;

	void PhysicsManager::Init() {

	}

	void PhysicsManager::Add(Collider* collider, RigidBody* rigidbody) {
		m_colliders.push_back(collider);
		m_collidables.insert(std::pair<Collider*, RigidBody*>(collider, rigidbody));
	}

	void PhysicsManager::Clean() {
		m_collidables.clear();
		for (int i = 0; i < m_colliders.size(); i++) {
			delete m_colliders[i];
		}

		m_colliders.clear();
	}

	void PhysicsManager::Update() {
		for (int i = 0, size = m_colliders.size() - 1; i < size; i++) {
			for (int j = i + 1; j < size + 1; j++) {
				Collision col = m_colliders[i]->IsColliding(*m_colliders[j]);
				if (col.normal != maths::Vec3(0, 0, 0)) {
					if(m_collidables[m_colliders[i]] != nullptr)
						m_collidables[m_colliders[i]]->ResolveCollision(col, m_collidables[m_colliders[j]]);

					if (m_collidables[m_colliders[j]] != nullptr)
						m_collidables[m_colliders[j]]->ResolveCollision(col, m_collidables[m_colliders[i]]);
				}
			}
		}
	}

	void PhysicsManager::Remove(Collider* collider) {
		m_collidables.erase(collider);
	}

}	}