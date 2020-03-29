#include "generator.h"
#include <stdlib.h>  // for strtol
#include <random>
#include <chrono>

using namespace std;
char lowercase[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                      'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                      'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char uppercase[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                      'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                      'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char symbols[26]   = { '!', '@', '#', '$', '%', '^', '&', '*',
                       '(', ')', '_', '+', '-', '=' };


Generator::Generator(string pass){

}

void Generator::GeneratePassword(bitset<6> bits){
    int num = (int)(bits.to_ulong());

    if(num < 6){
        num = 6;
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    string newPass = "";
    for(int i=0;i<num;i++){
        newPass += "x";
    }
    cout << "This is your new password: " + newPass << endl;

}


