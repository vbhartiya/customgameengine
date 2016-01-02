#include "scene.h"

namespace engine { namespace component {
	
	Scene::Scene(const char* name)
		: m_name(name), m_filepath(nullptr), m_layer(nullptr)
	{

	}

	Scene::Scene(const char* name, const char* filepath, graphics::Layer* layer)
		: m_name(name), m_filepath(filepath), m_layer(layer)
	{
		tinyxml2::XMLDocument doc;
		doc.LoadFile(filepath);

		tinyxml2::XMLElement* element = doc.FirstChildElement();
		for (element = element->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {
			m_actors.push_back(ActorFactory::CreateActorFromXML(element, m_layer));
		}
	}

	Scene::~Scene() {
		for (int i = 0; i < m_actors.size(); i++)
			delete m_actors[i];

		delete m_layer;
	}

	void Scene::Add(Actor* actor) {
		m_actors.push_back(actor);
	}

	void Scene::Start() {
		for (Actor* a : m_actors) {
			a->Start();
		}
	}

	void Scene::Update(float deltaTime) {
		for (Actor* a : m_actors) {
			a->Update(deltaTime);
		}
	}

} }