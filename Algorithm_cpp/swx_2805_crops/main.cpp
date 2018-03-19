#include <cstdio>
#define MAX_SIZE 50
using namespace std;
int T, N, ans;
int map[MAX_SIZE][MAX_SIZE];
void solve() {
    int r = N/2;
    int c = N/2;
    int w = 0;
    for(int row = 0; row <= r; row++) {
        for(int col = c-w; col <= c+w; col++) {
            ans += map[row][col];
        }
        w++;
    }
    
    w = (N-3) / 2;
    for(int row = r+1; row < N; row++) {
        for(int col = c-w; col <= c+w; col++) {
            ans += map[row][col];
        }
        w--;
    }
}
int main() {
    scanf("%d", &T);
    for(int test_case = 1; test_case <= T; test_case++) {
        ans = 0;
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                scanf("%1d", &map[i][j]);
            }
        }

        if(N==1) ans = map[0][0];
        else solve();
        printf("#%d %d\n", test_case, ans);
    }
    
    return 0;
}
