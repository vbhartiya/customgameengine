#pragma once

#include "actor.h"
#include "actorfactory.h"

#include "../Graphics/Layers/layer.h"

#include <vector>

namespace engine { namespace component {

	class Scene {
	private:
		std::vector<Actor*> m_actors;
		const char* m_name, *m_filepath;
		graphics::Layer* m_layer;
	public:
		Scene(const char* name);
		Scene(const char* name, const char* filepath, graphics::Layer* layer);
		~Scene();

		void Add(Actor* actor);
		void Start();
		void Update(float deltaTime);
	};

} }