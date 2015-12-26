#pragma once

#include <vector>

#include "../Graphics/Layers/group.h"

namespace engine {	namespace component {

	class Component;
	class CTransform;
	class CRigidBody;
	class CCollider;

	class Actor {
	private:
		const char* m_name;
		CTransform* m_transform;
		CRigidBody* m_rigidbody;
		std::vector< Component* > m_components;
	public:
		Actor(const char* name);
		~Actor();
		void AddComponent(Component* component);
		void AddComponent(CRigidBody* component);
		void AddComponent(CCollider* component);
		void Start();
		void Update(float deltaTime);

		inline CTransform* GetTransform() const { return m_transform; }
		inline CRigidBody* GetRigidBody() const { return m_rigidbody; }
	};

}	}
