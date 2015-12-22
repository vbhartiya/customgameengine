#include "sprite.h"

namespace engine {	namespace graphics {

	Sprite::Sprite()
		: Renderable2D(maths::Vec3(0, 0, 0), maths::Vec2(1, 1), maths::Vec4(1, 1, 1, 1))
	{

	}


	Sprite::Sprite(Texture* texture)
		: Renderable2D(maths::Vec3(0, 0, 0), maths::Vec2(1, 1), maths::Vec4(1, 1, 1, 1))
	{
		m_texture = texture;
	}

	Sprite::Sprite(float x, float y, float width, float height, maths::Vec4 color) 
		: Renderable2D(maths::Vec3(x, y, 0), maths::Vec2(width, height), color)
	{

	}

	Sprite::Sprite(float x, float y, float width, float height, Texture* texture)
		: Renderable2D(maths::Vec3(x, y, 0), maths::Vec2(width, height), maths::Vec4(1, 1, 1, 1))
	{
		m_texture = texture;
	}

}	}
