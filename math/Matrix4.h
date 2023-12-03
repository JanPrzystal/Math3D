#pragma once

#include "Defs.h"
static number PI = 3.14159f;

struct Matrix4 {
	number matrix[4][4];

	Matrix4();

	Matrix4(Matrix4 &matrix);

	Matrix4(number m00, number m11, number m22, number m33);

	static Matrix4 getCameraMatrix(number aspectRatio, number nearPlane, number farPlane, number fov);
};
