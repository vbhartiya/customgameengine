#include "cinput.h"

namespace engine { namespace component {
	ComponentRegistry CInput::reg("Input", CreateFromXML);

	engine::component::Component* CInput::CreateFromXML(tinyxml2::XMLElement* element) {
		return new CInput();
	}

	void CInput::Update(float deltaTime) {
		if (engine::input::Input::IsKeyTyped(GLFW_KEY_SPACE))
			m_parent->GetRigidBody()->AddForce(engine::maths::Vec3(0, 300, 0));

	}
}	}