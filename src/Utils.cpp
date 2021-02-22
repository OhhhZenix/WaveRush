#include "Utils.hpp"

#include <random>

int Random(int p_Min, int p_Max)
{
	std::random_device f_Device;
	std::default_random_engine f_Gen(f_Device());
	std::uniform_int_distribution<int> f_Dist(p_Min, p_Max);
	return f_Dist(f_Gen);
}