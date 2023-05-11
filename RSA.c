#include <stdio.h>
#include <math.h>
int n;
void encrypt(int M, int e){
	unsigned long long int text = pow(M, e);
	printf("Encrypted text = %llu", text%n);
}

void decrypt(int C, int d){
	unsigned long long int text = pow(C, d);
	printf("Decrypted text = %llu", text%n);
}

int main(){
	int p, q, e, d;
	printf("p = ");
	scanf("%d", &p);
	printf("q = ");
	scanf("%d", &q);
	printf("e = ");
	scanf("%d", &e);
	n = p*q;
	int n_ = (p-1)*(q-1);
	int i=1;
	while(1){
		if((n_*i+1)%e==0){
			d = (n_*i+1)/e;
			break;
		}
		i++;
	}
	printf("d = %d\n", d);
	int m;
	printf("Enter the text: ");
	scanf("%d", &m);
	char ch;
	printf("Enter 'e' for encryption or 'd' for decryption: ");
	scanf("\n%c", &ch);
	switch(ch){
		case 'e':
			encrypt(m, e);
			break;
		case 'd':
			decrypt(m, d);
			break;
	}
	return 0;
}
