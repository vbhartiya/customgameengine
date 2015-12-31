#pragma once

#include "actor.h"
#include "componentregistery.h"
#include "../../Ext/TinyXML/tinyxml2.h"

namespace engine {	namespace component {

	class Component {
	protected:
		Actor* m_parent;
	public:
		Component() = default;
		Component(Actor* parent) { m_parent = parent; }

		virtual void Start() {}
		virtual void Update(float deltaTime) {}
		inline virtual void PostAdd() {}

		inline void SetParent(Actor* parent) { m_parent = parent; }

		inline const Actor& GetParent() const { return *m_parent; }
	};

}	}
