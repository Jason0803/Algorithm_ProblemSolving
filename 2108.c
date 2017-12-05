#include <stdio.h>
#include <stdlib.h>
#define MAX_COUNT 500000
#define MAX_INPUT 4000
int comp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
void average(int* array, int size) {
	int sum = 0;
	for(int i = 0; i < size; i++) {
		sum += array[i];
	}
	printf("%d\n", sum);
}
void median(int* array, int size) {
	printf("%d\n", array[size/2]);
}
void freq(int* array, int size) {
	int* temp = (int*)malloc(sizeof(int)*MAX_INPUT*2+1);
	memset(temp, 0, MAX_INPUT*2+1);
	for(int i = 0; i < size; i++) {
		temp[array[i]+4000]++;
	}
}
void range(int* array, int size) {
	qsort(array, size, sizeof(int), comp);
	printf("%d", array[size-1]-array[0]);
}
int main() {

	return 0;
}