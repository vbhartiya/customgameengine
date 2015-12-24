#pragma once

#include <vector>

namespace engine {	namespace component {

	class Component;
	class CTransform;
	class CRigidBody;

	class Actor {
	private:
		CTransform* m_transform;
		CRigidBody* m_rigidbody;
		std::vector< Component* > m_components;
	public:
		Actor();
		~Actor();
		void AddComponent(Component* component);
		void AddComponent(CRigidBody* component);
		void Start();
		void Update(float deltaTime);

		inline CTransform* GetTransform() const { return m_transform; }
		inline CRigidBody* GetRigidBody() const { return m_rigidbody; }
	};

}	}
