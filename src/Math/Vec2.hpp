#pragma once

#include "Core/PCH.hpp"

template <typename T>
struct Vec2 {
	T X, Y;

	Vec2(T p_X = static_cast<T>(0), T p_Y = static_cast<T>(0)) {
		X = p_X;
		Y = p_Y;
	}

	// Vec2 Operations
	inline Vec2 operator+(const Vec2& p_Other) const {
		return Vec2(this->X + p_Other.X, this->Y + p_Other.Y);
	}

	inline Vec2& operator+=(const Vec2& p_Other) {
		this->X += p_Other.X;
		this->Y += p_Other.Y;
		return *this;
	}

	inline Vec2 operator-(const Vec2& p_Other) const {
		return Vec2(this->X - p_Other.X, this->Y - p_Other.Y);
	}

	inline Vec2& operator-=(const Vec2& p_Other) {
		this->X -= p_Other.X;
		this->Y -= p_Other.Y;
		return *this;
	}

	inline Vec2 operator*(const Vec2& p_Other) const {
		return Vec2(this->X * p_Other.X, this->Y * p_Other.Y);
	}

	// Scalar Operations
	inline Vec2 operator*(T p_Other) const {
		return Vec2(this->X * p_Other, this->Y * p_Other);
	}

	inline Vec2 operator/(T p_Other) const {
		return Vec2(this->X / p_Other, this->Y / p_Other);
	}
};