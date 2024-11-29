#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;


struct Level1 : public Level {
    private:
        int curLevel;
        std::default_random_engine rng;
        std::discrete_distribution<int> dist;
        int seed;
    public:
        Level1(int curLevel, int seed);
        std::unique_ptr<Block> createBlock();
};

#endif
