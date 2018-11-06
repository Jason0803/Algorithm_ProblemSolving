#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

#define PATH    '1'
#define WALL    '0'

int N, M;

char map[110][110];
int dist[110][110];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
typedef struct _Pos {
    int r, c;
}Pos;
queue<Pos> q;
void bfs() {
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        q.pop();
        for(int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(map[nr][nc] == PATH) {
                map[nr][nc] = WALL;
                dist[nr][nc] = dist[r][c] + 1;
                q.push(Pos{nr,nc});
            }
        }
    }
}
int main() {
    printf("test..\n");
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++)
        scanf("%s",map[i]);
        
    q.push(Pos{0,0});
    bfs();

    printf("%d\n", dist[N-1][M-1]+1);

    return 0;
}