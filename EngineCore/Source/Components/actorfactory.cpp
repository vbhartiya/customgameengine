#include "actorfactory.h"
#include "ctransform.h"


namespace engine {	namespace component {

	ComponentMap ActorFactory::m_creators;

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

	void ActorFactory::AddComponentFromXML(Actor* actor, tinyxml2::XMLElement* element) {
		actor->AddComponent(m_creators[element->Value()](element));
	}

}	}