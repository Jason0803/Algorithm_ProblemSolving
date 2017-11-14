#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int num = 0;
	char* input;

	input = (char*)malloc(sizeof(char)*100);
	scanf("%s", input);
	
	int length = strlen(input);

	for(int i = 0; i < length; i++) {
		if(i != 0 && i%10 == 0) printf("%s", "\n");
		printf("%c", input[i]);
	}	

	return 0;
}