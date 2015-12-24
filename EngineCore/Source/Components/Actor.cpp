#include "actor.h"
#include "component.h"
#include "ctransform.h"
#include "crigidbody.h"

namespace engine { namespace component {

	Actor::Actor() {
		m_transform = new CTransform(this);
		m_rigidbody = nullptr;
	}

	Actor::~Actor() {
		for (unsigned int i = 0; i < m_components.size(); i++) {
			delete m_components[i];
		}
		delete	m_transform;
	}

	void Actor::AddComponent(Component* component) {		
		m_components.push_back(component);
		m_components.back()->SetParent(this);
	}

	void Actor::AddComponent(CRigidBody* component) {
		m_components.push_back(component);
		m_components.back()->SetParent(this);

		m_rigidbody = component;
	}

	void Actor::Start() {
		for (unsigned int i = 0; i < m_components.size(); i++) {
			m_components[i]->Start();
		}
	}

	void Actor::Update(float deltaTime) {
		for (unsigned int i = 0; i < m_components.size(); i++) {
			m_components[i]->Update(deltaTime);
		}
	}

}	}