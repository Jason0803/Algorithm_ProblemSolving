#include <stdio.h>
#include <stdlib.h>
int create(int input) {
	int sum = input;
	while(input > 0) {
		sum += (input % 10);
		input /= 10;
	}
	return sum;
}
int main() {
	int* array = (int* )malloc(sizeof(int)*10000);
	int result = 0;

	for(int i = 0; i <= 10000; i++){
		result = create(i);
		if(result < 10000)
			array[result] = result;
	}
	for(int i = 1; i < 10000; i++) {
		if(array[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}