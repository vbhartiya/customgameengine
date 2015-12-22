#pragma once

#include "maths.h"

namespace engine {	namespace maths {

	struct Mat4 {
		union {
			float elems[4 * 4];
			Vec4  cols[4];
		};

		Mat4();
		Mat4(float diagonal);
		Mat4(const Mat4& original);
		
		Mat4& mul(const Mat4 &other);
		Mat4& operator*=(const Mat4 &other);

		Mat4& Transpose();

		Vec2 mul(const Vec2 &other) const;
		Vec3 mul(const Vec3 &other) const;
		Vec4 mul(const Vec4 &other) const;

		static Mat4 Identity();
		
		static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
		static Mat4 Perspective(float fov, float aspect_ratio, float near, float far);

		static Mat4 Translation(const Vec3 &translation);
		static Mat4 Rotation(float angle, const Vec3 &axis);
		static Mat4 Scale(const Vec3& scale);

		friend Mat4 operator*(Mat4 left, const Mat4& right);
		friend Vec2 operator*(const Mat4& left, const Vec2& right);
		friend Vec3 operator*(const Mat4& left, const Vec3& right);
		friend Vec4 operator*(const Mat4& left, const Vec4& right);

	private:
		inline void Swap(int index1, int index2) {
			float t = elems[index1];
			elems[index1] = elems[index2];
			elems[index2] = t;
		}
	};

}	}