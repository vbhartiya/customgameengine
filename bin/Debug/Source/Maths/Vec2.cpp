#include "Vec2.h"

namespace engine {	namespace maths {
	
	Vec2::Vec2() {
		x = 0.0f;
		y = 0.0f;
	}

	Vec2::Vec2(const float &x, const float &y) {
		this->x = x;
		this->y = y;
	}

	Vec2& Vec2::add(const Vec2 &other) {
		x += other.x;
		y += other.y;

		return *this;
	}

	Vec2& Vec2::sub(const Vec2 &other) {
		x -= other.x;
		y -= other.y;

		return *this;
	}

	Vec2& Vec2::mul(const Vec2 &other) {
		x *= other.x;
		y *= other.y;

		return *this;
	}

	Vec2& Vec2::div(const Vec2 &other) {
		x /= other.x;
		y /= other.y;

		return *this;
	}


	Vec2& Vec2::div(const float& other) {
		x /= other;
		y /= other;
		
		return *this;
	}

	Vec2& Vec2::operator+=(const Vec2& other) {
		return this->add(other);
	}

	Vec2& Vec2::operator-=(const Vec2& other) {
		return this->sub(other);
	}

	Vec2& Vec2::operator*=(const Vec2& other) {
		return this->mul(other);
	}

	Vec2& Vec2::operator/=(const Vec2& other) {
		return this->div(other);
	}

	Vec2& Vec2::operator/=(const float& other) {
		return this->div(other);
	}

	bool Vec2::operator==(const Vec2& other) {
		return x == other.x && y == other.y;
	}

	bool Vec2::operator!=(const Vec2& other) {
		return !(*this == other);
	}

	Vec2 operator+(Vec2 left, const Vec2& right) {
		return left.add(right);
	}

	Vec2 operator-(Vec2 left, const Vec2& right) {
		return left.sub(right);
	}

	Vec2 operator*(Vec2 left, const Vec2& right) {
		return left.mul(right);
	}

	Vec2 operator/(Vec2 left, const Vec2& right) {
		return left.div(right);
	}

	Vec2 operator/(Vec2 left, const float& right) {
		return left.div(right);
	}

	std::ostream& operator<<(std::ostream& out, const Vec2& vector) {
		return out << "(" << vector.x << ", " << vector.y << ")";
	}

}	}