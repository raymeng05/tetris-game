#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"
#include <string>
#include <fstream>
using namespace std;



struct Level0 : public Level {
    private:
        int curLevel;
        string f1;
        ifstream readf1; 
    public:
        Level0(int curLevel, string f1);
        std::unique_ptr<Block> createBlock();
};

#endif
