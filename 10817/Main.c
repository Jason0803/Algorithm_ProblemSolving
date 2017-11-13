#include <stdio.h>
#include <stdlib.h>

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main() {
	int* input = malloc(sizeof(int) * 3);
	int mid = 0;

	scanf("%d %d %d", &input[0], &input[1], &input[2]);
	qsort(input, 3, sizeof(int), comp);

	printf("%d", input[1]);

	return 0;
}