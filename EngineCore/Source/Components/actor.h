#pragma once

#include <vector>
#include "ctransform.h"
#include "crigidbody.h"

namespace engine {	namespace component {

	class Actor {
	private:
		CTransform* m_transform;
		CRigidBody* m_rigidbody;
		std::vector< Component* > m_components;
	public:
		Actor();
		~Actor();
		void AddComponent(Component* component);
		void Start();
		void Update(float deltaTime);

		inline CTransform* GetTransform() const { return m_transform; }
		inline CRigidBody* GetRigidBody() const { return m_rigidbody; }
	};

}	}
