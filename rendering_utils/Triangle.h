#pragma once
#include "Vector3.h"

class Triangle {
public:
	Vector3 vertices[3];

	Triangle(Vector3 v1, Vector3 v2, Vector3 v3);

	Triangle(const Triangle& triangle);

	Vector3 findNormal() const;
};