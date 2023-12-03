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

	Vector3 cross(const Vector3& vec) const;

	Vector3 normalized();
};

typedef Vector3 Point;