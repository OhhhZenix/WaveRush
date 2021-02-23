#pragma once

#include <random>

#define SquaredValue(a) ((a) * (a))

#define LerpValue(a, b, t) ((a) + ((t) * ((b) - (a))))

#define MaxValue(a, b) (((a) > (b)) ? (a) : (b))

#define MinValue(a, b) (((a) < (b)) ? (a) : (b))

#define ClampValue(a, b, c) (MinValue(MaxValue(c, a), b))

inline float RandomF(float p_Min, float p_Max)
{
	std::random_device f_RandomDevice;
	std::mt19937 f_MT(f_RandomDevice());
	std::uniform_real_distribution<float> f_Dist(p_Min, p_Max);
	return f_Dist(f_MT);
}