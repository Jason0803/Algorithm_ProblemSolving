#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_SIZE 51
using namespace std;
typedef struct _Point {
    int r, c;
    int type;
    int depth;
}Point;
queue<Point> q;
int T, N, M, R, C, L, ans;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
bool isConnected(int from, int to, int dir) {
    bool ret = false;
    
    if(dir == 0) {
        if(to == 1 || to == 2 || to == 5 || to == 6) {
            if(from != 3 && from != 5 && from != 6) ret = true;
        }
    } else if(dir == 1) {
        if(to == 1 || to == 2 || to == 4 || to == 7) {
            if(from != 3 && from != 4 && from != 7) ret = true;
        }
    } else if(dir == 2) {
        if(to == 1 || to == 3 || to == 4 || to == 5) {
            if(from != 2 && from != 4 && from != 5) ret = true;
        }
    } else {
        if(to == 1 || to == 3 || to == 6 || to == 7) {
            if(from != 2 && from != 6 && from != 7) ret = true;
        }
    }
    
    return ret;
}
void init() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            visited[i][j] = false;
        }
    }
}
void input() {
    ans = 1;
    cin >> N >> M >> R >> C >> L;
    visited[R][C] = true;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }
    q.push(Point{R,C, map[R][C], 1});
}
void bfs() {
    while(!q.empty()) {
        int q_size = q.size();
        while(q_size--) {
            int r = q.front().r;
            int c = q.front().c;
            int type = q.front().type;
            int depth = q.front().depth;
            q.pop();
            // in case bfs reaches the depth (L)
            if(depth == L) continue;
            for(int d=0; d<4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                if(visited[nr][nc] || !map[nr][nc]) continue;
                if(isConnected(type, map[nr][nc], d)) {
                    ans++;
                    visited[nr][nc] = true;
                    q.push(Point{nr,nc,map[nr][nc],depth+1});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        input();
        bfs();
        cout << "#" << test_case << " " << ans << '\n';
        init();
    }
    return 0;
}
