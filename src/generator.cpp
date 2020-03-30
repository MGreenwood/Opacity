#include "generator.h"
#include <stdlib.h>  // for strtol
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> lower {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                      'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                      'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
vector<char> upper {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                      'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                      'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> symbols   { '!', '@', '#', '$', '%', '^', '&', '*',
                       '(', ')', '_', '+', '-', '=' };
vector<char> numbers {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int minOfEach = 2;
int minLength = 8;

Generator::Generator(string pass){
    // shuffle all dictionaries
    // apparently this is the best way to generate random numbers
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(lower.begin(), lower.end(), rng);
    shuffle(upper.begin(), upper.end(), rng);
    shuffle(symbols.begin(), symbols.end(), rng);
}

void Generator::GeneratePassword(bitset<6> bits){
    int lUsed = minOfEach;
    int uUsed = minOfEach;
    int sUsed = minOfEach;
    int nUsed = minOfEach;
    int num = (int)(bits.to_ulong());

    if(num < minLength){
        num = minLength;
    }

    string newPass = "";

    for(int i=0; i<minOfEach; ++i){
        newPass += lower[i];
    }
    for(int i=0; i<minOfEach; ++i){
        newPass += upper[i];
    }
    for(int i=0; i<minOfEach; ++i){
        newPass += symbols[i];
    }
    for(int i=0; i<minOfEach; ++i){
        newPass += numbers[i];
    }
    srand(chrono::steady_clock::now().time_since_epoch().count());
    while(newPass.length() < num){
        short sel = rand() % 4;
        switch(sel){
            case 0:
                if(lUsed == lower.size())
                    continue;
                newPass += lower[lUsed];
                lUsed++;
                break;
            case 1:
                if(uUsed == upper.size())
                    continue;
                newPass += upper[uUsed];
                uUsed++;
                break;
            case 2:
                if(sUsed == symbols.size())
                    continue;
                newPass += symbols[sUsed];
                sUsed++;
                break;
            case 3:
                if(nUsed == numbers.size())
                    continue;
                newPass += numbers[nUsed];
                nUsed++;
                break;
        }
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(newPass.begin(), newPass.end(), rng);
    cout << "This is your new password: " << newPass << endl;
}


