#include "crigidbody.h"

namespace engine {	namespace component {
	ComponentRegistry CRigidBody::reg("RigidBody", CreateFromXML);

	Component* CRigidBody::CreateFromXML(tinyxml2::XMLElement* element) {
		float mass = 1.0f;
		if (element->Attribute("mass")) {
			mass = element->FloatAttribute("mass");
		}

		CRigidBody* rb = new CRigidBody(mass);
		float gravityScale = 1.0f;
		if (element->Attribute("gravityScale")) {
			gravityScale = element->FloatAttribute("gravityScale");
		}
		rb->SetGravityScale(gravityScale);

		return rb;
	}

	CRigidBody::CRigidBody(float mass) {
		m_rigidbody = new physics::RigidBody(mass, mass);		
	}

	CRigidBody::~CRigidBody() {
		delete m_rigidbody;
	}

	void CRigidBody::Update(float deltaTime) {
		m_rigidbody->Update(deltaTime);
		m_parent->GetTransform()->Translate(m_rigidbody->GetVelocity() * deltaTime);
	}

}	}