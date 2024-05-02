#ifndef COLOR_H
#define COLOR_H
#include <cstdint>
#include <cassert>

#include "Vector3.h"

class Color {
public:
	uint8_t r, g, b, a;
	static const int max_color = 1<<(sizeof(r)*8);

	Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
	Color(){
		Color(0, 0, 0, 0);
	}

	int toInt_24() {
		return (r << 16) | (g << 8) | b;
	}

	static Color fromVector(Vector3 color) {
		assert(color.x >= 0.0 && color.x <= 1.0);
        assert(color.y >= 0.0 && color.y <= 1.0);
        assert(color.z >= 0.0 && color.z <= 1.0);
		return Color((uint8_t)(color.x * 255), (uint8_t)(color.y * 255), (uint8_t)(color.z * 255), 255);
	}

	Vector3 toVector() {
		return Vector3(static_cast<number>(r)/max_color, static_cast<number>(g)/max_color, static_cast<number>(b)/max_color);
	}

	Color operator + (Color& const other) const{
		return Color(r+other.r, g+other.g, b+other.b, a+other.a);
	}

	inline Color& operator += (Color& const other)
	{
		r += other.r;
		g += other.g;
		b += other.b;
		a += other.a;
		return *this;
	}

	Color operator * (number number) const{
		return Color(r*number, g*number, b*number, a*number);
	}

	Color operator * (const Color& color) const{
		int red = r*color.r;
		int grn = g*color.g;
		int blu = b*color.b;
		return Color(red>>8, grn>>8, blu>>8, a);
	}

	Color operator / (number number) const{
		return *this * (1/number);
	}

	inline Color& operator /= (number number){
		number = (1/number);
		r *= number;
		g *= number;
		b *= number;
		a *= number;
		return *this;
	}
};

// extern const Color COLOR_WHITE = Color((uint8_t)255, (uint8_t)255, (uint8_t)255, (uint8_t)255);

#endif