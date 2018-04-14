#include <iostream>

using namespace std;
int N, M, map[501][501], ans;
bool visited[501][501];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
void exceptionalCase(int r, int c) {
    // ㅗ
    if(r >= 1 && c >= 1 && c < M-1) {
        ans = max(ans, map[r][c] + map[r-1][c] + map[r][c-1] + map[r][c+1]);
    }
    // ㅜ
    if(r < N-1 && c >= 1 && c < M-1) {
        ans = max(ans, map[r][c] + map[r+1][c] + map[r][c-1] + map[r][c+1]);
    }
    // ㅓ
    if(r >= 1 && c >= 1 && r < N-1) {
        ans = max(ans, map[r][c] + map[r+1][c] + map[r-1][c] + map[r][c-1]);
    }
    // ㅏ
    if(r >= 1 && r < N-1 &&c < M-1) {
        ans = max(ans, map[r][c] + map[r-1][c] + map[r+1][c] + map[r][c+1]);
    }
}
void dfs(int r, int c, int depth, int sum) {
    if(depth == 4) {
        ans = sum > ans ? sum : ans;
        return;
    }
    for(int d=0; d<4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc]) continue;
        visited[nr][nc] = true;
        dfs(nr, nc, depth+1, sum + map[nr][nc]);
        visited[nr][nc] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            exceptionalCase(i,j);
            visited[i][j] = true;
            dfs(i, j, 1, map[i][j]);
            visited[i][j] = false;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
