#include "ctransform.h"

namespace engine {	namespace component {

	CTransform::CTransform(Actor* const parent) 
		: m_position(maths::Vec3(0,0,0)), m_rotation(maths::Vec3(0,0,0)), m_scale(maths::Vec2(1,1)), 
		  m_rotation_matrix(maths::Mat4::Identity()), Component(parent) {}

	void CTransform::InitializeFromXML(tinyxml2::XMLElement* element) {
		maths::Vec3 pos = m_position, rot = m_rotation;
		maths::Vec2 scl = m_scale;

		if (element->Attribute("pX")) {
			pos.x = element->FloatAttribute("pX");
		}
		if (element->Attribute("pY")) {
			pos.y = element->FloatAttribute("pY");
		}
		if (element->Attribute("pZ")) {
			pos.z = element->FloatAttribute("pZ");
		}

		if (element->Attribute("rX")) {
			rot.x = element->FloatAttribute("rX");
		}
		if (element->Attribute("rY")) {
			rot.y = element->FloatAttribute("rY");
		}
		if (element->Attribute("rZ")) {
			rot.z = element->FloatAttribute("rZ");
		}

		if (element->Attribute("sX")) {
			scl.x = element->FloatAttribute("sX");
		}
		if (element->Attribute("sY")) {
			scl.y = element->FloatAttribute("sY");
		}

		SetPosition(pos);
		SetRotation(rot);
		SetScale(scl);
	}

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