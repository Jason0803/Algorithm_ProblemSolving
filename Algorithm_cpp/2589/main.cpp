#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 55
using namespace std;
struct Point {
    int r, c;
};
char map[MAX][MAX];
int dist[MAX][MAX];
bool visit[MAX][MAX];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
queue<pair<int,int>> q;
int n, m, max_dist;
void bfs() {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 <= nr && nr < n && 0<= nc && nc < m) {
                if(visit[nr][nc] || map[nr][nc] != 'L') continue;
                visit[nr][nc] = true;
                q.push(make_pair(nr,nc));
                dist[nr][nc] = dist[r][c] + 1;
                if(max_dist < dist[nr][nc]) max_dist = dist[nr][nc];
            }
        }
    }
}
void init() {
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            dist[i][j] = 0;
            visit[i][j] = false;
        }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            if(map[i][j] == 'L') {
                q.push(make_pair(i,j));
                visit[i][j] = true;
                bfs();
                init();
            }
        }
    }
    cout << max_dist << '\n';

    return 0;
}
