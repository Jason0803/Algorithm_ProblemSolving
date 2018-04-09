#include <iostream>
#include <queue>
#define EMPTY   '.'
using namespace std;
typedef struct _Point {
    int r, c;
} Point;
queue<Point> q;
int ans;
char map[13][7];
bool stable, visited[13][7];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
void input();
void solve();
void dfs(Point p);
void gravity();
int main() {
    input();
    solve();
    return 0;
}
void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0; i<12; i++) {
        cin >> map[i];
    }
}
void dfs(Point p) {
    q.push(p);
    visited[p.r][p.c] = true;
    for(int d=0; d<4; d++) {
        int nr = p.r + dr[d];
        int nc = p.c + dc[d];
        if(nr < 0 || nr >= 12 || nc < 0 || nc >= 6) continue;
        if(visited[nr][nc] || map[nr][nc] != map[p.r][p.c]) continue;
        dfs(Point{nr,nc});
    }
}
void gravity() {
    for(int col=0; col<6; col++) {
        for(int row=11; row>0; row--) {
            if(map[row][col] == EMPTY) continue;
            for(int k=11; k>row; k--) {
                if(map[k][col] == EMPTY){
                    map[k][col] = map[row][col];
                    map[row][col] = EMPTY;
                    break;
                }
            }
        }
    }
    ans++;
}
void init() {
    for(int i=0; i<12; i++)
        for(int j=0; j<6; j++)
            visited[i][j] = false;
}
void solve() {
    while(true) {
        stable = true;
        // 1. look-up chaining blocks
        for(int i=0; i<12; i++) {
            for(int j=0; j<6; j++) {
                if(map[i][j] != EMPTY && !visited[i][j]) {
                    dfs(Point{i,j});
                    int q_sz = q.size();
                    while(!q.empty()){
                        if(q_sz >= 4) {
                            stable = false;
                            map[q.front().r][q.front().c] = EMPTY;
                        }
                        q.pop();
                    }
                }
            }
        }
        if(stable) break;
        
        // 2. gravity
        gravity();
        init();
    }
    cout << ans << '\n';
}
