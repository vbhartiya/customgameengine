#include "actorfactory.h"
#include "ctransform.h"


namespace engine {	namespace component {

	ComponentMap *ActorFactory::m_creators = nullptr;

	Actor* ActorFactory::CreateActorFromXML(tinyxml2::XMLElement* element, graphics::Layer* layer) {
		Actor* newActor = new Actor(element->Attribute("name"));

		newActor->SetLayer(layer);

		for (tinyxml2::XMLElement* e = element->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
			if (std::string(e->Value()) == "Transform") {
				newActor->GetTransform()->InitializeFromXML(e);
			}
			else {
				AddComponentFromXML(newActor, e);
			}
		}

		return newActor;
	}

	void ActorFactory::AddCreator(const std::string& name, ComponentCreator creator) {
		if (m_creators == nullptr)
			m_creators = new ComponentMap();

		m_creators->insert(std::pair<std::string, ComponentCreator>(name, creator));
	}

	void ActorFactory::AddComponentFromXML(Actor* actor, tinyxml2::XMLElement* element) {
		auto it = m_creators->find(element->Value());
		if (it != m_creators->end()) {
			actor->AddComponent(it->second(element));
		}
	}

}	}