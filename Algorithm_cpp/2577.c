#include <stdio.h>
#include <stdlib.h>
int main() {
	int numbers[10] = {0};
	int a = 0; int b = 0; int c = 0; int temp = 0;
	int number = 0;
	scanf("%d\n%d\n%d", &a, &b, &c);

	number = a*b*c;

	while(number > 0) {
		temp = (number % 10);
		numbers[temp]++;
		number /= 10;
	}
	for(int i = 0; i < 10; i++) {
		printf("%d\n", numbers[i]);
	}
	return 0;
}