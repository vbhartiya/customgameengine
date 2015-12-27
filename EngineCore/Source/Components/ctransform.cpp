#include "ctransform.h"

namespace engine {	namespace component {

	CTransform::CTransform(Actor* const parent) 
		: m_position(maths::Vec3(0,0,0)), m_rotation(maths::Vec3(0,0,0)), m_scale(maths::Vec2(1,1)), 
		  m_rotation_matrix(maths::Mat4::Identity()), Component(parent) {}

	void CTransform::Translate(const maths::Vec3& translation) {
		m_position += translation;
		SetRotationMatrix();
	}
	
	void CTransform::SetRotationMatrix() {
		m_rotation_matrix = maths::Mat4::Rotation(m_rotation.x, maths::Vec3(1, 0, 0)) *
							maths::Mat4::Rotation(m_rotation.y, maths::Vec3(0, 1, 0)) *
							maths::Mat4::Rotation(m_rotation.z, maths::Vec3(0, 0, 1));
		
		m_rotation_matrix = maths::Mat4::Translation(m_position) * m_rotation_matrix * maths::Mat4::Translation(-1 * m_position);

		if(m_parent->m_actor_group != nullptr)
			m_parent->m_actor_group->SetTransformation(m_rotation_matrix);
		
	}

}	}