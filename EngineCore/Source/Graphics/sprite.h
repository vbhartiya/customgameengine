#pragma once

#include "renderable2D.h"
#include "../Maths/Maths.h"

namespace engine { namespace graphics {

	class Sprite : public Renderable2D {
	public :
		Sprite();
		Sprite(Texture* texture);
		Sprite(float x, float y, float width, float height, maths::Vec4 color);
		Sprite(float x, float y, float width, float height, Texture* texture);
	};

}	}
