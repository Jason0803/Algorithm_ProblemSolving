#include <cstdio>
#include <algorithm>
#define MAX 100
using namespace std;
int n, rain;
int map[MAX+1][MAX+1];
bool check[MAX+1][MAX+1];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
void dfs(int r, int c) {
    check[r][c] = true;
    for(int k=0; k<4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if(0 <= nr && nr < n && 0 <= nc && nc < n) {
            if(rain < map[nr][nc] && check[nr][nc] == false) {
                dfs(nr, nc);
            }
        }
    }
}
int main() {
    int highest = 0;
    int lowest = 101;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
            highest = max(highest, map[i][j]);
            lowest = min(lowest, map[i][j]);
        }
    }
    int count=0;
    printf("h : %d, l : %d\n", highest, lowest);
    for(rain=0; rain<=highest; rain++){
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                check[i][j] = false;
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] > rain && check[i][j] == false){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        count = max(ans, count);
        printf("ans : %d\n", ans);
        printf("count : %d\n", count);
    }
    printf("%d\n", count);
    return 0;
}
