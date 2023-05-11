#include <stdio.h>
#include <math.h>

int primitive(int q){
	int i, j, sum=0;
	for(i=1;i<q;i++){
		sum += i;
	}
	for(i=2;i<q;i++){
		int val = sum;
		for(j=1;j<q;j++){
			val -= (int)pow(i,j) % q;
		}
		if(val==0){
			return i;
		}
	}
}

int main(){
	int q, a, Xa, Xb, Ya, Yb;
	printf("Enter the prime number (q): ");
	scanf("%d", &q);
	printf("Private key of A (less than q): ");
	scanf("%d", &Xa);
	printf("Private key of B (less than q): ");
	scanf("%d", &Xb);
	a = primitive(q);
	printf("\nThe minimum primitive root of the prime number is %d.\n", a);
	Ya = (int)pow(a,Xa) % q;
	Yb = (int)pow(a,Xb) % q;
	printf("\nPublic key of A is %d.\n", Ya);
	printf("Public key of B is %d.\n", Yb);
	int k = (int)pow(Ya,Xb) % q;
	printf("\nSecret key generated for A and B is %d.\n", k);
	return 0;
}
