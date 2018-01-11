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

	solutions[0] = 0;
	solutions[1] = steps[1];
	solutions[2] = steps[1] + steps[2];

	return 0;
}