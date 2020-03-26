#include "hash.h"
#include <iostream>
#include <stdlib.h>  // for strtol

Hash::Hash(std::string pass){

}

void Hash::GeneratePassword(std::bitset<7> bits){
    int num = (int)(bits.to_ulong());

    std::string newPass = "";
    for(int i=0;i<num;i++){
        newPass += "x";
    }
    std::cout << "This is your new password: " + newPass << std::endl;

}

