#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;


struct Level4 : public Level {
    private:
        int curLevel;
        std::default_random_engine rng;
        std::discrete_distribution<int> dist;
    public:
        Level4(int curLevel);
        std::unique_ptr<Block> createBlock();
};

#endif
