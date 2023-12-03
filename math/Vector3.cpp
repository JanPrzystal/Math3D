#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>
#include <string>

void Vector3::setValues(number x, number y, number z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(number x, number y, number z) {
	setValues(x, y, z);
}

Vector3::Vector3(const Vector3& vec) {
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;
}

Vector3::Vector3() {
	setValues(0.0f, 0.0f, 0.0f);
}

number Vector3::magnitude() {
	return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector4 Vector3::toVector4() const {
	return Vector4(this->x, this->y, this->z, (number)1);
}

Vector3 Vector3::operator + (number number) const {
	return Vector3(this->x + number, this->y + number, this->z + number);
}

Vector3 Vector3::operator / (number number) const {
	return Vector3(this->x / number, this->y / number, this->z / number);
}

Vector3 Vector3::operator * (number number) const {
	return Vector3(this->x * number, this->y * number, this->z * number);
}

number Vector3::operator * (const Vector3& vec) const {//dot product
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

Vector3 Vector3::operator * (const Matrix4& matrix) const{
	Vector4 vec4 = toVector4();
	vec4 = vec4 * matrix;
	//std::cout << "matrix mul " << vec4.toString() << std::endl;
	vec4 = vec4 / vec4.w;
	//std::cout << "divided " << vec4.toString() << std::endl;

	return Vector3(vec4.x, vec4.y, vec4.z);
}

Vector3 Vector3::operator + (const Vector3& vec) const {
	return Vector3(
		this->x + vec.x,
		this->y + vec.y,
		this->z + vec.z
	);
}

Vector3 Vector3::operator - (const Vector3& vec) const {
	return Vector3(
		this->x - vec.x,
		this->y - vec.y,
		this->z - vec.z
	);
}

Vector3 Vector3::cross(const Vector3& vec) const {
	Vector3 normal(
		this->y * vec.z - this->z * vec.y,
		this->z * vec.x - this->x * vec.z,
		this->x * vec.y - this->y * vec.x
	);
	return normal;
}

Vector3 Vector3::normalized() {
	return *this / magnitude();
}

	//std::string toString() {
	//	return "Vector3: [" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]";
	//}
