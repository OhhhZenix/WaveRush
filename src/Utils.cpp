#include "Utils.hpp"

double clamp(double min, double max, double num)
{
    if (num <= min)
        return min;
    if (num >= max)
        return max;
    return num;
}

int random(int min, int max)
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL)); //seeding for the first time only!
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

double lerp(double a, double b, double t)
{
    return (a + (t * (b - a)));
}