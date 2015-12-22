#include "ctransform.h"

namespace engine {	namespace component {

	CTransform::CTransform(Actor* const parent) 
		: m_position(maths::Vec3(0,0,0)), m_rotation(maths::Vec3(0,0,0)), m_scale(maths::Vec2(1,1)), Component(parent) {}

	void CTransform::Translate(const maths::Vec3& translation) {
		m_position += translation;
	}

}	}