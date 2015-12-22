#include "mat4.h"

namespace engine {	namespace maths {
	
	Mat4::Mat4() {
		for (int i = 0; i < 16; i++) {
			elems[i] = 0.0f;
		}
	}

	Mat4::Mat4(float diagonal) {
		for (int i = 0; i < 16; i++) {
			elems[i] = 0.0f;
		}

		elems[0 + 0 * 4] = diagonal;
		elems[1 + 1 * 4] = diagonal;
		elems[2 + 2 * 4] = diagonal;
		elems[3 + 3 * 4] = diagonal;
	}

	Mat4::Mat4(const Mat4& original) {
		for (int i = 0; i < 16; i++) {
			elems[i] = original.elems[i];
		}
	}

	Mat4& Mat4::mul(const Mat4& other) {
		Transpose();
		float data[16];

		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4; i++) {

				data[i + j * 4] = 0.0f;
				for (int k = 0; k < 4; k++) {
					data[i + j * 4] += elems[k + j * 4] * other.elems[k + i * 4];
				}

			}
		}

		memcpy(elems, data, 16 * sizeof(float));
		
		return Transpose();
	}

	Mat4& Mat4::Transpose() {
		Swap(1, 4);
		Swap(2, 8);
		Swap(3, 12);
		Swap(6, 9);
		Swap(7, 13);
		Swap(11, 14);

		return *this;
	}


	Vec4 Mat4::mul(const Vec4 &other) const {
		return Vec4(
				cols[0].x * other.x + cols[1].x * other.y + cols[2].x * other.z + cols[3].x * other.w,
				cols[0].y * other.x + cols[1].y * other.y + cols[2].y * other.z + cols[3].y * other.w,
				cols[0].z * other.x + cols[1].z * other.y + cols[2].z * other.z + cols[3].z * other.w,
				cols[0].w * other.x + cols[1].w * other.y + cols[2].w * other.z + cols[3].w * other.w
			);
	}

	Vec3 Mat4::mul(const Vec3 &other) const {
		return Vec3(
			cols[0].x * other.x + cols[1].x * other.y + cols[2].x * other.z + cols[3].x,
			cols[0].y * other.x + cols[1].y * other.y + cols[2].y * other.z + cols[3].y,
			cols[0].z * other.x + cols[1].z * other.y + cols[2].z * other.z + cols[3].z
			);
	}

	Vec2 Mat4::mul(const Vec2 &other) const {
		return Vec2(
			cols[0].x * other.x + cols[1].x * other.y + cols[3].x,
			cols[0].y * other.x + cols[1].y * other.y + cols[3].y
			);
	}

	Mat4& Mat4::operator*=(const Mat4 &other) {
		return mul(other);
	}

	Mat4 Mat4::Identity() {
		return Mat4(1.0f);
	}

	Mat4 Mat4::Orthographic(float left, float right, float bottom, float top, float near, float far) {
		Mat4 result(1.0f);

		result.elems[0 + 0 * 4] =  2.0f / (right - left);
		result.elems[1 + 1 * 4] =  2.0f / (top - bottom);
		result.elems[2 + 2 * 4] = -2.0f / (far - near);

		result.elems[0 + 3 * 4] = (left + right) / (left - right);
		result.elems[1 + 3 * 4] = (bottom + top) / (bottom - top);
		result.elems[2 + 3 * 4] = (far + near) / (far - near);

		return result;
	}

	Mat4 Mat4::Perspective(float fov, float aspect_ratio, float near, float far) {
		Mat4 result(1.0f);

		float q = 1.0f / tan(ToRad(0.5f * fov));
		float a = q / aspect_ratio;

		float b = (near + far) / (near - far);
		float c = (2.0f * near * far) / (near - far);

		result.elems[0 + 0 * 4] = q;
		result.elems[1 + 1 * 4] = a;
		result.elems[2 + 2 * 4] = b;
		result.elems[3 + 2 * 4] = -1.0f;
		result.elems[2 + 3 * 4] = c;
		
		return result;
	}

	Mat4 Mat4::Translation(const Vec3 &translation) {
		Mat4 result(1.0f);

		result.elems[0 + 3 * 4] = translation.x;
		result.elems[1 + 3 * 4] = translation.y;
		result.elems[2 + 3 * 4] = translation.z;

		return result;
	}

	Mat4 Mat4::Rotation(float angle, const Vec3 &axis) {
		Mat4 result(1.0f);

		float r = ToRad(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;
		
		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		result.elems[0 + 0 * 4] = x * x * omc + c;
		result.elems[1 + 0 * 4] = y * x * omc + z * s;
		result.elems[2 + 0 * 4] = z * x * omc - y * s;

		result.elems[0 + 1 * 4] = x * y * omc - z * s;
		result.elems[1 + 1 * 4] = y * y * omc + c;
		result.elems[2 + 1 * 4] = y * z * omc + x * s;

		result.elems[0 + 2 * 4] = x * z * omc + y * s;
		result.elems[1 + 2 * 4] = y * z * omc - x * s;
		result.elems[2 + 2 * 4] = z * z * omc + c;

		return result;
	}

	Mat4 Mat4::Scale(const Vec3& scale) {
		Mat4 result(1.0f);

		result.elems[0 + 0 * 4] = scale.x;
		result.elems[1 + 1 * 4] = scale.y;
		result.elems[2 + 2 * 4] = scale.z;

		return result;
	}

	Mat4 operator*(Mat4 left, const Mat4& right) {
		return left.mul(right);
	}

	Vec4 operator*(const Mat4& left, const Vec4& right) {
		return left.mul(right);
	}

	Vec3 operator*(const Mat4& left, const Vec3& right) {
		return left.mul(right);
	}

	Vec2 operator*(const Mat4& left, const Vec2& right) {
		return left.mul(right);
	}

}	}