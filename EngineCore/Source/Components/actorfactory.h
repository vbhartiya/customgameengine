#pragma once

#include "component.h"
#include "ctransform.h"
#include "csprite.h"
#include "crigidbody.h"
#include "ccoliider.h"

#include "../Graphics/Layers/layer.h"

#include <map>

namespace engine {	namespace component {

	static class ActorFactory {
	private:
		static void AddComponentFromXML(Actor* actor, tinyxml2::XMLElement* element);
	public:
		static Actor* CreateActorFromXML(tinyxml2::XMLElement* element, graphics::Layer* layer = nullptr);
	};

}	}