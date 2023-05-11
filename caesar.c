#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *s, int key){
	printf("Encrypted text: ");
	int i=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]>='A' && s[i]<='Z'){
			printf("%c", (s[i]-'A'+key)%26 + 'A');
		}
		if(s[i]>='a' && s[i]<='z'){
			printf("%c", (s[i]-'a'+key)%26 + 'a');
		}
	}
}

void decrypt(char *s, int key){
	printf("Decrypted text: ");
	int i=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]>='A' && s[i]<='Z'){
			printf("%c", (s[i]-'A'-key)+26%26 + 'A');
		}
		if(s[i]>='a' && s[i]<='z'){
			printf("%c", (s[i]-'a'-key+26)%26 + 'a');
		}
	}
}
int main(int argc, char *argv[]) {
	char *str;
	str = malloc(256);
	printf("Enter the plain text: ");
	scanf("%[^\n]s", str);
	int key;
	printf("Enter cipher key: ");
	scanf("%d", &key);
	encrypt(str, key);
	printf("\n");
	decrypt(str, key);
	return 0;
}
