#pragma once
#include "Triangle.h"
#include <vector>

class Mesh {
public:
	std::vector<Triangle> triangles;

	Mesh(std::vector<Triangle> triangles);

	void rotate(Matrix4& rotation);
};

Mesh rotateMesh(Mesh mesh, Matrix4& rotation);