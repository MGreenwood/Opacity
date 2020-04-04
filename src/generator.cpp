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
vector<char> symbols   { '!', '@', '%', '^', '&', '*', '[', ']', '{', '}',
                       '(', ')', '_', '+', '-', '=', '?' };
vector<char> numbers {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
unsigned int minOfEach = 2;
unsigned int minLength = 8;

Generator::Generator(){
    // apparently this is the best way to generate random numbers
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    // shuffle all dictionaries
    shuffle(lower.begin(), lower.end(), rng);
    shuffle(upper.begin(), upper.end(), rng);
    shuffle(symbols.begin(), symbols.end(), rng);
}

void Generator::GeneratePassword(bitset<6> bits){
    unsigned int num = (int)(bits.to_ulong());

    if(num < minLength){
        num = minLength;
    }

    string newPass = "";

    // insert the minimum number of each type
    for(unsigned int i=0; i<minOfEach; ++i){
        newPass += lower[i];
        newPass += upper[i];
        newPass += symbols[i];
        newPass += numbers[i];
    }

    srand(chrono::steady_clock::now().time_since_epoch().count());
    string val;
    while(newPass.length() < num){
        short sel = rand() % 4;
        switch(sel){
            case 0:
                if(lower.size() == 0)
                    continue;
                val = lower.back();
                newPass += val;
                lower.pop_back();
                break;
            case 1:
                if(upper.size() == 0)
                    continue;
                val = upper.back();
                newPass += val;
                upper.pop_back();
                break;
            case 2:
                if(symbols.size() == 0)
                    continue;
                val = symbols.back();
                newPass += val;
                symbols.pop_back();
                break;
            case 3:
                if(numbers.size() == 0)
                    continue;
                val = numbers.back();
                newPass += val;
                numbers.pop_back();
                break;
        }
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(newPass.begin(), newPass.end(), rng);
    cout << "This is your new password: " << newPass << endl;
}


