#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int n = 0;
	scanf("%d", &n);
	if(n > 0) {
		int sum;
		int stroke;
		char* testCase;  
		for(int i = 0; i < n; i++) {
			testCase = (char* )malloc(sizeof(char) * 81);
			scanf("%s", testCase);
			sum = 0;
			stroke = 1;
			for(int j = 0; j < strlen(testCase); j++) {
				if(testCase[j] == 'O') {
					sum += stroke;
					stroke++;
				} else if(testCase[j] == 'X') {
					stroke = 1;
				}
			}
			free(testCase);
			printf("%d\n", sum);
		}
	}
	return 0;
}