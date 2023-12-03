#pragma once
#include <cstdint>

struct Color {
	static Color white;

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
};

Color Color::white = Color((uint8_t)255, (uint8_t)255, (uint8_t)255, (uint8_t)255);
