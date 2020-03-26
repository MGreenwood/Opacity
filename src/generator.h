#pragma once

#include <bitset>
#include <iostream>
#include <string>
class Generator{
    public:
        Generator(std::string pass);

        // bitset will be in the following form
        //  |   bits 1 - 6    | bit 7 |
        //  +-----------------+-------+
        //  | number of chars |symbols|
        void GeneratePassword(std::bitset<7> bits);

        static std::bitset<7> IntToBitset(int i){
            if(i > 63)
                return 0x0;

            int curr = 32, rem = i, ct = 5;
            std::bitset<7> bs;
            bs[6] = 0;
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
        static std::string Hash(std::string);
};
