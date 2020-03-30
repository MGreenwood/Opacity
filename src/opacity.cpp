#include "generator.h"
#include <iostream>
#include <ostream>
#include <bitset>
#include <string>

int main(int argc, char** argv){
    // Default password is 15 characters
    // Max is 63
    std::bitset<6> set = 0xF;

    if(argc > 1){
        int num = strtol(argv[1], NULL, 10);
        set = Generator::IntToBitset(num);
    }

    Generator gen = Generator("test");
    gen.GeneratePassword(set);
}
