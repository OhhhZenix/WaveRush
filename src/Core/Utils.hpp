#pragma once

#include "Core/PCH.hpp"
#include "Math/Vec2.hpp"

#define SquaredValue(a) ((a) * (a))

#define LerpValue(a, b, t) ((a) + ((t) * ((b) - (a))))

#define MaxValue(a, b) (((a) > (b)) ? (a) : (b))

#define MinValue(a, b) (((a) < (b)) ? (a) : (b))

#define ClampValue(a, b, c) (MinValue(MaxValue(c, a), b))

#define Distance2D(p_X1, p_Y1, p_X2, p_Y2) sqrt(pow((p_X1) - (p_X2), 2) + pow((p_Y1) - (p_Y2), 2))

template <typename T>
inline float Random(T p_Min, T p_Max) {
	std::random_device f_RandomDevice;
	std::mt19937 f_MT(f_RandomDevice());
	std::uniform_real_distribution<T> f_Dist(p_Min, p_Max);
	return f_Dist(f_MT);
}

struct PolarCoord {
	float Angle;
	float Magnitude;

	Vec2<float> ToCartesian() const {
		return {
			Magnitude * cos(Angle),
			Magnitude * sin(Angle)
		};
	}
};