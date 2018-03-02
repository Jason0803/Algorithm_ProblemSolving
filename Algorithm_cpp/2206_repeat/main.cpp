#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_SIZE 1002
#define NOT_DESTROYED 0
#define DESTROYED 1

using namespace std;
typedef struct _Point {
    int r,c;
    int passed; // 0 or 1
}Point;
int n, m, result;
char map[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE][2];
int dist[MAX_SIZE][MAX_SIZE][2];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void input() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> map[i];
    }
}
void bfs() {
    queue<Point> q;
    q.push(Point{0,0,NOT_DESTROYED});
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int passed = q.front().passed;
        q.pop();
        
        for(int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(check[nr][nc][passed] || map[nr][nc] == '1') continue;
            check[nr][nc][passed] = true;
            dist[nr][nc][passed] = dist[r][c][passed] + 1;
            q.push(Point{nr,nc,passed});
        }
        if(passed == NOT_DESTROYED) {
            for(int d=0; d<4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if(check[nr][nc][passed]) continue;
                check[nr][nc][DESTROYED] = true;
                dist[nr][nc][DESTROYED] = dist[r][c][NOT_DESTROYED] + 1;
                q.push(Point{nr,nc,DESTROYED});
            }
        }
    }
}
int main() {
    input();
    bfs();
    if(dist[n-1][m-1][NOT_DESTROYED] != 0 && dist[n-1][m-1][DESTROYED] != 0) {
        result = min(dist[n-1][m-1][NOT_DESTROYED], dist[n-1][m-1][DESTROYED]);
    } else {
        result = max(dist[n-1][m-1][NOT_DESTROYED], dist[n-1][m-1][DESTROYED]);
    }
    if(result > 0) cout << result+1 << '\n';
    else cout << "-1\n";
    return 0;
}
