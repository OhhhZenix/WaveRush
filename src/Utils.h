double clamp(double min, double max, double num)
{
    if (num <= min)
        return min;
    if (num >= max)
        return max;
    return num;
}

int random(int min, int max) //range : [min, max]
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL)); //seeding for the first time only!
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}