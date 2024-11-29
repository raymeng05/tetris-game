#include "level2.h"
using namespace std;

Level2::Level2(int curLevel, int seed): Level{curLevel}, curLevel{curLevel}, seed{seed} {
    std::discrete_distribution<int>::param_type p({1, 1, 1, 1, 1, 1, 1});
    dist.param(p);
}

std::unique_ptr<Block> Level2::createBlock() {
    rng.seed(static_cast<unsigned int>(std::time(0)));
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
