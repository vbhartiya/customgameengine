#pragma once

#include <iostream>

namespace engine { namespace maths {
	
	struct Vec4 {
		float x, y, z, w;

		Vec4() = default;
		Vec4(const float &x, const float &y);
		Vec4(const float &x, const float &y, const float &z);
		Vec4(const float &x, const float &y, const float &z, const float &w);

		Vec4& add(const Vec4& other);
		Vec4& sub(const Vec4& other);
		Vec4& mul(const Vec4& other);
		Vec4& mul(const float scalar);
		Vec4& div(const Vec4& other);
		
		Vec4& operator+=(const Vec4& other);
		Vec4& operator-=(const Vec4& other);
		Vec4& operator*=(const Vec4& other);
		Vec4& operator/=(const Vec4& other);

		bool operator==(const Vec4& other);
		bool operator!=(const Vec4& other);

		friend Vec4 operator+(Vec4 left, const Vec4& right);
		friend Vec4 operator-(Vec4 left, const Vec4& right);
		friend Vec4 operator*(Vec4 left, const Vec4& right);
		friend Vec4 operator*(Vec4 left, const float right);
		friend Vec4 operator/(Vec4 left, const Vec4& right);
		
		friend std::ostream& operator<<(std::ostream& out, const Vec4& vector);
	};

}	}