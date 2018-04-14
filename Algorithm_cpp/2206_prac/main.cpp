#include <iostream>
#include <queue>
using namespace std;
typedef struct _Point {
    int r, c, cnt;
    bool passed;
}Point;
int N, M;
char map[1001][1001];
bool visited[1001][1001][2];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int bfs(){
    queue<Point> q;
    visited[0][0][0] = true;
    q.push(Point{0,0,1,false});
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int cnt = q.front().cnt;
        bool passed = q.front().passed;
        q.pop();
        if(r == N-1 && c == M-1) {
            return cnt;
        }
        for(int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc][passed]) continue;
            if(map[nr][nc] == '1') {
                if(!passed) {
                    visited[nr][nc][1] = true;
                    q.push(Point{nr,nc,cnt+1,!passed});
                }
            } else {
                visited[nr][nc][passed] = true;
                q.push(Point{nr,nc,cnt+1,passed});
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }
    cout << bfs() << '\n';
    return 0;
}

