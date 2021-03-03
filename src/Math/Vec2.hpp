#pragma once

#include "Core/PCH.hpp"

struct Vec2f {
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

    // Vec2 Operations

    inline Vec2f operator+(const Vec2f& p_Other) const
    {
        return Vec2f(_mm_add_ps(this->Value, p_Other.Value));
    }

    inline Vec2f operator+=(const Vec2f& p_Other)
    {
        this->Value = _mm_add_ps(this->Value, p_Other.Value);
        return *this;
    }

    inline Vec2f operator-(const Vec2f& p_Other) const
    {
        return Vec2f(_mm_sub_ps(this->Value, p_Other.Value));
    }

    inline Vec2f operator-=(const Vec2f& p_Other)
    {
        this->Value = _mm_sub_ps(this->Value, p_Other.Value);
        return *this;
    }

    inline Vec2f operator*(const Vec2f& p_Other) const
    {
        return Vec2f(_mm_mul_ps(this->Value, p_Other.Value));
    }

    // Scalar Operations
    inline Vec2f operator*(float p_Other) const
    {
        return Vec2f(this->X * p_Other, this->Y * p_Other);
    }

    inline Vec2f operator/(float p_Other) const
    {
        return Vec2f(this->X / p_Other, this->Y / p_Other);
    }
};