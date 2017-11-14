#include <stdio.h>
#include <stdlib.h>
int comp (const void * elem1, const void * elem2) {
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
int main() {
	int n = 0;
	int x = 0;
	int* input;
	float sum = 0;

	scanf("%d", &n);
	if(n > 0 && n <= 1000) {
		input = malloc(sizeof(int) * n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &x);
			if(x > 0 && x <= 100) 
				input[i] = x;
		}
		qsort(input, n, sizeof(int), comp);
		if(input[n-1] != 0) {
			for(int i = 0; i < n; i++) {
				sum += (float)input[i]/input[n-1] * 100;
			}
			printf("%.2f", (float)sum/n);
		}
	}
	return 0;
}