#include <iostream>

using namespace std;
int W, H, ans, map[50][50];
int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};
void dfs(int r, int c) {
    for(int d=0; d<8; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
        if(map[nr][nc] == 1) {
            map[nr][nc] = 2;
            dfs(nr, nc);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1) {
        cin >> W >> H;
        if(W == 0 && H == 0) break;
        
        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                cin >> map[i][j];
            }
        }
        ans = 0;
        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                if(map[i][j] == 1) {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
