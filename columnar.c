#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char *str, *key;
	str = malloc(256);
	printf("Enter plain text: ");
	scanf("%s", str);
	str = realloc(str, strlen(str)+1);
	
	key = malloc(256);
	printf("\nEnter key word: ");
	scanf("%s", key);
	key = realloc(key, strlen(key)+1);
	
	int col=strlen(key);
	int row = strlen(str)%col==0? strlen(str)/col : strlen(str)/col+1;
		
	char arr[row][col];
	int i, j, c=0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(c==strlen(str)){
				arr[i][j] = 'X';
				continue;
			}
			arr[i][j] = str[c];
			c++;
		}
	}
	printf("\nCipher text: ");
	char ch = 'a';
	int s=0;
	while(s<col){
		for(i=0;i<col;i++){
			if(key[i]==ch){
				s++;
				for(j=0;j<row;j++){
					printf("%c", arr[j][i]);
				}
			}
		}
		ch++;
	}
	
	return 0;
}
