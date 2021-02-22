#pragma once

#include <cmath>
#include <cstdint>
#include "Math.hpp"

struct Vector2f
{
	float X, Y;

	inline float Distance(const Vector2f& p_Left, const Vector2f& p_Right)
	{
		return sqrt(SquaredValue(p_Right.X - p_Left.X) + SquaredValue(p_Right.Y - p_Left.Y));
	}

	inline Vector2f Normalize(const Vector2f& p_Vec)
	{
		float f_Distance = Distance({ 0, 0 }, p_Vec);
		return { p_Vec.X / f_Distance, p_Vec.Y / f_Distance };
	}

	inline Vector2f
	operator+(const Vector2f& p_Right)
	{
		return { this->X + p_Right.X, this->Y + p_Right.Y };
	}

	inline Vector2f operator-(const Vector2f& p_Right)
	{
		return { this->X - p_Right.X, this->Y - p_Right.Y };
	}

	inline Vector2f operator*(const Vector2f& p_Right)
	{
		return { this->X * p_Right.X, this->Y * p_Right.Y };
	}
};
