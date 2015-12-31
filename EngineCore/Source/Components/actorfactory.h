#pragma once

#include "actor.h"

#include "../Graphics/Layers/layer.h"

#include "../../Ext/TinyXML/tinyxml2.h"

#include <map>

namespace engine {	namespace component {

	typedef Component*(*ComponentCreator)(tinyxml2::XMLElement*);
	typedef std::map<std::string, ComponentCreator> ComponentMap;

	static class ActorFactory {
	private:
		static ComponentMap m_creators;
	private:
		static void AddComponentFromXML(Actor* actor, tinyxml2::XMLElement* element);
	protected:
		static void AddCreator(std::string name, ComponentCreator creator) { m_creators.insert(std::pair<std::string, ComponentCreator>(name, creator)); }
	public:
		static Actor* CreateActorFromXML(tinyxml2::XMLElement* element, graphics::Layer* layer = nullptr);
	};

}	}