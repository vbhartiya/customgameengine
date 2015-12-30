#include "actorfactory.h"

namespace engine {	namespace component {


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
		if (std::string(element->Value()) == "Sprite") {
			actor->AddComponent(CSprite::CreateFromXML(element));
		} else if (std::string(element->Value()) == "RigidBody") {
			actor->AddComponent(CRigidBody::CreateFromXML(element));
		} else if (std::string(element->Value()) == "CircleCollider" || 
				   std::string(element->Value()) == "AxisAlignedBoundingBox") {
			actor->AddComponent(CCollider::CreateFromXML(element));
		}
	}

}	}