#pragma once

#include <memory>
#include <cmath>

class Vector2 {
public:
	float x;
	float y;

public:
	static const Vector2 ZERO;
	static const Vector2 UP;
	static const Vector2 DOWN;
	static const Vector2 LEFT;
	static const Vector2 RIGHT;

public:
	inline Vector2(): x(0.f), y(0.f) {}
	inline Vector2(float x, float y): x(x), y(y) {}

	inline Vector2 operator+(const Vector2& vector) const { return {x + vector.x, y + vector.y}; }
	inline Vector2 operator-(const Vector2& vector) const { return {x - vector.x, y - vector.y}; }
	inline Vector2 operator*(float value) const { return {x * value, y * value}; }
	inline Vector2 operator/(float value) const { return {x / value, y / value}; }

	inline Vector2 operator+=(const Vector2& vector) { x += vector.x; y += vector.y; return *this; }
	inline Vector2 operator-=(const Vector2& vector) { x -= vector.x; y -= vector.y; return *this; }
	inline Vector2 operator*=(float value) { x *= value; y *= value; return *this; }
	inline Vector2 operator/=(float value) { x /= value; y /= value; return *this; }

	[[nodiscard]] inline float Length() const { return sqrtf(x * x + y * y); }
	[[nodiscard]] inline float Dot(const Vector2& vector) const { return x * vector.x + y * vector.y; }
	inline Vector2 Normalize() { float length = Length(); x /= length; y /= length; return *this;	}
};

typedef Vector2 Point;
