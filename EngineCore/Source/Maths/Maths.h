#pragma once

#define _USE_MATH_DEFINES

#include <math.h>

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

namespace engine {	namespace maths {

	inline float ToRad(float degrees) {
		return degrees * ((float)M_PI / 180.0f);
	}

}	}