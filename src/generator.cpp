#include "generator.h"
#include <stdlib.h>  // for strtol

Generator::Generator(std::string pass){

}

void Generator::GeneratePassword(std::bitset<7> bits){
    int num = (int)(bits.to_ulong());

    std::string newPass = "";
    for(int i=0;i<num;i++){
        newPass += "x";
    }
    std::cout << "This is your new password: " + newPass << std::endl;

}

std::string Generator::Hash(std::string){



    return "";
}
