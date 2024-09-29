#pragma once
#include "Defs.h"
#include "Vector4.h"
#include "Matrix4.h"

struct Vector3 {
	number x, y, z;

	void setValues(number x, number y, number z);

	Vector3(number x, number y, number z);

	Vector3(const Vector3& vec);

	Vector3();

	number magnitude();

	Vector4 toVector4() const;

	Vector3 operator + (number number) const;

	Vector3 operator / (number number) const;

	Vector3 operator * (number number) const;

	number operator * (const Vector3& vec) const;

	Vector3 operator * (const Matrix4& matrix) const;

	Vector3 operator + (const Vector3& vec) const;

	Vector3 operator - (const Vector3& vec) const;

	Vector3& operator += (const Vector3& other);

	Vector3 cross(const Vector3& vec) const;

	Vector3 normalized();

	static Vector3 random();

	static Vector3 random(double min, double max);

	number length_squared() const;

	static Vector3 random_in_unit_sphere();

	static Vector3 random_normalized_vector();

	static Vector3 random_on_hemisphere(const Vector3& normal);

	static Vector3 reflect(const Vector3& v, const Vector3& n);

	bool near_zero() ;
};

typedef Vector3 Point;