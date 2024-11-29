#ifndef LEVEL2_H
#define LEVEL2_H
#include "level.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;


struct Level2 : public Level {
    private:
        int curLevel;
        std::default_random_engine rng;
        std::discrete_distribution<int> dist;
        int seed;
    public:
        Level2(int curLevel, int seed);
        std::unique_ptr<Block> createBlock();
};

#endif
