//sg
//Author : Aman Madaan <madaan.amanmadaan@gmail.com>
#include <string.h>
#include "SDES.h"
#include <stdio.h>
#include <iostream>
#include "CharDataConverter.h"
///Define this macro to get more detailed output 
#define verbose
SDES::SDES(int initialPerm[], unsigned char *keyGeneratorInput) 
{
    this->IP = initialPerm;
    //calculate inverse permutation
    for(int i = 0; i < 8; i++) {
        R_IP[IP[i] - 1] = i + 1;
    }
    this->keyGeneratorInput = keyGeneratorInput;
    genkey();
}

unsigned char *SDES::encrypt(unsigned char *input) 
{
    int l = strlen((char*)input);
    unsigned char *res = new unsigned char[l + 1];
    unsigned char *inputBinaryString;
    unsigned char *temp;
    #ifdef verbose
    printf("Encrypting each unsigned character :\n");
    #endif
    for(int i = 0; i < l; i++) {
        inputBinaryString = CharDataConverter::CharacterToBinary(input[i]);
        #ifdef verbose
        printf("%s => ", inputBinaryString);
        #endif
        temp = permute(fK(SW(fK(permute(inputBinaryString, IP), 1)), 2), R_IP);
        #ifdef verbose
        printf("%s\n", temp);
        #endif
        res[i] = CharDataConverter::BinaryToCharacter(temp);

    }
    res[l] = '\0';
    printf("\n%s => %s\n", input, res); 
    return res;
}

unsigned char *SDES::decrypt(unsigned char *input) 
{
    int l = strlen((char*)input);
    unsigned char *res = new unsigned char[l + 1];
    unsigned char *inputBinaryString;
    unsigned char *temp;
    #ifdef verbose
    printf("Decrypting each unsigned character :\n");
    #endif
    for(int i = 0; i < l; i++) {
        inputBinaryString = CharDataConverter::CharacterToBinary(input[i]);
        #ifdef verbose
        printf("%s => ", inputBinaryString);
        #endif
        temp = permute(fK(SW(fK(permute(inputBinaryString, IP), 2)), 1), R_IP);
        #ifdef verbose
        printf("%s\n", temp);
        #endif
        res[i] = CharDataConverter::BinaryToCharacter(temp);
    }
    res[l] = '\0';
    printf("%s => %s\n", input, res); 
    return res;
}

void SDES::genkey()
{
//First, permute
    int P10[] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    keyGeneratorInput = permute(keyGeneratorInput, P10);

//rotate
    LS();

//extract key1
    int P8[] = {6, 3, 7, 4, 8, 5, 10, 9};
    for(int i = 0; i < 8; i++) {
    key1[i] = keyGeneratorInput[P8[i] - 1];
}

//rotate again, 2 times
    LS();
    LS();

//extract key2
    for(int i = 0; i < 8; i++) {
        key2[i] = keyGeneratorInput[P8[i] - 1];
    }

    key1[8] = key2[8] = '\0';
    printf("Key 1 : %s\nKey 2 : %s\n", key1, key2);
}

//perform a circular left shift
void SDES::LS()
{
    unsigned char temp1 = keyGeneratorInput[0];
    unsigned char temp2 = keyGeneratorInput[5];
    for(int i  = 0; i < 4; i++) {
        keyGeneratorInput[i] = keyGeneratorInput[i + 1];
        keyGeneratorInput[5 + i] = keyGeneratorInput[5 + i + 1];
    }

    keyGeneratorInput[4] = temp1;
    keyGeneratorInput[9] = temp2;
}

unsigned char *SDES::permute(unsigned char *input, int *permutation) 
{
    int l = strlen((char*)input);
    unsigned char * result = new unsigned char[l+1];
    for(int i = 0; i < l; i++) {
        result[i] = input[permutation[i] - 1];
    }
    return result;
}
unsigned char *SDES::F(unsigned char *input, int keyNumber)
{
    unsigned char *key = (keyNumber == 1)?(key1):(key2);
//expansion/permutation 
    int EXPANSION[] = {4, 1 ,2, 3, 2, 3, 4, 1};
    unsigned char expandedInput[9];
    for(int i = 0; i < 8; i++) {
        expandedInput[i] = input[EXPANSION[i] - 1];
    }
    expandedInput[8] = '\0';
//add the expanded input to the key

    for(int i = 0; i < 8; i++) {
// taking XOR
        expandedInput[i] = (key[i] == expandedInput[i])?('0'):('1');
    }
    
    int S0[][4] = {{1, 0, 3, 2},
                  {3, 2, 1, 0},
                  {0, 2, 1, 3},
                  {3, 1, 3, 2}};
    int S1[][4] = {{0, 1, 2, 3},
                  {2, 0, 1, 3},
                  {3, 0, 1, 0},
                  {2, 1, 0, 3}};

    int r, c, res;
//apply first half of the expanded input to S0
    r = (expandedInput[0] - 48)*2 +  (expandedInput[3] - 48);
    c = (expandedInput[1] - 48)*2 +  (expandedInput[2] - 48);
    res = S0[r][c];
    unsigned char digit1, digit2, digit3, digit4;
    digit2 = res % 2;
    digit1 =  (res / 2) % 2;

    r = (expandedInput[4] - 48)*2 +  (expandedInput[7] - 48);
    c = (expandedInput[5] - 48)*2 +  (expandedInput[6] - 48);
    res = S1[r][c];
    digit4 = res % 2;
    digit3 = (res / 2) % 2;
    unsigned char *mapping = new unsigned char[5];
    mapping[0] =  digit2 + 48;
    mapping[1] =  digit4 + 48;
    mapping[2] =  digit3 + 48;
    mapping[3] = digit1 + 48;
    mapping[4] = '\0';
    return mapping;
}

unsigned char *SDES::SW(unsigned char *input) 
{
    int l = 8;
    int mid = l / 2;
    unsigned char *temp = new unsigned char[l + 1];
    for(int i = 0; i < l; i++) {
        temp[i] = input[i];
    }
    temp[8] = '\0';
    for(int i = 0; i < mid; i++) {
        temp[i] = temp[i] ^ temp[mid + i];
        temp[mid + i] = temp[i] ^ temp[mid + i];
        temp[i] = temp[i] ^ temp[mid + i];
    }
    return temp;
}

unsigned char *SDES::fK(unsigned char *input, int keyNumber) 
{
    unsigned char *key = (keyNumber == 1)?(key1):(key2);
    //fK(L, R) = ((L ^ F(R, SK)), R)
    //get F(R, SK)
    unsigned char *mapping = F((key + 4), keyNumber); 
    unsigned char *res  = new unsigned char[9];
    //Take L ^ F(R, SK)
    for(int i = 0; i < 4; i++) {
        res[i] = (input[i] == mapping[i])?('0'):('1');
    }
    //Append the right half 
    for(int i = 4; i < 8; i++) {
        res[i] = input[i];
    }
    res[8] = '\0';
    return res;
    
}
int main() 
{
    int IP[] = {2, 6, 3, 1, 4, 8, 5, 7};
    char msg[300];
    printf("Enter your message : ");
    std::cin.getline(msg, 300, '@');
    SDES sd1(IP, (unsigned char *)"1010000010");
    unsigned char *enc = sd1.encrypt((unsigned char *)msg);
    sd1.decrypt(enc);
    return 0;
}
