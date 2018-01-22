#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 5000
using namespace std;
int t, n, cnt_group;
int x, y, r;
int map[MAX+1][MAX+1];
int check[MAX+1][MAX+1];

int dr[] = {1, -1, 0,  0, -1, -1, 1, 1};
int dc[] = {0,  0, 1, -1, -1, 1, -1, 1};
void group(int r, int c, int rad) {
    for(int k=0; k<8; k++){
        for(int l=1; l<=rad; l++){
            int nr = r + dr[k]*l;
            int nc = c + dc[k]*l;
            if(0 <= nr && nr <= MAX && 0 <= nc && nc <= MAX) {
                if(check[nr][nc] == false) {
                    check[nr][nc] = true;
                }
            }
        }

    }
}
int main(){
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int highest = 0;
        int high_x = 0;
        int high_y = 0;
        for(cnt_group=1; cnt_group<=n; cnt_group++) {
            scanf("%d %d %d", &x, &y, &r);
            high_x = max(x, high_x);
            high_y = max(y, high_y);
            group(y,x,r);
        }
        for(int i=0; i<=high_y; i++) {
            for(int j=0; j<=high_y; j++) {
                highest = max(highest, map[i][j]);
            }
        }
        printf("%d\n", highest);
        // init.
        for(=0; i<=MAX; i++) {
            for(int j=0; j<=MAX; j++) {
                map[i][j] = 0;
            }
        }
    }
    return 0;
}
