#include "URNG.hpp"

#include <random>

int URNG(int min, int max) {
     if (min > max) {
         int tmp = min;
         min = max;
         max = tmp;
     }
    // uniformly-distributed integer random number
    std::random_device rd;
    // A Mersenne Twister pseudo-random generator of 32-bit numbers
    std::mt19937 gen(rd());
    // Uniform distribution
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}
