#include "Mesh.h"

Mesh::Mesh(std::vector<Triangle> triangles) {
	this->triangles = triangles;
}

void Mesh::rotate(Matrix4& rotation){
	for (Triangle& t : this->triangles) {
		t.vertices[0] = t.vertices[0] * rotation;
		t.vertices[1] = t.vertices[1] * rotation;
		t.vertices[2] = t.vertices[2] * rotation;
	}
}


Mesh rotateMesh(Mesh mesh, Matrix4& rotation) {
	mesh.rotate(rotation);
	return mesh;
}