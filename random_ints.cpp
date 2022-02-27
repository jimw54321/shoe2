#include <cstdlib>
#include <ctime>
#include "random_ints.h"

void seed_rand_func()
{
    srand((unsigned int)time(nullptr));
    // Bill Weinman's advice to throw away the first call to rand().
    (void)rand();
}

// return a random integer from 0 (zero) to n-1.
int random_num(const int& n)
{
    return (int)rand() % n;
}
