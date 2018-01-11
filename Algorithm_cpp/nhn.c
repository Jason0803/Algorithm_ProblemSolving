#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int input = 0;
	int temp = 0;
	char* numbersToKorean = {"일", "이", "삼", "사", "오", "육", "칠", "팔", "구"};
	char* units = { "십", "백", "천", "만" };
	int unit = 0;
	scanf("%d", &input);

	while(input > 0) {
		temp = input % 10;
		switch(temp) {
			case 1: {
				printf("%s", 일);
				break;
			}
			case 2: {}
		}
	}

	return 0;
}