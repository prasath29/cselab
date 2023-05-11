#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void playfair(char key[], char plaintext[]){
	int m=0, n;
	while(m<strlen(plaintext)){
		int i1, i2, j1, j2, idx;
		for(n=0;n<25;n++){
			if(plaintext[m]==key[n]){
				i1 = n/5;
				j1 = n%5;
			}
			else if(plaintext[m+1]==key[n]){
				i2 = n/5;
				j2 = n%5;
			}
		}
		if(i1==i2){
			idx = i1*5 + (j1+1)%5;
			plaintext[m] = key[idx];
			idx = i1*5 + (j2+1)%5;
			plaintext[m+1] = key[idx];
		}
		else if(j1==j2){
			idx = ((i1+1)%5)*5 + j1;
			plaintext[m] = key[idx];
			idx = ((i2+1)%5)*5 + j2;
			plaintext[m+1] = key[idx];
		}
		else{
			idx = i1*5 + j2;
			plaintext[m] = key[idx];
			idx = i2*5 + j1;
			plaintext[m+1] = key[idx];
		}
		m = m+2;
	}
	printf("\nCipher Text: ");
	for(n=0;plaintext[n]!='\0';n++){
		printf("%c", plaintext[n]);
		if(n%2){
			printf(" ");
		}
	}
}

int main(){
	char *s, key[5][5];
	s = malloc(256);
	printf("Key: ");
	scanf("%s", s);
	s = realloc(s, strlen(s)+1);
	int chr[26] = {0};
	int i, j=0, idx;
	for(i=0;i<strlen(s);i++){
		if(s[i]=='i'){
			idx = s[i] - 96;
		}
		else{
			idx = s[i] - 97;
		}
		chr[idx]++;
	}
	char letters[25];
	for(i=0;i<strlen(s);i++){
		if(s[i]=='i'){
			idx = s[i] - 96;
		}
		else{
			idx = s[i] - 97;
		}
		if(chr[idx]>0){
			letters[j]=idx+'a';
			chr[idx] = -1;
			j++;
		}
	}
	for(i=0;i<26;i++){
		if(chr[i]==0){
			if(i==8){
				continue;
			}
			letters[j] = i+'a';
			j++;
		}
	}
	int k=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			key[i][j] = letters[k];
			k++;
		}
	}
	printf("\nKey Matrix:\n\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%c ", key[i][j]);
		}
		printf("\n");
	}
	
	char *text;
	text = malloc(256);
	printf("\nPlain Text: ");
	scanf("%s", text);
	text = realloc(text, strlen(text)+1);
	char input[strlen(text)*2];
	for(k=0;text[k]!='\0';k++){
		if(text[k]=='i'){
			text[k]='j';
		}
	}
	i = 0; j = 0;
	while(i<strlen(text)){
		if(text[i]!=text[i+1]){
			input[j] = text[i];
			j++;
			input[j] = text[i+1];
			j++;
			i = i+2;
		}
		else{
			input[j] = text[i];
			j++;
			input[j] = 'x';
			j++;
			i = i+1;
		}
	}
	if(strlen(input)%2){
		strcat(input, "x");
	}
	printf("\nPlain Text Split: ");
	for(i=0;input[i]!='\0';i++){
		printf("%c", input[i]);
		if(i%2){
			printf(" ");
		}
	}
	printf("\n");
	playfair(letters, input);
	return 0;
}
