#pragma once

#include <iostream>

namespace engine { namespace maths {
	
	struct Vec2 {
		float x, y;

		Vec2();
		Vec2(const float &x, const float &y);

		Vec2& add(const Vec2& other);
		Vec2& sub(const Vec2& other);
		Vec2& mul(const Vec2& other);
		Vec2& div(const Vec2& other);
		Vec2& div(const float& other);
		
		Vec2& operator+=(const Vec2& other);
		Vec2& operator-=(const Vec2& other);
		Vec2& operator*=(const Vec2& other);
		Vec2& operator/=(const Vec2& other);
		Vec2& operator/=(const float& other);

		bool operator==(const Vec2& other);
		bool operator!=(const Vec2& other);

		friend Vec2 operator+(Vec2 left, const Vec2& right);
		friend Vec2 operator-(Vec2 left, const Vec2& right);
		friend Vec2 operator*(Vec2 left, const Vec2& right);
		friend Vec2 operator/(Vec2 left, const Vec2& right);
		friend Vec2 operator/(Vec2 left, const float& right);
		
		friend std::ostream& operator<<(std::ostream& out, const Vec2& vector);
	};

}	}