#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define true 1
#define false 0

void sort_reverse(int* array, int size) {
	int pos = 0;
	int temp = 0;
	for(int i = 0; i < size; i++) {
		pos = i;
		for(int j = i + 1; j < size; j++) {
			if(array[pos] < array[j]) {
				temp = array[pos];
				array[pos] = array[j];
				array[j] = temp;
			}
		}
	}
}
int main() {
	/*
		1. 입력받음
		2. 문자 > 숫자
		3. 해당 숫자 배열을 조합하여 만들 수 있는 수
			입력 : 142356
			거꾸로 정렬 시 : 654321
			--> std::sort(myVector.begin(), myVector.end());
			myVector.reverse();

	 */

	string input;
	int count;

	scanf("%s %d", string, &count);
	printf("%s %d\n", string, count);






	/*
		1. 입력받음 (문자열 + 숫자)
		2. 문자열 한 글자를 -'0' 하면서 정수 배열에 삽입
		3. while (count >0 ) 
		4. 	(i 번째 < i+j) ? pos = i+j : j++
		 	:: Selection Sort 의 내림차순버전
			--> 클 수록 앞으로배치하게 함
			--> swap 시 count = count - 1; flag = true;
		5. 4번이후, flag == false 일 때, 제일 작은 놈을 맨 ㄷ

	 */



	// 완전탐색
	/*
		1. 입력받음
		2. 문자 > 숫자
		3. 해당 숫자 배열을 조합하여 만들 수 있는 수
			입력 : 142356
			거꾸로 정렬 시 : 654321
			--> std::sort(myVector.begin(), myVector.end());
			myVector.reverse();

	 */



	// 또 다른 방법
	/*
		1. 어차피 입력과 n 가지가 다르다면, n/2 번의 이동 필요
		--> x 번 이동 할 경우
			a) x 가 짝수 
				- 현재가 가장 클 경우 입력값 바로 출력 !
				- else, 

	 */
	return 0;
}