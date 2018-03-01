#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_SIZE 52
using namespace std;
int n, m, ans;
queue<pair<int, int>>q;
char map[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
void init() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            check[i][j] = false;
            dist[i][j] = 0;
        }
    }
}
void input() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> map[i];
    
}
void bfs() {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(check[nr][nc] || map[nr][nc] != 'L') continue;
            
            check[nr][nc] = true;
            q.push(make_pair(nr,nc));
            dist[nr][nc] = dist[r][c] + 1;
                
            if(ans < dist[nr][nc]) ans = dist[nr][nc];
        }
    }
}
int main() {
    input();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 'L') {
                q.push(make_pair(i,j));
                check[i][j] = true;
                bfs();
                init();
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
