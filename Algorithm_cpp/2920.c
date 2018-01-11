#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int input[8] = {0};
	int flag = 0;
	for(int i = 0; i < 8; i++) {
		scanf("%d", &input[i]);
	}

	printf("Input ");
	for(int i = 0; i < 8; i++) {
		printf("%d", input[i]);
	}

	for(int j = 0; j < 8; j++) {
		if(j == 0) {
			if(input[0] != 1 || input[0] != 8) {
				printf("first input was not in order !\n");
				flag = 0;
				break;
			}
		}
		if(input[j] == j+1) {
			printf("ASC : current index : [%d]\n", j);
			flag = 1;
		}
		else if(input[j] == 8-j) {
			printf("DESC : current index : [%d]\n", j);
			flag = -1;
		}
		else {
			printf("MIX : current index : [%d]\n", j);
			flag = 0;
		}
	}

	if(flag == 0 ) printf("mixed");
	else if(flag == -1) printf("descending");
	else if(flag == 1) printf("ascending");

	return 0;
}