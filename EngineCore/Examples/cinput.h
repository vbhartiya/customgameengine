#pragma once

#include "../Source/Input/input.h"
#include "../Source/Components/component.h"
#include "../Source/Components/crigidbody.h"


namespace engine { namespace component {
	class CInput : public engine::component::Component {
	private:
		static engine::component::ComponentRegistry reg;
	public:
		static engine::component::Component* CreateFromXML(tinyxml2::XMLElement* element);
		void Update(float deltaTime) override;
	};
}	}
