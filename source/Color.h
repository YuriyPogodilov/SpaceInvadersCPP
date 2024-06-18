#pragma once
#include <cstdint>

class Color {
public:
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

public:
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
	explicit Color(uint32_t hexColor);


	static const Color White;
	static const Color Black;
	static const Color Red;
	static const Color Green;
	static const Color Blue;
};