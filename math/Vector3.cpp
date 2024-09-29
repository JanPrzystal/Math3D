#include "Vector3.h"
#include "Vector4.h"
#include "util.h"
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

Vector3& Vector3::operator += (const Vector3& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
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

Vector3 Vector3::random() {
	return Vector3(random_number(), random_number(), random_number());
}

Vector3 Vector3::random(double min, double max) {
	return Vector3(random_number(min,max), random_number(min,max), random_number(min,max));
}

number Vector3::length_squared() const {
	return this->x*this->x + this->y*this->y + this->z*this->z;
}

Vector3 Vector3::random_in_unit_sphere() {
    while (true) {
        auto p = Vector3::random(-1,1);
        if (p.length_squared() < 1)
            return p;
    }
}

Vector3 Vector3::random_normalized_vector() {
    return random_in_unit_sphere().normalized();
}

Vector3 Vector3::random_on_hemisphere(const Vector3& normal) {
    Vector3 on_sphere = random_normalized_vector();
    if (on_sphere * normal > 0.0) // In the same hemisphere as the normal
        return on_sphere;
    else
        return on_sphere * -1;
}

bool Vector3::near_zero() {
	// Return true if the vector is close to zero in all dimensions.
	auto s = 1e-8;
	return (fabs(this->x) < s) && (fabs(this->y) < s) && (fabs(this->z) < s);
}

Vector3 Vector3::reflect(const Vector3& v, const Vector3& n) {
    return v - n*((v*n)*2);
}

	//std::string toString() {
	//	return "Vector3: [" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]";
	//}

//BELOW ARE METHODS WITH INTRINSIC VECTOR OPERATIONS. TESTED TO BE SLOWER
// Vector3 Vector3::operator * (number number) const {
// 	__m128 a = _mm_set_ps(x, y, z, 0);
// 	__m128 b = _mm_set_ps(number, number, number, 0);
// 	__m128 result = _mm_mul_ps(a, b);
// 	return Vector3(result.m128_f32[3], result.m128_f32[2], result.m128_f32[1]);
// }

// number Vector3::operator * (const Vector3& vec) const {//dot product
// 	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
// }

// Vector3 Vector3::operator * (const Matrix4& matrix) const{
// 	Vector4 vec4 = toVector4();
// 	vec4 = vec4 * matrix;
// 	//std::cout << "matrix mul " << vec4.toString() << std::endl;
// 	vec4 = vec4 / vec4.w;
// 	//std::cout << "divided " << vec4.toString() << std::endl;

// 	return Vector3(vec4.x, vec4.y, vec4.z);
// }

// Vector3 Vector3::operator + (const Vector3& vec) const {
// 	__m128 a = _mm_set_ps(x, y, z, 0.0f);
// 	__m128 b = _mm_set_ps(vec.x, vec.y, vec.z, 0.0f);
// 	__m128 result = _mm_add_ps(a, b);

// 	return Vector3(
// 		result.m128_f32[3],
// 		result.m128_f32[2],
// 		result.m128_f32[1]
// 	);
// }

// Vector3 Vector3::operator - (const Vector3& vec) const {
// 	return Vector3(
// 		this->x - vec.x,
// 		this->y - vec.y,
// 		this->z - vec.z
// 	);
// }

// Vector3& Vector3::operator += (Vector3& const vec)
// {
// 	__m128 a = _mm_set_ps(x, y, z, 0);
// 	__m128 b = _mm_set_ps(vec.x, vec.y, vec.z, 0);
// 	__m128 result = _mm_add_ps(a, b);

// 	this->x = result.m128_f32[3];
// 	this->y = result.m128_f32[2];
// 	this->z = result.m128_f32[1];
// 	return *this;
// }

