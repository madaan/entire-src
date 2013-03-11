//sg
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * decimalToBin(int decimal)
{
	int bit = 4;
	char *res=(char *)malloc(sizeof(char)*(bit+1));
	int i=0;
	unsigned long long mask=1<<(bit-1);
	while(i<bit)
	{
	if(decimal&mask)
	{
		res[i]='1';
	}
	else
	{
		res[i]='0';
	}
	i++;
	mask=mask>>1;
	}
	res[i]='\0';
	return res;
}
int binTodec(char * str) {
	int n1, n2;
	n1 = n2 = 0;
	int i = 0;
	for( i = 0; i < 4; i++) {
		if(str[i] == '1' ) {
			n1 += 1<<(3-i);
		}
	}
	for( i = 4; i < 8; i++) {
		if(str[i] == '1' ) {
			n2 += 1<<(7-i);
			//printf("Adding %d",1<<(7-i));
		}
	}
	printf("\n||%.4s    ||%.4s    ||%d        ||%s        ||              ||",str,(str+4), (n1+n2)&(0x0000000F), decimalToBin((n1+n2)&(0x0000000F)));
	return 1;
}

int main() {
	char * nibble[]={"0001","0010","0111","1110","1111"};
	int i,j,x;
	char temp[9];
	temp[8] = '\0';
	printf("\n||A    ||B    ||Sum    ||Output    ||Expected     ||");
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			for( x = 0; x < 4; x++) {
				temp[x] = nibble[i][x];
			}
			for( x = 0; x < 4; x++) {
				temp[x+4] = nibble[j][x];
			}
			
			//strcat(temp,nibble[i]);
			//strcat(temp,nibble[j]);
			binTodec(temp);
		}
	}
	printf("\n");
	return 0;
}
