#include "Color.h"

const Color Color::White(255, 255, 255);
const Color Color::Black(0, 0, 0);
const Color Color::Red(255, 0, 0);
const Color Color::Green(0, 255, 0);
const Color Color::Blue(0, 0, 255);

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
	r(red), g(green), b(blue), a(alpha)
{}

Color::Color(uint32_t hexColor) {
	r = hexColor >> 24;
	g = hexColor >> 16;
	b = hexColor >> 8;
	a = hexColor >> 0;
}
