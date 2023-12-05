#ifndef COLOR_H
#define COLOR_H
#include <cstdint>
#include <cassert>

#include "Vector3.h"

class Color {
public:
	uint8_t r, g, b, a;

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
};

// extern const Color COLOR_WHITE = Color((uint8_t)255, (uint8_t)255, (uint8_t)255, (uint8_t)255);

#endif