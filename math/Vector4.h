#pragma once
#include <string>
#include "Defs.h"
#include "Matrix4.h"

struct Vector4 {
	number x, y, z, w;

	void setValues(number x, number y, number z, number w);

	Vector4(number x, number y, number z, number w);

	Vector4();

	number operator * (const Vector4& vec) const;

	Vector4 operator + (number number) const;

	Vector4 operator / (number number)const;


	static Vector4* fillArrayFromMatrix(const Matrix4& m, Vector4 arr[]);

	std::string toString();

	Vector4 operator * (const Matrix4& matrix) const;

};
