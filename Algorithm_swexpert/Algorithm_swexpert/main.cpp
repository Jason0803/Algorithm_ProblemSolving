#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void swap(char* a, char* b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void getMax(const char* str, int count) {
    /*
         1. 문자열로 받음
         2. 한 글자 씩 -'0' 하면서 정수 배열에 집어 넣음
             ** count가 짝수인 경우, 현재 상태가 가장 큰 값인지 확인 (내림차순 정렬 후 비교)
         3.
     */
    int max;
}


int main() {
    int T, test_case, swap_count;
    char* input;
    scanf("%d", &T);
    for(test_case = 1; test_case <= T; test_case++) {
        scanf("%s %d", input, &swap_count);
        
        
    }

    return 0;
}
