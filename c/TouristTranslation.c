//sg
#include<stdio.h>
#include<ctype.h>

int main() {
	int T; 
	char lperm[27],uperm[27];
	scanf("%d", &T);
	scanf("%s", lperm);
	char sentence[101];
	char translation[101];
	int i;
	
	//make a uperm
	for( i = 0;i < 26 ; i++) {
		uperm[i] = lperm[i] - 32;
	}
	
	while ( T-- ) {
		scanf("%s",sentence);
		i = 0;
		while(sentence[i]) {
			if( sentence[i] == '_' ) {
				translation[i] = ' ';
			} else if(!isalpha(sentence[i])){
				translation[i] = sentence[i];
			} else { //alphabet
				if(isupper(sentence[i])) {
					translation[i] = uperm[sentence[i] - 65 ];
				}
				else {
					translation[i] = lperm[sentence[i] - 97 ];
				}
			}
			i++;
		}
		translation[i] = '\0';
		printf("%s\n",translation);
		
	}
	
	return 0;
}
