#pragma once

#include <vector>
#include "actor.h"

namespace engine { namespace component {

	class Scene {
	private:
		std::vector<Actor*> m_actors;
		const char* m_name;
	public:
		Scene(const char* name);
		~Scene();
		void Add(Actor* actor);
		void Update(float deltaTime);
	};

} }