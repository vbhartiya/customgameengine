#pragma once

#include "../Maths/Maths.h"
#include "component.h"

namespace engine {	namespace component {

	class CTransform : public Component {
		friend class Actor;
	private:
		maths::Vec3 m_position;
		maths::Vec3 m_rotation;
		maths::Vec2 m_scale;

		maths::Mat4 m_rotation_matrix, m_transform_matrix;
	public:
		CTransform(Actor* parent);
		void Translate(const maths::Vec3& translation);

		void InitializeFromXML(tinyxml2::XMLElement* element);
				
		inline void SetPosition(const maths::Vec3& position) { m_position = position; SetRotationMatrix(); }
		inline void SetRotation(const maths::Vec3& rotation) { m_rotation = rotation; SetRotationMatrix(); }
		inline void SetScale   (const maths::Vec2& scale)    { m_scale = scale; }
		
		inline const maths::Vec3& GetPosition() const { return m_position; }
		inline const maths::Vec3& GetRotation() const { return m_rotation; }
		inline const maths::Vec2& GetScale() const { return m_scale; }
	private:
		void SetRotationMatrix();
	};

}	}