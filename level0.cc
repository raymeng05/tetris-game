#include "level0.h"
using namespace std;


Level0::Level0(int curLevel, string f1): Level{curLevel}, curLevel{curLevel}, f1{f1} {
    readf1.open(f1);
}

std::unique_ptr<Block> Level0::createBlock() {
    //need to figure out how to differentiate players
    char s1;
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
        }
    }
}
