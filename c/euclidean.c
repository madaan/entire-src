//sg
#include<stdio.h>

int euclidean(int a, int b) {
if(b == 0 ) {
	return a;
}
return euclidean(b, a%b);
}

/// method to get X, where X is (B*X)%A = 1
void extended_euclidean(int   a,int  b) {
int x1 = 1,y1 = 0,d1 = b;
int x2 = 0,y2 = 1,d2 = a;
int xt, yt, dt;
int k;
k = d1 / d2;
printf("%-10s|%-10s|%-10s|%-10s\n\n","x","y","d","k");
printf("%-10d|%-10d|%-10d|%-10d|\n",x1,y1,d1,0);
printf("%-10d|%-10d|%-10d|%-10d|\n",x2,y2,d2,k);
while(d2 != 1) {

xt = x1 - k*x2;
yt = y1 - k*y2;
dt = d1 - k*d2;

//update the values
x1 = x2; y1 = y2; d1 = d2;
x2 = xt; y2 = yt; d2 = dt;
if( d2 == 0) {
printf("\n\nMultiplicative inverse does not exist\n");
break;
}
k = d1 / d2;
printf("%-10d|%-10d|%-10d|%-10d|\n",x2,y2,d2,k);
}

if(x2 < 0 ) { 
x2 = -x2;
x2= a - x2;
}

if(y2 < 0 ) { 
y2 = -y2;
y2= b - y2;
}

printf("\n\nMultiplicative inverse of %d modulo %d = %d\n",b, a, x2);
printf("\nMultiplicative inverse of %d modulo %d = %d\n", a, b, y2);
}

int main() {

int a,b;
scanf("%d%d",&a, &b);
printf("\n HCF(%d, %d) =  %d \n\n",a, b,  euclidean(a,b));
extended_euclidean(a,b);
return 0;
}
