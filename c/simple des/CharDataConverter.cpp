//sg
//Author : Aman Madaan <madaan.amanmadaan@gmail.com>
#include "CharDataConverter.h"
#include "stdio.h"

//This class is made to help the simple des class in handling the character data
//that is passed by the user. The algorithm takes as input an 8 bit binary
//number. This class handles the conversion from a character to an 8 bit binary
//number and back.
    ///converts a character to a string that stores the binary representation
    unsigned char *CharDataConverter::CharacterToBinary(unsigned char input)
    {
        unsigned char *res = new unsigned char[9];
        int i_input = input;

        for(int i = 0; i < 8; i++) {
            res[i] = i_input % 2 + 48; 
            i_input = i_input / 2;
        }

        res[8] = '\0';
        for(int i = 0; i < 4; i++) {
            res[i] = res[i] ^ res[7 - i];
            res[7 -i] = res[i] ^ res[7 - i];
            res[i] = res[i] ^ res[7 - i];
        }

        return res;
    }
    ///provides the reverse mapping
    unsigned char CharDataConverter::BinaryToCharacter(unsigned char *input)
    {
        int res = 0;
        int pow2 = 1;
        for(int i = 7; i >= 0; i--) {
            if (input[i] == '1') {
                res += pow2;
            }
            pow2 = pow2 << 1;
        }
        return res;    
    }
