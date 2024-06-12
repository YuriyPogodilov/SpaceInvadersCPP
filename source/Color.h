#pragma once

class Color {
public:
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

public:
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}

	explicit Color(uint32_t hexColor) {
		r = hexColor >> 24;
		g = hexColor >> 16;
		b = hexColor >> 8;
		a = hexColor >> 0;
	}
};