#include "cinput.h"

namespace engine { namespace component {
	ComponentRegistry CInput::reg("Input", CreateFromXML);

	engine::component::Component* CInput::CreateFromXML(tinyxml2::XMLElement* element) {		
		return new CInput();
	}

	void CInput::Update(float deltaTime) {
		if (engine::input::Input::IsKeyTyped(GLFW_KEY_W))
			m_parent->GetRigidBody()->AddForce(engine::maths::Vec3(0, 400, 0));

		float axis = 0.0f;
		if (engine::input::Input::IsKeyPressed(GLFW_KEY_D))
			axis = 1.0f;
		else if (engine::input::Input::IsKeyPressed(GLFW_KEY_A))
			axis = -1.0f;
		
		m_parent->GetRigidBody()->SetVelocity(maths::Vec3(axis * 7.0f, m_parent->GetRigidBody()->GetVelocity().y, 0));
		m_parent->GetTransform()->SetRotation(maths::Vec3(0, 0,-2.0f * maths::Sign(axis) * m_parent->GetRigidBody()->GetVelocity().y));

	}
}	}