#include<stdio.h>
#include<math.h>

int modInverse(int m, int n){
	int i=1;
	while(i>0){
		if((n*i + 1)%m == 0){
			return (n*i + 1) / m;
		}
	}
}
int main(){
	int p, q, h, H, x, y, g, k, r, s, w, u1, u2, v;
	printf("Enter the prime number (p) = ");
	scanf("%d", &p);
	printf("Enter the prime divisor of p-1 (q) = ");
	scanf("%d", &q);
	printf("Enter any integer (h) where (0 < h < p-1) = ");
	scanf("%d", &h);
	printf("Enter the value of H(m) = ");
	scanf("%d", &H);
	
	g = (int)pow(h, (p-1)/q) % p;
	
	printf("Enter user's private key (x) where (0 < x < q) = ");
	scanf("%d", &x);
	
	y = (int)pow(g, x) % p;
	
	printf("Enter user's per secret number (k) where (0 < k < q) = ");
	scanf("%d", &k);
	
	printf("\nSignature creation......\n");
	r = ((int)pow(g, k) % p) % q;
	printf("r = %d\n", r);
	s = ((modInverse(k, q) * (H % q)) + ((x * r) % q)) % q;
	printf("s = %d\n", s);
	
	printf("\nSignature verification......\n");
	w = modInverse(s, q);
	u1 = (H * w) % q;
	u2 = (r * w) % q;
	v = (((int)pow(g, u1) * (int)pow(y, u2)) % p) % q;
	if(v==r){
		printf("v = %d and r = %d\nThe digital signature is verified.", v, r);
	}
	return 0;
}
