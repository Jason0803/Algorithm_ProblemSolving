#include <stdio.h>
int N, L, map[105][105];

int main(void) {
    scanf("%d %d", &N, &L);        // n^2
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
    
    int ans = 2 * N;
    // row
    for(int i=0; i<N; i++) {
        int bh = map[i][0], ch, cnt = 1;
        for(int j=1; j<N; j++) {
            ch = map[i][j];
            if(ch == bh) {
                cnt++;
            } else if(ch == bh + 1) {
                if(cnt >= L) {
                    bh = ch;
                    cnt = 1;
                } else {
                    ans--;
                    break;
                }
            } else if(ch == bh - 1){
                for(cnt = 1; cnt < L; cnt++) {
                    if(j+cnt >= N || map[i][j+cnt] != ch)
                        break;
                }
                if(cnt >= L) {
                    bh = ch;
                    j += L - 1;
                    cnt = 0;
                } else {
                    ans--;
                    break;
                }
            } else {
                ans--;
                break;
            }
        }
    }
    
    for(int i=0; i<N; i++) {
        int bh = map[0][i], ch, cnt = 1;
        for(int j=1; j<N; j++) {
            ch = map[j][i];
            if(ch == bh) {
                cnt++;
                continue;
            } else if(ch == bh+1) {
                if(cnt >= L) {
                    bh = ch;
                    cnt = 1;
                } else {
                    ans--;
                    break;
                }
            } else if(ch == bh - 1) {
                for(cnt = 1; cnt < L; cnt++) {
                    if(j+cnt >= N || map[j+cnt][i] != ch) break;
                }
                if(cnt >= L){
                    bh = ch;
                    j += L-1;
                    cnt = 0;
                } else {
                    ans--;
                    break;
                }
            } else {
                ans--;
                break;
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
