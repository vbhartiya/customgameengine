#pragma once

#include "actorfactory.h"

namespace engine {	namespace component {

	class ComponentRegistry : ActorFactory {
	public:
		ComponentRegistry(const std::string& name, ComponentCreator creator) {
			AddCreator(name, creator);
		}
	};

}	}
