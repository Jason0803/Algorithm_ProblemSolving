#include <stdio.h>
#include <stdlib.h>

 int main() {
 	int N;
 	scanf("%d", &N);
 	int* steps = (int* )malloc(sizeof(int) * N);
 	int i = N;
 	while(N > 0) {
 		scanf("%d", &steps[i-N]);
 		N--;
 	}
 	return 0;
 }