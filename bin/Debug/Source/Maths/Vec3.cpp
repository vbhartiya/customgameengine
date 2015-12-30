#include "Vec3.h"

namespace engine {	namespace maths {
	
	Vec3::Vec3() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vec3::Vec3(const float &x, const float &y) {
		this->x = x;
		this->y = y;
		z = 0.0f;
	}

	Vec3::Vec3(const float &x, const float &y, const float &z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3& Vec3::add(const Vec3 &other) {
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	Vec3& Vec3::sub(const Vec3 &other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	Vec3& Vec3::mul(const Vec3 &other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	Vec3& Vec3::mul(const float other) {
		x *= other;
		y *= other;
		z *= other;

		return *this;
	}

	Vec3& Vec3::div(const Vec3 &other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	Vec3& Vec3::div(const float other) {
		x /= other;
		y /= other;
		z /= other;

		return *this;
	}

	float Vec3::dot(const Vec3& other) {
		return x*other.x + y*other.y + z*other.z;
	}

	float Vec3::length() {
		return sqrt(this->dot(*this));
	}

	float Vec3::lengthsqrd() {
		return this->dot(*this);
	}

	Vec3& Vec3::operator+=(const Vec3& other) {
		return this->add(other);
	}

	Vec3& Vec3::operator-=(const Vec3& other) {
		return this->sub(other);
	}

	Vec3& Vec3::operator*=(const Vec3& other) {
		return this->mul(other);
	}

	Vec3& Vec3::operator/=(const Vec3& other) {
		return this->div(other);
	}

	bool Vec3::operator==(const Vec3& other) {
		return x == other.x && y == other.y && z == other.z;
	}

	bool Vec3::operator!=(const Vec3& other) {
		return !(*this == other);
	}

	Vec3 operator+(Vec3 left, const Vec3& right) {
		return left.add(right);
	}

	Vec3 operator-(Vec3 left, const Vec3& right) {
		return left.sub(right);
	}

	Vec3 operator*(Vec3 left, const Vec3& right) {
		return left.mul(right);
	}

	Vec3 operator*(Vec3 left, const float right) {
		return left.mul(right);
	}

	Vec3 operator/(Vec3 left, const Vec3& right) {
		return left.div(right);
	}

	Vec3 operator/(Vec3 left, const float right) {
		return left.div(right);
	}

	std::ostream& operator<<(std::ostream& out, const Vec3& vector) {
		return out << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	}

}	}