#include <stdio.h>

int main() {
	int input = 0;
	char result = ' ';
	scanf("%d", &input);

	if(input >= 0 && input <=100) {
		if(input >= 90) result = 'A';
		else if(input >= 80) result = 'B';
		else if(input >= 70) result = 'C';
		else if(input >= 60) result = 'D';
		else result = 'F';

		printf("%c", result);
	}
	return 0;
}