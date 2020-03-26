#include "hash.h"
#include <iostream>
#include <ostream>
#include <bitset>
#include <string>

int main(int argc, char** argv){
    std::bitset<7> set = (0xF << 1) + 1;
    if(argc > 1){
        std::cout << argv[1] << " is the arg\n";

        int num = strtol(argv[1], NULL, 10);
        // argv[1] >> num;

        set = Hash::IntToBitset(num);
        std::cout << set << "\n";
    }

    Hash hasher = Hash("test");
    hasher.GeneratePassword(set);
}
