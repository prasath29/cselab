#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char *str;
	str = malloc(256);
	printf("Plain Text: ");
	scanf("%s", str);
	str = realloc(str, strlen(str)+1);
	int key, i, j;
	printf("\nKey: ");
	scanf("%d", &key);
	printf("\nCipher Text: ");
	for(i=0;i<key;i++){
		for(j=i;j<strlen(str);j=j+key){
			printf("%c", str[j]);	
		}
	}
	return 0;
}


//  int temp = key - (strlen(str)%key);
//	int row = key, col = (strlen(str)+temp)/key;
//	char arr[row][col];
//	for(i=0;i<col;i++){
//		for(j=0;j<row;j++){
//			arr[i][j] = st
//			r;
//		}
//		printf("\n");
//	}
