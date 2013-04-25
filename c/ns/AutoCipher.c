//sg
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *cipher(char *input, int key)
{
    int l = strlen(input);
    char *cipher = malloc(l + 1);
    cipher[0] = (((input[0] - 97) + key) % 26) + 97;
    int i;
    for(i = 1; i < l; i++) {
        cipher[i] = (((input[i] - 97) + (input[i - 1] - 97)) % 26) + 97;
    }
    cipher[l] = '\0';
    return cipher;
}

char *decipher(char *input, int key)
{
    int l = strlen(input);
    int temp;
    char *plaintext = malloc(l + 1);
    temp =  ((input[0] - 97) - key);
    if (temp < 0) {
        plaintext[0] = (26 - temp) + 97;
    } else {
        plaintext[0] = temp + 97;
    }
    int i;
    for(i = 1; i < l; i++) {
       temp = (input[i] - 97) - (plaintext[i - 1] - 97);
       if (temp < 0) {
           plaintext[i] = (26 + temp) + 97;
       } else {
           plaintext[i] = temp + 97;
       }
    }
    plaintext[l] = '\0';
    return plaintext;
}
int main() 
{
    char input[100];
    int key;
    printf("Enter the message to be enrypted : ");
    scanf("%s", input);
    printf("Enter the key : ");
    scanf("%d", &key);
    char *cipherText = cipher(input, key);
    printf("Cipher text : %s\n", cipherText);
    printf("Plain Text  :%s\n", decipher(cipherText, key));
    return 0;
}
