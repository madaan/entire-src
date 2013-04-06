//sg
//Author : Aman Madaan <madaan.amanmadaan@gmail.com>
class SDES
{
    unsigned char key1[9], key2[9], *keyGeneratorInput;
    //the initial permutation and it's inverse
    int *IP, R_IP[8];
    void genkey();
    unsigned char *permute(unsigned char *input, int *permutation);
    //circular left shift
    void LS();
    //4 bit mapping required by fK
    unsigned char *F(unsigned char *input, int keyNumber);
    //the switch function 
    unsigned char *SW(unsigned char *input);
    unsigned char *fK(unsigned char *input, int keyNumber);
    public :
    SDES(int *initialPermutation, unsigned char *keyGeneratorInput); 
    unsigned char *encrypt(unsigned char *msg);
    unsigned char *decrypt(unsigned char *cipher);
};
