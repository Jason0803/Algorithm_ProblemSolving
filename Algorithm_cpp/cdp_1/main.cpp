#include <stdio.h>

int M;                    // 반복 인정 회수
char S[100000 + 10];    // 조사 문자열

int getlen(char *str) {
    int len = 0;
    for(int i=0; ; i++) {
        if(str[i] == '\0') break;
        len++;
    }
    return len;
}
void printshort(char r_char, int r_cnt) {
    printf("%c(%d)", r_char, r_cnt);
}
void printraw(char r_char, int r_cnt) {
    for(int i=0; i<r_cnt; i++) {
        printf("%c", r_char);
    }
}
int main(void)
{
    int i;            // 문자열 S의 어떤 문자를 지시
    int len;        // 문자열 S의 길이
    char r_char;    // 반복되는 문자
    int r_cnt;        // 반복 회수
    
    // 데이터 읽기
    scanf("%d", &M);
    scanf("%s", &S[0]);
    
    // 코드 구현 및 결과 출력
    
    r_char = S[0];
    r_cnt = 1;
    len = getlen(S);
    for(i=1; i<=len; i++) {
        if(S[i] != r_char) {
            if(r_cnt >= M) {
                printshort(r_char, r_cnt);
            } else {
                printraw(r_char, r_cnt);
            }
            r_char = S[i];
            r_cnt = 1;
        } else {
            r_cnt++;
        }
    }
    
    return 0;
}
