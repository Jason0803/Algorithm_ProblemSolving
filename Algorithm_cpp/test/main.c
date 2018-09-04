#include <stdio.h>
#include <stdlib.h>
int dist[100];
int ABS(int a, int b);
int input(int *ary);
int check(int *ary, int cnt);

int main()// main함수는 수정 불가
{
    int ary[100];
    int cnt;
    
    cnt = input(ary);
    
    if (cnt == 1 || check(ary, cnt) == 1 ) {
        printf("%d FN", cnt);
    }
    else {
        printf("%d NFN", cnt);
    }
    return 0;
}

int ABS(int a, int b){
    return (a>b?a-b:b-a);
}
int input(int *ary) {
    int cnt = 0;
    int dup_cnt = 0;
    scanf("%d", &cnt);
    for(int i=0; i<cnt; i++) scanf("%d", &ary[i]);
    for(int i=0; i<cnt; i++){
        for(int j=i+1; j<cnt; j++) {
            if(ary[i] == ary[j]) {
                dup_cnt++;
                for(int k=j; k<cnt; k++){
                    ary[k] = ary[k+1];
                }
                cnt--;
                j--;
            }
        }
    }
    return cnt;
}
int check(int *ary, int cnt) {
    int gap = 0;
    int check = 1;
    for(int i=0; i<cnt-1; i++) {
        gap = ABS(ary[i], ary[i+1]);
        dist[gap] = 1;
    }
    for(int i=1; i<=cnt-1; i++) {
        if(dist[i] == 0) {
            check = -1;
            break;
        }
    }
    return check;
}
