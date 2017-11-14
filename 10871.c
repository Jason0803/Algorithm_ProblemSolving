#include <stdio.h>

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
	
	scanf("%d %d", &n, &x);
	if(n >=1 && n <= 10000 && x >= 1 && x <= 10000) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &input);
			if(x > input) printf("%d ", input);
		}
	}


	return 0;
}