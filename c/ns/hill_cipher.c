//sg
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
///returns the multiplicative inverse of the given number
///in modulo 26
int mulInverse(int x) 
{
	int testers[]= {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
	int numEle = 12;
	int i = 0;
	for(i = 0; i < numEle; i++) {
		if ((testers[i] * x) % 26 == 1) {
			return testers[i];
		}
	}
	return -1;
}

///returns the determinant of a 3 X 3 matrix
int det(int mat[][3]) 
{
	return 
	mat[0][0]*(mat[1][1] * mat[2][2] - mat[1][2]*mat[2][1])
	-  mat[0][1]*(mat[1][0] * mat[2][2] - mat[1][2]*mat[2][0])
	+ mat[0][2]*(mat[1][0] * mat[2][1] - mat[1][1]*mat[2][0]);
}	

///calculates the transpose of a 3 X 3 matrix
void transpose(int **mat) 
{
	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = i + 1; j < 3; j++) {
			mat[i][j] ^= mat[j][i];
			mat[j][i] ^= mat[i][j];
			mat[i][j] ^= mat[j][i];
		}
	}
}

///calculates adjoint of a matrix
int** adjoint(int mat[][3]) 
{
	int **res;
	int i = 0;
	res = (int **)malloc(3 * sizeof(int *));
	for(i = 0; i < 3; i++) {
		res[i] = (int *)malloc(3 * sizeof(int));		
	}
	res[0][0] = mat[1][1] * mat[2][2] - mat[1][2]*mat[2][1];
	res[0][1] = -(mat[1][0] * mat[2][2] - mat[1][2]*mat[2][0]);
	res[0][2] = mat[1][0] * mat[2][1] - mat[1][1]*mat[2][0];
	res[1][0] = -(mat[0][1] * mat[2][2] - mat[0][2]*mat[2][1]);
	res[1][1] = (mat[0][0] * mat[2][2] - mat[0][2]*mat[2][0]);
	res[1][2] = -(mat[0][0] * mat[2][1] - mat[0][1]*mat[2][0]);
	res[2][0] = mat[0][1] * mat[1][2] - mat[0][2]*mat[1][1];
	res[2][1] = -(mat[0][0] * mat[1][2] - mat[0][2]*mat[1][0]);
	res[2][2] = mat[0][0] * mat[1][1] - mat[0][1]*mat[1][0];
    transpose(res); //adjoint is the transpose of cofactor
    return res;
}

			
///calculates each_element % N
void matrixMod(int **mat, int N) 
{
	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			mat[i][j] = mat[i][j] - floor((double)(mat[i][j]) / N) * N; //mat[i][j] % 26        
        }
    }
}
	
///returns the inverse key matrix
int** inverseKeyMatrix(int K[][3]) 
{

    
	int detK, detKInv, **adjK;
    int i, j;
    //calculating inverse key matrix for hill cipher
    //step 1 : calculate determinant
    detK = det(K);

    //step 2 : calculate multiplicative inverse of the matrix
	detKInv = mulInverse(detK % 26);

    //step 3 : calculate the adoint matrix
    adjK = adjoint(K);
    
    //step 4 : multiply each element of the adjoint by the multiplicative
    //inverse of the determinant
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
		adjK[i][j] = adjK[i][j] * detKInv;
		}
	}
    //step 5 : take mod
    matrixMod(adjK ,26);
    
    return adjK;
}

///this function takes a string and returns an integer array that maps
char* encrypt(int K[][3], char *msg)
{
    int charVec[3], i, j, k;
    int l = strlen(msg);
    int *encI = malloc(l * sizeof(int)); //the integer representation of the cipher text 
    char *cipherText = malloc(l + 1);
    for(i = 0; i < l; i += 3) {
        charVec[0] = msg[i] - 97;
        charVec[1] = msg[i + 1] - 97;
        charVec[2] = msg[i + 2] - 97;
        for(j = 0; j < 3; j++) {
            encI[i + j] = 0;
            for(k = 0; k < 3; k++) {
                encI [i + j] = encI[i + j] + K[j][k] * charVec[k];
            }
            encI[i + j] %= 26;
            cipherText[i + j] = encI[i + j] + 97;
        }
    }
    cipherText[l] = '\0';
    return cipherText;
}

///takes the inverse key matrix and the cipher text and returns the plain text
char* decrypt(int **iK, char *cipher)
{
    int charVec[3], i, j, k;
    int l = strlen(cipher); //the null
    int *decI = malloc(l * sizeof(int)); 
    char *plainText = malloc(l + 1);
    for(i = 0; i < l; i += 3) {
        charVec[0] = cipher[i] - 97;
        charVec[1] = cipher[i + 1] - 97;
        charVec[2] = cipher[i + 2] - 97;
        for(j = 0; j < 3; j++) {
            decI[i + j] = 0;
            for(k = 0; k < 3; k++) {
                decI[i + j] = decI[i + j] + iK[j][k] * charVec[k];
            }
            decI[i + j] %= 26;
            plainText[i + j] = decI[i + j] + 97;
        }
    }
    plainText[l] = '\0';
    return plainText;
}

int main() 
{
	int K[][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}, **invK;
    int i, l, j;
    char msg[1000], choice;
    while(1) {
        printf("\nDo you want to enter a key matrix or use the default?(e : enter/ d : default/ x : exit)\n> ");
        scanf("%c", &choice);
        getchar(); //eat the newline
        if (choice == 'x') {
            return 0;
        } else if (choice == 'e') {
            for (i = 0; i < 3; i++) {
		        printf("\nEnter %d row : ", i + 1);
		        scanf("%d%d%d",&K[i][0], &K[i][1], &K[i][2]);
	        }
            break;
        } else if(choice == 'd') {
            break;
        }
        else {
            printf("\nSorry I don't understand that");
        }
    }
            
    

    invK = inverseKeyMatrix(K);

    printf("\n\t\tKey Matrix\n\t");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%6d", K[i][j]);
        }
        printf("\n\t");
    }
    printf("\n\n\t\tInverse Key Matrix\n\t");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%6d", invK[i][j]);
        }
        printf("\n\t");
    }
    printf("\n");
    printf("Enter your message : ");
    scanf("%s",msg);
    l = strlen(msg);
    if (l % 3 != 0) { //make the length / 3
    for(i = 0; i < (3 - l%3); i++) {
        msg[l + i] = 'x';
    }
    l = l + 3 - l % 3;
    msg[l] = '\0';
    
    }
    char *enc = encrypt(K, msg);
    char *dec = decrypt(invK, enc);
    printf("\nencryption : %s\n\ndecryption : %s\n", enc, dec);
	return 0;
}
