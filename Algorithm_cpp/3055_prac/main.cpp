#include <iostream>
#include <queue>
#define MAX_SIZE 54
#define INF   987654321
#define EMPTY       '.'
#define HEDGE_HOG   'S'
#define WATER       '*'
#define STONE       'X'
#define CAVE        'D'
using namespace std;
typedef struct _Point {
    int r, c;
    int time;
} Point;
Point hedge, cave;
int R, C, ans;
queue<Point> q;
char map[MAX_SIZE][MAX_SIZE];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int dist[MAX_SIZE][MAX_SIZE][2]; // 0 : HEDGE_HOG, 1 : WATER
void input() {
    cin >> R >> C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
            dist[i][j][0] = dist[i][j][1] = INF;
            if(map[i][j] == HEDGE_HOG) {
                hedge.r = i;
                hedge.c = j;
                hedge.time = 0;
            } else if(map[i][j] == CAVE) {
                cave.r = i;
                cave.c = j;
                cave.time = 0;
            }
        }
    }
}
bool isSafe(int r, int c) {
    return (0 <= r && r < R && 0 <= c && c < C);
}
void flood(int _r, int _c) {
    q.push(Point{_r,_c,0});
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int time = q.front().time;
        q.pop();
        for(int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(isSafe(nr, nc) && dist[nr][nc][1] == INF && map[nr][nc] == EMPTY) {
                dist[nr][nc][1] = time+1;
                q.push(Point{nr,nc,time+1});
            }
        }
    }
}
void hedge_move() {
    q.push(hedge);
    dist[hedge.r][hedge.c][0] = 0;
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int time = q.front().time;
        q.pop();
        for(int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(map[nr][nc] == CAVE) {
                if(dist[nr][nc][0] > time+1)
                    dist[nr][nc][0] = time + 1;
                break;
            }
            if(!isSafe(nr, nc) || dist[nr][nc][0] != INF) continue;
            if(map[nr][nc] == EMPTY && dist[nr][nc][1] > time + 1) {
                dist[nr][nc][0] = time + 1;
                q.push(Point{nr,nc,time+1});
            }
        }
    }
}
void solve() {
    // 1. bfs for water flood
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(map[i][j] == WATER && dist[i][j][1] == INF) {
                dist[i][j][1] = 0;
                flood(i,j);
            }
        }
    }
    
    // 2. bfs for HEDGE_HOG moves
    hedge_move();
    ans = dist[cave.r][cave.c][0];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    
    if(ans == INF) cout << "KAKTUS\n";
    else cout << ans << '\n';
    return 0;
}
