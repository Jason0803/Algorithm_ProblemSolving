#include <iostream>
#include <queue>
#define MAX_SIZE 102
#define    EAST     1
#define    WEST     2
#define    SOUTH    3
#define    NORTH    4
using namespace std;
typedef struct _Point {
    int r, c;
    int dir;
    int cnt;
} Point;
Point robot, destination;
queue<Point> q;
int M, N, ans;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][5];
int dr[] = {0, 0, 0, 1, -1};
int dc[] = {0, 1, -1, 0, 0};
int opp(int dir) {
    if(dir == 1) return 2;
    else if(dir == 2) return 1;
    else if(dir == 3) return 4;
    else return 3;
}
void bfs() {
    q.push(robot);
    visited[robot.r][robot.c][robot.dir] = true;
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int dir = q.front().dir;
        int cnt = q.front().cnt;
        q.pop();
        if(r == destination.r && c == destination.c && dir == destination.dir) {
            ans = cnt;
            break;
        }
        
        // Go K
        for(int i=1; i<=3; i++) {
            int nr = r + dr[dir] * i;
            int nc = c + dc[dir] * i;
            if(nr < 1 || nr > N || nc < 1 || nc > M) break;
            if(map[nr][nc] == 1) break;
            if(visited[nr][nc][dir]) continue;
            visited[nr][nc][dir] = true;
            q.push(Point{nr, nc, dir, cnt+1});
        }
        
        // Turn dir
        for(int i=1; i<=4; i++) {
            if(i == dir || i == opp(dir)) continue;
            if(visited[r][c][i]) continue;
            visited[r][c][i] = true;
            q.push(Point{r, c, i, cnt+1});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
        }
    }
    cin >> robot.r >> robot.c >> robot.dir;
    robot.cnt = 0;
    cin >> destination.r >> destination.c >> destination.dir;
    bfs();
    return 0;
}
