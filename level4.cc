#include "level4.h"
using namespace std;

Level4::Level4(int curLevel): Level{curLevel}, curLevel{curLevel} {
    rng.seed(static_cast<unsigned int>(std::time(0)));
    std::discrete_distribution<int>::param_type p({2, 2, 1, 1, 1, 1, 1});
    dist.param(p);
}

std::unique_ptr<Block> Level4::createBlock() {
    int ind = dist(rng);
    switch(ind) {
        case 0: return std::make_unique<SBlock>();
        case 1: return std::make_unique<ZBlock>();
        case 2: return std::make_unique<TBlock>();
        case 3: return std::make_unique<OBlock>();
        case 4: return std::make_unique<LBlock>();
        case 5: return std::make_unique<IBlock>();
        case 6: return std::make_unique<JBlock>();
    }
}

//how to implement heavy effect??
//how to implement the 1x1 block in level 4??