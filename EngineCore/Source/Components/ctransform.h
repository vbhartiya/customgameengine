#pragma once

#include "../Maths/Maths.h"
#include "component.h"

namespace engine {	namespace component {

	class CTransform : public Component {
	private:
		maths::Vec3 m_position;
		maths::Vec3 m_rotation;
		maths::Vec2 m_scale;
	public:
		CTransform(Actor* parent);
		void Translate(const maths::Vec3& translation);
				
		inline void SetPosition(const maths::Vec3& position) { m_position = position; }
		inline void SetRotation(const maths::Vec3& rotation) { m_rotation = rotation; }
		inline void SetScale   (const maths::Vec2& scale)    { m_scale = scale; }
		
		inline const maths::Vec3& GetPosition() const { return m_position; }
		inline const maths::Vec3& GetRotation() const { return m_rotation; }
		inline const maths::Vec2& GetScale() const { return m_scale; }
	};

}	}