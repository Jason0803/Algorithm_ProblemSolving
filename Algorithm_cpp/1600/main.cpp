#include <iostream>
#include <queue>
#define INF         987654321
#define MAX_SIZE    201
#define MAX_K       31
using namespace std;
typedef struct _Point{
    int r, c;
    int movement;
    int k_used;
}Point;
queue<Point> q;
int K, W, H, ret;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_K];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int hdr[] = {-2, -1, -2, -1, 2, 1, 2, 1};
int hdc[] = {-1, -2, 1, 2, 1, 2, -1, -2};
bool isSafe(int r, int c) {
    return (0 <= r && r < H && 0 <= c && c < W);
}
void bfs() {
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int movement = q.front().movement;
        int k_used = q.front().k_used;
        q.pop();
        
        if(r == H-1 && c == W-1) {
            if(ret > movement) ret = movement;
            continue;
        }
        // K-USE
        if(k_used < K) {
            for(int d=0; d<8; d++) {
                int nr = r + hdr[d];
                int nc = c + hdc[d];
                if(!isSafe(nr, nc)) continue;
                if(visited[nr][nc][k_used+1] || map[nr][nc] == 1) continue;
                visited[nr][nc][k_used+1] = true;
                q.push(Point{nr, nc, movement+1, k_used+1});
            }
        }
        
        // normal move
        for(int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(!isSafe(nr, nc)) continue;
            if(visited[nr][nc][k_used] || map[nr][nc] == 1) continue;
            visited[nr][nc][k_used] = true;
            q.push(Point{nr, nc, movement+1, k_used});
        }
    }
}
int main() {
    cin >> K;
    cin >> W >> H;
    
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> map[i][j];
        }
    }
    ret = INF;
    q.push(Point{0,0,0,0});
    visited[0][0][0] = true;
    bfs();
    if(ret == INF) cout << "-1\n";
    else cout << ret << '\n';
    return 0;
}
