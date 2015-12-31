#pragma once

#include "actorfactory.h"

namespace engine {	namespace component {

	class ComponentRegistry : ActorFactory {
	public:
		ComponentRegistry(std::string name, ComponentCreator creator) {
			AddCreator(name, creator);
		}
	};

}	}
