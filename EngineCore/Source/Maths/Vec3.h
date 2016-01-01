#pragma once

#include "Vec2.h"
#include <iostream>

namespace engine { namespace maths {
	
	struct Vec3 {
		float x, y, z;

		Vec3();
		Vec3(const float &x, const float &y);
		Vec3(const float &x, const float &y, const float &z);

		Vec3& add(const Vec3& other);
		Vec3& sub(const Vec3& other);
		Vec3& mul(const Vec3& other);
		Vec3& mul(const float other);
		Vec3& div(const Vec3& other);
		Vec3& div(const float other);

		float dot(const Vec3& other);
		float length();
		float lengthsqrd();
		
		Vec3& operator+=(const Vec3& other);
		Vec3& operator-=(const Vec3& other);
		Vec3& operator*=(const Vec3& other);
		Vec3& operator/=(const Vec3& other);

		bool operator==(const Vec3& other);
		bool operator!=(const Vec3& other);

		friend Vec3 operator+(Vec3 left, const Vec3& right);
		friend Vec3 operator-(Vec3 left, const Vec3& right);
		friend Vec3 operator*(Vec3 left, const Vec3& right);
		friend Vec3 operator*(Vec3 left, const float right);
		friend Vec3 operator/(Vec3 left, const Vec3& right);
		friend Vec3 operator/(Vec3 left, const float right);
		
		friend std::ostream& operator<<(std::ostream& out, const Vec3& vector);
	};

}	}