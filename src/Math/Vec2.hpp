#pragma once

#include "Core/PCH.hpp"
#include "SimdUtils.hpp"

template <typename T>
struct Vec2 {
	union {
		struct {
			T X, Y;
		};
		SimdType Value;
	};

	Vec2(T p_X = static_cast<T>(0), T p_Y = static_cast<T>(0)) {
		X = p_X;
		Y = p_Y;
	}

	Vec2(SimdType p_Value) {
		Value = p_Value;
	}

	// Vec2 Operations
	inline Vec2 operator+(const Vec2& p_Other) const {
		return Vec2(SimdAdd(this->Value, p_Other.Value));
	}

	inline Vec2& operator+=(const Vec2& p_Other) {
		this->Value = SimdAdd(this->Value, p_Other.Value);
		return *this;
	}

	inline Vec2 operator-(const Vec2& p_Other) const {
		return Vec2(SimdSub(this->Value, p_Other.Value));
	}

	inline Vec2& operator-=(const Vec2& p_Other) {
		this->Value = SimdSub(this->Value, p_Other.Value);
		return *this;
	}

	inline Vec2 operator*(const Vec2& p_Other) const {
		return Vec2(SimdMul(this->Value, p_Other.Value));
	}

	// Scalar Operations
	inline Vec2 operator*(T p_Other) const {
		return Vec2(this->X * p_Other, this->Y * p_Other);
	}

	inline Vec2 operator/(T p_Other) const {
		return Vec2(this->X / p_Other, this->Y / p_Other);
	}
};