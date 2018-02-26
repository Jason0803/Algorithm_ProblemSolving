#include <iostream>
#include <string.h>
using namespace std;

int t, n, k, highest, ans;
int map[10][10];
bool check[10][10];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
void dfs(int r, int c, int len, bool flag) {
    check[r][c] = true;
    
    if(len > ans) ans = len;
    
    for(int d=0; d<4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        
        if(check[nr][nc] || nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        
        if(map[nr][nc] < map[r][c]) {
            dfs(nr, nc, len+1, flag);
            check[nr][nc] = false;
        } else if(!flag && map[nr][nc] >= map[r][c]) {
            for(int i=k; i>0; i--) {
                if(map[nr][nc] - i >= map[r][c]) continue;
                map[nr][nc] = map[nr][nc] - i;
                dfs(nr, nc, len+1, true);
                check[nr][nc] = false;
                map[nr][nc] = map[nr][nc] + i;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    
    cin >> t;
    for(int test_case=1; test_case<=t; test_case++) {
        cin >> n >> k;
        highest = 0;
        ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> map[i][j];
                highest = highest < map[i][j] ? map[i][j] : highest;
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(map[i][j] == highest) {
                    memset(check, false, sizeof(check));
                    dfs(i, j, 1, false);
                }
            }
        }
        cout << "#" << test_case << " " << ans << '\n';
    }
    return 0;
}
