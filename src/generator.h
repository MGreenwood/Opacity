#pragma once

#include <bitset>
#include <iostream>
#include <string>
class Generator{
    public:
        Generator(std::string pass);

        // bitset will be in the following form
        //  |   bits 1 - 6    | bit 6 |
        //  +-----------------+-------+
        //  | number of chars |symbols|
        void GeneratePassword(std::bitset<6> bits);

        static std::bitset<6> IntToBitset(int i){
            if(i > 63)
                return 0xF;

            int curr = 32, rem = i, ct = 5;
            std::bitset<6> bs;
            while(curr >= 1)
            {
                if(rem >= curr){
                    bs[ct] = 1;
                    rem %= curr;
                }
                else{
                    bs[ct] = 0;
                }
                ct--;
                curr /= 2;
            }
            return bs;
        }
};
