#pragma once

#include "Matrix4.h"
#include "Triangle.h"
// #include "Object3D.h"

class Camera 
// : public Object3D 
{
public:
	Point position;
	Matrix4 projectionMatrix;
	number fov;
	number nearPlane;
	number farPlane;
	number aspectRatio;

	Camera();

	Camera(number aspectRatio, number nearPlane, number farPlane, number fov);

	Triangle* projectTriangle(Triangle t);

};