#include <stdio.h>
int T, N, sum, ans;
int inputArr[100];
bool checkArr[10001];

void init(){
    for (int i = 0; i < 100; i++)
        inputArr[i] = 0;
    for (int j = 0; j < 10001; j++)
        checkArr[j] = false;
    ans = 0;
    sum = 0;
}

int main() {
    scanf(" %d", &T);
    
    for (int tc = 1; tc <= T; tc++){
        init();
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            scanf("%d", &inputArr[i]);
            sum += inputArr[i];
        }
        checkArr[0] = true;
        for(int i=0; i<N; i++) {
            for(int j=sum; j>=0; j--) {
                if(checkArr[j]) {
                    checkArr[inputArr[i] + j] = true;
                }
            }
        }
        
        for(int i=0; i<10001; i++)
            if(checkArr[i]) ans++;
        

        printf("#%d %d\n", tc, ans);
    }
    
    return 0;
}
