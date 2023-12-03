#include "Camera.h"

Camera::Camera() {
	this->position = Point(0.0f, 0.0f, 0.0f);
	Camera(3.0f/4.0f, 0.1f, 1000.0f, 90.0f);
}
	
Camera::Camera(number aspectRatio, number nearPlane, number farPlane, number fov) {
	this->position = Point(0.0f, 0.0f, 0.0f);
	this->aspectRatio = aspectRatio;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
	this->fov = fov;

	projectionMatrix = Matrix4::getCameraMatrix(aspectRatio, nearPlane, farPlane, fov);
	//std::cout << projectionMatrix.toString() << std::endl;
}

Triangle* Camera::projectTriangle(Triangle t) {
	t.vertices[0] = t.vertices[0] - position;
	t.vertices[1] = t.vertices[1] - position;
	t.vertices[2] = t.vertices[2] - position;

	number dot = t.findNormal() * t.vertices[0];

	if (dot >= 0.0f) {
		Triangle* projected = new Triangle(
			t.vertices[0] * this->projectionMatrix,
			t.vertices[1] * this->projectionMatrix,
			t.vertices[2] * this->projectionMatrix
		);
		return projected;
	}
	else
		return nullptr;
}

