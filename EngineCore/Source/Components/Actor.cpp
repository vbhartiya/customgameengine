#include "actor.h"
#include "component.h"
#include "csprite.h"
#include "ctransform.h"
#include "crigidbody.h"
#include "ccoliider.h"

#include "../Physics/physicsmanager.h"

namespace engine { namespace component {

	Actor::Actor(const char* name) {
		m_name = name;
		m_transform = new CTransform(this);
		m_rigidbody = nullptr;
		m_actor_group = nullptr;
		m_actor_layer = nullptr;
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
		m_components.back()->PostAdd();
	}

	void Actor::ComponentAdded(CSprite* component) {
		if (m_actor_group != nullptr) return;
				
		m_actor_group = new graphics::Group(m_transform->m_transform_matrix);
		m_actor_layer->Add(m_actor_group);

		m_actor_group->Add(component->m_sprite);
	}

	void Actor::ComponentAdded(CRigidBody* component) {
		if (m_rigidbody != nullptr) return;

		m_rigidbody = component;
	}

	void Actor::ComponentAdded(CCollider* component) {
		physics::PhysicsManager::Add(component->m_collider, (m_rigidbody == nullptr) ? nullptr : m_rigidbody->m_rigidbody);
	}

	void Actor::Start() {
		for (unsigned int i = 0; i < m_components.size(); i++) {
			m_components[i]->Start();
		}
	}

	void Actor::Update(float deltaTime) {
		if (!enabled) return;

		for (unsigned int i = 0; i < m_components.size(); i++) {
			m_components[i]->Update(deltaTime);
		}
	}

}	}