#include "Color.h"

const Color Color::WHITE(255, 255, 255);
const Color Color::BLACK(0, 0, 0);
const Color Color::RED(255, 0, 0);
const Color Color::GREEN(0, 255, 0);
const Color Color::BLUE(0, 0, 255);

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
	r(red), g(green), b(blue), a(alpha)
{}

Color::Color(uint32_t hexColor) {
	r = hexColor >> 24;
	g = hexColor >> 16;
	b = hexColor >> 8;
	a = hexColor >> 0;
}
