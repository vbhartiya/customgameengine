#pragma once

#include "../Maths/Maths.h"
#include "component.h"

namespace engine {	namespace component {

	class CTransform : public Component {
		friend class Actor;
	private:
		maths::Vec3 m_position, m_pivot;
		maths::Vec3 m_rotation;
		maths::Vec3 m_scale;

		maths::Mat4 m_transform_matrix;
	public:
		CTransform(Actor* parent);
		void Translate(const maths::Vec3& translation);

		void InitializeFromXML(tinyxml2::XMLElement* element);
				
		inline void SetPosition(const maths::Vec3& position) { m_position = position; SetTransformMatrix(); }
		inline void SetRotation(const maths::Vec3& rotation) { m_rotation = rotation; SetTransformMatrix(); }
		inline void SetScale   (const maths::Vec3& scale)    { m_scale = scale; SetTransformMatrix(); }
		inline void SetPivot   (const maths::Vec3& pivot)	 { m_pivot = pivot; SetTransformMatrix(); }
		
		inline const maths::Vec3& GetPosition() const { return m_position; }
		inline const maths::Vec3& GetRotation() const { return m_rotation; }
		inline const maths::Vec3& GetScale() const { return m_scale; }
	private:
		void SetTransformMatrix();
	};

}	}