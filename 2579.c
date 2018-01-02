#include <stdio.h>
#include <stdlib.h>
#define MAX_STEPS 301;

int steps[MAX_STEPS];
int solutions[MAX_STEPS];

int main() {
	int T;
	scanf("%d", &T);

	int i = T;
	
	while(T > 0) {
		scanf("%d", &steps[i-T]);
		T--;
	}

	for(int j = 0; j < i; j++) {

	}
	return 0;
}