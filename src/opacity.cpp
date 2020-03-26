#include "generator.h"
#include <iostream>
#include <ostream>
#include <bitset>
#include <string>

int main(int argc, char** argv){
    std::bitset<7> set = (0xF << 1) + 1;

    if(argc > 1){
        int num = strtol(argv[1], NULL, 10);
        set = Generator::IntToBitset(num);
    }

    Generator gen = Generator("test");
    gen.GeneratePassword(set);
}
