#include "level0.h"
using namespace std;


Level0::Level0(int curLevel, string f1, string f2): Level{curLevel}, curLevel{curLevel}, f1{f1}, f2{f2} {
    readf1.open(f1);
    readf2.open(f2);
}

std::unique_ptr<Block> Level0::createBlock() {
    //need to figure out how to differentiate players
    char s1;
    char s2;
    if (readf1 >> s1) {
        switch(s1) {
            case 'S': return std::make_unique<SBlock>();
            case 'Z': return std::make_unique<ZBlock>();
            case 'T': return std::make_unique<TBlock>();
            case 'O': return std::make_unique<OBlock>();
            case 'L': return std::make_unique<LBlock>();
            case 'I': return std::make_unique<IBlock>();
            case 'J': return std::make_unique<JBlock>();
        }
    } else {
        readf1.close();
        readf1.open(f1);
    }
    if (readf2 >> s2) {
        switch(s2) {
            case 'S': return std::make_unique<SBlock>();
            case 'Z': return std::make_unique<ZBlock>();
            case 'T': return std::make_unique<TBlock>();
            case 'O': return std::make_unique<OBlock>();
            case 'L': return std::make_unique<LBlock>();
            case 'I': return std::make_unique<IBlock>();
            case 'J': return std::make_unique<JBlock>();
        }
    } else {
        readf2.close();
        readf2.open(f2);
    }
}