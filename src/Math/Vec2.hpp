#pragma once

#include "Core/PCH.hpp"

struct Vec2f
{
	union
	{
		struct
		{
			float X, Y;
		};
		__m128 Value;
	};

	Vec2f(float p_X = 0.0f, float p_Y = 0.0f)
	{
		X = p_X;
		Y = p_Y;
	}

	Vec2f(__m128 p_Value)
	{
		Value = p_Value;
	}

	inline Vec2f operator+(const Vec2f& p_Other) const
	{
		return Vec2f(_mm_add_ps(this->Value, p_Other.Value));
	}
};