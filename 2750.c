#include <stdio.h>
#include <stdlib.h>
void sort(int* array, int size) {
	int pos = 0;
	int temp = 0;
	for(int i = 0; i < size; i++) {
		pos = i;
		for(int j = i + 1; j < size; j++) {
			if(array[pos] > array[j]) {
				temp = array[pos];
				array[pos] = array[j];
				array[j] = temp;
			}
		}
	}
}
int main() {
	int iterator = 0;
	scanf("%d", &iterator);

	if(iterator >= 1 && iterator <= 1000) {
		int* list = (int*)malloc(sizeof(int)*iterator);
		int input = 0;
		for(int i = 0; i < iterator;) {
			scanf("%d", &input);
			if(input <= 1000 && input >= -1000) {
				list[i++] = input;
			}
		}
		sort(list, iterator);
		for(int i = 0; i < iterator; i++) {
			printf("%d\n", list[i]);
		}
	}
	return 0;
}