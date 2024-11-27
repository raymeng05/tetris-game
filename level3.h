#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;


struct Level3 : public Level {
    private:
        int curLevel;
        std::default_random_engine rng;
        std::discrete_distribution<int> dist;
    public:
        Level3(int curLevel);
        std::unique_ptr<Block> createBlock();
};

#endif
