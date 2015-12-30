#include "Vec4.h"

namespace engine {	namespace maths {

	Vec4::Vec4(const float &x, const float &y) {
		this->x = x;
		this->y = y;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	Vec4::Vec4(const float &x, const float &y, const float &z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = 0.0f;
	}

	Vec4::Vec4(const float &x, const float &y, const float &z, const float &w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vec4& Vec4::add(const Vec4 &other) {
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}

	Vec4& Vec4::sub(const Vec4 &other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}

	Vec4& Vec4::mul(const Vec4 &other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;

		return *this;
	}

	Vec4& Vec4::mul(const float scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;

		return *this;
	}

	Vec4& Vec4::div(const Vec4 &other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;

		return *this;
	}

	Vec4& Vec4::operator+=(const Vec4& other) {
		return this->add(other);
	}

	Vec4& Vec4::operator-=(const Vec4& other) {
		return this->sub(other);
	}

	Vec4& Vec4::operator*=(const Vec4& other) {
		return this->mul(other);
	}

	Vec4& Vec4::operator/=(const Vec4& other) {
		return this->div(other);
	}

	bool Vec4::operator==(const Vec4& other) {
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	bool Vec4::operator!=(const Vec4& other) {
		return !(*this == other);
	}

	Vec4 operator+(Vec4 left, const Vec4& right) {
		return left.add(right);
	}

	Vec4 operator-(Vec4 left, const Vec4& right) {
		return left.sub(right);
	}

	Vec4 operator*(Vec4 left, const Vec4& right) {
		return left.mul(right);
	}

	Vec4 operator*(Vec4 left, const float right) {
		return left.mul(right);
	}

	Vec4 operator/(Vec4 left, const Vec4& right) {
		return left.div(right);
	}

	std::ostream& operator<<(std::ostream& out, const Vec4& vector) {
		return out << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
	}

}	}