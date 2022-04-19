/**
 * @file:	 vec.h
 * 
 * @summary: Vector3 (x, y, z) class
 */

#ifndef CSGO$$$HACK_VEC_H_
#define CSGO$$$HACK_VEC_H_

class Vec3 {
public:
	float x, y, z;
public:
	Vec3() : x(0), y(0), z(0) {}
	Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
	Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
public:
	Vec3& operator=(const Vec3& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	Vec3& operator+=(const Vec3& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vec3& operator-=(const Vec3& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Vec3& operator*=(float f) {
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}

	Vec3& operator/=(float f) {
		x /= f;
		y /= f;
		z /= f;
		return *this;
	}

	Vec3 operator+(const Vec3& v) const {
		return Vec3(x + v.x, y + v.y, z + v.z);
	}

	Vec3 operator-(const Vec3& v) const {
		return Vec3(x - v.x, y - v.y, z - v.z);
	}

	Vec3 operator*(float f) const {
		return Vec3(x * f, y * f, z * f);
	}

	Vec3 operator/(float f) const {
		return Vec3(x / f, y / f, z / f);
	}
};

#endif // !CSGO$$$HACK_VEC_H_