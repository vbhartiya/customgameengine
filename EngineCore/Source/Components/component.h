#pragma once

#include "actor.h"

namespace engine {	namespace component {

	class Component {
	protected:
		Actor* m_parent;
	public:
		Component() = default;
		Component(Actor* parent) { m_parent = parent; }

		virtual void Start() {};
		virtual void Update(float deltaTime) {};

		inline void SetParent(Actor* parent) { m_parent = parent; }

		inline const Actor& GetParent() const { return *m_parent; }
	};

}	}
