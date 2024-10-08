#include "Vector4.h"
#include "Vector3.h"

void Vector4::setValues(number x, number y, number z, number w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::Vector4(number x, number y, number z, number w) {
	setValues(x, y, z, w);
}

Vector4::Vector4() {
	setValues(0.0f, 0.0f, 0.0f, 0.0f);
}

number Vector4::operator * (const Vector4& vec) const {//dot product
	return this->x * vec.x + this->y * vec.y + this->z * vec.z + this->w * vec.w;
}
Vector4 Vector4::operator + (number number) const {
	return Vector4(this->x + number, this->y + number, this->z + number, this->w + number);
}
Vector4 Vector4::operator / (number number) const {
	return Vector4(this->x / number, this->y / number, this->z / number, this->w / number);
}

Vector4* Vector4::fillArrayFromMatrix(const Matrix4& m, Vector4 arr[]) {//columns to vectors
	arr[0] = Vector4(m.matrix[0][0], m.matrix[1][0], m.matrix[2][0], m.matrix[3][0]);
	arr[1] = Vector4(m.matrix[0][1], m.matrix[1][1], m.matrix[2][1], m.matrix[3][1]);
	arr[2] = Vector4(m.matrix[0][2], m.matrix[1][2], m.matrix[2][2], m.matrix[3][2]);
	arr[3] = Vector4(m.matrix[0][3], m.matrix[1][3], m.matrix[2][3], m.matrix[3][3]);
	return arr;
}

// std::string Vector4::toString() {
// 	return "Vector4: [" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + "]";
// }

Vector4 Vector4::operator * (const Matrix4& matrix) const {
	Vector4 mat[4];
	fillArrayFromMatrix(matrix, mat);

	return Vector4(
		*this * mat[0],
		*this * mat[1],
		*this * mat[2],
		*this * mat[3]
	);
}

