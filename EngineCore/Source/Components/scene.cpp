#include "scene.h"

namespace engine { namespace component {
	
	Scene::Scene(const char* name)
		: m_name(name)
	{

	}

	Scene::~Scene() {
		for (int i = 0; i < m_actors.size(); i++)
			delete m_actors[i];
	}

	void Scene::Add(Actor* actor) {
		m_actors.push_back(actor);
	}

	void Scene::Update(float deltaTime) {
		for (Actor* a : m_actors) {
			a->Update(deltaTime);
		}
	}

} }