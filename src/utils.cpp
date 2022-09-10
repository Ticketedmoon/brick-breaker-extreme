#include "utils.hpp"

double Utils::randomNumber(int min, int max)
{
    static std::mt19937 rng{ std::random_device{}() };
    std::uniform_real_distribution<double> dist(min, max);
    return dist(rng);
}